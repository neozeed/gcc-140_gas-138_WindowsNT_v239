/*********************************************************/
/**               Microsoft LAN Manager                 **/
/**       Copyright(c) Microsoft Corp., 1987-1990       **/
/**                                                     **/
/**        Prototypes for the RPC Runtime APIs.         **/
/**                                                     **/
/*********************************************************/

#ifndef __RPCBSE_H__
#define __RPCBSE_H__


#define IN
#define OUT
#define OPTIONAL

typedef RPC_HANDLE handle_t;
typedef RPC_HANDLE PAPI * PRPC_HANDLE;
typedef char small;
typedef unsigned char byte;
typedef unsigned char boolean;

typedef struct _RPC_VERSION {
    unsigned short MajorVersion;
    unsigned short MinorVersion;
} RPC_VERSION;

#ifndef GUID_DEFINED
#define GUID_DEFINED
typedef struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} GUID;
#endif

typedef struct _RPC_SYNTAX_IDENTIFIER {
    GUID SyntaxGUID;
    RPC_VERSION SyntaxVersion;
} RPC_SYNTAX_IDENTIFIER, PAPI * PRPC_SYNTAX_IDENTIFIER;

typedef struct _RPC_PROTOCOL {
    unsigned char MajorProtocol;
    unsigned char MinorProtocol;
} RPC_PROTOCOL, PAPI * PRPC_PROTOCOL;

#define RPC_STACK_TYPE_V1 0

#define OSF_RPC_V20_VERS 5
#define OSF_RPC_V20_VERS_MINOR 0

#define RPC_TRANSPORT_NAMEPIPE 1
#define RPC_TRANSPORT_LPC 2
#define RPC_TRANSPORT_TCP 3
#define RPC_TRANSPORT_DNET 4
#define RPC_TRANSPORT_NETBIOS 5

// RPC protocol level security should be assigned number between 1 and 255.

#define RPC_SECURITY_DS_HACK 250

// Transport level security should be assigned numbers greater than 255.

#define RPC_SECURITY_QOS 500

typedef struct _RPC_PROTOCOL_STACK {
    unsigned long	StackType;
    RPC_SYNTAX_IDENTIFIER InterfaceID;
    unsigned long	TransferSyntaxCount;
    PRPC_SYNTAX_IDENTIFIER TransferSyntaxes;
    unsigned long	SecurityType;
    unsigned long	SecurityInfoLength;
    unsigned char  PAPI * SecurityInfo;
    unsigned long	RPCProtocolCount;
    PRPC_PROTOCOL	RPCProtocols;
    unsigned long	TransportType;
    unsigned long	TransportInfoLength;
    unsigned char PAPI * TransportInfo;
} RPC_PROTOCOL_STACK, PAPI * PRPC_PROTOCOL_STACK;

typedef struct {
    unsigned char PAPI * UserName;
    unsigned char PAPI * ComputerName;
    unsigned short Privilege;
    unsigned long AuthFlags;
} RPC_CLIENT_INFORMATION1, PAPI * PRPC_CLIENT_INFORMATION1;

typedef struct {
    unsigned int Count;
    unsigned long TransportTypes[1];
} RPC_CONFIG_TRANSPORT, PAPI * PRPC_CONFIG_TRANSPORT;

typedef struct{
    unsigned long ConfigResourceWait;
} RPC_CONFIG_RESOURCE_WAIT, PAPI * PRPC_CONFIG_RESOURCE_WAIT;

typedef struct {
    RPC_HANDLE BindingHandle;
    RPC_HANDLE PreviousCallHandle;
} RPC_CLIENT_CALL_INFORMATION, PAPI * PRPC_CLIENT_CALL_INFORMATION;

typedef struct{
    RPC_HANDLE PreviousCallHandle;
    RPC_SYNTAX_IDENTIFIER InterfaceID;
    RPC_SYNTAX_IDENTIFIER TransferSyntax;
    unsigned long DataRepresentation;
} RPC_SERVER_CALL_INFORMATION, PAPI * PRPC_SERVER_CALL_INFORMATION;

typedef struct{
    RPC_SYNTAX_IDENTIFIER InterfaceID;
    RPC_SYNTAX_IDENTIFIER TransferSyntax;
} RPC_CLIENT_BINDING_INFORMATION, PAPI * PRPC_CLIENT_BINDING_INFORMATION;

typedef struct{
    RPC_HANDLE ServerHandle;
    RPC_HANDLE AddressHandle;
    RPC_HANDLE InterfaceHandle;
} RPC_SERVER_BINDING_INFORMATION, PAPI * PRPC_SERVER_BINDING_INFORMATION;

