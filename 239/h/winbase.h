/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1990  Microsoft Corporation

Module Name:

    winbase.h

Abstract:

    This module defines the 32-Bit Windows Base APIs

Created:

    18-Sep-1990

Revision History:

--*/

#ifndef _WINBASE_
#define _WINBASE_

/*
 * Compatability macros
 */

#define DefineHandleTable(w)            ((w),TRUE)
#define LimitEmsPages(dw)
#define SetSwapAreaSize(w)              (w)
#define LockSegment(w)                  GlobalFix((HANDLE)(w))
#define UnlockSegment(w)                GlobalUnfix((HANDLE)(w))

#define Yield()

#define INVALID_HANDLE_VALUE (HANDLE)-1
#define FILE_BEGIN           0
#define FILE_CURRENT         1
#define FILE_END             2
#define FILE_ATTRIBUTE_DIRECTORY    0x00000010

#define WAIT_OBJECT_0       ((STATUS_WAIT_0 ) + 0 )

#define WAIT_ABANDONED         ((STATUS_ABANDONED_WAIT_0 ) + 0 )
#define WAIT_ABANDONED_0       ((STATUS_ABANDONED_WAIT_0 ) + 0 )

#define WAIT_TIMEOUT                    STATUS_TIMEOUT
#define STILL_ACTIVE                    STATUS_PENDING
#define EXCEPTION_ACCESS_VIOLATION      STATUS_ACCESS_VIOLATION
#define EXCEPTION_DATATYPE_MISALIGNMENT STATUS_DATATYPE_MISALIGNMENT
#define EXCEPTION_BREAKPOINT            STATUS_BREAKPOINT
#define EXCEPTION_SINGLE_STEP           STATUS_SINGLE_STEP
#define CONTROL_C_EXIT                  STATUS_CONTROL_C_EXIT

//
// File creation flags must start in second byte since they
// are combined with the attributes
//

#define FILE_FLAG_WRITE_THROUGH     0x00000100
#define FILE_FLAG_OVERLAPPED        0x00000200
#define FILE_FLAG_NO_BUFFERING      0x00000400
#define FILE_FLAG_RANDOM_ACCESS     0x00000800
#define FILE_FLAG_SEQUENTIAL_SCAN   0x00001000

#define CREATE_NEW          1
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define OPEN_ALWAYS         4
#define TRUNCATE_EXISTING   5

//
// Define the NamedPipe definitions
//


//
// Define the dwOpenMode values for CreateNamedPipe
//

#define PIPE_ACCESS_INBOUND         0x00000001
#define PIPE_ACCESS_OUTBOUND        0x00000002
#define PIPE_ACCESS_DUPLEX          0x00000003

//
// Define the Named Pipe End flags for GetNamedPipeInfo
//

#define PIPE_CLIENT_END             0x00000000
#define PIPE_SERVER_END             0x00000001

//
// Define the dwPipeMode values for CreateNamedPipe
//

#define PIPE_WAIT                   0x00000000
#define PIPE_NOWAIT                 0x00000001
#define PIPE_READMODE_BYTE          0x00000000
#define PIPE_READMODE_MESSAGE       0x00000002
#define PIPE_TYPE_BYTE              0x00000000
#define PIPE_TYPE_MESSAGE           0x00000004

//
// Define the well known values for CreateNamedPipe nMaxInstances
//

#define PIPE_UNLIMITED_INSTANCES    255

//
// Special values for mailslot information.
//

//
// Special value for NextMessageSize to indicate that there is no next
// message.
//

#define MAILSLOT_NO_MESSAGE             -1

//
// Special value for mailslot size creation to indicate that the system
// should choose the size of the mailslot buffer.
//

#define MAILSLOT_SIZE_AUTO               0

//
// Special value for read timeout to indicate that mailslot reads should
// never timeout.
//

#define MAILSLOT_WAIT_FOREVER           -1

//
//  File structures
//

typedef struct _OVERLAPPED {
    DWORD   Internal;
    DWORD   InternalHigh;
    DWORD   Offset;
    DWORD   OffsetHigh;
    HANDLE  hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;

//
//  File System time stamps are represented with the following structure:
//

typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;

//
// System time is represented with the following structure:
//

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

typedef DWORD (*PTHREAD_START_ROUTINE)(
    LPVOID lpThreadParameter
    );
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

#ifdef i386
typedef PLDT_ENTRY LPLDT_ENTRY;
#else
typedef LPVOID LPLDT_ENTRY;
#endif

#define MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#define MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

//
// Provider capabilities flags.
//

#define PCF_DTRDTS       ((DWORD)0x0001)
#define PCF_RTSCTS       ((DWORD)0x0002)
#define PCF_CD           ((DWORD)0x0004)
#define PCF_PARITY_CHECK ((DWORD)0x0008)
#define PCF_XONXOFF      ((DWORD)0x0010)
#define PCF_SETXCHAR     ((DWORD)0x0020)
#define PCF_TOTTIMEOUTS  ((DWORD)0x0040)
#define PCF_INTTIMEOUTS  ((DWORD)0x0080)
#define PCF_SPECIALCHARS ((DWORD)0x0100)
#define PCF_16BITMODE    ((DWORD)0x0200)

//
// Comm provider settable parameters.
//

#define SP_PARITY         ((DWORD)0x0001)
#define SP_BAUD           ((DWORD)0x0002)
#define SP_DATABITS       ((DWORD)0x0004)
#define SP_STOPBITS       ((DWORD)0x0008)
#define SP_HANDSHAKING    ((DWORD)0x0010)
#define SP_PARITY_CHECK   ((DWORD)0x0020)
#define SP_CARRIER_DETECT ((DWORD)0x0040)

//
// Settable baud rates in the provider.
//

#define BAUD_075          ((DWORD)0x00000001)
#define BAUD_110          ((DWORD)0x00000002)
#define BAUD_134_5        ((DWORD)0x00000004)
#define BAUD_150          ((DWORD)0x00000008)
#define BAUD_300          ((DWORD)0x00000010)
#define BAUD_600          ((DWORD)0x00000020)
#define BAUD_1200         ((DWORD)0x00000040)
#define BAUD_1800         ((DWORD)0x00000080)
#define BAUD_2400         ((DWORD)0x00000100)
#define BAUD_4800         ((DWORD)0x00000200)
#define BAUD_7200         ((DWORD)0x00000400)
#define BAUD_9600         ((DWORD)0x00000800)
#define BAUD_14400        ((DWORD)0x00001000)
#define BAUD_19200        ((DWORD)0x00002000)
#define BAUD_38400        ((DWORD)0x00004000)
#define BAUD_56K          ((DWORD)0x00008000)
#define BAUD_USER         ((DWORD)0x10000000)

//
// Settable Data Bits
//

#define DATABITS_5        ((WORD)0x0001)
#define DATABITS_6        ((WORD)0x0002)
#define DATABITS_7        ((WORD)0x0004)
#define DATABITS_8        ((WORD)0x0008)
#define DATABITS_16       ((WORD)0x0010)
#define DATABITS_16X      ((WORD)0x0020)

//
// Settable Stop and Parity bits.
//

#define STOPBITS_10       ((WORD)0x0001)
#define STOPBITS_15       ((WORD)0x0002)
#define STOPBITS_20       ((WORD)0x0004)
#define PARITY_NONE       ((WORD)0x0100)
#define PARITY_ODD        ((WORD)0x0200)
#define PARITY_EVEN       ((WORD)0x0400)
#define PARITY_MARK       ((WORD)0x0800)
#define PARITY_SPACE      ((WORD)0x1000)

typedef struct _COMMPROP {
    WORD wPacketLength;
    WORD wPacketVersion;
    DWORD dwServiceMask;
    DWORD dwMaxConfigData;
    DWORD dwMaxTxQueue;
    DWORD dwMaxRxQueue;
    DWORD dwMaxBaud;
    DWORD dwDefTxQueue;
    DWORD dwDefRxQueue;
    DWORD dwDefBaud;
    WORD wDefDataBits;
    WORD wDefStopParity;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    WORD wSettableData;
    WORD wSettableStopParity;
    DWORD dwCurrentTxQueue;
    DWORD dwCurrentRxQueue;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR ProvChar[1];
} COMMPROP,*LPCOMMPROP;

typedef struct _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD fXoffSent : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 17;
    DWORD cbInQue;
    DWORD cbOutQue;
} COMSTAT, *LPCOMSTAT;

//
// DTR Control Flow Values.
//
#define DTR_CONTROL_DISABLE    0x00
#define DTR_CONTROL_ENABLE     0x01
#define DTR_CONTROL_HANDSHAKE  0x02

//
// RTS Control Flow Values
//
#define RTS_CONTROL_DISABLE    0x00
#define RTS_CONTROL_ENABLE     0x01
#define RTS_CONTROL_HANDSHAKE  0x02

typedef struct _DCB {
    DWORD DCBlength;      /* sizeof(DCB)                     */
    DWORD BaudRate;       /* Baudrate at which running       */
    DWORD fBinary: 1;     /* Binary Mode (skip EOF check)    */
    DWORD fParity: 1;     /* Enable parity checking          */
    DWORD fOutxCtsFlow:1; /* CTS handshaking on output       */
    DWORD fOutxDsrFlow:1; /* DSR handshaking on output       */
    DWORD fDtrControl:2;  /* DTR Flow control                */
    DWORD fDummy: 2;      /* Reserved                        */
    DWORD fOutX: 1;       /* Enable output X-ON/X-OFF        */
    DWORD fInX: 1;        /* Enable input X-ON/X-OFF         */
    DWORD fPeChar: 1;     /* Enable Parity Err Replacement   */
    DWORD fNull: 1;       /* Enable Null stripping           */
    DWORD fRtsControl:2;  /* Rts Flow control                */
    DWORD fDummy2:2;      /* Reserved                        */
    WORD TxDelay;         /* Amount of time between chars    */
    WORD XonLim;          /* Transmit X-ON threshold         */
    WORD XoffLim;         /* Transmit X-OFF threshold        */
    BYTE ByteSize;        /* Number of bits/byte, 4-8        */
    BYTE Parity;          /* 0-4=None,Odd,Even,Mark,Space    */
    BYTE StopBits;        /* 0,1,2 = 1, 1.5, 2               */
    char XonChar;         /* Tx and Rx X-ON character        */
    char XoffChar;        /* Tx and Rx X-OFF character       */
    char PeChar;          /* Parity error replacement char   */
    char EofChar;         /* End of Input character          */
    char EvtChar;         /* Recieved Event character        */
} DCB, *LPDCB;

typedef struct _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;          /* Maximum time between read chars. */
    DWORD ReadTotalTimeoutMultiplier;   /* Multiplier of characters.        */
    DWORD ReadTotalTimeoutConstant;     /* Constant in milliseconds.        */
    DWORD WriteTotalTimeoutMultiplier;  /* Multiplier of characters.        */
    DWORD WriteTotalTimeoutConstant;    /* Constant in milliseconds.        */
} COMMTIMEOUTS,*LPCOMMTIMEOUTS;

