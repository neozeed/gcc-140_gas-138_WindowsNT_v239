/*++

Copyright (c) 1990  Microsoft Corporation

Module Name:

    WinSpool.h

Abstract:

    Header file for Print APIs

Author:

    Dave Snipp (DaveSn) 15-Mar-1991

Revision History:

--*/

#ifndef _WINSPOOL_
#define _WINSPOOL_

typedef struct _PRINTERSERVER {
   HANDLE hProvidor;
   LPSTR lpName;
   LPSTR lpDescription;
   LPSTR lpLocation;
   DWORD cbData;
} PRINTERSERVER, *LPPRINTERSERVER;

typedef struct _PRINTER {
   DWORD Reserved;
   LPPRINTERSERVER lpPrinterServer;
   LPSTR lpPrinterName;
   LPSTR lpPortName;
   LPSTR lpDriverName;
   LPSTR lpComment;
   LPSTR lpLocation;
   LPDEVMODE lpDevMode;
   LPSTR lpSepFile;
   LPSTR lpPrintProcessor;
   LPSTR lpDatatype;
   LPSTR lpParameters;
   LPSTR lpVendorData;
   DWORD Attributes;
   DWORD Priority;
   DWORD DefaultPriority;
   DWORD StartTime;
   DWORD UntilTime;
   DWORD Status;
   DWORD cJobs;
   DWORD AveragePPM;
} PRINTER, *LPPRINTER;

#define PRINTER_CONTROL_PAUSE		 1
#define PRINTER_CONTROL_RESUME		 2
#define PRINTER_CONTROL_PURGE		 3

#define PRINTER_STATUS_PAUSED		 0x00000001
#define PRINTER_STATUS_ERROR		 0x00000002
#define PRINTER_STATUS_PENDING_DELETION  0x00000004

#define PRINTER_ATTRIBUTE_QUEUED	 0x00000001
#define PRINTER_ATTRIBUTE_DIRECT	 0x00000002
#define PRINTER_ATTRIBUTE_DEFAULT	 0x00000004

#define NO_PRIORITY   0
#define MAX_PRIORITY 99
#define MIN_PRIORITY  1
#define DEF_PRIORITY  1

typedef struct _JOB {
   DWORD cVersion;
   DWORD JobId;
   LPPRINTERSERVER lpPrinterServer;
   LPSTR lpPrinterName;
   LPSTR lpUserName;
   LPSTR lpDocument;
   LPSTR lpNotifyName;
   LPSTR lpDatatype;
   LPSTR lpPrintProcessor;
   LPSTR lpParameters;
   LPSTR lpDriverName;
   LPDEVMODE lpDevMode;
   LPSTR lpStatus;
   DWORD Status;
   DWORD Priority;
   DWORD Position;
   DWORD StartTime;
   DWORD UntilTime;
   DWORD TotalPages;
   DWORD Size;
   DWORD Submitted;
   SYSTEMTIME Time;
} JOB, *LPJOB;

#define JOB_CONTROL_PAUSE              1
#define JOB_CONTROL_RESUME             2
#define JOB_CONTROL_CANCEL             3
#define JOB_CONTROL_RESTART            4

#define JOB_STATUS_SPOOLING   0x00000001
#define JOB_STATUS_PRINTING   0x00000002
#define JOB_STATUS_PAUSED     0x00000004
#define JOB_STATUS_ERROR      0x00000008
#define JOB_STATUS_OFFLINE    0x00000010
#define JOB_STATUS_PAPEROUT   0x00000020
#define JOB_STATUS_DELETING   0x00000040

typedef struct _DRIVERINFO {
   DWORD cVersion;
   LPSTR lpDriverName;        // PSCRIPT.QMS 810
   LPSTR lpEnvironment;       // Win32.x86
   LPSTR lpDriverPath;        // c:\drivers\pscript.dll
   LPSTR lpDeviceName;        // QMS 810
   LPSTR lpDataFile;          // QMS810.PPD
   LPSTR lpConfigFile;        // PSCRIPT.EXE
} DRIVERINFO, *LPDRIVERINFO;

BOOL
SetJob(
    IN LPJOB lpJob,
    IN DWORD Command
);

BOOL
GetJob(
   LPPRINTER lpPrinter,
   DWORD JobId,
   LPJOB lpJob,
   DWORD cbBuf,
   LPDWORD pcbNeeded
);

BOOL
EnumJobs(
   LPPRINTER lpPrinter,
   DWORD FirstJob,
   DWORD NoJobs,
   LPJOB lpJob,
   DWORD cbBuf,
   LPDWORD lpcbNeeded,
   LPDWORD lpcReturned
);

BOOL
AddPrinter(
   LPPRINTER lpPrinter
);

BOOL
DeletePrinter(
   LPPRINTER lpPrinter
);

BOOL
SetPrinter(
   LPPRINTER lpPrinter,
   DWORD Command
);

BOOL
GetPrinter(
   LPSTR lpName,
   LPPRINTER lpPrinter,
   DWORD cbBuf,
   LPDWORD pcbNeeded
);

BOOL
EnumPrinters(
   DWORD Type,
   LPPRINTER lpPrinter,
   DWORD cbBuf,
   LPDWORD pcbNeeded,
   LPDWORD lpcReturned
);

BOOL
GetJobFromHandle(
   HANDLE hFile,
   LPJOB lpJob,
   DWORD cbBuf,
   LPDWORD pcbNeeded
);

BOOL
AddPrinterDriver(
   LPPRINTERSERVER lpPrinterServer,
        LPDRIVERINFO lpDriverInfo
);

BOOL
EnumPrinterDrivers(
   LPPRINTERSERVER lpPrinterServer,
   LPSTR    lpEnvironment,
   LPDRIVERINFO   lpDriverInfo,
   DWORD    cbBuf,
   LPDWORD  pcbNeeded,
   LPDWORD  lpcReturned
);

BOOL
GetPrinterDriver(
   LPPRINTER    lpPrinter,
   LPSTR        lpEnvironment,
   LPDRIVERINFO lpDriverInfo,
   DWORD        cbBuf,
   LPDWORD      lpcbNeeded
);

BOOL
AddPrintProcessor(
   LPPRINTERSERVER lpPrinterServer,
   LPSTR lpEnvironment,
   LPSTR lpPathName,
   LPSTR lpName
);

HANDLE
OpenSpooler(
   LPPRINTER lpPrinter
);

BOOL
StartDocSpooler(
   HANDLE   hSpooler
);

BOOL
StartFrameSpooler(
   HANDLE hSpooler
);

BOOL
WriteSpooler(
   HANDLE hSpooler,
   LPVOID pBuf,
   DWORD cbBuf,
   LPDWORD pcWritten
);

BOOL
EndFrameSpooler(
   HANDLE hSpooler
);

BOOL
AbortSpooler(
   HANDLE hSpooler
);

BOOL
ReadSpooler(
   HANDLE hSpooler,
   LPVOID pBuf,
   DWORD cbBuf,
   LPDWORD lpNoBytesRead
);

BOOL
EndDocSpooler(
   HANDLE   hSpooler
);

BOOL
CloseSpooler(
   HANDLE hSpooler
);

BOOL
PrinterProperties(
   HWND  hWnd,
   LPPRINTER   lpPrinter
);

#endif // _WINSPOOL_
