/***
*direct.h - function declarations for directory handling/creation
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This include file contains the function declarations for the library
*	functions related to directory handling and creation.
*
****/

#ifndef _INC_DIRECT

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

/* _getdiskfree structure for _getdiskfree() */

#ifndef _DISKFREE_T_DEFINED

struct _diskfree_t {
	unsigned total_clusters;
	unsigned avail_clusters;
	unsigned sectors_per_cluster;
	unsigned bytes_per_sector;
	};

#define _DISKFREE_T_DEFINED

#endif

/* function prototypes */

int _chdir(const char *);
int _chdrive(int);
char * _getcwd(char *, int);
char * _getdcwd(int, char *, int);
int _getdrive(void);
int _mkdir(const char *);
int _rmdir(const char *);
unsigned _getdiskfree(unsigned, struct _diskfree_t *);
unsigned long _getdrives(void);

#if !__STDC__
/* Non-ANSI names for compatibility */
#define chdir	_chdir
#define getcwd	_getcwd
#define mkdir	_mkdir
#define rmdir	_rmdir
#define diskfree_t  _diskfree_t
#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#define _INC_DIRECT
#endif	/* _INC_DIRECT */
