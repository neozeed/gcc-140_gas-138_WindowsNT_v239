/***
*conio.h - console and port I/O declarations
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This include file contains the function declarations for
*	the MS C V2.03 compatible console and port I/O routines.
*
****/

#ifndef _INC_CONIO

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif

/* function prototypes */

char * _cgets(char *);
int _cprintf(const char *, ...);
int _cputs(const char *);
int _cscanf(const char *, ...);
int _getch(void);
int _getche(void);
int _kbhit(void);
int _putch(int);
int _ungetch(int);


#if !__STDC__
/* Non-ANSI names for compatibility */
#define cgets	_cgets
#define cprintf _cprintf
#define cputs	_cputs
#define cscanf	_cscanf
#define getch	_getch
#define getche	_getche
#define kbhit	_kbhit
#define putch	_putch
#define ungetch _ungetch
#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#define _INC_CONIO
#endif	/* _INC_CONIO */
