#include <vector>
#include "EQ_Lock.h"
#include "BaseDefine.h"

CEQ_Log               g_LogFile;

vector<void*>         g_RecvMsg;
CEQ_Lock              g_RecvMsgLock;