typedef struct _SYSTEM_INFO {
    DWORD dwOemId;
    DWORD dwPageSize;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD dwActiveProcessorMask;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwProcessorRevision;
    DWORD dwProcessorOptions;
} SYSTEM_INFO, *LPSYSTEM_INFO;

#define FreeModule(hLibModule) FreeLibrary((hLibModule))
#define MakeProcInstance(lpProc,hInstance) (lpProc)
#define FreeProcInstance(lpProc)

/* Global Memory Flags */
#define GMEM_FIXED          0x0000
#define GMEM_MOVEABLE       0x0002
#define GMEM_NOCOMPACT      0x0010
#define GMEM_NODISCARD      0x0020
#define GMEM_ZEROINIT       0x0040
#define GMEM_MODIFY         0x0080
#define GMEM_DISCARDABLE    0x0100
#define GMEM_NOT_BANKED     0x1000
#define GMEM_SHARE          0x2000
#define GMEM_DDESHARE       0x2000
#define GMEM_NOTIFY         0x4000
#define GMEM_LOWER          GMEM_NOT_BANKED
#define GMEM_VALID_FLAGS    0x7F72
#define GMEM_INVALID_HANDLE 0x8000

#define GHND                (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define GPTR                (GMEM_FIXED | GMEM_ZEROINIT)

#define GlobalDiscard( h )              (HANDLE)(h)
#define GlobalLRUNewest( h )            (HANDLE)(h)
#define GlobalLRUOldest( h )            (HANDLE)(h)
#define GlobalCompact( dw )             (0x100000L)
#define GlobalFix( h )                  (h)
#define GlobalUnfix( h )                ((BOOL)h)
#define GlobalUnWire( h )               (TRUE)
#define GlobalWire( h )                 (LPSTR)(h)

/* Flags returned by GlobalFlags (in addition to GMEM_DISCARDABLE) */
#define GMEM_DISCARDED      0x4000
#define GMEM_LOCKCOUNT      0x00FF

typedef struct _MEMORYSTATUS {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    DWORD dwTotalPhys;
    DWORD dwAvailPhys;
    DWORD dwTotalPageFile;
    DWORD dwAvailPageFile;
    DWORD dwTotalVirtual;
    DWORD dwAvailVirtual;
} MEMORYSTATUS, *LPMEMORYSTATUS;

/* Local Memory Flags */
#define LMEM_FIXED          0x0000
#define LMEM_MOVEABLE       0x0002
#define LMEM_NOCOMPACT      0x0010
#define LMEM_NODISCARD      0x0020
#define LMEM_ZEROINIT       0x0040
#define LMEM_MODIFY         0x0080
#define LMEM_DISCARDABLE    0x0F00
#define LMEM_VALID_FLAGS    0x0F72
#define LMEM_INVALID_HANDLE 0x8000

#define LHND                (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define LPTR                (LMEM_FIXED | LMEM_ZEROINIT)

#define NONZEROLHND         (LMEM_MOVEABLE)
#define NONZEROLPTR         (LMEM_FIXED)

#define LocalShrink( h, n ) (0x10000)
#define LocalCompact( h ) (0x10000)
#define LocalDiscard( h ) (NULL)

/* Flags returned by LocalFlags (in addition to LMEM_DISCARDABLE) */
#define LMEM_DISCARDED      0x4000
#define LMEM_LOCKCOUNT      0x00FF

//
// dwCreationFlag values
//

#define DEBUG_PROCESS               0x00000001
#define DEBUG_ONLY_THIS_PROCESS     0x00000002

#define CREATE_SUSPENDED            0x00000004

#define DETACHED_PROCESS            0x00000008

#define CREATE_NEW_CONSOLE          0x00000010

#define PROFILE_USER                0x10000000
#define PROFILE_KERNEL              0x20000000
#define PROFILE_SERVER              0x40000000

#define THREAD_PRIORITY_LOWEST          THREAD_BASE_PRIORITY_MIN
#define THREAD_PRIORITY_BELOW_NORMAL    (THREAD_PRIORITY_LOWEST+1)
#define THREAD_PRIORITY_NORMAL          0
#define THREAD_PRIORITY_HIGHEST         THREAD_BASE_PRIORITY_MAX
#define THREAD_PRIORITY_ABOVE_NORMAL    (THREAD_PRIORITY_HIGHEST-1)
#define THREAD_PRIORITY_ERROR_RETURN    (MAXLONG)

//
// Debug APIs
//
#define EXCEPTION_DEBUG_EVENT       1
#define CREATE_THREAD_DEBUG_EVENT   2
#define CREATE_PROCESS_DEBUG_EVENT  3
#define EXIT_THREAD_DEBUG_EVENT     4
#define EXIT_PROCESS_DEBUG_EVENT    5
#define LOAD_DLL_DEBUG_EVENT        6
#define UNLOAD_DLL_DEBUG_EVENT      7
#define OUTPUT_DEBUG_STRING_EVENT   8

typedef struct _EXCEPTION_DEBUG_INFO {
    EXCEPTION_RECORD ExceptionRecord;
    DWORD dwFirstChance;
} EXCEPTION_DEBUG_INFO, *LPEXCEPTION_DEBUG_INFO;

typedef struct _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPTHREAD_START_ROUTINE lpStartAddress;
} CREATE_THREAD_DEBUG_INFO, *LPCREATE_THREAD_DEBUG_INFO;

typedef struct _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lpBaseOfImage;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPTHREAD_START_ROUTINE lpStartAddress;
} CREATE_PROCESS_DEBUG_INFO, *LPCREATE_PROCESS_DEBUG_INFO;

typedef struct _EXIT_THREAD_DEBUG_INFO {
    DWORD dwExitCode;
} EXIT_THREAD_DEBUG_INFO, *LPEXIT_THREAD_DEBUG_INFO;

typedef struct _EXIT_PROCESS_DEBUG_INFO {
    DWORD dwExitCode;
} EXIT_PROCESS_DEBUG_INFO, *LPEXIT_PROCESS_DEBUG_INFO;

typedef struct _LOAD_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lpBaseOfDll;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
} LOAD_DLL_DEBUG_INFO, *LPLOAD_DLL_DEBUG_INFO;

typedef struct _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lpBaseOfDll;
} UNLOAD_DLL_DEBUG_INFO, *LPUNLOAD_DLL_DEBUG_INFO;

typedef struct _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lpDebugStringData;
    WORD fUnicode;
    WORD nDebugStringLength;
} OUTPUT_DEBUG_STRING_INFO, *LPOUTPUT_DEBUG_STRING_INFO;

typedef struct _DEBUG_EVENT {
    DWORD dwDebugEventCode;
    DWORD dwProcessId;
    DWORD dwThreadId;
    union {
        EXCEPTION_DEBUG_INFO Exception;
        CREATE_THREAD_DEBUG_INFO CreateThread;
        CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
        EXIT_THREAD_DEBUG_INFO ExitThread;
        EXIT_THREAD_DEBUG_INFO ExitProcess;
        LOAD_DLL_DEBUG_INFO LoadDll;
        UNLOAD_DLL_DEBUG_INFO UnloadDll;
        OUTPUT_DEBUG_STRING_INFO DebugString;
    } u;
} DEBUG_EVENT, *LPDEBUG_EVENT;

typedef PCONTEXT LPCONTEXT;
typedef PEXCEPTION_RECORD LPEXCEPTION_RECORD;
typedef EXCEPTION_POINTERS LPEXCEPTION_POINTERS;

#define DRIVE_REMOVABLE 2
#define DRIVE_FIXED     3
#define DRIVE_REMOTE    4
#define DRIVE_CDROM     5
#define DRIVE_RAMDISK   6


#define GetFreeSpace(w)                 (0x100000L)


#define FILE_TYPE_UNKNOWN   0x0000
#define FILE_TYPE_DISK      0x0001
#define FILE_TYPE_CHAR      0x0002
#define FILE_TYPE_PIPE      0x0003
#define FILE_TYPE_REMOTE    0x8000


#define STD_INPUT_HANDLE    (DWORD)-10
#define STD_OUTPUT_HANDLE   (DWORD)-11
#define STD_ERROR_HANDLE      (DWORD)-12

#define NOPARITY            0
#define ODDPARITY           1
#define EVENPARITY          2
#define MARKPARITY          3
#define SPACEPARITY         4

#define ONESTOPBIT          0
#define ONE5STOPBITS        1
#define TWOSTOPBITS         2

#define IGNORE              0       // Ignore signal
#define INFINITE            0xFFFFFFFF  // Infinite timeout

//
// Basud rates at which the communication device operates
//

#define CBR_110             110
#define CBR_300             300
#define CBR_600             600
#define CBR_1200            1200
#define CBR_2400            2400
#define CBR_4800            4800
#define CBR_9600            9600
#define CBR_14400           14400
#define CBR_19200           19200
#define CBR_38400           38400
#define CBR_56000           56000
#define CBR_128000          128000
#define CBR_256000          256000

//
// Error Flags
//

#define CE_RXOVER           0x0001  // Receive Queue overflow
#define CE_OVERRUN          0x0002  // Receive Overrun Error
#define CE_RXPARITY         0x0004  // Receive Parity Error
#define CE_FRAME            0x0008  // Receive Framing error
#define CE_BREAK            0x0010  // Break Detected
#define CE_TXFULL           0x0100  // TX Queue is full
#define CE_PTO              0x0200  // LPTx Timeout
#define CE_IOE              0x0400  // LPTx I/O Error
#define CE_DNS              0x0800  // LPTx Device not selected
#define CE_OOP              0x1000  // LPTx Out-Of-Paper
#define CE_MODE             0x8000  // Requested mode unsupported

#define IE_BADID            (-1)    // Invalid or unsupported id
#define IE_OPEN             (-2)    // Device Already Open
#define IE_NOPEN            (-3)    // Device Not Open
#define IE_MEMORY           (-4)    // Unable to allocate queues
#define IE_DEFAULT          (-5)    // Error in default parameters
#define IE_HARDWARE         (-10)   // Hardware Not Present
#define IE_BYTESIZE         (-11)   // Illegal Byte Size
#define IE_BAUDRATE         (-12)   // Unsupported BaudRate

//
// Events
//

#define EV_RXCHAR           0x0001  // Any Character received
#define EV_RXFLAG           0x0002  // Received certain character
#define EV_TXEMPTY          0x0004  // Transmitt Queue Empty
#define EV_CTS              0x0008  // CTS changed state
#define EV_DSR              0x0010  // DSR changed state
#define EV_RLSD             0x0020  // RLSD changed state
#define EV_BREAK            0x0040  // BREAK received
#define EV_ERR              0x0080  // Line status error occurred
#define EV_RING             0x0100  // Ring signal detected
#define EV_PERR             0x0200  // Printer error occured
#define EV_RX80FULL         0x0400  // Receive buffer is 80 percent full
#define EV_EVENT1           0x0800  // Provider specific event 1
#define EV_EVENT2           0x1000  // Provider specific event 2