typedef struct {
    RPC_HANDLE Handle;
    unsigned long DataRepresentation;
    void PAPI * Buffer;
    unsigned int BufferLength;
    unsigned int ProcNum;
    PRPC_SYNTAX_IDENTIFIER TransferSyntax;
    long reserved;
} RPC_MESSAGE, PAPI * PRPC_MESSAGE;

typedef enum {
    RpcStopWhenUnbind = 1,
    RpcStopWhenCallsComplete,
    RpcStopImmediate
} RPC_STOP_FLAG;

typedef enum  {
    RpcMinimizeResourceUsage,
    RpcNormalResourceUsage,
    RpcMaximizeSpeed
} RPC_RESOURCE_USAGE;

typedef enum {
    RpcScopeLocal = 0,
    RpcScopeDomain = 1
} RPC_SCOPE;

typedef enum {
    RpcConfigTransport = 1,
    RpcConfigResourceWait = 2
} RPC_CONFIG;

typedef enum {
    RpcResponseTypeReply = 0,
    RpcResponseTypeRemoteFault = 1
} RPC_RESPONSE_TYPES;


typedef void (PAPI * RPC_DISPATCH_FUNCTION) (IN OUT PRPC_MESSAGE Message);

typedef struct {
    unsigned int DispatchTableCount;
    RPC_DISPATCH_FUNCTION PAPI * DispatchTable;
    int Reserved;
} RPC_DISPATCH_TABLE, PAPI * PRPC_DISPATCH_TABLE;

typedef enum _RPC_CLIENT_PRIORITY {
    RpcPriorityReject = 0,
    RpcPriorityNormal = 10,
    RpcPriorityHigh = 20,
    RpcPriorityCritical = 30
} RPC_CLIENT_PRIORITY;

typedef
int /* RPC_CLIENT_PRIORITY -- BUGBUG: Glock 1.2 replace int with this*/
(PAPI * RPC_NEW_CLIENT_EVENT) (
    IN RPC_HANDLE CallHandle
    );

typedef enum _RPC_THREAD_EVENT_TYPE {
    RpcCreateThreadRequest,
    RpcDeleteThreadNotify,
    RpcInitializeThread,
    RpcFinalizeThread
} RPC_THREAD_EVENT_TYPE;

typedef
unsigned int
(PAPI * RPC_THREAD_EVENT) (
    IN RPC_THREAD_EVENT_TYPE Event
    );

typedef
void
(PAPI * RPC_MANAGER_ERROR_EVENT) (
    IN void PAPI * ErrorObject,
    IN RPC_STATUS ErrorCode
    );

typedef struct {
    RPC_HANDLE CallHandle;
    unsigned int ProcNum;
} RPC_REPLY_FAILED_INFORMATION, PAPI * PRPC_REPLY_FAILED_INFORMATION;

typedef struct {
    unsigned int Count;
    RPC_NEW_CLIENT_EVENT NewClientEvent;
    RPC_THREAD_EVENT ThreadEvent;
    RPC_MANAGER_ERROR_EVENT ManagerErrorEvent;
} RPC_EVENT_HANDLERS, PAPI * PRPC_EVENT_HANDLERS;

typedef
void
(PAPI * PRPC_RUNDOWN) (
    void PAPI * AssociationContext
    );


/*** Server API's ***/

RPC_STATUS RPC_ENTRY
RpcCreateServer (
    IN PRPC_EVENT_HANDLERS EventHandlers OPTIONAL,
    OUT PRPC_HANDLE ServerHandle
    );

RPC_STATUS RPC_ENTRY
RpcDeleteServer (
    IN RPC_HANDLE ServerHandle,
    IN RPC_STOP_FLAG StopFlag
    );

#define RPC_ADDRESS_AVOID_DEADLOCK 1

RPC_STATUS RPC_ENTRY
RpcAddAddress (
    IN RPC_HANDLE ServerHandle,
    IN PRPC_PROTOCOL_STACK RequestedAddress,
    IN unsigned int AddressFlags,
    OUT PRPC_HANDLE AddressHandle,
    IN void PAPI * SecurityDescriptor,
    IN RPC_RESOURCE_USAGE ResourceUsage,
    IN unsigned long Timeout OPTIONAL
    );

RPC_STATUS RPC_ENTRY
RpcRemoveAddress (
    IN RPC_HANDLE AddressHandle,
    IN RPC_STOP_FLAG StopFlag
    );

