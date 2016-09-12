#pragma once

#include "EQUtils.h"
#include "EQ_Singleton.h"

/*WebSocket: client HandShake Request

	(Protocol : GET / websocket HTTP / 1.1

		Upgrade : websocket

		Connection : Upgrade

		Host : localhost : 8080

		Origin : null

		Pragma : no - cache

		Cache - Control : no - cache

		Sec - WebSocket - Key : ATl8Uw8Aq5jd99q6j + O6yQ ==

		Sec - WebSocket - Version : 13

		Sec - WebSocket - Extensions : x - webkit - deflate - frame

		User - Agent : Mozilla / 5.0 (Windows NT 6.1; WOW64) AppleWebKit / 537.36 (KHTML, like Gecko) Chrome / 31.0.1650.63 Safari / 537.36
)WebSocket : Server HandShake Response

	(Protocol : HTTP / 1.1 101 Switching Protocols

		Upgrade : websocket

		Connection : Upgrade

		Sec - WebSocket - Accept : gxP + GKTdyoHJgvSMl8GLm8iXxvg =

)*/

class CWebSocketFrameHandler :public CEQ_SingletonT<CWebSocketFrameHandler>
{
public:
	CWebSocketFrameHandler();
	virtual ~CWebSocketFrameHandler();
public:
	inline unsigned  int& getVersion() { return m_nVersion; };
	inline void setVersion(unsigned int nVersion) { m_nVersion = nVersion; };
	inline void setCloseState() { m_nCloseState = true; };
	inline bool getCloseState() { return m_nCloseState; };

public:
	bool CheckHandleShake(const char* data, unsigned int &version, unsigned int length, std::string &response);
	bool HandleFrame(const char* data, unsigned int &version, unsigned int length, vector<string>& responsevec);
public:
	void PushNotifications(const char* data, unsigned int length, int nWebMarkId);
	void PushNotifications(const char* data, unsigned int length);

private:
	bool  m_nCloseState;
	unsigned int m_nVersion;

	enum EWebSocketState
	{
		EWebSocketState_Close = 4,
	};
};