//
// Escape Functions
//

#define SETXOFF             1       // Simulate XOFF received
#define SETXON              2       // Simulate XON received
#define SETRTS              3       // Set RTS high
#define CLRRTS              4       // Set RTS low
#define SETDTR              5       // Set DTR high
#define CLRDTR              6       // Set DTR low
#define RESETDEV            7       // Reset device if possible
#define SETBREAK            8       // Set the device break line.
#define CLRBREAK            9       // Clear the device break line.

//
// PURGE function flags.
//
#define PURGE_TXABORT       0x0001  // Kill the pending/current writes to the comm port.
#define PURGE_RXABORT       0x0002  // Kill the pending/current reads to the comm port.
#define PURGE_TXCLEAR       0x0004  // Kill the transmit queue if there.
#define PURGE_RXCLEAR       0x0008  // Kill the typeahead buffer if there.

#define LPTx                0x80    // Set if ID is for LPT device

//
// Modem Status Flags
//
#define MS_CTS_ON           ((DWORD)0x0010)
#define MS_DSR_ON           ((DWORD)0x0020)
#define MS_RING_ON          ((DWORD)0x0040)
#define MS_RLSD_ON          ((DWORD)0x0080)

//
// WaitSoundState() Constants
//

#define S_QUEUEEMPTY        0
#define S_THRESHOLD         1
#define S_ALLTHRESHOLD      2

//
// Accent Modes
//

#define S_NORMAL      0
#define S_LEGATO      1
#define S_STACCATO    2

//
// SetSoundNoise() Sources
//

#define S_PERIOD512   0     // Freq = N/512 high pitch, less coarse hiss
#define S_PERIOD1024  1     // Freq = N/1024
#define S_PERIOD2048  2     // Freq = N/2048 low pitch, more coarse hiss
#define S_PERIODVOICE 3     // Source is frequency from voice channel (3)
#define S_WHITE512    4     // Freq = N/512 high pitch, less coarse hiss
#define S_WHITE1024   5     // Freq = N/1024
#define S_WHITE2048   6     // Freq = N/2048 low pitch, more coarse hiss
#define S_WHITEVOICE  7     // Source is frequency from voice channel (3)

#define S_SERDVNA     (-1)  // Device not available
#define S_SEROFM      (-2)  // Out of memory
#define S_SERMACT     (-3)  // Music active
#define S_SERQFUL     (-4)  // Queue full
#define S_SERBDNT     (-5)  // Invalid note
#define S_SERDLN      (-6)  // Invalid note length
#define S_SERDCC      (-7)  // Invalid note count
#define S_SERDTP      (-8)  // Invalid tempo
#define S_SERDVL      (-9)  // Invalid volume
#define S_SERDMD      (-10) // Invalid mode
#define S_SERDSH      (-11) // Invalid shape
#define S_SERDPT      (-12) // Invalid pitch
#define S_SERDFQ      (-13) // Invalid frequency
#define S_SERDDR      (-14) // Invalid duration
#define S_SERDSR      (-15) // Invalid source
#define S_SERDST      (-16) // Invalid state

#define NMPWAIT_WAIT_FOREVER            0xffffffff
#define NMPWAIT_NOWAIT                  0x00000001
#define NMPWAIT_USE_DEFAULT_WAIT        0x00000000

#define FS_CASE_IS_PRESERVED            FILE_CASE_PRESERVED_NAMES
#define FS_CASE_SENSITIVE               FILE_CASE_SENSITIVE_SEARCH
#define FS_UNICODE_STORED_ON_DISK       FILE_UNICODE_ON_DISK

#define FILE_MAP_WRITE      SECTION_MAP_WRITE
#define FILE_MAP_READ       SECTION_MAP_READ
#define FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS

#define OF_READ             0x00000000
#define OF_WRITE            0x00000001
#define OF_READWRITE        0x00000002
#define OF_SHARE_COMPAT     0x00000000
#define OF_SHARE_EXCLUSIVE  0x00000010
#define OF_SHARE_DENY_WRITE 0x00000020
#define OF_SHARE_DENY_READ  0x00000030
#define OF_SHARE_DENY_NONE  0x00000040
#define OF_PARSE            0x00000100
#define OF_DELETE           0x00000200
#define OF_VERIFY           0x00000400
#define OF_CANCEL           0x00000800
#define OF_CREATE           0x00001000
#define OF_PROMPT           0x00002000
#define OF_EXIST            0x00004000
#define OF_REOPEN           0x00008000

typedef struct _OFSTRUCT {
    BYTE cBytes;
    BYTE fFixedDisk;
    WORD nErrCode;
    WORD Reserved1;
    WORD Reserved2;
    BYTE szPathName[120];
} OFSTRUCT, *LPOFSTRUCT, *POFSTRUCT;

LONG
APIENTRY
InterlockedIncrement(
    LPLONG lpAddend
    );

LONG
APIENTRY
InterlockedDecrement(
    LPLONG lpAddend
    );

// MVDM related Stuff
#define MAXIMUM_VDM_COMMAND_LENGTH	128
#define MAXIMUM_VDM_ENVIORNMENT 	32*1024
#define MAXIMUM_VDM_CURRENT_DIR 	64

// VDMState defines
#define ASKING_FOR_FIRST_COMMAND 1	// Very First call.
#define ASKING_FOR_WOW_BINARY	 2	// Caller is WOWVDM
#define ASKING_FOR_DOS_BINARY	 4	// Caller is DOSVDM
#define ASKING_FOR_SECOND_TIME	 8	// Caller is asking second time after
					// allocating bigger buffers.
typedef struct _VDMINFO {
    LPVOID CmdLine;
    LPVOID Enviornment;
    USHORT CmdSize;
    USHORT CurDrive;
    ULONG  EnviornmentSize;
    ULONG  ErrorCode;
    ULONG  VDMState;
    ULONG  iTask;
} VDMINFO, *PVDMINFO;

DWORD
APIENTRY
FreeResource(
        HANDLE hResData
        );

LPSTR
APIENTRY
LockResource(
        HANDLE hResData
        );

#define UnlockResource(hResData) ((hResData), 0)
#define MAXINTATOM 0xC000
#define MAKEINTATOM(i)  (LPSTR)((DWORD)((WORD)(i)))

int
APIENTRY
WinMain(
    HANDLE hInstance,
    HANDLE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd
    );

BOOL
APIENTRY
FreeLibrary(
    HANDLE hLibModule
    );

FARPROC
APIENTRY
GetProcAddress(
    HANDLE hModule,
    LPSTR lpProcName
    );

DWORD
APIENTRY
GetVersion( VOID );

HANDLE
APIENTRY
GlobalAlloc(
    DWORD dwFlags,
    DWORD dwBytes
    );

HANDLE
APIENTRY
GlobalReAlloc(
    HANDLE hMem,
    DWORD dwBytes,
    DWORD dwFlags
    );

DWORD
APIENTRY
GlobalSize(
    HANDLE hMem
    );

DWORD
APIENTRY
GlobalFlags(
    HANDLE hMem
    );


LPSTR
APIENTRY
GlobalLock(
    HANDLE hMem
    );


HANDLE
APIENTRY
GlobalHandle(
    LPSTR pMem
    );


BOOL
APIENTRY
GlobalUnlock(
    HANDLE hMem
    );


LPVOID
APIENTRY
GlobalFree(
    HANDLE hMem
    );


VOID
APIENTRY
GlobalMemoryStatus(
    LPMEMORYSTATUS lpBuffer
    );

HANDLE
APIENTRY
LocalAlloc(
    DWORD dwFlags,
    DWORD dwBytes
    );

HANDLE
APIENTRY
LocalReAlloc(
    HANDLE hMem,
    DWORD dwBytes,
    DWORD dwFlags
    );

LPSTR
APIENTRY
LocalLock(
    HANDLE hMem
    );

HANDLE
APIENTRY
LocalHandle(
    LPSTR pMem
    );

BOOL
APIENTRY
LocalUnlock(
    HANDLE hMem
    );

DWORD
APIENTRY
LocalSize(
    HANDLE hMem
    );

DWORD
LocalFlags(
    HANDLE hMem
    );

HANDLE
APIENTRY
LocalFree(
    HANDLE hMem
    );

LPVOID
APIENTRY
VirtualAlloc(
    LPVOID lpAddress,
    DWORD dwSize,
    DWORD flAllocationType,
    DWORD flProtect
    );

BOOL
APIENTRY
VirtualFree(
    LPVOID lpAddress,
    DWORD dwSize,
    DWORD dwFreeType
    );

BOOL
APIENTRY
VirtualProtect(
    LPVOID lpAddress,
    DWORD dwSize,
    DWORD flNewProtect,
    PDWORD lpflOldProtect
    );

DWORD
APIENTRY
VirtualQuery(
    LPVOID lpAddress,
    PMEMORY_BASIC_INFORMATION lpBuffer,
    DWORD dwLength
    );

HANDLE
APIENTRY
HeapCreate(
    DWORD flOptions,
    DWORD dwInitialSize,
    DWORD dwMaximumSize
    );

BOOL
APIENTRY
HeapDestroy(
    HANDLE hHeap
    );

LPSTR
APIENTRY
HeapAlloc(
    HANDLE hHeap,
    DWORD dwBytes
    );

BOOL
APIENTRY
HeapFree(
    HANDLE hHeap,
    LPSTR lpMem
    );

DWORD
APIENTRY
HeapSize(
    HANDLE hHeap,
    LPSTR lpMem
    );


HANDLE
APIENTRY
OpenProcess(
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    DWORD dwProcessId
    );

HANDLE
APIENTRY
GetCurrentProcess(
    VOID
    );

DWORD
APIENTRY
GetCurrentProcessId(
    VOID
    );

VOID
APIENTRY
ExitProcess(
    DWORD dwExitCode
    );

BOOL
APIENTRY
TerminateProcess(
    HANDLE hProcess,
    DWORD dwExitCode
    );

BOOL
APIENTRY
GetExitCodeProcess(
    HANDLE hProcess,
    LPDWORD lpExitCode
    );


VOID
APIENTRY
FatalExit(
    DWORD dwExitCode
    );

LPVOID
APIENTRY
GetEnvironmentStrings(
    VOID
    );

VOID
APIENTRY
RaiseException(
    DWORD dwExceptionCode,
    DWORD dwExceptionFlags,
    DWORD nNumberOfArguments,
    LPDWORD lpArguments
    );

EXCEPTION_DISPOSITION
APIENTRY
UnhandledExceptionFilter(
    struct _EXCEPTION_POINTERS *ExceptionInfo
    );

HANDLE
APIENTRY
CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    DWORD dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId
    );

HANDLE
APIENTRY
GetCurrentThread(
    VOID
    );

DWORD
APIENTRY
GetCurrentThreadId(
    VOID
    );

BOOL
APIENTRY
SetThreadPriority(
    HANDLE hThread,
    int nPriority
    );

int
APIENTRY
GetThreadPriority(
    HANDLE hThread
    );

