/*********************************************************/
/**               Microsoft LAN Manager                 **/
/**       Copyright(c) Microsoft Corp., 1987-1990       **/
/**                                                     **/
/**     Rpc Error Codes from the compiler and runtime   **/
/**                                                     **/
/*********************************************************/

/*
If you change this file, you must also change rpcerr.h.
*/

#ifndef __RPCNTERR_H__
#define __RPCNTERR_H__

#define RPC_NO_ERROR			0x00000000L

#define RPC_ABORTING_MANAGER		0xC0020001L
#define RPC_ACCESS_DENIED		0xC0020002L
#define RPC_ASSOCIATION_CLOSED		0xC0020003L
#define RPC_BUFFER_TOO_SMALL		0xC0020004L
#define RPC_CALL_FAILED			0xC0020005L
#define RPC_CALL_FAILED_DNE		0xC0020006L
#define RPC_CANNOT_BIND			0xC0020007L
#define RPC_CANNOT_CONNECT		0xC0020008L
#define RPC_CANNOT_SUPPORT		0xC0020009L
#define RPC_DUPLICATE_ADDRESS		0xC002000AL
#define RPC_DUPLICATE_INTERFACE		0xC002000BL
#define RPC_INTERFACE_NOT_FOUND		0xC002000CL
#define RPC_INTERNAL_ERROR		0xC002000DL
#define RPC_INVALID_ADDRESS		0xC002000EL
#define RPC_INVALID_FLAGS		0xC002000FL
#define RPC_INVALID_HANDLE		0xC0020010L
#define RPC_INVALID_INTERFACE		0xC0020011L
#define RPC_INVALID_LEVEL		0xC0020012L
#define RPC_INVALID_PARAMETER		0xC0020013L
#define RPC_INVALID_PROTOCOL		0xC0020014L
#define RPC_INVALID_STACK		0xC0020015L
#define RPC_INVALID_TRANSFER_SYNTAX	0xC0020016L
#define RPC_INVALID_TRANSPORT		0xC0020017L
#define RPC_INVALID_VALUE		0xC0020018L
#define RPC_INVALID_VERSION		0xC0020019L
#define RPC_NO_ADDRESSES		0xC002001AL
#define RPC_NO_CALL_ACTIVE		0xC002001BL
#define RPC_NO_RUNDOWN			0xC002001CL
#define RPC_NO_STACKS			0xC002001DL
#define RPC_OUT_OF_MEMORY		0xC002001EL
#define RPC_OUT_OF_RESOURCES		0xC002001FL
#define RPC_OUT_OF_THREADS		0xC0020020L
#define RPC_PROTOCOL_ERROR		0xC0020021L
#define RPC_REPLY_FAILED		0xC0020022L
#define RPC_RESOURCE_WAIT_TIMEOUT	0xC0020023L
#define RPC_SERVER_OUT_OF_RESOURCES	0xC0020024L

#define RPC_NOT_IMPLEMENTED		0xC0020025L

#define RPC_NO_CONTEXT_AVAILABLE        0xC0020026L
#define RPC_INVALID_SECURITY            0xC0020027L
#define RPC_SERVER_TOO_BUSY             0xC0020028L

// The list of servers available for auto_handle binding has been exhausted.

#define RPC_X_NO_MORE_ENTRIES		0xC0030000L

// Insufficient memory available to set up necessary data structures.

#define RPC_X_NO_MEMORY			0xC0030001L

// The specified bounds of an array are inconsistent.

#define RPC_X_INVALID_BOUND		0xC0030002L

// The discriminant value does not match any of the case values.
// There is no default case.

#define RPC_X_INVALID_TAG		0xC0030003L

// The file designated by DCERPCCHARTRANS cannot be opened.

#define RPC_X_SS_CHAR_TRANS_OPEN_FAIL	0xC0030004L

// The file containing char translation table has fewer than 512 bytes.

#define RPC_X_SS_CHAR_TRANS_SHORT_FILE	0xC0030005L

// A null context handle is passed in an [in] parameter position.

#define RPC_X_SS_IN_NULL_CONTEXT	0xC0030006L

// Only raised on the callee side.
// A uuid in an [in] handle does not correspond to any known context.

#define RPC_X_SS_CONTEXT_MISMATCH	0xC0030007L

// Only raised on the caller side.
// A uuid in an [in, out] context handle changed during a call.

#define RPC_X_SS_CONTEXT_DAMAGED	0xC0030008L


#endif /* __RPCNTERR_H__ */
