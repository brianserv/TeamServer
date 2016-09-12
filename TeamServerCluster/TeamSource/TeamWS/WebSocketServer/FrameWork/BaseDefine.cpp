#include "BaseDefine.h"

CEQ_Log                 g_LogFile;
CBackendClient          g_BackendClient;
vector<void*>           g_RecvMsg;
CEQ_Lock                g_RecvMsgLock;