VOID
APIENTRY
ExitThread(
    DWORD dwExitCode
    );

BOOL
APIENTRY
TerminateThread(
    HANDLE hThread,
    DWORD dwExitCode
    );

BOOL
APIENTRY
GetExitCodeThread(
    HANDLE hThread,
    LPDWORD lpExitCode
    );

BOOL
APIENTRY
GetThreadSelectorEntry(
    HANDLE hThread,
    DWORD dwSelector,
    LPLDT_ENTRY lpSelectorEntry
    );

DWORD
APIENTRY
GetLastError(
    VOID
    );

VOID
APIENTRY
SetLastError(
    DWORD dwErrCode
    );

BOOL
APIENTRY
GetOverlappedResult(
    HANDLE hFile,
    LPOVERLAPPED lpOverlapped,
    LPDWORD lpNumberOfBytesTransferred,
    BOOL bWait
    );

BOOL
APIENTRY
SetErrorMode(
    BOOL bMode
    );


BOOL
APIENTRY
ReadProcessMemory(
    HANDLE hProcess,
    LPVOID lpBaseAddress,
    LPVOID lpBuffer,
    DWORD nSize,
    LPDWORD lpNumberOfBytesRead
    );

BOOL
APIENTRY
WriteProcessMemory(
    HANDLE hProcess,
    LPVOID lpBaseAddress,
    LPVOID lpBuffer,
    DWORD nSize,
    LPDWORD lpNumberOfBytesWritten
    );

BOOL
APIENTRY
GetThreadContext(
    HANDLE hThread,
    LPCONTEXT lpContext
    );

BOOL
APIENTRY
SetThreadContext(
    HANDLE hThread,
    LPCONTEXT lpContext
    );

DWORD
APIENTRY
SuspendThread(
    HANDLE hThread
    );

DWORD
APIENTRY
ResumeThread(
    IN HANDLE hThread
    );

VOID
APIENTRY
DebugBreak(
    VOID
    );

BOOL
APIENTRY
WaitForDebugEvent(
    LPDEBUG_EVENT lpDebugEvent,
    DWORD dwMilliseconds
    );

BOOL
APIENTRY
ContinueDebugEvent(
    DWORD dwProcessId,
    DWORD dwThreadId,
    DWORD dwContinueStatus
    );

BOOL
APIENTRY
DebugActiveProcess(
    DWORD dwProcessId
    );

VOID
APIENTRY
InitializeCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
    );

VOID
APIENTRY
EnterCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
    );

VOID
APIENTRY
LeaveCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
    );

VOID
APIENTRY
DeleteCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
    );

BOOL
APIENTRY
SetEvent(
    HANDLE hEvent
    );

BOOL
APIENTRY
ResetEvent(
    HANDLE hEvent
    );

BOOL
APIENTRY
PulseEvent(
    HANDLE hEvent
    );

BOOL
APIENTRY
ReleaseSemaphore(
    HANDLE hSemaphore,
    LONG lReleaseCount,
    LPLONG lpPreviousCount
    );

BOOL
APIENTRY
ReleaseMutex(
    HANDLE hMutex
    );

DWORD
APIENTRY
WaitForSingleObject(
    HANDLE hHandle,
    DWORD dwMilliseconds
    );

DWORD
APIENTRY
WaitForMultipleObjects(
    DWORD nCount,
    LPHANDLE lpHandles,
    BOOL bWaitAll,
    DWORD dwMilliseconds
    );

VOID
APIENTRY
Sleep(
    DWORD dwMilliseconds
    );

HANDLE
APIENTRY
LoadResource(
    HANDLE hModule,
    HANDLE hResInfo
    );

DWORD
APIENTRY
SizeofResource(
    HANDLE hModule,
    HANDLE hResInfo
    );

ATOM
APIENTRY
GlobalDeleteAtom(
    ATOM nAtom
    );

BOOL
APIENTRY
InitAtomTable(
    DWORD nSize
    );

ATOM
APIENTRY
DeleteAtom(
    ATOM nAtom
    );

DWORD
APIENTRY
SetHandleCount(
    DWORD dwNumber
    );

DWORD
APIENTRY
GetLogicalDrives(
    VOID
    );

BOOL
APIENTRY
LockFile(
    HANDLE hFile,
    DWORD dwFileOffsetHigh,
    DWORD dwFileOffsetLow,
    DWORD nNumberOfBytesToLock
    );

BOOL
APIENTRY
UnlockFile(
    HANDLE hFile,
    DWORD dwFileOffsetHigh,
    DWORD dwFileOffsetLow,
    DWORD nNumberOfBytesToUnlock
    );

DWORD
APIENTRY
GetFileType(
    HANDLE hFile
    );

DWORD
APIENTRY
GetFileSize(
    HANDLE hFile,
    LPDWORD lpFileSizeHigh
    );

HANDLE
APIENTRY
GetStdHandle(
    DWORD nStdHandle
    );

BOOL
APIENTRY
SetStdHandle(
    DWORD nStdHandle,
    HANDLE hHandle
    );

BOOL
APIENTRY
WriteFile(
    HANDLE hFile,
    LPVOID lpBuffer,
    DWORD nNumberOfBytesToWrite,
    LPDWORD lpNumberOfBytesWritten,
    LPOVERLAPPED lpOverlapped
    );

BOOL
APIENTRY
ReadFile(
    HANDLE hFile,
    LPVOID lpBuffer,
    DWORD nNumberOfBytesToRead,
    LPDWORD lpNumberOfBytesRead,
    LPOVERLAPPED lpOverlapped
    );

BOOL
APIENTRY
FlushFileBuffers(
    HANDLE hFile
    );

BOOL
APIENTRY
SetEndOfFile(
    HANDLE hFile
    );

DWORD
APIENTRY
SetFilePointer(
    HANDLE hFile,
    LONG lDistanceToMove,
    PLONG lpDistanceToMoveHigh,
    DWORD dwMoveMethod
    );

BOOL
APIENTRY
FindClose(
    HANDLE hFindFile
    );

BOOL
APIENTRY
GetFileTime(
    HANDLE hFile,
    LPFILETIME lpCreationTime,
    LPFILETIME lpLastAccessTime,
    LPFILETIME lpLastWriteTime
    );

BOOL
APIENTRY
SetFileTime(
    HANDLE hFile,
    LPFILETIME lpCreationTime,
    LPFILETIME lpLastAccessTime,
    LPFILETIME lpLastWriteTime
    );

BOOL
APIENTRY
CloseHandle(
    HANDLE hObject
    );

BOOL
APIENTRY
DuplicateHandle(
    HANDLE hSourceProcessHandle,
    HANDLE hSourceHandle,
    HANDLE hTargetProcessHandle,
    LPHANDLE lpTargetHandle,
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    DWORD dwOptions
    );

DWORD
APIENTRY
LoadModule(
    LPSTR lpModuleName,
    LPVOID lpParameterBlock
    );

DWORD
APIENTRY
WinExec(
    LPSTR lpCmdLine,
    WORD nCmdShow
    );

BOOL
APIENTRY
BuildCommDCB(
    LPSTR lpDef,
    LPDCB lpDCB
    );

BOOL
APIENTRY
ClearCommBreak(
    HANDLE hFile
    );

BOOL
APIENTRY
ClearCommError(
    HANDLE hFile,
    LPDWORD lpErrors,
    LPCOMSTAT lpStat
    );

BOOL
APIENTRY
SetupComm(
    HANDLE hFile,
    DWORD dwInQueue,
    DWORD dwOutQueue
    );

BOOL
APIENTRY
EnableCommNotification(
    HANDLE hFile,
    HANDLE hWnd,
    DWORD dwInTrigger,
    DWORD dwOutTrigger
    );

BOOL
APIENTRY
EscapeCommFunction(
    HANDLE hFile,
    DWORD dwFunc
    );

BOOL
APIENTRY
ExtendedProviderFunction(
    HANDLE hFile,
    WORD wCatagory,
    WORD wFunction,
    LPVOID lpParam,
    LPVOID lpData,
    DWORD dwParamLength,
    LPDWORD lpDataLength
    );

BOOL
APIENTRY
GetCommConfig(
    HANDLE hFile,
    LPVOID lpCOMMCONFIG,
    DWORD dwSize
    );

BOOL
APIENTRY
GetCommMask(
    HANDLE hFile,
    LPDWORD lpEvtMask
    );

BOOL
APIENTRY
GetCommModemStatus(
    HANDLE hFile,
    LPDWORD lpModemStat
    );

BOOL
APIENTRY
GetCommState(
    HANDLE hFile,
    LPDCB lpDCB
    );

BOOL
APIENTRY
GetCommTimeouts(
    HANDLE hFile,
    LPCOMMTIMEOUTS lpCommTimeouts
    );

BOOL
APIENTRY
PurgeComm(
    HANDLE hFile,
    DWORD dwFlags
    );

BOOL
APIENTRY
SetCommBreak(
    HANDLE hFile
    );

BOOL
APIENTRY
SetCommConfig(
    HANDLE hFile,
    LPVOID lpCOMMCONFIG,
    DWORD dwSize
    );

BOOL
APIENTRY
SetCommMask(
    HANDLE hFile,
    DWORD dwEvtMask
    );

BOOL
APIENTRY
SetCommState(
    HANDLE hFile,
    LPDCB lpDCB
    );

BOOL
APIENTRY
SetCommTimeouts(
    HANDLE hFile,
    LPCOMMTIMEOUTS lpCommTimeouts
    );

BOOL
APIENTRY
TransmitCommChar(
    HANDLE hFile,
    char cChar
    );

BOOL
APIENTRY
WaitCommEvent(
    HANDLE hFile,
    LPDWORD lpEvtMask,
    HANDLE hEvent
    );

BOOL
APIENTRY
Beep(
    DWORD dwFreq,
    DWORD dwDuration
    );

VOID
APIENTRY
OpenSound(
    VOID
    );

VOID
APIENTRY
CloseSound(
    VOID
    );

VOID
APIENTRY
StartSound(
    VOID
    );

VOID
APIENTRY
StopSound(
    VOID
    );

DWORD
APIENTRY
WaitSoundState(
    DWORD nState
    );

DWORD
APIENTRY
SyncAllVoices(
    VOID
    );

DWORD
APIENTRY
CountVoiceNotes(
    DWORD nVoice
    );

LPDWORD
APIENTRY
GetThresholdEvent(
    VOID
    );

DWORD
APIENTRY
GetThresholdStatus(
    VOID
    );

DWORD
APIENTRY
SetSoundNoise(
    DWORD nSource,
    DWORD nDuration
    );

DWORD
APIENTRY
SetVoiceAccent(
    DWORD nVoice,
    DWORD nTempo,
    DWORD nVolume,
    DWORD nMode,
    DWORD nPitch
    );

DWORD
APIENTRY
SetVoiceEnvelope(
    DWORD nVoice,
    DWORD nShape,
    DWORD nRepeat
    );

