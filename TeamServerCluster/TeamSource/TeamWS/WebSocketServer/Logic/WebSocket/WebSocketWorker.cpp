#include "WebSocketWorker.h"

#include "WebSocketFrameHandler.h"

#include "../../FrameWork/PlayerClient.h"
#include "../../FrameWork/WebSocketServer.h"
#include "../../Logic/WebFrameFilter/WebFrameFilter.h"
#include "../../Logic/Message/WSSMessage/WSSMessage.h"

CWebSocketWorker::CWebSocketWorker()
{
}

CWebSocketWorker::~CWebSocketWorker()
{
	m_strResponsevec.clear();
}

void CWebSocketWorker::WebSocketFrameHandler(const char* data, unsigned int length, void* pPacketHead, void* pClient)
{
	PACKETHEAD* pPacketHeadEx = reinterpret_cast<PACKETHEAD*>(pPacketHead);
	CPlayerClient* pPlayerClient = reinterpret_cast<CPlayerClient*>(pClient);
	if (NULL == pPacketHeadEx || NULL == pClient)
		return;

	//WebSocket	shakeHand
	std::string response;
	unsigned int nVersion = pPlayerClient->GetVersion();
	if (CWebSocketFrameHandler::Instance().CheckHandleShake(data, nVersion, length, response))
	{
		pPlayerClient->SetVersion(nVersion);
		CWebSocketServer::Instance().SendClientMsg(const_cast<char*>(response.c_str()), response.length(), pPlayerClient->GetIndex());
		return;
	}
	else
	{
		//WebSocket	HandFrame
		m_strResponsevec.clear();

		if (!CWebSocketFrameHandler::Instance().HandleFrame(data, nVersion, length, m_strResponsevec))
		{
			if (CWebSocketFrameHandler::Instance().getCloseState())
				pPlayerClient->OnDisconnect(0);
			return;
		}
		//WebSocket Frame Handler
		WebSocketFrameHandler(pPlayerClient->GetIndex());
	}

	string strShakeTest("1|1|200|2|300:2|1|200|2|500");
	PushNotifications(strShakeTest, pPlayerClient->GetIndex());
}

void CWebSocketWorker::WebSocketFrameHandler(int nWebMarkId)
{
	RESPONSE_VEC::iterator iter = m_strResponsevec.begin();
	RESPONSE_VEC::iterator iterEnd = m_strResponsevec.end();
	for (; iter != iterEnd; ++iter)
	{
		if (!(*iter).empty())
		{
			if (CWebFrameFilter::Instance().ParseWebTextFrame((*iter), nWebMarkId));
			{
				switch (CWebFrameFilter::Instance().GetFilterCommand())
				{
				case 4195657:
					CWSSMessage::Instance().ProcessMsg(CWebFrameFilter::Instance().GetWebTextFrame_LeafVec(), nWebMarkId);
					g_LogFile.WriteErrorLogInfo(LOGIC_LOG_INFO, "【CMD：%0X PROTO_CMD_W2P_GM_ACT_SENDEMAILREWARD_ASK】", CWebFrameFilter::Instance().GetFilterCommand());
					break;
				}
			}
		}
	}
}

void CWebSocketWorker::PushNotifications(string strPushNotifications)
{
	CWebSocketFrameHandler::Instance().PushNotifications(strPushNotifications.c_str(), strPushNotifications.length());
}

void CWebSocketWorker::PushNotifications(string strPushNotifications, int nWebMarkId)
{
	CWebSocketFrameHandler::Instance().PushNotifications(strPushNotifications.c_str(), strPushNotifications.length(), nWebMarkId);
}

void CWebSocketWorker::OnTimer()
{
	string strShakeTest("PushNotifications ALL WebSocket Client");
	PushNotifications(strShakeTest);
}