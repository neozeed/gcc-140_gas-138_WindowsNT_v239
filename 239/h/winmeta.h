/*

Copyright (c) 1985-91, Microsoft Corporation

Module Name:

    winmeta.h

Abstract:

    Procedure declarations, constant definitions and macros for the
    Metafile functions.

Warning:

    This file is TEMPORARY and will be folded into wingdi.h when
    we're allowed to.

--*/


// Metafile constants

#define METAEX_SIGNATURE	0x464D544E	// 'NTMF'

#define METAEX_FORMAT_10000	0x10000 	// Windows NT format
#define METAEX_FORMAT_300	0x300		// Windows 3.x format


// Metafile type definitions

typedef struct tagMETARECORDEX
{
    DWORD   iType;		// Record type MR_XXX
    DWORD   nSize;		// Record size in bytes
    DWORD   dParm[1];		// Parameters
} METARECORDEX, *PMETARECORDEX, *LPMETARECORDEX;

typedef struct tagMETAHEADEREX
{
    DWORD   iType;		// Record type MR_METAFILE
    DWORD   nSize;		// Record size in bytes
    RECTL   rclBounds;		// Inclusive-inclusive bounds in device units
    RECTL   rclFrame;		// Inclusive-inclusive Picture Frame of metafile in .01 mm units
    DWORD   dSignature; 	// Signature.  Must be METAEX_SIGNATURE.
    DWORD   nVersion;		// Version number
    DWORD   nBytes;		// Size of the metafile in bytes
    DWORD   nRecords;		// Number of records in the metafile
    USHORT  nHandles;		// Number of handles in the handle table
				// Handle index zero is reserved.
    USHORT  sReserved;		// Reserved.  Must be zero.
    DWORD   offDescription;	// Offset to the metafile description record.
				// This is zero if there is no metafile description.
    DWORD   nPalEntries;	// Number of entries in the metafile palette.
    DWORD   offPalEntries;	// Offset to the metafile palette record.
				// This is zero if there is no metafile palette.
    SIZEL   szlDevice;		// Size of the reference device in pels
    SIZEL   szlMillimeters;	// Size of the reference device in millimeters
} METAHEADEREX, *PMETAHEADEREX, *LPMETAHEADEREX;


// Metafile Function Declarations

HMF   APIENTRY CloseMetaFileEx(IN HDC hDC);
#ifdef UNICODE
#define CopyMetaFileEx CopyMetaFileExW
#else
#define CopyMetaFileEx CopyMetaFileExA
#endif // !UNICODE
HMF   APIENTRY CopyMetaFileExA(IN HMF,IN LPSTR);
HMF   APIENTRY CopyMetaFileExW(IN HMF,IN LPWSTR);

#ifdef UNICODE
#define CreateMetaFileEx CreateMetaFileExW
#else
#define CreateMetaFileEx CreateMetaFileExA
#endif // !UNICODE
HDC   APIENTRY CreateMetaFileExA(IN HDC, IN LPSTR, IN LPRECT, IN LPSTR);
HDC   APIENTRY CreateMetaFileExW(IN HDC, IN LPWSTR, IN LPRECT, IN LPWSTR);

BOOL  APIENTRY DeleteMetaFileEx(IN HMF);
#ifdef UNICODE
#define GetMetaFileEx GetMetaFileExW
#else
#define GetMetaFileEx GetMetaFileExA
#endif // !UNICODE
HMF   APIENTRY GetMetaFileExA(IN LPSTR psz);
HMF   APIENTRY GetMetaFileExW(IN LPWSTR pwsz);

DWORD APIENTRY GetMetaFileBitsEx(IN HMF, IN DWORD, OUT LPBYTE, IN UINT, IN HDC);
UINT  APIENTRY GetMetaFileHeaderEx(IN HMF, IN UINT, OUT LPMETAHEADEREX OPTIONAL);

#ifdef UNICODE
#define GetMetaFileDescriptionEx GetMetaFileDescriptionExW
#else
#define GetMetaFileDescriptionEx GetMetaFileDescriptionExA
#endif // !UNICODE
UINT  APIENTRY GetMetaFileDescriptionExA(IN HMF, IN UINT, OUT LPSTR OPTIONAL);
UINT  APIENTRY GetMetaFileDescriptionExW(IN HMF, IN UINT, OUT LPWSTR OPTIONAL);

UINT  APIENTRY GetMetaFilePaletteEntriesEx(IN HMF, IN UINT, OUT LPPALETTEENTRY OPTIONAL);
BOOL  APIENTRY EnumMetaFileEx(IN HDC hdc, IN HMF hmf, IN PROC pfn, IN LPVOID pv);
BOOL  APIENTRY PlayMetaFileEx(IN HDC hDC, IN HMF hMF);
BOOL  APIENTRY PlayMetaFileRecordEx(IN HDC, IN LPHANDLETABLE, IN LPMETARECORDEX, IN UINT);
HMF   APIENTRY SetMetaFileBitsEx(IN DWORD, IN LPBYTE, IN HDC OPTIONAL, IN LPMETAFILEPICT OPTIONAL);

BOOL  APIENTRY GdiComment(IN HDC, IN UINT, IN LPBYTE);
