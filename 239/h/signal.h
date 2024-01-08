/***
*signal.h - defines signal values and routines
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This file defines the signal values and declares the signal functions.
*	[ANSI/System V]
*
****/

#ifndef _INC_SIGNAL

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif

#ifndef _SIG_ATOMIC_T_DEFINED
typedef int sig_atomic_t;
#define _SIG_ATOMIC_T_DEFINED
#endif

#define NSIG 23     /* maximum signal number + 1 */

/* signal types */

#define SIGINT		2	/* interrupt */
#define SIGILL		4	/* illegal instruction - invalid function image */
#define SIGFPE		8	/* floating point exception */
#define SIGSEGV 	11	/* segment violation */
#define SIGTERM 	15	/* Software termination signal from kill */
#define SIGUSR1 	16	/* User defined signal 1 */
#define SIGUSR2 	17	/* User defined signal 2 */
#define SIGUSR3 	20	/* User defined signal 3 */
#define SIGBREAK	21	/* Ctrl-Break sequence */
#define SIGABRT 	22	/* abnormal termination triggered by abort call */


/* signal action codes */

#define SIG_DFL (void (*)(int))0	   /* default signal action */
#define SIG_IGN (void (*)(int))1	   /* ignore signal */
#define SIG_SGE (void (*)(int))3	   /* signal gets error */
#define SIG_ACK (void (*)(int))4	   /* acknowledge */


/* signal error value (returned by signal call on error) */

#define SIG_ERR (void (*)(int))-1	     /* signal error value */

/* pointer to exception information pointers structure */

#ifdef	_MT
extern void * * __pxcptinfoptrs(void);
#define _pxcptinfoptrs	(*__pxcptinfoptrs())
#else
extern void * _pxcptinfoptrs;
#endif

/* function prototypes */

void (* signal(int, void (*)(int)))(int);
int raise(int);

#ifdef __cplusplus
}
#endif

#define _INC_SIGNAL
#endif	/* _INC_SIGNAL */