DWORD
APIENTRY
SetVoiceNote(
    DWORD nVoice,
    DWORD nValue,
    DWORD nLength,
    DWORD nCdots
    );

DWORD
APIENTRY
SetVoiceQueueSize(
    DWORD nVoice,
    DWORD nBytes
    );

DWORD
APIENTRY
SetVoiceSound(
    DWORD nVoice,
    LONG lFrequency,
    DWORD nDuration
    );

DWORD
APIENTRY
SetVoiceThreshold(
    DWORD nVoice,
    DWORD nNotes
    );

int
APIENTRY
MulDiv(
    int nNumber,
    int nNumerator,
    int nDenominator
    );

VOID
APIENTRY
GetSystemTime(
    LPSYSTEMTIME lpSystemTime
    );

BOOL
APIENTRY
SetSystemTime(
    LPSYSTEMTIME lpSystemTime
    );

VOID
APIENTRY
GetSystemInfo(
    LPSYSTEM_INFO lpSystemInfo
    );


//
// Routines to convert back and forth between system time and file time
//

BOOL
APIENTRY
SystemTimeToFileTime(
    LPSYSTEMTIME lpSystemTime,
    LPFILETIME lpFileTime
    );

BOOL
APIENTRY
FileTimeToSystemTime(
    LPFILETIME lpFileTime,
    LPSYSTEMTIME lpSystemTime
    );

LONG
APIENTRY
CompareFileTime(
    LPFILETIME lpFileTime1,
    LPFILETIME lpFileTime2
    );

BOOL
APIENTRY
FileTimeToDosDateTime(
    LPFILETIME lpFileTime,
    LPWORD lpFatDate,
    LPWORD lpFatTime
    );

BOOL
APIENTRY
DosDateTimeToFileTime(
    WORD wFatDate,
    WORD wFatTime,
    LPFILETIME lpFileTime
    );

DWORD
APIENTRY
GetTickCount(
    VOID
    );

DWORD
APIENTRY
FormatMessage(
    DWORD dwFlags,
    LPVOID lpSource,
    DWORD dwMessageId,
    DWORD dwLanguageId,
    LPSTR lpBuffer,
    DWORD nSize,
    LPVOID lpArguments
    );

#define FORMAT_MESSAGE_ALLOCATE_BUFFER 0x00000100
#define FORMAT_MESSAGE_IGNORE_INSERTS  0x00000200
#define FORMAT_MESSAGE_FROM_STRING     0x00000400
#define FORMAT_MESSAGE_FROM_HMODULE    0x00000800
#define FORMAT_MESSAGE_FROM_SYSTEM     0x00001000
#define FORMAT_MESSAGE_MAX_WIDTH_MASK  0x000000FF


BOOL
APIENTRY
CreatePipe(
    PHANDLE hReadPipe,
    PHANDLE hWritePipe,
    LPSECURITY_ATTRIBUTES lpPipeAttributes,
    DWORD nSize
    );

BOOL
APIENTRY
ConnectNamedPipe(
    HANDLE hNamedPipe,
    LPOVERLAPPED lpOverlapped
    );

BOOL
APIENTRY
DisconnectNamedPipe(
    HANDLE hNamedPipe
    );

BOOL
APIENTRY
SetNamedPipeHandleState(
    HANDLE hNamedPipe,
    LPDWORD lpMode,
    LPDWORD lpMaxCollectionCount,
    LPDWORD lpCollectDataTimeout
    );

BOOL
APIENTRY
GetNamedPipeInfo(
    HANDLE hNamedPipe,
    LPDWORD lpFlags,
    LPDWORD lpOutBufferSize,
    LPDWORD lpInBufferSize,
    LPDWORD lpMaxInstances
    );

BOOL
APIENTRY
PeekNamedPipe(
    HANDLE hNamedPipe,
    LPVOID lpBuffer,
    DWORD nBufferSize,
    LPDWORD lpBytesRead,
    LPDWORD lpTotalBytesAvail,
    LPDWORD lpBytesLeftThisMessage
    );

BOOL
APIENTRY
TransactNamedPipe(
    HANDLE hNamedPipe,
    LPVOID lpInBuffer,
    DWORD nInBufferSize,
    LPVOID lpOutBuffer,
    DWORD nOutBufferSize,
    LPDWORD lpBytesRead,
    LPOVERLAPPED lpOverlapped
    );

HANDLE
APIENTRY
CreateMailslotA(
    IN LPSTR lpName,
    IN DWORD nMaxMessageSize,
    IN DWORD nMailslotSize,
    IN DWORD lReadTimeout,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes OPTIONAL
    );
HANDLE
APIENTRY
CreateMailslotW(
    IN LPWSTR lpName,
    IN DWORD nMaxMessageSize,
    IN DWORD nMailslotSize,
    IN DWORD lReadTimeout,
    IN LPSECURITY_ATTRIBUTES lpSecurityAttributes OPTIONAL
    );
#ifdef UNICODE
#define CreateMailslot CreateMailslotW
#else
#define CreateMailslot CreateMailslotA
#endif // !UNICODE

BOOL
APIENTRY
GetMailslotInfo(
    IN HANDLE hMailslot,
    OUT LPDWORD lpMaxMessageSize OPTIONAL,
    OUT LPDWORD lpMailslotSize OPTIONAL,
    OUT LPDWORD lpNextSize OPTIONAL,
    OUT LPDWORD lpMessageCount OPTIONAL,
    OUT LPDWORD lpReadTimeout OPTIONAL
    );

BOOL
APIENTRY
SetMailslotInfo(
    IN HANDLE hMailslot,
    IN DWORD lReadTimeout
    );

LPVOID
APIENTRY
MapViewOfFile(
    HANDLE hFileMappingObject,
    DWORD dwDesiredAccess,
    DWORD dwFileOffsetHigh,
    DWORD dwFileOffsetLow,
    DWORD dwNumberOfBytesToMap
    );

BOOL
APIENTRY
FlushViewOfFile(
    LPVOID lpBaseAddress,
    DWORD dwNumberOfBytesToFlush
    );

BOOL
APIENTRY
UnmapViewOfFile(
    LPVOID lpBaseAddress
    );

//
// _l Compat Functions
//

int
APIENTRY
lstrcmp(
    LPSTR lpString1,
    LPSTR lpString2
    );

int
APIENTRY
lstrcmpi(
    LPSTR lpString1,
    LPSTR lpString2
    );

LPSTR
APIENTRY
lstrcpy(
    LPSTR lpString1,
    LPSTR lpString2
    );

LPSTR
APIENTRY
lstrcat(
    LPSTR lpString1,
    LPSTR lpString2
    );

int
APIENTRY
lstrlen(
    LPSTR lpString
    );

int
APIENTRY
OpenFile(
    LPSTR lpFileName,
    LPOFSTRUCT lpReOpenBuff,
    WORD wStyle
    );

int
APIENTRY
OpenSystemFile(
    LPSTR lpFileName,
    LPOFSTRUCT lpReOpenBuff,
    WORD wStyle
    );

int
APIENTRY
_lopen(
    LPSTR lpPathName,
    int iReadWrite
    );

int
APIENTRY
_lcreat(
    LPSTR lpPathName,
    WORD  iAttribute
    );

DWORD
APIENTRY
_lread(
    int hFile,
    LPSTR lpBuffer,
    int nBytes
    );

DWORD
APIENTRY
_lwrite(
    int hFile,
    LPSTR lpBuffer,
    int nBytes
    );

int
APIENTRY
_lclose(
    int hFile
    );

int
APIENTRY
_llseek(
    int hFile,
    int lOffset,
    int iOrigin
    );

DWORD
APIENTRY
TlsAlloc(
    VOID
    );

LPVOID
APIENTRY
TlsGetValue(
    DWORD dwTlsIndex
    );

BOOL
APIENTRY
TlsSetValue(
    DWORD dwTlsIndex,
    LPVOID lpTlsValue
    );

BOOL
APIENTRY
TlsFree(
    DWORD dwTlsIndex
    );

//
// Dual Mode API below this line. Dual Mode Structures also included.
//

#define STARTF_USESHOWWINDOW    1
#define STARTF_USESIZE          2
#define STARTF_USEPOSITION      4
#define STARTF_USECOUNTCHARS    8
#define STARTF_USEFILLATTRIBUTE 16

typedef struct _STARTUPINFOA {
    DWORD   cb;
    LPSTR   lpReserved;
    LPSTR   lpDesktop;
    LPSTR   lpTitle;
    DWORD   dwX;
    DWORD   dwY;
    DWORD   dwXSize;
    DWORD   dwYSize;
    DWORD   dwXCountChars;
    DWORD   dwYCountChars;
    DWORD   dwFillAttribute;
    DWORD   dwFlags;
    WORD    wShowWindow;
    WORD    cbReserved2;
    LPBYTE  lpReserved2;
} STARTUPINFOA, *LPSTARTUPINFOA;
typedef struct _STARTUPINFOW {
    DWORD   cb;
    LPWSTR  lpReserved;
    LPWSTR  lpDesktop;
    LPWSTR  lpTitle;
    DWORD   dwX;
    DWORD   dwY;
    DWORD   dwXSize;
    DWORD   dwYSize;
    DWORD   dwXCountChars;
    DWORD   dwYCountChars;
    DWORD   dwFillAttribute;
    DWORD   dwFlags;
    WORD    wShowWindow;
    WORD    cbReserved2;
    LPBYTE  lpReserved2;
} STARTUPINFOW, *LPSTARTUPINFOW;
#ifdef UNICODE
#define STARTUPINFO STARTUPINFOW
#define LPSTARTUPINFO LPSTARTUPINFOW
#else
#define STARTUPINFO STARTUPINFOA
#define LPSTARTUPINFO LPSTARTUPINFOA
#endif // UNICODE

typedef struct _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    CHAR   cFileName[ MAX_PATH ];
} WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;
typedef struct _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    WCHAR  cFileName[ MAX_PATH ];
} WIN32_FIND_DATAW, *PWIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;
#ifdef UNICODE
#define WIN32_FIND_DATA WIN32_FIND_DATAW
#define PWIN32_FIND_DATA PWIN32_FIND_DATAW
#define LPWIN32_FIND_DATA LPWIN32_FIND_DATAW
#else
#define WIN32_FIND_DATA WIN32_FIND_DATAA
#define PWIN32_FIND_DATA PWIN32_FIND_DATAA
#define LPWIN32_FIND_DATA LPWIN32_FIND_DATAA
#endif // UNICODE

HANDLE
APIENTRY
CreateMutexA(
    LPSECURITY_ATTRIBUTES lpMutexAttributes,
    BOOL bInitialOwner,
    LPSTR lpName
    );
HANDLE
APIENTRY
CreateMutexW(
    LPSECURITY_ATTRIBUTES lpMutexAttributes,
    BOOL bInitialOwner,
    LPWSTR lpName
    );
#ifdef UNICODE
#define CreateMutex CreateMutexW
#else
#define CreateMutex CreateMutexA
#endif // !UNICODE

HANDLE
APIENTRY
OpenMutexA(
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPSTR lpName
    );
