/***
*limits.h - implementation dependent values
*
*	Copyright (c) 1985-1990, Microsoft Corporation.  All rights reserved.
*
*Purpose:
*	Contains defines for a number of implementation dependent values
*	which are commonly used in C programs.
*	[ANSI]
*
****/

#define CHAR_BIT	  8		/* number of bits in a char */
#define SCHAR_MIN	(-127)		/* minimum signed char value */
#define SCHAR_MAX	  127		/* maximum signed char value */
#define UCHAR_MAX	  0xff		/* maximum unsigned char value */
#ifndef _CHAR_UNSIGNED
#define CHAR_MIN	SCHAR_MIN	/* mimimum char value */
#define CHAR_MAX	SCHAR_MAX	/* maximum char value */
#else
#define CHAR_MIN	  0
#define CHAR_MAX	UCHAR_MAX
#endif
#define	MB_LEN_MAX	  1		/* max. # bytes in multibyte char */
#define SHRT_MIN	(-32767)	/* minimum (signed) short value */
#define SHRT_MAX	  32767 	/* maximum (signed) short value */
#define USHRT_MAX	  0xffff	/* maximum unsigned short value */
#define INT_MIN 	(-2147483647)	/* minimum (signed) int value */
#define INT_MAX 	  2147483647	/* maximum (signed) int value */
#define UINT_MAX	  0xffffffff	/* maximum unsigned int value */
#define LONG_MIN	(-2147483647)	/* minimum (signed) long value */
#define LONG_MAX	  2147483647	/* maximum (signed) long value */
#define ULONG_MAX	  0xffffffff	/* maximum unsigned long value */
