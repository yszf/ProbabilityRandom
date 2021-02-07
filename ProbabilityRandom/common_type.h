#ifndef __COMMON_TYPE_H_2021_2_4__
#define __COMMON_TYPE_H_2021_2_4__

#include <iostream>
#include <cassert>
#ifdef _WIN32
#include <windows.h>
#define SleepMs(x) Sleep(x)
#else
#include <unistd.h>
#define SleepMs(x) usleep(x * 1000)
#endif

#ifndef INT8
typedef signed char INT8;
#endif

#ifndef UINT8
typedef unsigned char UINT8;
#endif

#ifndef INT16
typedef signed short INT16;
#endif

#ifndef UINT16
typedef unsigned short UINT16;
#endif

#ifndef INT32
typedef signed int INT32;
#endif

#ifndef UINT32
typedef unsigned int UINT32;
#endif

#ifndef INT64
typedef signed long long INT64;
#endif

#ifndef UINT64
typedef unsigned long long UINT64;
#endif

#ifndef FLOAT
typedef float FLOAT;
#endif

#ifndef BOOL
typedef INT32 BOOL;
#endif

#ifndef VOID
typedef void VOID;
#endif


#endif