HANDLE
APIENTRY
OpenMutexW(
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPWSTR lpName
    );
#ifdef UNICODE
#define OpenMutex OpenMutexW
#else
#define OpenMutex OpenMutexA
#endif // !UNICODE

HANDLE
APIENTRY
CreateEventA(
    LPSECURITY_ATTRIBUTES lpEventAttributes,
    BOOL bManualReset,
    BOOL bInitialState,
    LPSTR lpName
    );
HANDLE
APIENTRY
CreateEventW(
    LPSECURITY_ATTRIBUTES lpEventAttributes,
    BOOL bManualReset,
    BOOL bInitialState,
    LPWSTR lpName
    );
#ifdef UNICODE
#define CreateEvent CreateEventW
#else
#define CreateEvent CreateEventA
#endif // !UNICODE

HANDLE
APIENTRY
OpenEventA(
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPSTR lpName
    );
HANDLE
APIENTRY
OpenEventW(
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPWSTR lpName
    );
#ifdef UNICODE
#define OpenEvent OpenEventW
#else
#define OpenEvent OpenEventA
#endif // !UNICODE

HANDLE
APIENTRY
CreateSemaphoreA(
    LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    LONG lInitialCount,
    LONG lMaximumCount,
    LPSTR lpName
    );
HANDLE
APIENTRY
CreateSemaphoreW(
    LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    LONG lInitialCount,
    LONG lMaximumCount,
    LPWSTR lpName
    );
#ifdef UNICODE
#define CreateSemaphore CreateSemaphoreW
#else
#define CreateSemaphore CreateSemaphoreA
#endif // !UNICODE

HANDLE
APIENTRY
OpenSemaphoreA(
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPSTR lpName
    );
HANDLE
APIENTRY
OpenSemaphoreW(
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPWSTR lpName
    );
#ifdef UNICODE
#define OpenSemaphore OpenSemaphoreW
#else
#define OpenSemaphore OpenSemaphoreA
#endif // !UNICODE

HANDLE
APIENTRY
CreateFileMappingA(
    HANDLE hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    DWORD flProtect,
    DWORD dwMaximumSizeHigh,
    DWORD dwMaximumSizeLow,
    LPSTR lpName
    );
HANDLE
APIENTRY
CreateFileMappingW(
    HANDLE hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    DWORD flProtect,
    DWORD dwMaximumSizeHigh,
    DWORD dwMaximumSizeLow,
    LPWSTR lpName
    );
#ifdef UNICODE
#define CreateFileMapping CreateFileMappingW
#else
#define CreateFileMapping CreateFileMappingA
#endif // !UNICODE

HANDLE
APIENTRY
OpenFileMappingA(
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPSTR lpName
    );
HANDLE
APIENTRY
OpenFileMappingW(
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    LPWSTR lpName
    );
#ifdef UNICODE
#define OpenFileMapping OpenFileMappingW
#else
#define OpenFileMapping OpenFileMappingA
#endif // !UNICODE

DWORD
APIENTRY
GetLogicalDriveStringsA(
    DWORD nBufferLength,
    LPSTR lpBuffer
    );
DWORD
APIENTRY
GetLogicalDriveStringsW(
    DWORD nBufferLength,
    LPWSTR lpBuffer
    );
#ifdef UNICODE
#define GetLogicalDriveStrings GetLogicalDriveStringsW
#else
#define GetLogicalDriveStrings GetLogicalDriveStringsA
#endif // !UNICODE

HANDLE
APIENTRY
LoadLibraryA(
    LPSTR lpLibFileName
    );
HANDLE
APIENTRY
LoadLibraryW(
    LPWSTR lpLibFileName
    );
#ifdef UNICODE
#define LoadLibrary LoadLibraryW
#else
#define LoadLibrary LoadLibraryA
#endif // !UNICODE

DWORD
APIENTRY
GetModuleFileNameA(
    HANDLE hModule,
    LPSTR lpFilename,
    DWORD nSize
    );
DWORD
APIENTRY
GetModuleFileNameW(
    HANDLE hModule,
    LPWSTR lpFilename,
    DWORD nSize
    );
#ifdef UNICODE
#define GetModuleFileName GetModuleFileNameW
#else
#define GetModuleFileName GetModuleFileNameA
#endif // !UNICODE

HANDLE
APIENTRY
GetModuleHandleA(
    LPSTR lpModuleName
    );
HANDLE
APIENTRY
GetModuleHandleW(
    LPWSTR lpModuleName
    );
#ifdef UNICODE
#define GetModuleHandle GetModuleHandleW
#else
#define GetModuleHandle GetModuleHandleA
#endif // !UNICODE

BOOL
APIENTRY
CreateProcessA(
    LPSTR lpApplicationName,
    LPSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPSTR lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
    );
BOOL
APIENTRY
CreateProcessW(
    LPWSTR lpApplicationName,
    LPWSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPWSTR lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
    );
#ifdef UNICODE
#define CreateProcess CreateProcessW
#else
#define CreateProcess CreateProcessA
#endif // !UNICODE

VOID
APIENTRY
FatalAppExitA(
    WORD wAction,
    LPSTR lpMessageText
    );
VOID
APIENTRY
FatalAppExitW(
    WORD wAction,
    LPWSTR lpMessageText
    );
#ifdef UNICODE
#define FatalAppExit FatalAppExitW
#else
#define FatalAppExit FatalAppExitA
#endif // !UNICODE

VOID
APIENTRY
GetStartupInfoA(
    LPSTARTUPINFOA lpStartupInfo
    );
VOID
APIENTRY
GetStartupInfoW(
    LPSTARTUPINFOW lpStartupInfo
    );
#ifdef UNICODE
#define GetStartupInfo GetStartupInfoW
#else
#define GetStartupInfo GetStartupInfoA
#endif // !UNICODE

LPSTR
APIENTRY
GetCommandLineA(
    VOID
    );
LPWSTR
APIENTRY
GetCommandLineW(
    VOID
    );
#ifdef UNICODE
#define GetCommandLine GetCommandLineW
#else
#define GetCommandLine GetCommandLineA
#endif // !UNICODE

DWORD
APIENTRY
GetEnvironmentVariableA(
    LPSTR lpName,
    LPSTR lpBuffer,
    DWORD nSize
    );
DWORD
APIENTRY
GetEnvironmentVariableW(
    LPWSTR lpName,
    LPWSTR lpBuffer,
    DWORD nSize
    );
#ifdef UNICODE
#define GetEnvironmentVariable GetEnvironmentVariableW
#else
#define GetEnvironmentVariable GetEnvironmentVariableA
#endif // !UNICODE

BOOL
APIENTRY
SetEnvironmentVariableA(
    LPSTR lpName,
    LPSTR lpValue
    );
BOOL
APIENTRY
SetEnvironmentVariableW(
    LPWSTR lpName,
    LPWSTR lpValue
    );
#ifdef UNICODE
#define SetEnvironmentVariable SetEnvironmentVariableW
#else
#define SetEnvironmentVariable SetEnvironmentVariableA
#endif // !UNICODE

VOID
APIENTRY
OutputDebugStringA(
    LPSTR lpOutputString
    );
VOID
APIENTRY
OutputDebugStringW(
    LPWSTR lpOutputString
    );
#ifdef UNICODE
#define OutputDebugString OutputDebugStringW
#else
#define OutputDebugString OutputDebugStringA
#endif // !UNICODE

HANDLE
APIENTRY
FindResourceA(
    HANDLE hModule,
    LPSTR lpName,
    LPSTR lpType
    );
HANDLE
APIENTRY
FindResourceW(
    HANDLE hModule,
    LPWSTR lpName,
    LPWSTR lpType
    );
#ifdef UNICODE
#define FindResource FindResourceW
#else
#define FindResource FindResourceA
#endif // !UNICODE

BOOL
APIENTRY
EnumResourceTypesA(
    HANDLE hModule,
    FARPROC lpEnumFunc,
    LONG lParam
    );
BOOL
APIENTRY
EnumResourceTypesW(
    HANDLE hModule,
    FARPROC lpEnumFunc,
    LONG lParam
    );
#ifdef UNICODE
#define EnumResourceTypes EnumResourceTypesW
#else
#define EnumResourceTypes EnumResourceTypesA
#endif // !UNICODE


BOOL
APIENTRY
EnumResourceNamesA(
    HANDLE hModule,
    LPSTR lpType,
    FARPROC lpEnumFunc,
    LONG lParam
    );
BOOL
APIENTRY
EnumResourceNamesW(
    HANDLE hModule,
    LPWSTR lpType,
    FARPROC lpEnumFunc,
    LONG lParam
    );
#ifdef UNICODE
#define EnumResourceNames EnumResourceNamesW
#else
#define EnumResourceNames EnumResourceNamesA
#endif // !UNICODE

ATOM
APIENTRY
GlobalAddAtomA(
    LPSTR lpString
    );
ATOM
APIENTRY
GlobalAddAtomW(
    LPWSTR lpString
    );
#ifdef UNICODE
#define GlobalAddAtom GlobalAddAtomW
#else
#define GlobalAddAtom GlobalAddAtomA
#endif // !UNICODE

ATOM
APIENTRY
GlobalFindAtomA(
    LPSTR lpString
    );
ATOM
APIENTRY
GlobalFindAtomW(
    LPWSTR lpString
    );
#ifdef UNICODE
#define GlobalFindAtom GlobalFindAtomW
#else
#define GlobalFindAtom GlobalFindAtomA
#endif // !UNICODE

DWORD
APIENTRY
GlobalGetAtomNameA(
    ATOM nAtom,
    LPSTR lpBuffer,
    DWORD nSize
    );
DWORD
APIENTRY
GlobalGetAtomNameW(
    ATOM nAtom,
    LPWSTR lpBuffer,
    DWORD nSize
    );
#ifdef UNICODE
#define GlobalGetAtomName GlobalGetAtomNameW
#else
#define GlobalGetAtomName GlobalGetAtomNameA
#endif // !UNICODE

ATOM
APIENTRY
AddAtomA(
    LPSTR lpString
    );
ATOM
APIENTRY
AddAtomW(
    LPWSTR lpString
    );
#ifdef UNICODE
#define AddAtom AddAtomW
#else
#define AddAtom AddAtomA
#endif // !UNICODE

ATOM
APIENTRY
FindAtomA(
    LPSTR lpString
    );
ATOM
APIENTRY
FindAtomW(
    LPWSTR lpString
    );
#ifdef UNICODE
#define FindAtom FindAtomW
#else
#define FindAtom FindAtomA
#endif // !UNICODE

DWORD
APIENTRY
GetAtomNameA(
    ATOM nAtom,
    LPSTR lpBuffer,
    DWORD nSize
    );
DWORD
APIENTRY
GetAtomNameW(
    ATOM nAtom,
    LPWSTR lpBuffer,
    DWORD nSize
    );
#ifdef UNICODE
#define GetAtomName GetAtomNameW
#else
#define GetAtomName GetAtomNameA
#endif // !UNICODE

