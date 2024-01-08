/***
*excpt.h - definitions/declarations for Structured Exception Handling
*
*       Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This file defines the compiler-dependent definitions used to
*       access the structured exception handling syntax.
*
*******************************************************************************/

#ifndef _EXCPT_
#define _EXCPT_

//
// C Structured Exception Handling.
//

//
// Exception disposition return values.
//

typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;

#if defined(__cplusplus)
#define EXCEPTION_EXTERN extern "C"
#define EXCEPTION_NOPROTO ...
#else
#define EXCEPTION_EXTERN extern
#define EXCEPTION_NOPROTO
#endif

#if defined(lint) || defined(_lint)

#define try                         /* nothing */
#define except                      /* nothing */
#define finally                     /* nothing */
#define GetExceptionCode            (unsigned long) 5  /* any bogus value */
#define GetExceptionInformation     (struct _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination         _abnormal_termination
#define abnormal_termination        _abnormal_termination

EXCEPTION_EXTERN unsigned long _exception_code( EXCEPTION_NOPROTO );
EXCEPTION_EXTERN int _abnormal_termination( EXCEPTION_NOPROTO );

#elif defined(i386)

#define try                         _try
#define except                      _except
#define finally                     _finally
#define GetExceptionCode            (unsigned long)_exception_code
#define GetExceptionInformation     (struct _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination         _abnormal_termination
#define abnormal_termination        _abnormal_termination

EXCEPTION_EXTERN unsigned long _exception_code( EXCEPTION_NOPROTO );
EXCEPTION_EXTERN int _abnormal_termination( EXCEPTION_NOPROTO );

#elif defined(MIPS)

#define try                         __builtin_try
#define except                      __builtin_except
#define finally                     __builtin_finally
#define leave                       __builtin_leave
#define GetExceptionCode()          __exception_code
#define GetExceptionInformation()   (struct _EXCEPTION_POINTERS *)__exception_info
#define abnormal_termination()      __abnormal_termination
#define AbnormalTermination()       __abnormal_termination

EXCEPTION_EXTERN unsigned long GetExceptionCode();
EXCEPTION_EXTERN int AbnormalTermination();

//
// Random noise to keep the Mips C Compiler happy.
//

typedef struct _EXCEPTION_POINTERS *Exception_info_ptr;

struct _EXCEPTION_RECORD;
struct _CONTEXT;
struct _DISPATCHER_CONTEXT;

EXCEPTION_DISPOSITION
__C_specific_handler (
    struct _EXCEPTION_RECORD *ExceptionRecord,
    void *EstablisherFrame,
    struct _CONTEXT *ContextRecord,
    struct _DISPATCHER_CONTEXT *DispatcherContext
    );

#endif

//
// Values for except() expresion
//

#define EXCEPTION_EXECUTE_HANDLER     1
#define EXCEPTION_CONTINUE_SEARCH     0
#define EXCEPTION_CONTINUE_EXECUTION -1

#endif
