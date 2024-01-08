/***
*sys\timeb.h - definition/declarations for _ftime()
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This file define the _ftime() function and the types it uses.
*	[System V]
*
*******************************************************************************/

#ifndef _INC_TIMEB

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif

#ifndef _TIME_T_DEFINED
typedef long time_t;
#define _TIME_T_DEFINED
#endif

/* structure returned by _ftime system call */

#ifndef _TIMEB_DEFINED
struct _timeb {
	time_t time;
	unsigned short millitm;
	short _timezone;
	short dstflag;
	};

/* must be same name as extern declared in time.h */
#define timezone _timezone

#if !__STDC__
/* Non-ANSI name for compatibility */
#define timeb _timeb
#endif

#define _TIMEB_DEFINED
#endif


/* function prototypes */

void _ftime(struct _timeb *);

#if !__STDC__
/* Non-ANSI name for compatibility */
#define ftime	 _ftime
#endif

#ifdef __cplusplus
}
#endif

#define _INC_TIMEB
#endif	/* _INC_TIMEB */
