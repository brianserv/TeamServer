#pragma once
#ifndef __BASE_DEFIN_H__
#define __BASE_DEFIN_H__

#include <map>
#include "EQUtils.h"
#include "EQ_Log.h"
#include "EQ_Time.h"
#include "EQ_String.h"
#include "EQ_ObjPool.h"
#include "EQ_DataType.h"
#include "BasePacket.h"

#define  CLIENT_MESSAGE_LEN_MAX                                      (1024 * 8)
#define  SERVER_MESSAGE_LEN_MAX                                      (1024 * 8 - 8 -4)
#define  ACCOUNT_ID_LEN_MAX                                           100
#define  ROLE_RECRUITPARTNER_LEN_MAX                                  512
#define  PARTNER_TALENTLIST_LEN_MAX                                   512
#define  MAX_SQL_STR_LENGTH                                           1024 * 8

extern CEQ_Log               g_LogFile;
extern vector<void*>         g_RecvMsg;
extern CEQ_Lock              g_RecvMsgLock;

#endif//__BASE_DEFIN_H__