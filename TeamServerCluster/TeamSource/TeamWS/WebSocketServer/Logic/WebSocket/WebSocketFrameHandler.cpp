#include "WebSocketFrameHandler.h"
#include "websocket/WebSocket.h"
#include "websocket/WebSocketManager.h"

#include "../../FrameWork/BaseDefine.h"
#include "../../FrameWork/PlayerClient.h"
#include "../../FrameWork/WebSocketServer.h"

CWebSocketFrameHandler::CWebSocketFrameHandler() :m_nCloseState(false), m_nVersion(13)
{
}
CWebSocketFrameHandler::~CWebSocketFrameHandler()
{
}

bool CWebSocketFrameHandler::CheckHandleShake(const char* data, unsigned int &version, unsigned int length, std::string &response)
{
	CWebSocket* pWebsocket = CWebSocketManager::Handle(data, version, length, response);
	if (!response.empty())
	{
		setVersion(version);

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_DEBUG, "\r\n WebSocket: client HandShake Request \r\n(Protocol: %s)\r\n", data);

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_DEBUG, "\r\n WebSocket: Server HandShake Response \r\n(Protocol:%s) \r\n ", response.c_str());

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_DEBUG, "\r\n WebSocket: WebClient - WebSocketServer HandShake Success \r\n(Protocol: Version: V %2d)\r\n ", version);
		return true;
	}
	return false;
}

bool CWebSocketFrameHandler::HandleFrame(const char* data, unsigned int &version, unsigned int length, vector<string>& responsevec)
{
	std::string response;
	CWebSocket* pWebsocket = CWebSocketManager::Handle(data, version, length, response);
	if (NULL == pWebsocket)
	{
		return false;
	}

	g_LogFile.WriteErrorLogInfo(LOGIC_LOG_DEBUG, "WebSocket: Data Send/Receive ull-duplex communication processing");

	bool bSend;
	const CWebSocketMessage* pWebsocketMessage = NULL;

	size_t nLength = (size_t)length;
	pWebsocketMessage = pWebsocket->Handle(data, nLength, bSend);
	if (NULL == pWebsocketMessage)
	{
		return false;
	}
	if (pWebsocket->GetState() == EWebSocketState_Close)
	{
		setCloseState();
		return false;
	}

	CConvertCharString  ConvertCharStringObj;

	typedef const std::vector<const CWebSocketFrame*> const_WebSocketFrameVec;

	const_WebSocketFrameVec& vWebSocketFrame = pWebsocketMessage->GetFrames();

	const_WebSocketFrameVec::const_iterator iter = vWebSocketFrame.begin();
	const_WebSocketFrameVec::const_iterator iterEnd = vWebSocketFrame.end();
	const char* pApplicationData = NULL;
	string strplit("\\n");
	vector<string> straimrsponsevec;
	string::size_type pos;
	for (; iter != iterEnd; ++iter)
	{
		const CWebSocketFrame* pWebSocketFrame = *iter;
		if (NULL != pWebSocketFrame)
		{
			pApplicationData = pWebSocketFrame->GetApplicationData();
			if (NULL != pApplicationData)
			{
				string strTemp(pApplicationData);

				string strResponese("");

				pos = strTemp.find(strplit);
				if (pos != strTemp.npos)
				{
					strResponese = strTemp.substr(pos, pWebSocketFrame->GetLength());
				}
				else
				{
					pos = strTemp.find_first_of(strplit);
					if (pos != strTemp.npos)
					{
						strResponese = strTemp.substr(pos, pWebSocketFrame->GetLength());
					}
					else
					{
						strResponese = strTemp;
					}
				}

				straimrsponsevec = PARSE_STRINGS::ParseString::Split(strResponese, strplit);
				if (straimrsponsevec[0].empty())
				{
					std::vector<string>::iterator it = straimrsponsevec.begin() + 0;
					straimrsponsevec.erase(it);
				}

				vector<string> strTempVec;
				strTempVec.swap(straimrsponsevec);
				vector<string>::iterator itex = strTempVec.begin();
				vector<string>::iterator itex_end = strTempVec.end();
				for (; itex != itex_end; ++itex)
				{
					responsevec.push_back(*itex);
				}

				g_LogFile.WriteErrorLogInfo(LOGIC_LOG_DEBUG, "WebSocket: Receive WebClient (Data: %s)\r\n", ConvertCharStringObj.U2G(strResponese.c_str()));
			}
		}
	}
	return true;
}

void CWebSocketFrameHandler::PushNotifications(const char* data, unsigned int length, int nWebMarkId)
{
	std::string response;
	CWebSocket* pWebsocket = CWebSocketManager::Handle(data, m_nVersion, length, response);
	if (!response.empty())
		return;

	const CWebSocketMessage *msg = pWebsocket->Send(WebSocketTextFrame, data, length);
	if (msg == NULL || !msg->IsComplete())
		return;

	std::vector<const CWebSocketFrame *> frames = msg->GetFrames();

	CConvertCharString  ConvertCharStringObj;

	for (unsigned int i = 0; i < frames.size(); i++)
	{
		CWebSocketServer::Instance().SendClientMsg(const_cast<char*>(frames.at(i)->GetFrameData()), (long)frames.at(i)->GetFrameLength(), nWebMarkId);

		g_LogFile.WriteErrorLogInfo(LOGIC_LOG_DEBUG, "WebSocket: Send To  WebClient (Response Data: %s Player nIndex: %d)\r\n", ConvertCharStringObj.U2G(data), nWebMarkId);
	}
}

void CWebSocketFrameHandler::PushNotifications(const char* data, unsigned int length)
{
	std::string response;
	CWebSocket* pWebsocket = CWebSocketManager::Handle(data, m_nVersion, length, response);
	if (!response.empty())
		return;

	const CWebSocketMessage *msg = pWebsocket->Send(WebSocketTextFrame, data, length);
	if (msg == NULL || !msg->IsComplete())
		return;

	std::vector<const CWebSocketFrame *> frames = msg->GetFrames();

	CConvertCharString  ConvertCharStringObj;

	for (unsigned int i = 0; i < frames.size(); i++)
	{
		CWebSocketServer::Instance().SendClientMsg(const_cast<char*>(frames.at(i)->GetFrameData()), (long)frames.at(i)->GetFrameLength());
	}
}