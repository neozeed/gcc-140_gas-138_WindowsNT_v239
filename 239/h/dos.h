/***
*dos.h - definitions for MS-DOS interface routines
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	Defines the structs and unions used for the direct DOS interface
*	routines; includes macros to access the segment and offset
*	values of far pointers, so that they may be used by the routines; and
*	provides function prototypes for direct DOS interface functions.
*
****/

#ifndef _INC_DOS

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif



/* _getdiskfree structure (duplicated in DIRECT.H) */

#ifndef _DISKFREE_T_DEFINED

struct _diskfree_t {
	unsigned total_clusters;
	unsigned avail_clusters;
	unsigned sectors_per_cluster;
	unsigned bytes_per_sector;
	};

#define _DISKFREE_T_DEFINED

#endif



/* File attribute constants */

#define _A_NORMAL	0x00	/* Normal file - No read/write restrictions */
#define _A_RDONLY	0x01	/* Read only file */
#define _A_HIDDEN	0x02	/* Hidden file */
#define _A_SYSTEM	0x04	/* System file */
#define _A_SUBDIR	0x10	/* Subdirectory */
#define _A_ARCH 	0x20	/* Archive file */

/* external variable declarations */

extern unsigned int _osversion;

extern unsigned int _osmajor;
extern unsigned int _osminor;
extern unsigned int _baseversion;
extern unsigned int _basemajor;
extern unsigned int _baseminor;

/* function prototypes */

unsigned _getdiskfree(unsigned, struct _diskfree_t *);

#if !__STDC__
/* Non-ANSI name for compatibility */
#define diskfree_t  _diskfree_t
#endif	/* __STDC__ */

/* restore default alignment */


#ifdef __cplusplus
}
#endif

#define _INC_DOS
#endif	/* _INC_DOS */
