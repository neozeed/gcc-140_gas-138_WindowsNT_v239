/***
* wcstr.h - declarations for wide character string manipulation functions
*
*       Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This file contains the function declarations for the string
*       manipulation functions.
*       [UNICODE/ISO]
*
****/

#ifndef _INC_WCSTR



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
#define NULL    ((void *)0)
#endif


/* function prototypes */

wchar_t *wcscat(wchar_t *string1, const wchar_t *string2);
wchar_t *wcschr(const wchar_t *string1, wchar_t character);
int      wcscmp(const wchar_t *string1, const wchar_t *string2);
wchar_t *wcscpy(wchar_t *string1, const wchar_t *string2);
size_t   wcscspn(const wchar_t *string1, const wchar_t *string2);
size_t   wcslen(const wchar_t *string);
wchar_t *wcsncat(wchar_t *string1, const wchar_t *string2, size_t count);
int      wcsncmp(const wchar_t *string1, const wchar_t *string2, size_t count);
wchar_t *wcsncpy(wchar_t *string1, const wchar_t *string2, size_t count);
wchar_t *wcspbrk(const wchar_t *string1, const wchar_t *string2);
wchar_t *wcsrchr(const wchar_t *string, wchar_t character);
size_t   wcsspn(const wchar_t *string1, const wchar_t *string2);
wchar_t *wcswcs(const wchar_t *string1, const wchar_t *string2);
int      wcstomb(char *string, wchar_t character);
size_t   wcstombs(char *dest, const wchar_t *string, size_t count);

#define _INC_WCSTR

#endif  /* _INC_WCSTR */
