/***
*math.h - definitions and declarations for math library
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This file contains constant definitions and external subroutine
*	declarations for the math subroutine library.
*	[ANSI/System V]
*
****/

#ifndef _INC_MATH

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif

/* definition of _exception struct - this struct is passed to the matherr
 * routine when a floating point exception is detected
 */

#ifndef _EXCEPTION_DEFINED
struct _exception {
	int type;		/* exception type - see below */
	char *name;		/* name of function where error occured */
	double arg1;		/* first argument to function */
	double arg2;		/* second argument (if any) to function */
	double retval;		/* value to be returned by function */
	} ;

#if !__STDC__
/* Non-ANSI name for compatibility */
#define exception _exception
#endif

#define _EXCEPTION_DEFINED
#endif


/* definition of a _complex struct to be used by those who use cabs and
 * want type checking on their argument
 */

#ifndef _COMPLEX_DEFINED
struct _complex {
	double x,y;	/* real and imaginary parts */
	} ;

#if !__STDC__
/* Non-ANSI name for compatibility */
#define complex _complex
#endif

#define _COMPLEX_DEFINED
#endif


/* Constant definitions for the exception type passed in the _exception struct
 */

#define _DOMAIN 	1	/* argument domain error */
#define _SING		2	/* argument singularity */
#define _OVERFLOW	3	/* overflow range error */
#define _UNDERFLOW	4	/* underflow range error */
#define _TLOSS		5	/* total loss of precision */
#define _PLOSS		6	/* partial loss of precision */

#define EDOM		33
#define ERANGE		34


/* definitions of _HUGE and HUGE_VAL - respectively the XENIX and ANSI names
 * for a value returned in case of error by a number of the floating point
 * math routines
 */

extern double _HUGE;
#define HUGE_VAL _HUGE

/* function prototypes */

int	abs(int);
double	acos(double);
double	asin(double);
double	atan(double);
double	atan2(double, double);
double	atof(const char *);
double	_cabs(struct _complex);
double	ceil(double);
double	cos(double);
double	cosh(double);
int	_dieeetomsbin(double *, double *);
int	_dmsbintoieee(double *, double *);
double	exp(double);
double	fabs(double);
int	_fieeetomsbin(float *, float *);
double	floor(double);
double	fmod(double, double);
int	_fmsbintoieee(float *, float *);
double	frexp(double, int *);
double	_hypot(double, double);
double	_j0(double);
double	_j1(double);
double	_jn(int, double);
long	labs(long);
double	ldexp(double, int);
double	log(double);
double	log10(double);
int	_matherr(struct _exception *);
double	modf(double, double *);
double	pow(double, double);
double	sin(double);
double	sinh(double);
double	sqrt(double);
double	tan(double);
double	tanh(double);
double	_y0(double);
double	_y1(double);
double	_yn(int, double);


#ifdef i386
#pragma function(acos, asin, atan, atan2, cos, cosh, exp, fmod, log, log10, pow, sin, sinh, sqrt, tan, tanh)
#endif

#if !__STDC__
/* Non-ANSI names for compatibility */

#define DOMAIN		_DOMAIN
#define SING		_SING
#define OVERFLOW	_OVERFLOW
#define UNDERFLOW	_UNDERFLOW
#define TLOSS		_TLOSS
#define PLOSS		_PLOSS

#define matherr 	_matherr

extern double HUGE;

#define cabs		_cabs
#define dieeetomsbin	_dieeetomsbin
#define dmsbintoieee	_dmsbintoieee
#define fieeetomsbin	_fieeetomsbin
#define fmsbintoieee	_fmsbintoieee
#define hypot		_hypot
#define j0		_j0
#define j1		_j1
#define jn		_jn
#define matherr 	_matherr
#define y0		_y0
#define y1		_y1
#define yn		_yn

#define cabsl		_cabsl
#define hypotl		_hypotl
#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#define _INC_MATH
#endif	/* _INC_MATH */
