#pragma once

#ifndef  EQ_DATATYPE_FILE
#define  EQ_DATATYPE_FILE

#if defined (_WIN32) || defined (_WIN64)
#define    WINDOWS_VESION
#pragma  warning(disable: 4200)
#include <basetsd.h>
#else
#define    LINUX_VESION
#endif

#define      __BOOL       bool
#define      __CHAR       char
#define      __UCHAR      unsigned char
#define      __ULONG      unsigned long

typedef __UCHAR     BYTE;

#if defined (WINDOWS_VESION)

#define    __INT16      INT16
#define    __UINT16     UINT16
#define    __INT32      INT32
#define    __UINT32     UINT32
#define    __INT64      INT64
#define    __UINT64     UINT64

#else
#define    __INT16      int16_t
#define    __UINT16     u_int16_t
#define    __INT32      int32_t
#define    __UINT32     u_int32_t
#define    __INT64      int64_t
#define    __UINT64     u_int64_t

#endif

#endif
