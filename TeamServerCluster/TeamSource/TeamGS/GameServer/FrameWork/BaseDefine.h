#pragma once
#ifndef __BASE_DEFIN_H__
#define __BASE_DEFIN_H__

#include <map>
#include "EQUtils.h"
#include "EQ_Log.h"
#include "EQ_Time.h"
#include "EQ_String.h"
#include "EQ_DataType.h"
#include "EQ_ObjPool.h"
#include "EQ_FileFolder.h"
#include "EQ_UniqueVector.h"
#include "EQ_URL.h"
#include "EQ_Singleton.h"
#include "EQ_Random.h"
#include "EQ_CurlHttp.h"
#include "EQ_IPAddresses.h"
#include "BasePacket.h"
#include "json/json.h"

#include "encrypt/md5.h"

#include "DBClient.h"
#include "DBLogClient.h"
#include "CenterClient.h"

#include "ConfigFile.h"

#include "HttpLinkApplication.h"
#include "../Logic/Common/GameEnum.h"
#include "../Logic/Common/GameMacro.h"
#include "../Logic/Common/GameStructure.h"
#include "../Logic/GameFormula/GameFormula.h"

#include "dbEngine/EQ_DAL_Engine.h"

#include "../Logic/DBCache/DBManager.h"

#define  CLIENT_MESSAGE_LEN_MAX                                      (1024 * 8)
#define  SERVER_MESSAGE_LEN_MAX                                      (1024 * 8 - 8 -4)
#define  MAX_SQL_STR_LENGTH                                           1024 * 8
#define  MAX_HTTP_STR_LENGTH                                          1024
#define  MAX_HTTP_LINK_THREADS_NUM                                     5

#define  TEXAS_HISTORY_BOARD_NUM                                       10

#define  BET_TEA_ID 1

#define	CRLF "\r\n"

#define HTTP_HEADER_DOMAIN_TABLE_NAME "Table-Name"

#define HTTP_JSON_TABLE_BRACE_LEFT "{\""
#define HTTP_JSON_TABLE_COLON_MIDDLE  "\":"
#define HTTP_JSON_TABLE_BRACE_RIGHT "}"

typedef enum { HTTP1_0, HTTP1_1, HTTP_UNSUPPORTED } HTTP_ProtocolVersion;

const short WEBPORT80 = 80;
const string CONSTR_ROLE_TOKEN_KEY = "love21pink";

extern CEQ_Log               g_LogFile;
extern CDBClient             g_DBClient;
extern CDBLogClient          g_DBLogClient;
extern CCenterClient         g_CenterClient;
extern vector<void*>         g_RecvMsg;
extern CEQ_Lock              g_RecvMsgLock;
extern CEQ_Lock              g_HttpLock;
extern CEQ_CurlHttp          g_CurlHttp;
extern CHttpLinkApplication  g_HttpLinkApplication[MAX_HTTP_LINK_THREADS_NUM];
extern bool                  g_StartServer;
extern bool                  g_PrizePool;
extern bool                  g_ResourceLoadSucc;
extern bool                  g_GameRoomBindSucc;
extern CGameFormula          g_GameFormula;

extern CEQ_DAL_Engine        g_dbEngine;
extern CDBManager            g_DBManager;

extern vector<void*>         g_Req_HttpMsg;
extern CEQ_Lock              g_Req_HttpMsg_Lock;

extern vector<void*>         g_Res_HttpMsg;
extern CEQ_Lock              g_Res_HttpMsg_Lock;

#endif//__BASE_DEFIN_H__
