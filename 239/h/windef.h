/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1985-91, Microsoft Corporation

Module Name:

    windef.h

Abstract:

    Type definitions for Windows' basic types.

--*/

#ifndef _WINDEF_
#define _WINDEF_

// BASETYPES is defined in ntdef.h if these types are already defined

#ifndef BASETYPES
#define BASETYPES
typedef unsigned long ULONG;
typedef ULONG *PULONG;
typedef unsigned short USHORT;
typedef USHORT *PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR *PUCHAR;
typedef char *PSZ;
typedef char *PCHAR;

#ifndef THANKS
#define IN
#define OUT
#define OPTIONAL
#endif  // !THANKS

#endif  // !BASETYPES

#ifndef THANKS
#define CRITICAL
#define XXX
#define NEXTCOUNT
#define PREVCOUNT
#define BATCH
#define CHUNKY
#define BREAK
#endif  // !THANKS

#define MAX_PATH          260

#ifndef NULL
#define NULL                0
#endif

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#define far
#define near
#define pascal
#ifdef DOSWIN32
#define cdecl _cdecl
#else
#define cdecl
#endif
#define APIENTRY
#define APIPRIVATE

#define FAR                 far
#define NEAR                near
#define PASCAL              pascal

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef FLOAT               *PFLOAT;
typedef BOOL near           *PBOOL;
typedef BOOL far            *LPBOOL;
typedef char near           *PSTR;
typedef char near           *NPSTR;
typedef char far            *LPSTR;
typedef BYTE near           *PBYTE;
typedef BYTE far            *LPBYTE;
typedef int near            *PINT;
typedef int far             *LPINT;
typedef WORD near           *PWORD;
typedef WORD far            *LPWORD;
typedef long far            *LPLONG;
typedef DWORD near          *PDWORD;
typedef DWORD far           *LPDWORD;
typedef void far            *LPVOID;

typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;

#ifndef NT_INCLUDED
#include <winnt.h>
#endif // NT_INCLUDED

#ifndef NOMINMAX

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#endif  /* NOMINMAX */

#define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))
#define LOWORD(l)           ((WORD)(l))
#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
#define LOBYTE(w)           ((BYTE)(w))
#define HIBYTE(w)           ((BYTE)(((WORD)(w) >> 8) & 0xFF))


#ifndef WIN_INTERNAL
typedef HANDLE              HWND;
typedef HANDLE              HHOOK;
#endif

typedef WORD                ATOM;

typedef HANDLE NEAR         *SPHANDLE;
typedef HANDLE FAR          *LPHANDLE;
typedef HANDLE              GLOBALHANDLE;
typedef HANDLE              LOCALHANDLE;
typedef int (FAR APIENTRY *FARPROC)();      // should be removed some day!!!
typedef int (NEAR APIENTRY *NEARPROC)();
typedef int (APIENTRY *PROC)();             // new 32-bit version

typedef HANDLE  HSTR;
typedef HANDLE  HICON;
typedef HANDLE  HDC;
typedef HANDLE  HWINSTA;
typedef HANDLE  HDESK;
typedef HANDLE  HMENU;
typedef HANDLE  HPEN;
typedef HANDLE  HFONT;
typedef HANDLE  HBRUSH;
typedef HANDLE  HBITMAP;
typedef HANDLE  HCURSOR;
typedef HANDLE  HRGN;
typedef HANDLE  HPALETTE;
typedef HANDLE  HMODULE;
typedef HANDLE  HMF;

typedef DWORD   COLORREF;

typedef struct tagRECT
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT, *PRECT, NEAR *NPRECT, FAR *LPRECT;

typedef struct _RECTL	    /* rcl */
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECTL, *PRECTL;

typedef struct tagPOINT
{
    LONG  x;
    LONG  y;
} POINT, *PPOINT, NEAR *NPPOINT, FAR *LPPOINT;

typedef struct _POINTL      /* ptl  */
{
    LONG  x;
    LONG  y;
} POINTL, *PPOINTL;

typedef struct tagSIZE
{
    LONG        cx;
    LONG        cy;
} SIZE, *PSIZE, *LPSIZE;

typedef SIZE               SIZEL;
typedef SIZE               *PSIZEL;

typedef struct tagPOINTS
{
    SHORT   x;
    SHORT   y;
} POINTS, *PPOINTS, *LPPOINTS;

/* mode selections for the device mode function */
#define DM_UPDATE           1
#define DM_COPY             2
#define DM_PROMPT           4
#define DM_MODIFY           8

#define DM_IN_BUFFER        DM_MODIFY
#define DM_IN_PROMPT        DM_PROMPT
#define DM_OUT_BUFFER       DM_COPY
#define DM_OUT_DEFAULT      DM_UPDATE

/* device capabilities indices */
#define DC_FIELDS           1
#define DC_PAPERS           2
#define DC_PAPERSIZE        3
#define DC_MINEXTENT        4
#define DC_MAXEXTENT        5
#define DC_BINS             6
#define DC_DUPLEX           7
#define DC_SIZE             8
#define DC_EXTRA            9
#define DC_VERSION          10
#define DC_DRIVER           11


#endif // _WINDEF_