DWORD
APIENTRY
GetProfileIntA(
    LPSTR lpAppName,
    LPSTR lpKeyName,
    DWORD nDefault
    );
DWORD
APIENTRY
GetProfileIntW(
    LPWSTR lpAppName,
    LPWSTR lpKeyName,
    DWORD nDefault
    );
#ifdef UNICODE
#define GetProfileInt GetProfileIntW
#else
#define GetProfileInt GetProfileIntA
#endif // !UNICODE

DWORD
APIENTRY
GetProfileStringA(
    LPSTR lpAppName,
    LPSTR lpKeyName,
    LPSTR lpDefault,
    LPSTR lpReturnedString,
    DWORD nSize
    );
DWORD
APIENTRY
GetProfileStringW(
    LPWSTR lpAppName,
    LPWSTR lpKeyName,
    LPWSTR lpDefault,
    LPWSTR lpReturnedString,
    DWORD nSize
    );
#ifdef UNICODE
#define GetProfileString GetProfileStringW
#else
#define GetProfileString GetProfileStringA
#endif // !UNICODE

BOOL
APIENTRY
WriteProfileStringA(
    LPSTR lpAppName,
    LPSTR lpKeyName,
    LPSTR lpString
    );
BOOL
APIENTRY
WriteProfileStringW(
    LPWSTR lpAppName,
    LPWSTR lpKeyName,
    LPWSTR lpString
    );
#ifdef UNICODE
#define WriteProfileString WriteProfileStringW
#else
#define WriteProfileString WriteProfileStringA
#endif // !UNICODE

DWORD
APIENTRY
GetProfileSectionA(
    LPSTR lpAppName,
    LPSTR lpReturnedString,
    DWORD nSize
    );
DWORD
APIENTRY
GetProfileSectionW(
    LPWSTR lpAppName,
    LPWSTR lpReturnedString,
    DWORD nSize
    );
#ifdef UNICODE
#define GetProfileSection GetProfileSectionW
#else
#define GetProfileSection GetProfileSectionA
#endif // !UNICODE

DWORD
APIENTRY
WriteProfileSectionA(
    LPSTR lpAppName,
    LPSTR lpString
    );
DWORD
APIENTRY
WriteProfileSectionW(
    LPWSTR lpAppName,
    LPWSTR lpString
    );
#ifdef UNICODE
#define WriteProfileSection WriteProfileSectionW
#else
#define WriteProfileSection WriteProfileSectionA
#endif // !UNICODE

DWORD
APIENTRY
GetPrivateProfileIntA(
    LPSTR lpAppName,
    LPSTR lpKeyName,
    DWORD nDefault,
    LPSTR lpFileName
    );