RPC_STATUS RPC_ENTRY
RpcAddInterface (
    IN RPC_HANDLE ServerHandle,
    IN PRPC_PROTOCOL_STACK ProtocolStack,
    OUT PRPC_HANDLE InterfaceHandle,
    IN void PAPI * SecurityDescriptor,
    IN PRPC_DISPATCH_TABLE DispatchTable
    );

RPC_STATUS RPC_ENTRY
RpcRemoveInterface (
    IN RPC_HANDLE InterfaceHandle,
    IN RPC_STOP_FLAG StopFlag
    );

RPC_STATUS RPC_ENTRY
RpcMonitorAssociation (
    IN RPC_HANDLE Handle,
    IN PRPC_RUNDOWN RundownRoutine,
    IN void *pContext
    );

RPC_STATUS RPC_ENTRY
RpcStopMonitorAssociation (
    IN RPC_HANDLE Handle
    );


RPC_STATUS RPC_ENTRY
RpcExport (
    IN RPC_HANDLE ExportHandle,
    IN RPC_SCOPE Scope,
    IN PRPC_PROTOCOL_STACK ProtocolStack
    );


RPC_STATUS RPC_ENTRY
RpcWithdraw (
    IN RPC_HANDLE WithdrawHandle,
    IN PRPC_PROTOCOL_STACK ProtocolStack
    );

RPC_STATUS RPC_ENTRY
RpcQueryClient (
    IN RPC_HANDLE Handle,
    IN unsigned int ClientInformationLevel,
    OUT void PAPI * ClientInformation,
    IN OUT unsigned int PAPI * ClientInformationLength
    );

RPC_HANDLE RPC_ENTRY
RpcGetCurrentCallHandle(
        OUT PRPC_SERVER_CALL_INFORMATION CallInformation OPTIONAL
        );

RPC_STATUS RPC_ENTRY
RpcGetAssociationContext (
    OUT void PAPI * PAPI * AssociationContext
    );

RPC_STATUS RPC_ENTRY
RpcSetAssociationContext (
    OUT void PAPI * AssociationContext
    );


/*** The following are client side API's ***/

RPC_STATUS RPC_ENTRY
RpcImport (
    IN unsigned char PAPI * DomainName,
    IN RPC_SCOPE Scope,
    IN PRPC_PROTOCOL_STACK ProtocolStack,
    IN PRPC_DISPATCH_TABLE CallBackTable OPTIONAL,
    OUT PRPC_HANDLE BindingHandle
    );

RPC_STATUS RPC_ENTRY
RpcBindToInterface (
    IN PRPC_PROTOCOL_STACK InterfaceInstance,
    IN PRPC_DISPATCH_TABLE CallBackTable OPTIONAL,
    OUT PRPC_HANDLE BindingHandle
    );

RPC_STATUS RPC_ENTRY
RpcUnbind (
    IN RPC_HANDLE BindingHandle
    );

RPC_STATUS RPC_ENTRY
RpcDuplicateBinding (
    IN RPC_HANDLE Binding,
    OUT PRPC_HANDLE NewBinding
    );


RPC_STATUS RPC_ENTRY
RpcQueryCall (
    IN RPC_HANDLE CallHandle,
    OUT void PAPI * CallInformation,
    IN OUT unsigned int PAPI * CallInformationLength
    );

RPC_STATUS RPC_ENTRY
RpcQueryBinding (
    IN RPC_HANDLE Handle,
    OUT void PAPI * BindingInformation,
    IN OUT unsigned int PAPI * BindingInformationLength
    );

RPC_STATUS RPC_ENTRY
RpcQueryProtocolStack (
    IN RPC_HANDLE Handle,
    OUT PRPC_PROTOCOL_STACK ProtocolStack,
    IN OUT unsigned int PAPI * ProtocolStackLength
    );

RPC_STATUS RPC_ENTRY
RpcQueryConfig (
    IN  RPC_CONFIG ConfigType,
    OUT void PAPI * ConfigInformation,
    IN  OUT unsigned int PAPI * ConfigInformationLength
    );

RPC_STATUS RPC_ENTRY
RpcSetConfig (
    IN  RPC_CONFIG ConfigType,
    OUT void PAPI * ConfigInformation
    );

RPC_STATUS RPC_ENTRY
RpcGetBuffer (
    IN OUT PRPC_MESSAGE Message
    );

RPC_STATUS RPC_ENTRY
RpcFreeBuffer (
    IN OUT PRPC_MESSAGE Message
    );

RPC_STATUS RPC_ENTRY
RpcSendReceive (
    IN OUT PRPC_MESSAGE Message
    );

void RPC_ENTRY
RpcRaiseException (
    RPC_STATUS exception
    );

#endif /* __RPCBSE_H__ */
