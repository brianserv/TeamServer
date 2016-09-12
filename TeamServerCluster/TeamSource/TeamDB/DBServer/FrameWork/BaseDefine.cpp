#include "BaseDefine.h"

CEQ_Log               g_LogFile;

CDBManager      g_DBManager[DB_CONN_NUM];
CDBApplication  g_DBApplication[DB_CONN_NUM];
CEQ_DAL_Engine        g_dbEngine;

vector<void*>         g_RecvMsg;
CEQ_Lock              g_RecvMsgLock;