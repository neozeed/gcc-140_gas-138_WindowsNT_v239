/***
*stdlib.h - declarations/definitions for commonly used library functions
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This include file contains the function declarations for
*	commonly used library functions which either don't fit somewhere
*	else, or, like toupper/tolower, can't be declared in the normal
*	place for other reasons.
*	[ANSI]
*
****/

#ifndef _INC_STDLIB

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


#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif


/* define NULL pointer value */

#ifndef NULL
#ifdef __cplusplus
#define NULL	0
#else
#define NULL	((void *)0)
#endif
#endif


/* definition of the return type for the onexit() function */

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1


#ifndef _ONEXIT_T_DEFINED
typedef int (* _onexit_t)(void);
#if !__STDC__
/* Non-ANSI name for compatibility */
#define onexit_t _onexit_t
#endif
#define _ONEXIT_T_DEFINED
#endif


/* Data structure definitions for div and ldiv runtimes. */

#ifndef _DIV_T_DEFINED

typedef struct _div_t {
	int quot;
	int rem;
} div_t;

typedef struct _ldiv_t {
	long quot;
	long rem;
} ldiv_t;

#define _DIV_T_DEFINED
#endif

/* Maximum value that can be returned by the rand function. */

#define RAND_MAX 0x7fff

extern	unsigned short __mb_cur_max;	/* max mb-len for current locale */
#define	MB_CUR_MAX __mb_cur_max

/* min and max macros */

#define __max(a,b)	(((a) > (b)) ? (a) : (b))
#define __min(a,b)	(((a) < (b)) ? (a) : (b))


/* sizes for buffers used by the _makepath() and _splitpath() functions.
 * note that the sizes include space for 0-terminator
 */

#define _MAX_PATH	260	/* max. length of full pathname */
#define _MAX_DRIVE	3	/* max. length of drive component */
#define _MAX_DIR	256	/* max. length of path component */
#define _MAX_FNAME	256	/* max. length of file name component */
#define _MAX_EXT	256	/* max. length of extension component */

/* constants for _seterrormode() */
#define _CRIT_ERROR_PROMPT  0
#define _CRIT_ERROR_FAIL    1

/* constants for _sleep() */
#define _SLEEP_MINIMUM	0
#define _SLEEP_FOREVER	-1

/* external variable declarations */

#ifdef	_MT
extern int * _errno(void);
extern unsigned long * __doserrno(void);
#define errno	    (*_errno())
#define _doserrno   (*__doserrno())
#else	/* ndef _MT */
extern int errno;			/* XENIX style error number */
extern unsigned long _doserrno;	/* OS system error value */
#endif	/* _MT */
extern char * _sys_errlist[]; /* perror error message table */
extern int _sys_nerr; 	/* # of entries in sys_errlist table */

extern char ** _environ;	/* pointer to environment table */
extern int _fmode;		/* default file translation mode */
extern int _fileinfo; 	/* open file info mode (for spawn) */

extern unsigned int _psp;	/* Program Segment Prefix */


/* DOS major/minor version numbers */

extern unsigned int _osmajor;
extern unsigned int _osminor;

/* OS API mode */

#define _DOS_MODE	0	/* DOS */
#define _OS2_MODE	1	/* OS/2 */
#define _WIN_MODE	2	/* Windows */
#define _OS2_20_MODE	3	/* OS/2 2.0 */
#define _DOSX32_MODE	4	/* DOSX32 */

extern unsigned char _osmode;

/* CPU addressing mode */

#define _REAL_MODE	0	/* real mode */
#define _PROT_MODE	1	/* protect mode */
#define _FLAT_MODE	2	/* flat mode */

extern unsigned char _cpumode;


/* function prototypes */

void   abort(void);
int    abs(int);
int    atexit(void (*)(void));
double atof(const char *);
int    atoi(const char *);
long   atol(const char *);
#if defined(i386)
long double _atold(const char *);
#endif
void * bsearch(const void *, const void *, size_t, size_t,
	int (*)(const void *, const void *));
void * calloc(size_t, size_t);
div_t  div(int, int);
char * _ecvt(double, int, int *, int *);
void   exit(int);
void   _exit(int);
char * _fcvt(double, int, int *, int *);
void   free(void *);
char * _fullpath(char *, const char *, size_t);
char * _gcvt(double, int, char *);
char * getenv(const char *);
char * _itoa(int, char *, int);
long   labs(long);
ldiv_t ldiv(long, long);
unsigned long _lrotl(unsigned long, int);
unsigned long _lrotr(unsigned long, int);
char * _ltoa(long, char *, int);
void   _makepath(char *, const char *, const char *, const char *,
	const char *);
void * malloc(size_t);
_onexit_t _onexit(_onexit_t);
void   perror(const char *);
int    _putenv(const char *);
void   qsort(void *, size_t, size_t, int (*)
	(const void *, const void *));
unsigned int _rotl(unsigned int, int);
unsigned int _rotr(unsigned int, int);
int    rand(void);
void * realloc(void *, size_t);
void   _searchenv(const char *, const char *, char *);
void   _splitpath(const char *, char *, char *, char *, char *);
void   srand(unsigned int);
double strtod(const char *, char **);
long   strtol(const char *, char **, int);
#if defined(i386)
long double _strtold(const char *, char **);
#endif
unsigned long strtoul(const char *, char **, int);
void   _swab(char *, char *, int);
int    system(const char *);
char * _ultoa(unsigned long, char *, int);
int    mblen(const char *, size_t);
int    mbtowc(wchar_t *, const char *, size_t);
int    wctomb(char *, wchar_t);
size_t mbstowcs(wchar_t *, const char *, size_t);
size_t wcstombs(char *, const wchar_t *, size_t);
void _seterrormode(int);
void _beep(unsigned, unsigned);
void _sleep(unsigned long);

#ifndef tolower 	/* tolower has been undefined - use function */
int tolower(int);
#endif	/* tolower */

#ifndef toupper 	/* toupper has been undefined - use function */
int toupper(int);
#endif	/* toupper */

#if !__STDC__
/* Non-ANSI names for compatibility */

#ifndef __cplusplus
#define max(a,b)	(((a) > (b)) ? (a) : (b))
#define min(a,b)	(((a) < (b)) ? (a) : (b))
#endif

#define sys_errlist _sys_errlist
#define sys_nerr    _sys_nerr
#define environ     _environ

#define DOS_MODE    _DOS_MODE
#define OS2_MODE    _OS2_MODE

#define ecvt	    _ecvt
#define fcvt	    _fcvt
#define gcvt	    _gcvt
#define itoa	    _itoa
#define ltoa	    _ltoa
#define onexit	    _onexit
#define putenv	    _putenv
#define swab	    _swab
#define ultoa	    _ultoa

#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#define _INC_STDLIB
#endif	/* _INC_STDLIB */
