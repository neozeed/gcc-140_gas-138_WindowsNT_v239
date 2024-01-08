/***
*process.h - definition and declarations for process control functions
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This file defines the modeflag values for spawnxx calls.
*	Only P_WAIT and P_OVERLAY are currently implemented on MS-DOS.
*	Also contains the function argument declarations for all
*	process control related routines.
*
****/

#ifndef _INC_PROCESS

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif

/* modeflag values for _spawnxx routines */

#ifndef _MT
extern int _p_overlay;
#endif

#define _P_WAIT 	0
#define _P_NOWAIT	1
#ifdef	_MT
#define _P_OVERLAY	2
#else
#define _P_OVERLAY	_p_overlay
#endif
#define _OLD_P_OVERLAY	2
#define _P_NOWAITO	3
#define _P_DETACH	4


/* action codes used with _cwait() */

#define _WAIT_CHILD	 0
#define _WAIT_GRANDCHILD 1


/* function prototypes */

#ifdef _MT
unsigned long  _beginthread (void (*) (void *),
	unsigned, void *);
void _endthread(void);
#endif
void abort(void);
void _cexit(void);
void _c_exit(void);
int _cwait(int *, int, int);
int _execl(const char *, const char *, ...);
int _execle(const char *, const char *, ...);
int _execlp(const char *, const char *, ...);
int _execlpe(const char *, const char *, ...);
int _execv(const char *, const char * const *);
int _execve(const char *, const char * const *, const char * const *);
int _execvp(const char *, const char * const *);
int _execvpe(const char *, const char * const *, const char * const *);
void exit(int);
void _exit(int);
int _getpid(void);
int _spawnl(int, const char *, const char *, ...);
int _spawnle(int, const char *, const char *, ...);
int _spawnlp(int, const char *, const char *, ...);
int _spawnlpe(int, const char *, const char *, ...);
int _spawnv(int, const char *, const char * const *);
int _spawnve(int, const char *, const char * const *,
	const char * const *);
int _spawnvp(int, const char *, const char * const *);
int _spawnvpe(int, const char *, const char * const *,
	const char * const *);
int system(const char *);
int _wait(int *);
int _loaddll(char *);
int _unloaddll(int);
int (* _getdllprocaddr(int, char *, int))();

#if !__STDC__
/* Non-ANSI names for compatibility */

#define P_WAIT		_P_WAIT
#define P_NOWAIT	_P_NOWAIT
#define P_OVERLAY	_P_OVERLAY
#define OLD_P_OVERLAY	_OLD_P_OVERLAY
#define P_NOWAITO	_P_NOWAITO
#define P_DETACH	_P_DETACH

#define WAIT_CHILD	_WAIT_CHILD
#define WAIT_GRANDCHILD _WAIT_GRANDCHILD

#define cwait	 _cwait
#define execl	 _execl
#define execle	 _execle
#define execlp	 _execlp
#define execlpe  _execlpe
#define execv	 _execv
#define execve	 _execve
#define execvp	 _execvp
#define execvpe  _execvpe
#define getpid	 _getpid
#define spawnl	 _spawnl
#define spawnle  _spawnle
#define spawnlp  _spawnlp
#define spawnlpe _spawnlpe
#define spawnv	 _spawnv
#define spawnve  _spawnve
#define spawnvp  _spawnvp
#define spawnvpe _spawnvpe
#define wait	 _wait

#endif

#ifdef __cplusplus
}
#endif

#define _INC_PROCESS
#endif	/* _INC_PROCESS */
