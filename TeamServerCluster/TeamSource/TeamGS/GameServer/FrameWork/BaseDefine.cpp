#include <vector>
#include "EQ_Lock.h"
#include "BaseDefine.h"

CEQ_Log            		 g_LogFile;
CDBClient          		 g_DBClient;
CDBLogClient       		 g_DBLogClient;
CCenterClient      		 g_CenterClient;
vector<void*>      		 g_RecvMsg;
CEQ_Lock           		 g_RecvMsgLock;
CEQ_Lock                 g_HttpLock;
CEQ_CurlHttp       		 g_CurlHttp;
CHttpLinkApplication     g_HttpLinkApplication[MAX_HTTP_LINK_THREADS_NUM];
bool                     g_StartServer;
bool                     g_PrizePool;
bool                     g_GameRoomBindSucc;
bool                     g_ResourceLoadSucc;
CGameFormula             g_GameFormula;

CEQ_DAL_Engine         g_dbEngine;
CDBManager             g_DBManager;

vector<void*>            g_Req_HttpMsg;
CEQ_Lock                 g_Req_HttpMsg_Lock;

vector<void*>            g_Res_HttpMsg;
CEQ_Lock                 g_Res_HttpMsg_Lock;