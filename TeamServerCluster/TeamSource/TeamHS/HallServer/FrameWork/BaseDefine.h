#pragma once
#ifndef __BASE_DEFIN_H__
#define __BASE_DEFIN_H__

#include "EQUtils.h"
#include "EQ_Log.h"
#include "EQ_Time.h"
#include "EQ_String.h"
#include "EQ_DataType.h"
#include "EQ_Singleton.h"
#include "EQ_ObjPool.h"
#include "BasePacket.h"

#include "encrypt/md5.h"

#include "GameClient.h"

#include "dbEngine/EQ_DAL_Engine.h"

#include "../Logic/DBCache/DBManager.h"
#include "../../../../TeamSDK/BaseInterface/dbEngine/EQ_DAL_Engine.h"

#define  CLIENT_MESSAGE_LEN_MAX                                      (1024 * 8)
#define  SERVER_MESSAGE_LEN_MAX                                      (1024 * 8 - 8 -4)

#define  MAX_SQL_STR_LENGTH                                           1024 * 8

extern CEQ_Log               g_LogFile;
extern CGameClient           g_GameClient;
extern CEQ_DAL_Engine        g_dbEngine;
extern CDBManager            g_DBManager;
extern vector<void*>         g_RecvMsg;
extern CEQ_Lock              g_RecvMsgLock;

#endif//__BASE_DEFIN_H__