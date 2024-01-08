/***
*time.h - definitions/declarations for time routines
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This file has declarations of time routines and defines
*	the structure returned by the localtime and gmtime routines and
*	used by asctime.
*	[ANSI/System V]
*
****/

#ifndef _INC_TIME

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif

/* define the implementation defined time type */

#ifndef _TIME_T_DEFINED
typedef long time_t;		/* time value */
#define _TIME_T_DEFINED 	/* avoid multiple def's of time_t */
#endif

#ifndef _CLOCK_T_DEFINED
typedef long clock_t;
#define _CLOCK_T_DEFINED
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif


/* define NULL pointer value */

#ifndef NULL
#ifdef __cplusplus
#define NULL	0
#else
#define NULL	((void *)0)
#endif
#endif


#ifndef _TM_DEFINED
struct tm {
	int tm_sec;	/* seconds after the minute - [0,59] */
	int tm_min;	/* minutes after the hour - [0,59] */
	int tm_hour;	/* hours since midnight - [0,23] */
	int tm_mday;	/* day of the month - [1,31] */
	int tm_mon;	/* months since January - [0,11] */
	int tm_year;	/* years since 1900 */
	int tm_wday;	/* days since Sunday - [0,6] */
	int tm_yday;	/* days since January 1 - [0,365] */
	int tm_isdst;	/* daylight savings time flag */
	};
#define _TM_DEFINED
#endif


/* clock ticks macro - ANSI version */

#define CLOCKS_PER_SEC	1000


/* extern declarations for the global variables used by the ctime family of
 * routines.
 */

/* non-zero if daylight savings time is used */
extern int _daylight;

/* difference in seconds between GMT and local time */
extern long _timezone;

/* standard/daylight savings time zone names */
extern char * _tzname[2];


/* function prototypes */

char * asctime(const struct tm *);
char * ctime(const time_t *);
clock_t clock(void);
double difftime(time_t, time_t);
struct tm * gmtime(const time_t *);
struct tm * localtime(const time_t *);
time_t mktime(struct tm *);
size_t strftime(char *, size_t, const char *, const struct tm *);
char * _strdate(char *);
char * _strtime(char *);
time_t time(time_t *);
void _tzset(void);
unsigned _getsystime(struct tm *);
unsigned _setsystime(struct tm *, unsigned);


#if !__STDC__
/* Non-ANSI names for compatibility */

#define CLK_TCK  CLOCKS_PER_SEC

#define daylight _daylight
#define timezone _timezone
#define tzname	 _tzname

#define tzset	 _tzset

#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#define _INC_TIME
#endif	/* _INC_TIME */
