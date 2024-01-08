/*********************************************************/
/**               Microsoft LAN Manager                 **/
/**       Copyright(c) Microsoft Corp., 1991            **/
/**                                                     **/
/**            Base Include file for NT                 **/
/**                                                     **/
/*********************************************************/

#ifndef __RPC_H__
#define __RPC_H__


typedef long RPC_STATUS;

#define PAPI
#define RPC_ENTRY

#ifdef IN

#undef IN
#undef OUT
#undef OPTIONAL
#endif

typedef void * RPC_HANDLE;

#include "rpcbse.h"
#include "rpcnterr.h"

#ifndef try
#include <excpt.h>
#endif

#define RpcTryExcept \
    try \
        {

// trystmts

#define RpcExcept(expr) \
        } \
    except (expr) \
        {

// exceptstmts

#define RpcEndExcept \
        }

#define RpcTryFinally \
    try \
        {

// trystmts

#define RpcFinally \
        } \
    finally \
        {

// finallystmts

#define RpcEndFinally \
        }

// define the following functions/variables for benifit of C++ preprocessors

#if defined(i386)
unsigned long _exception_code(void);
int _abnormal_termination(void);

#endif

#define RpcExceptionCode() GetExceptionCode()
#define RpcAbnormalTermination() AbnormalTermination()

RPC_STATUS RPC_ENTRY
RpcImpersonateClient (
    IN RPC_HANDLE CallHandle OPTIONAL
    );

RPC_STATUS RPC_ENTRY
RpcRevertToSelf (
    );

#endif // __RPC_H__
