/***
*memory.h - declarations for buffer (memory) manipulation routines
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This include file contains the function declarations for the
*	buffer (memory) manipulation routines.
*	[System V]
*
****/

#ifndef _INC_MEMORY

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif


/* function prototypes */

void * _memccpy(void *, const void *, int, unsigned int);
void * memchr(const void *, int, size_t);
int memcmp(const void *, const void *, size_t);
void * memcpy(void *, const void *, size_t);
int _memicmp(const void *, const void *, unsigned int);
void * memset(void *, int, size_t);

#if !__STDC__
/* Non-ANSI names for compatibility */
#define memccpy  _memccpy
#define memicmp  _memicmp
#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#define _INC_MEMORY
#endif	/* _INC_MEMORY */
