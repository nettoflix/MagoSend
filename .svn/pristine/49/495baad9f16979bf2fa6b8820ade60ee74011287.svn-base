#ifndef LINDOWS_H
#define LINDOWS_H

#include <inttypes.h>

#include <string>

//#include "CUtil.h"

//#define Sleep(x) CThreadSleeper::msleep(x)


#define BOOL bool

#define __stdcall

#define LONGLONG int64_t

#define LONG long

#define HRESULT long

typedef unsigned char BYTE;

typedef int HANDLE;

#define UINT uint32_t

#define FALSE false

#define TRUE true


inline double GetTickCount(void)
{
  struct timespec now;
  if (clock_gettime(CLOCK_MONOTONIC, &now))
    return 0;
  return now.tv_sec * 1000.0 + now.tv_nsec / 1000000.0;
}


#endif // LINDOWS_H