DWORD
APIENTRY
GetPrivateProfileIntW(
    LPWSTR lpAppName,
    LPWSTR lpKeyName,
    DWORD nDefault,
    LPWSTR lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileInt GetPrivateProfileIntW
#else
#define GetPrivateProfileInt GetPrivateProfileIntA
#endif // !UNICODE

DWORD
APIENTRY
GetPrivateProfileStringA(
    LPSTR lpAppName,
    LPSTR lpKeyName,
    LPSTR lpDefault,
    LPSTR lpReturnedString,
    DWORD nSize,
    LPSTR lpFileName
    );
DWORD
APIENTRY
GetPrivateProfileStringW(
    LPWSTR lpAppName,
    LPWSTR lpKeyName,
    LPWSTR lpDefault,
    LPWSTR lpReturnedString,
    DWORD nSize,
    LPWSTR lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileString GetPrivateProfileStringW
#else
#define GetPrivateProfileString GetPrivateProfileStringA
#endif // !UNICODE

BOOL
APIENTRY
WritePrivateProfileStringA(
    LPSTR lpAppName,
    LPSTR lpKeyName,
    LPSTR lpString,
    LPSTR lpFileName
    );
BOOL
APIENTRY
WritePrivateProfileStringW(
    LPWSTR lpAppName,
    LPWSTR lpKeyName,
    LPWSTR lpString,
    LPWSTR lpFileName
    );
#ifdef UNICODE
#define WritePrivateProfileString WritePrivateProfileStringW
#else
#define WritePrivateProfileString WritePrivateProfileStringA
#endif // !UNICODE

DWORD
APIENTRY
GetPrivateProfileSectionA(
    LPSTR lpAppName,
    LPSTR lpReturnedString,
    DWORD nSize,
    LPSTR lpFileName
    );
DWORD
APIENTRY
GetPrivateProfileSectionW(
    LPWSTR lpAppName,
    LPWSTR lpReturnedString,
    DWORD nSize,
    LPWSTR lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileSection GetPrivateProfileSectionW
#else
#define GetPrivateProfileSection GetPrivateProfileSectionA
#endif // !UNICODE

DWORD
APIENTRY
WritePrivateProfileSectionA(
    LPSTR lpAppName,
    LPSTR lpString,
    LPSTR lpFileName
    );
DWORD
APIENTRY
WritePrivateProfileSectionW(
    LPWSTR lpAppName,
    LPWSTR lpString,
    LPWSTR lpFileName
    );
#ifdef UNICODE
#define WritePrivateProfileSection WritePrivateProfileSectionW
#else
#define WritePrivateProfileSection WritePrivateProfileSectionA
#endif // !UNICODE

DWORD
APIENTRY
GetDriveTypeA(
    LPSTR lpRootPathName
    );
DWORD
APIENTRY
GetDriveTypeW(
    LPWSTR lpRootPathName
    );
#ifdef UNICODE
#define GetDriveType GetDriveTypeW
#else
#define GetDriveType GetDriveTypeA
#endif // !UNICODE

DWORD
APIENTRY
GetSystemDirectoryA(
    LPSTR lpBuffer,
    DWORD nSize
    );
DWORD
APIENTRY
GetSystemDirectoryW(
    LPWSTR lpBuffer,
    DWORD nSize
    );
#ifdef UNICODE
#define GetSystemDirectory GetSystemDirectoryW
#else
#define GetSystemDirectory GetSystemDirectoryA
#endif // !UNICODE

DWORD
APIENTRY
GetTempPathA(
    DWORD nBufferLength,
    LPSTR lpBuffer
    );
DWORD
APIENTRY
GetTempPathW(
    DWORD nBufferLength,
    LPWSTR lpBuffer
    );
#ifdef UNICODE
#define GetTempPath GetTempPathW
#else
#define GetTempPath GetTempPathA
#endif // !UNICODE

WORD
APIENTRY
GetTempFileNameA(
    LPSTR lpPathName,
    LPSTR lpPrefixString,
    WORD wUnique,
    LPSTR lpTempFileName
    );
WORD
APIENTRY
GetTempFileNameW(
    LPWSTR lpPathName,
    LPWSTR lpPrefixString,
    WORD wUnique,
    LPWSTR lpTempFileName
    );
#ifdef UNICODE
#define GetTempFileName GetTempFileNameW
#else
#define GetTempFileName GetTempFileNameA
#endif // !UNICODE

DWORD
APIENTRY
GetWindowsDirectoryA(
    LPSTR lpBuffer,
    DWORD nSize
    );
DWORD
APIENTRY
GetWindowsDirectoryW(
    LPWSTR lpBuffer,
    DWORD nSize
    );
#ifdef UNICODE
#define GetWindowsDirectory GetWindowsDirectoryW
#else
#define GetWindowsDirectory GetWindowsDirectoryA
#endif // !UNICODE

BOOL
APIENTRY
SetCurrentDirectoryA(
    LPSTR lpPathName
    );
BOOL
APIENTRY
SetCurrentDirectoryW(
    LPWSTR lpPathName
    );
#ifdef UNICODE
#define SetCurrentDirectory SetCurrentDirectoryW
#else
#define SetCurrentDirectory SetCurrentDirectoryA
#endif // !UNICODE

DWORD
APIENTRY
GetCurrentDirectoryA(
    DWORD nBufferLength,
    LPSTR lpBuffer
    );
DWORD
APIENTRY
GetCurrentDirectoryW(
    DWORD nBufferLength,
    LPWSTR lpBuffer
    );
#ifdef UNICODE
#define GetCurrentDirectory GetCurrentDirectoryW
#else
#define GetCurrentDirectory GetCurrentDirectoryA
#endif // !UNICODE

BOOL
APIENTRY
GetDiskFreeSpaceA(
    LPSTR lpRootPathName,
    LPDWORD lpSectorsPerCluster,
    LPDWORD lpBytesPerSector,
    LPDWORD lpNumberOfFreeClusters,
    LPDWORD lpTotalNumberOfClusters
    );
BOOL
APIENTRY
GetDiskFreeSpaceW(
    LPWSTR lpRootPathName,
    LPDWORD lpSectorsPerCluster,
    LPDWORD lpBytesPerSector,
    LPDWORD lpNumberOfFreeClusters,
    LPDWORD lpTotalNumberOfClusters
    );
#ifdef UNICODE
#define GetDiskFreeSpace GetDiskFreeSpaceW
#else
#define GetDiskFreeSpace GetDiskFreeSpaceA
#endif // !UNICODE

BOOL
APIENTRY
CreateDirectoryA(
    LPSTR lpPathName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
BOOL
APIENTRY
CreateDirectoryW(
    LPWSTR lpPathName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateDirectory CreateDirectoryW
#else
#define CreateDirectory CreateDirectoryA
#endif // !UNICODE

BOOL
APIENTRY
RemoveDirectoryA(
    LPSTR lpPathName
    );
BOOL
APIENTRY
RemoveDirectoryW(
    LPWSTR lpPathName
    );
#ifdef UNICODE
#define RemoveDirectory RemoveDirectoryW
#else
#define RemoveDirectory RemoveDirectoryA
#endif // !UNICODE

DWORD
APIENTRY
GetFullPathNameA(
    LPSTR lpFileName,
    DWORD nBufferLength,
    LPSTR lpBuffer,
    LPSTR *lpFilePart
    );
DWORD
APIENTRY
GetFullPathNameW(
    LPWSTR lpFileName,
    DWORD nBufferLength,
    LPWSTR lpBuffer,
    LPWSTR *lpFilePart
    );
#ifdef UNICODE
#define GetFullPathName GetFullPathNameW
#else
#define GetFullPathName GetFullPathNameA
#endif // !UNICODE

#define EXPAND_LOCAL_DRIVES


HANDLE
APIENTRY
CreateFileA(
    LPSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
    );
HANDLE
APIENTRY
CreateFileW(
    LPWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
    );
#ifdef UNICODE
#define CreateFile CreateFileW
#else
#define CreateFile CreateFileA
#endif // !UNICODE

BOOL
APIENTRY
SetFileAttributesA(
    LPSTR lpFileName,
    DWORD dwFileAttributes
    );
BOOL
APIENTRY
SetFileAttributesW(
    LPWSTR lpFileName,
    DWORD dwFileAttributes
    );
#ifdef UNICODE
#define SetFileAttributes SetFileAttributesW
#else
#define SetFileAttributes SetFileAttributesA
#endif // !UNICODE

DWORD
APIENTRY
GetFileAttributesA(
    LPSTR lpFileName
    );
DWORD
APIENTRY
GetFileAttributesW(
    LPWSTR lpFileName
    );
#ifdef UNICODE
#define GetFileAttributes GetFileAttributesW
#else
#define GetFileAttributes GetFileAttributesA
#endif // !UNICODE

BOOL
APIENTRY
DeleteFileA(
    LPSTR lpFileName
    );
BOOL
APIENTRY
DeleteFileW(
    LPWSTR lpFileName
    );
#ifdef UNICODE
#define DeleteFile DeleteFileW
#else
#define DeleteFile DeleteFileA
#endif // !UNICODE

HANDLE
APIENTRY
FindFirstFileA(
    LPSTR lpFileName,
    LPWIN32_FIND_DATAA lpFindFileData
    );
HANDLE
APIENTRY
FindFirstFileW(
    LPWSTR lpFileName,
    LPWIN32_FIND_DATAW lpFindFileData
    );
#ifdef UNICODE
#define FindFirstFile FindFirstFileW
#else
#define FindFirstFile FindFirstFileA
#endif // !UNICODE

BOOL
APIENTRY
FindNextFileA(
    HANDLE hFindFile,
    LPWIN32_FIND_DATAA lpFindFileData
    );
BOOL
APIENTRY
FindNextFileW(
    HANDLE hFindFile,
    LPWIN32_FIND_DATAW lpFindFileData
    );
#ifdef UNICODE
#define FindNextFile FindNextFileW
#else
#define FindNextFile FindNextFileA
#endif // !UNICODE

DWORD
APIENTRY
SearchPathA(
    LPSTR lpPath,
    LPSTR lpFileName,
    LPSTR lpExtension,
    DWORD nBufferLength,
    LPSTR lpBuffer,
    LPSTR *lpFilePart
    );
DWORD
APIENTRY
SearchPathW(
    LPWSTR lpPath,
    LPWSTR lpFileName,
    LPWSTR lpExtension,
    DWORD nBufferLength,
    LPWSTR lpBuffer,
    LPWSTR *lpFilePart
    );
#ifdef UNICODE
#define SearchPath SearchPathW
#else
#define SearchPath SearchPathA
#endif // !UNICODE

BOOL
APIENTRY
CopyFileA(
    LPSTR lpExistingFileName,
    LPSTR lpNewFileName,
    BOOL bFailIfExists
    );
BOOL
APIENTRY
CopyFileW(
    LPWSTR lpExistingFileName,
    LPWSTR lpNewFileName,
    BOOL bFailIfExists
    );
#ifdef UNICODE
#define CopyFile CopyFileW
#else
#define CopyFile CopyFileA
#endif // !UNICODE

BOOL
APIENTRY
MoveFileA(
    LPSTR lpExistingFileName,
    LPSTR lpNewFileName
    );
BOOL
APIENTRY
MoveFileW(
    LPWSTR lpExistingFileName,
    LPWSTR lpNewFileName
    );
#ifdef UNICODE
#define MoveFile MoveFileW
#else
#define MoveFile MoveFileA
#endif // !UNICODE

HANDLE
APIENTRY
CreateNamedPipeA(
    LPSTR lpName,
    DWORD dwOpenMode,
    DWORD dwPipeMode,
    DWORD nMaxInstances,
    DWORD nOutBufferSize,
    DWORD nInBufferSize,
    DWORD nDefaultTimeOut,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
HANDLE
APIENTRY
CreateNamedPipeW(
    LPWSTR lpName,
    DWORD dwOpenMode,
    DWORD dwPipeMode,
    DWORD nMaxInstances,
    DWORD nOutBufferSize,
    DWORD nInBufferSize,
    DWORD nDefaultTimeOut,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateNamedPipe CreateNamedPipeW
#else
#define CreateNamedPipe CreateNamedPipeA
#endif // !UNICODE

BOOL
APIENTRY
GetNamedPipeHandleStateA(
    HANDLE hNamedPipe,
    LPDWORD lpState,
    LPDWORD lpCurInstances,
    LPDWORD lpMaxCollectionCount,
    LPDWORD lpCollectDataTimeout,
    LPSTR lpUserName,
    DWORD nMaxUserNameSize
    );
BOOL
APIENTRY
GetNamedPipeHandleStateW(
    HANDLE hNamedPipe,
    LPDWORD lpState,
    LPDWORD lpCurInstances,
    LPDWORD lpMaxCollectionCount,
    LPDWORD lpCollectDataTimeout,
    LPWSTR lpUserName,
    DWORD nMaxUserNameSize
    );
#ifdef UNICODE
#define GetNamedPipeHandleState GetNamedPipeHandleStateW
#else
#define GetNamedPipeHandleState GetNamedPipeHandleStateA
#endif // !UNICODE

BOOL
APIENTRY
CallNamedPipeA(
    LPSTR lpNamedPipeName,
    LPVOID lpInBuffer,
    DWORD nInBufferSize,
    LPVOID lpOutBuffer,
    DWORD nOutBufferSize,
    LPDWORD lpBytesRead,
    DWORD nTimeOut
    );
BOOL
APIENTRY
CallNamedPipeW(
    LPWSTR lpNamedPipeName,
    LPVOID lpInBuffer,
    DWORD nInBufferSize,
    LPVOID lpOutBuffer,
    DWORD nOutBufferSize,
    LPDWORD lpBytesRead,
    DWORD nTimeOut
    );
#ifdef UNICODE
#define CallNamedPipe CallNamedPipeW
#else
#define CallNamedPipe CallNamedPipeA
#endif // !UNICODE

BOOL
APIENTRY
WaitNamedPipeA(
    LPSTR lpNamedPipeName,
    DWORD nTimeOut
    );
BOOL
APIENTRY
WaitNamedPipeW(
    LPWSTR lpNamedPipeName,
    DWORD nTimeOut
    );
#ifdef UNICODE
#define WaitNamedPipe WaitNamedPipeW
#else
#define WaitNamedPipe WaitNamedPipeA
#endif // !UNICODE

BOOL
APIENTRY
GetVolumeInformationA(
    LPSTR lpRootPathName,
    LPSTR lpVolumeNameBuffer,
    DWORD nVolumeNameSize,
    LPDWORD lpVolumeSerialNumber,
    LPDWORD lpMaximumComponentLength,
    LPDWORD lpFileSystemFlags,
    LPSTR lpFileSystemNameBuffer,
    DWORD nFileSystemNameSize
    );
BOOL
APIENTRY
GetVolumeInformationW(
    LPWSTR lpRootPathName,
    LPWSTR lpVolumeNameBuffer,
    DWORD nVolumeNameSize,
    LPDWORD lpVolumeSerialNumber,
    LPDWORD lpMaximumComponentLength,
    LPDWORD lpFileSystemFlags,
    LPWSTR lpFileSystemNameBuffer,
    DWORD nFileSystemNameSize
    );
#ifdef UNICODE
#define GetVolumeInformation GetVolumeInformationW
#else
#define GetVolumeInformation GetVolumeInformationA
#endif // !UNICODE

//
// Private MVDM apis
//

VOID
APIENTRY
VDMOperationStarted(
    IN BOOL IsWowCaller
    );

BOOL
APIENTRY
GetNextVDMCommand(
    PVDMINFO pVDMInfo
    );

VOID
APIENTRY
ExitVDM(
    IN BOOL IsWowCaller,
    IN ULONG iWowTask
    );
//
// Event logging APIs
//
BOOL
APIENTRY
ClearEventLogA (
    IN	HANDLE hEventLog,
    IN	LPSTR	lpBackupFileName
    );
//
// Event logging APIs
//
BOOL
APIENTRY
ClearEventLogW (
    IN	HANDLE hEventLog,
    IN	LPWSTR	lpBackupFileName
    );
#ifdef UNICODE
#define ClearEventLog ClearEventLogW
#else
#define ClearEventLog ClearEventLogA
#endif // !UNICODE

BOOL
APIENTRY
CloseEventLog (
    IN	HANDLE hEventLog
    );

HANDLE
APIENTRY
OpenEventLogA (
    IN	LPSTR	lpUNCServerName,
    IN	LPSTR	lpModuleName
    );
HANDLE
APIENTRY
OpenEventLogW (
    IN	LPWSTR	lpUNCServerName,
    IN	LPWSTR	lpModuleName
    );
#ifdef UNICODE
#define OpenEventLog OpenEventLogW
#else
#define OpenEventLog OpenEventLogA
#endif // !UNICODE

BOOL
APIENTRY
ReadEventLogA (
    IN		HANDLE	hEventLog,
    IN		DWORD	    dwReadFlags,
    IN		DWORD	    dwRecordOffset,
    OUT		LPVOID	    lpBuffer,
    IN		DWORD	    nNumberOfBytesToRead,
    OUT 	DWORD	    *pnBytesRead,
    OUT 	DWORD	    *pnMinNumberOfBytesNeeded
    );
BOOL
APIENTRY
ReadEventLogW (
    IN		HANDLE	hEventLog,
    IN		DWORD	    dwReadFlags,
    IN		DWORD	    dwRecordOffset,
    OUT		LPVOID	    lpBuffer,
    IN		DWORD	    nNumberOfBytesToRead,
    OUT 	DWORD	    *pnBytesRead,
    OUT 	DWORD	    *pnMinNumberOfBytesNeeded
    );
#ifdef UNICODE
#define ReadEventLog ReadEventLogW
#else
#define ReadEventLog ReadEventLogA
#endif // !UNICODE

BOOL
APIENTRY
WriteEventLogEntryA (
    IN		HANDLE	hEventLog,
    IN		WORD	    wType,
    IN		DWORD	    dwEventID,
    IN		PSID	    lpUserSid	    OPTIONAL,
    IN		WORD	    wNumStrings,
    IN		DWORD	    dwDataSize,
    IN		LPSTR	    *lpStrings      OPTIONAL,
    IN		LPVOID	    lpRawData	    OPTIONAL
    );
BOOL
APIENTRY
WriteEventLogEntryW (
    IN		HANDLE	hEventLog,
    IN		WORD	    wType,
    IN		DWORD	    dwEventID,
    IN		PSID	    lpUserSid	    OPTIONAL,
    IN		WORD	    wNumStrings,
    IN		DWORD	    dwDataSize,
    IN		LPWSTR	    *lpStrings      OPTIONAL,
    IN		LPVOID	    lpRawData	    OPTIONAL
    );
#ifdef UNICODE
#define WriteEventLogEntry WriteEventLogEntryW
#else
#define WriteEventLogEntry WriteEventLogEntryA
#endif // !UNICODE
//
// DOS and OS/2 Compatible Error Code definitions returned by the Win32 Base
// API functions.
//

#include <winerror.h>

/* Abnormal termination codes */

#define TC_NORMAL       0
#define TC_HARDERR      1
#define TC_GP_TRAP      2
#define TC_SIGNAL       3

#endif // _WINBASE_
