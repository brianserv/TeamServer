#include <vector>
#include "EQ_Lock.h"
#include "BaseDefine.h"

CEQ_Log               g_LogFile;
CGameClient           g_GameClient;
CEQ_DAL_Engine        g_dbEngine;
CDBManager            g_DBManager;
vector<void*>         g_RecvMsg;
CEQ_Lock              g_RecvMsgLock;