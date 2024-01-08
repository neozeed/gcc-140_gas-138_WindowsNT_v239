/*********************************************************/
/**               Microsoft LAN Manager                 **/
/**       Copyright(c) Microsoft Corp., 1987-1990       **/
/**                                                     **/
/**      context management API's used by the stubs     **/
/**                                                     **/
/*********************************************************/

#ifndef __RPCNDR_H__
#define __RPCNDR_H__

/* Client and Server Contexts.  Just enough of the structure is exposed
to allow access to some public fields
*/

typedef struct {RPC_HANDLE hRPC;} PAPI * NDR_CCONTEXT;
typedef struct {void * pad[2]; void * userContext; } * NDR_SCONTEXT;

#define NDRSContextValue(hContext) (&(hContext)->userContext)
#define NDRCContextBinding(hContext) ((hContext)->hRPC)

#define cbNDRContext 20         /* size of context on WIRE */

typedef void (*NDR_RUNDOWN)(void * context);

void RPC_ENTRY
NDRCContextMarshall (
        IN  NDR_CCONTEXT CContext,
        OUT void PAPI *pBuff
        );

void RPC_ENTRY
NDRCContextUnmarshall (
        OUT NDR_CCONTEXT PAPI *pCContext,
        IN  RPC_HANDLE hBinding,
        IN  void PAPI *pBuff,
	IN  unsigned long DataRepresentation
        );

void RPC_ENTRY
NDRSContextMarshall (
        IN  NDR_SCONTEXT CContext,
        OUT void PAPI *pBuff,
        IN  NDR_RUNDOWN userRunDownIn
        );

NDR_SCONTEXT RPC_ENTRY
NDRSContextUnmarshall (
	IN  void PAPI *pBuff,
	IN  unsigned long DataRepresentation
        );

void RPC_ENTRY
NDRcopy (
	IN void PAPI *pTarget,
	IN void PAPI *pSource,
	IN unsigned int size
        );

#endif // __RPCNDR_H__
