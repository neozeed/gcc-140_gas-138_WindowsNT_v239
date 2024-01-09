#ifdef USEBROKENCTYPE
/***
*ctype.h - character conversion macros and ctype macros
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	Defines macros for character classification/conversion.
*	[ANSI/System V]
*
****/

#ifndef _INC_CTYPE

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif

/*
 * This declaration allows the user access to the ctype look-up
 * array _ctype defined in ctype.obj by simply including ctype.h
 */

extern unsigned char _ctype[];


/* set bit masks for the possible character types */

#define _UPPER		0x1	/* upper case letter */
#define _LOWER		0x2	/* lower case letter */
#define _DIGIT		0x4	/* digit[0-9] */
#define _SPACE		0x8	/* tab, carriage return, newline, */
				/* vertical tab or form feed */
#define _PUNCT		0x10	/* punctuation character */
#define _CONTROL	0x20	/* control character */
#define _BLANK		0x40	/* space char */
#define _HEX		0x80	/* hexadecimal digit */


/* character classification function prototypes */

#ifndef _CTYPE_DEFINED
int isalpha(int);
int isupper(int);
int islower(int);
int isdigit(int);
int isxdigit(int);
int isspace(int);
int ispunct(int);
int isalnum(int);
int isprint(int);
int isgraph(int);
int iscntrl(int);
//int toupper(int);
//int tolower(int);
int _tolower(int);
int _toupper(int);
int __isascii(int);
int __toascii(int);
int __iscsymf(int);
int __iscsym(int);
#define _CTYPE_DEFINED
#endif

#ifdef _INTL
int __isleadbyte(int);
#endif


/* the character classification macro definitions */

#define isalpha(_c)	( (_ctype+1)[_c] & (_UPPER|_LOWER) )
#define isupper(_c)	( (_ctype+1)[_c] & _UPPER )
#define islower(_c)	( (_ctype+1)[_c] & _LOWER )
#define isdigit(_c)	( (_ctype+1)[_c] & _DIGIT )
#define isxdigit(_c)	( (_ctype+1)[_c] & _HEX )
#define isspace(_c)	( (_ctype+1)[_c] & _SPACE )
#define ispunct(_c)	( (_ctype+1)[_c] & _PUNCT )
#define isalnum(_c)	( (_ctype+1)[_c] & (_UPPER|_LOWER|_DIGIT) )
#define isprint(_c)	( (_ctype+1)[_c] & (_BLANK|_PUNCT|_UPPER|_LOWER|_DIGIT) )
#define isgraph(_c)	( (_ctype+1)[_c] & (_PUNCT|_UPPER|_LOWER|_DIGIT) )
#define iscntrl(_c)	( (_ctype+1)[_c] & _CONTROL )
#if !__STDC__
#define toupper(_c)	( (islower(_c)) ? _toupper(_c) : (_c) )
#define tolower(_c)	( (isupper(_c)) ? _tolower(_c) : (_c) )
#endif	/* __STDC__ */
#define _tolower(_c)	( (_c)-'A'+'a' )
#define _toupper(_c)	( (_c)-'a'+'A' )
#define __isascii(_c)	( (unsigned)(_c) < 0x80 )
#define __toascii(_c)	( (_c) & 0x7f )

#ifndef isleadbyte
#ifdef _INTL
#define isleadbyte(_c)	__isleadbyte(_c)
#else
#define isleadbyte(_c)	(0)
#endif
#endif

/* MS C version 2.0 extended ctype macros */

#define __iscsymf(_c)	(isalpha(_c) || ((_c) == '_'))
#define __iscsym(_c)	(isalnum(_c) || ((_c) == '_'))

#if !__STDC__
/* Non-ANSI names for compatibility */
#define isascii __isascii
#define toascii __toascii
#define iscsymf __iscsymf
#define iscsym	__iscsym
#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#define _INC_CTYPE
#endif	/* _INC_CTYPE */
#else
#include <ctype.h>
#endif
