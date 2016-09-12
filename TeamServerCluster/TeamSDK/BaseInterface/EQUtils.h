#pragma once

#ifndef  EQ_Utils_FILE
#define  EQ_Utils_FILE

#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <time.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;


#if defined (_WIN32) || defined (_WIN64)

#include "sysdef.h"
#include <tchar.h>
#include <winsock2.h>
#include <Windows.h>
#include "mswsock.h"
#include <assert.h>
#include <direct.h>   
#include <io.h>


#else
#include <stdint.h>
#include <pthread.h>
#include <sys/epoll.h>
#include <sys/socket.h> 
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/sysinfo.h>
#include <stdarg.h>   
#include <sys/stat.h>
#include <sys/time.h>
#include <stdarg.h>


#define TIMEDIFF_MICRO_SECOND(s, e) (((e.tv_sec)-(s.tv_sec))*1000000 + (e.tv_usec) - (s.tv_usec))
#define TIMEDIFF_MILLI_SECOND(s, e) (((e.tv_sec)-(s.tv_sec))*1000 + ((e.tv_usec) - (s.tv_usec))/1000)

#endif



#define SAFE_DELETE(p)			{ if ((p) != NULL) { delete (p); (p) = NULL; } }


#define SAFE_DELETE_ARRAY(p)	{ if ((p) != NULL) { delete [](p); (p) = NULL; } }

#define SAFE_DELETE_GDIOBJ(p)	{ if ((p) != NULL) { DeleteObject(p); (p) = NULL; } }

#define SAFE_RELEASE(p)			{ if ((p) != NULL) { (p)->Release(); (p) = NULL; } }


#define PAI 3.14159265358979323
#define CountArray(Array) (sizeof(Array)/sizeof(Array[0]))

#define EQ_MINUTE 60

#endif
