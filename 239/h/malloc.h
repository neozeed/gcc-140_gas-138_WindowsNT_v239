/***
*malloc.h - declarations and definitions for memory allocation functions
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	Contains the function declarations for memory allocation functions;
*	also defines manifest constants and types used by the heap routines.
*	[System V]
*
****/

#ifndef _INC_MALLOC

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif

#define _HEAPEMPTY	(-1)
#define _HEAPOK 	(-2)
#define _HEAPBADBEGIN	(-3)
#define _HEAPBADNODE	(-4)
#define _HEAPEND	(-5)
#define _HEAPBADPTR	(-6)
#define _FREEENTRY	0
#define _USEDENTRY	1

/* Define _HEAP_MAXREQ to be equal to (unsigned)( -sizeof(_heap_seg_desc)
 * - 2*sizeof(int) ) */

#define _HEAP_MAXREQ	0xFFFFFFD8


#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif


#ifndef _HEAPINFO_DEFINED
typedef struct _heapinfo {
	int * _pentry;
	size_t _size;
	int _useflag;
	} _HEAPINFO;
#define _HEAPINFO_DEFINED
#endif


/* external variable declarations */

extern unsigned int _amblksiz;


/* function prototypes */

void * _alloca(size_t);
void * calloc(size_t, size_t);
void * _expand(void *, size_t);
void free(void *);
int _heapadd(void *, size_t);
int _heapchk(void);
int _heapmin(void);
int _heapset(unsigned int);
int _heapwalk(_HEAPINFO *);
void * malloc(size_t);
size_t _msize(void *);
void * realloc(void *, size_t);

#if !__STDC__
/* Non-ANSI names for compatibility */
#define alloca	   _alloca
#endif	/* __STDC__*/

#ifdef __cplusplus
}
#endif

#define _INC_MALLOC
#endif	/* _INC_MALLOC */
