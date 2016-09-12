#pragma once
#ifndef __BASE_DEFIN_H__
#define __BASE_DEFIN_H__

#include <map>
#include <vector>
#include "EQ_Log.h"
#include "EQ_Time.h"
#include "EQ_Lock.h"
#include "EQ_String.h"
#include "EQ_DataType.h"
#include "EQ_Singleton.h"
#include "EQ_ObjPool.h"
#include "EQ_MultiThreads.h"
#include "BasePacket.h"
#include "encrypt/md5.h"

#include "EQ_ConvertCharString.h"

#include "BackendClient.h"

#define  CLIENT_MESSAGE_LEN_MAX                                      (1024 * 8)
#define  SERVER_MESSAGE_LEN_MAX                                      (1024 * 8 - 8 -4)

const int SERVER_LISTEN_WEB_PORT = 8080;

extern CEQ_Log g_LogFile;
extern CBackendClient g_BackendClient;

extern vector<void*> g_RecvMsg;
extern CEQ_Lock g_RecvMsgLock;

#endif//__BASE_DEFIN_H__