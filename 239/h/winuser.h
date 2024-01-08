/*++ BUILD Version: 0003    // Increment this if a change has global effects

Copyright (c) 1985-91, Microsoft Corporation

Module Name:

    winuser.h

Abstract:

    Procedure declarations, constant definitions and macros for the User
    component.

--*/

#ifndef _WINUSER_
#define _WINUSER_

#ifndef NOUSER

typedef HWND HWNDFF;
typedef HWND HWNDVERBATIM;
typedef HANDLE HACCEL;
typedef HANDLE HWPI;
typedef PVOID LPMONO1BITS;
typedef PVOID LPMONO2BITS;
typedef PVOID LPCOLORBITS;
typedef PWORD LPPRIORITYLIST;
typedef PVOID LPMENUTEMPLATEA;
typedef PVOID LPMENUTEMPLATEW;
#ifdef UNICODE
#define LPMENUTEMPLATE LPMENUTEMPLATEW
#else
#define LPMENUTEMPLATE LPMENUTEMPLATEA
#endif // UNICODE
typedef PVOID LPTABS;
typedef PVOID LPSYSCOLOR;
typedef PVOID LPCOLORVALUES;
typedef PVOID LPDLGTEMPLATESTUBA;
typedef PVOID LPDLGTEMPLATESTUBW;
#ifdef UNICODE
#define LPDLGTEMPLATESTUB LPDLGTEMPLATESTUBW
#else
#define LPDLGTEMPLATESTUB LPDLGTEMPLATESTUBA
#endif // UNICODE
typedef LPSTR   LPSTRNULL;
typedef LPWSTR  LPWSTRNULL;
#ifdef UNICODE
#define LPTSTRNULL LPWSTRNULL
#else
#define LPTSTRNULL LPSTRNULL
#endif // UNICODE
typedef LPSTR   LPSTRID;
typedef LPWSTR  LPWSTRID;
#ifdef UNICODE
#define LPTSTRID LPWSTRID
#else
#define LPTSTRID LPSTRID
#endif // UNICODE
typedef LPSTR   LPSTR2;
typedef LPWSTR  LPWSTR2;
#ifdef UNICODE
#define LPTSTR2 LPWSTR2
#else
#define LPTSTR2 LPSTR2
#endif // UNICODE
typedef LPSTR   OUTLPSTR;
typedef LPWSTR  OUTLPWSTR;
#ifdef UNICODE
#define OUTLPTSTR OUTLPWSTR
#else
#define OUTLPTSTR OUTLPSTR
#endif // UNICODE
typedef HWND HWNDIA;
typedef DWORD GSPOLY;
typedef LPSTR CHNGMENUPOLY;
typedef LPSTR   MENUPOLYA;
typedef LPWSTR  MENUPOLYW;
#ifdef UNICODE
#define MENUPOLY MENUPOLYW
#else
#define MENUPOLY MENUPOLYA
#endif // UNICODE
typedef PVOID LPKEYSTATE;
typedef PVOID OUTLPKEYSTATE;
#ifdef THANKS
typedef PUSHORT OUTP2CHARS;
#else
typedef PVOID OUTP2CHARS;
#endif

typedef LONG (APIENTRY *WNDPROC)(HWND, UINT, DWORD, LONG);

#define MAKEINTRESOURCE(i)  (LPSTR)((DWORD)((WORD)(i)))

#ifndef NORESOURCE

/* Predefined Resource Types */
#define RT_CURSOR           MAKEINTRESOURCE(1)
#define RT_BITMAP           MAKEINTRESOURCE(2)
#define RT_ICON             MAKEINTRESOURCE(3)
#define RT_MENU             MAKEINTRESOURCE(4)
#define RT_DIALOG           MAKEINTRESOURCE(5)
#define RT_STRING           MAKEINTRESOURCE(6)
#define RT_FONTDIR          MAKEINTRESOURCE(7)
#define RT_FONT             MAKEINTRESOURCE(8)
#define RT_ACCELERATOR      MAKEINTRESOURCE(9)
#define RT_RCDATA           MAKEINTRESOURCE(10)
#define RT_MESSAGETABLE     MAKEINTRESOURCE(11)

#define DIFFERENCE  11

/* NOTE: if any new resource types are introduced above this point, then the
** value of DIFFERENCE must be changed.
** (RT_GROUP_CURSOR - RT_CURSOR) must always be equal to DIFFERENCE
** (RT_GROUP_ICON - RT_ICON) must always be equal to DIFFERENCE
*/
#define RT_GROUP_CURSOR     MAKEINTRESOURCE((DWORD)RT_CURSOR + DIFFERENCE)
/* The value RT_BITMAP+DIFFERENCE (13) is intentionally unused */
#define RT_GROUP_ICON       MAKEINTRESOURCE((DWORD)RT_ICON + DIFFERENCE)
/* The value 15 is unused/obsolete */
#define RT_VERSION          MAKEINTRESOURCE(16)

#endif /* NORESOURCE */

int APIENTRY wvsprintf(LPSTR, LPSTR, LPSTR);
int cdecl wsprintf(LPSTR, LPSTR, ...);

#ifndef NOSCROLL

/* Scroll Bar Constants */
#define SB_HORZ             0
#define SB_VERT             1
#define SB_CTL              2
#define SB_BOTH             3

/* Scroll Bar Commands */
#define SB_LINEUP           0
#define SB_LINEDOWN         1
#define SB_PAGEUP           2
#define SB_PAGEDOWN         3
#define SB_THUMBPOSITION    4
#define SB_THUMBTRACK       5
#define SB_TOP              6
#define SB_BOTTOM           7
#define SB_ENDSCROLL        8

#endif /* NOSCROLL */

#ifndef NOSHOWWINDOW

/* ShowWindow() Commands */
#define SW_HIDE             0
#define SW_SHOWNORMAL       1
#define SW_NORMAL           1
#define SW_SHOWMINIMIZED    2
#define SW_SHOWMAXIMIZED    3
#define SW_MAXIMIZE         3
#define SW_SHOWNOACTIVATE   4
#define SW_SHOW             5
#define SW_MINIMIZE         6
#define SW_SHOWMINNOACTIVE  7
#define SW_SHOWNA           8
#define SW_RESTORE          9
#define SW_SHOWDEFAULT      10

/* Old ShowWindow() Commands */
#define HIDE_WINDOW         0
#define SHOW_OPENWINDOW     1
#define SHOW_ICONWINDOW     2
#define SHOW_FULLSCREEN     3
#define SHOW_OPENNOACTIVATE 4

/* Identifiers for the WM_SHOWWINDOW message */
#define SW_PARENTCLOSING    1
#define SW_OTHERZOOM        2
#define SW_PARENTOPENING    3
#define SW_OTHERUNZOOM      4

#endif /* NOSHOWWINDOW */

#ifndef NOVIRTUALKEYCODES

/* Virtual Keys, Standard Set */
#define VK_LBUTTON        0x01
#define VK_RBUTTON        0x02
#define VK_CANCEL         0x03
#define VK_MBUTTON        0x04    /* NOT contiguous with L & RBUTTON */

#define VK_BACK           0x08
#define VK_TAB            0x09

#define VK_CLEAR          0x0C
#define VK_RETURN         0x0D

#define VK_SHIFT          0x10
#define VK_CONTROL        0x11
#define VK_MENU           0x12
#define VK_PAUSE          0x13
#define VK_CAPITAL        0x14

#define VK_ESCAPE         0x1B

#define VK_SPACE          0x20
#define VK_PRIOR          0x21
#define VK_NEXT           0x22
#define VK_END            0x23
#define VK_HOME           0x24
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
/* #define VK_COPY        0x2C not used by keyboards. */
#define VK_INSERT         0x2D
#define VK_DELETE         0x2E
#define VK_HELP           0x2F

/* VK_0 thru VK_9 are the same as ASCII '0' thru '9' (0x30 - 0x39) */
/* VK_A thru VK_Z are the same as ASCII 'A' thru 'Z' (0x41 - 0x5A) */

#define VK_NUMPAD0        0x60
#define VK_NUMPAD1        0x61
#define VK_NUMPAD2        0x62
#define VK_NUMPAD3        0x63
#define VK_NUMPAD4        0x64
#define VK_NUMPAD5        0x65
#define VK_NUMPAD6        0x66
#define VK_NUMPAD7        0x67
#define VK_NUMPAD8        0x68
#define VK_NUMPAD9        0x69
#define VK_MULTIPLY       0x6A
#define VK_ADD            0x6B
#define VK_SEPARATOR      0x6C
#define VK_SUBTRACT       0x6D
#define VK_DECIMAL        0x6E
#define VK_DIVIDE         0x6F
#define VK_F1             0x70
#define VK_F2             0x71
#define VK_F3             0x72
#define VK_F4             0x73
#define VK_F5             0x74
#define VK_F6             0x75
#define VK_F7             0x76
#define VK_F8             0x77
#define VK_F9             0x78
#define VK_F10            0x79
#define VK_F11            0x7A
#define VK_F12            0x7B
#define VK_F13            0x7C
#define VK_F14            0x7D
#define VK_F15            0x7E
#define VK_F16            0x7F
#define VK_F17            0x80
#define VK_F18            0x81
#define VK_F19            0x82
#define VK_F20            0x83
#define VK_F21            0x84
#define VK_F22            0x85
#define VK_F23            0x86
#define VK_F24            0x87

#define VK_NUMLOCK        0x90

/*
 * VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
 * Used only as parameters to GetAsyncKeyState() and GetKeyState().
 * No other API or message will distinguish left and right keys in this way.
 */
#define VK_LSHIFT         0xA0
#define VK_RSHIFT         0xA1
#define VK_LCONTROL       0xA2
#define VK_RCONTROL       0xA3
#define VK_LMENU          0xA4
#define VK_RMENU          0xA5

#define VK_ATTN           0xF6
#define VK_CRSEL          0xF7
#define VK_EXSEL          0xF8
#define VK_EREOF          0xF9
#define VK_PLAY           0xFA
#define VK_ZOOM           0xFB
#define VK_NONAME         0xFC
#define VK_PA1            0xFD
#define VK_OEM_CLEAR      0xFE

#endif /* NOVIRTUALKEYCODES */

#ifndef NOWH

/* SetWindowsHook() codes */
#define WH_MSGFILTER        (-1)
#define WH_JOURNALRECORD    0
#define WH_JOURNALPLAYBACK  1
#define WH_KEYBOARD         2
#define WH_GETMESSAGE       3
#define WH_CALLWNDPROC      4
#define WH_CBT              5
#define WH_SYSMSGFILTER     6
#define WH_MOUSE            7
#define WH_HARDWARE         8
#define WH_DEBUG            9


/* Hook Codes */
#define HC_LPLPFNNEXT       (-2)
#define HC_LPFNNEXT         (-1)
#define HC_ACTION           0
#define HC_GETNEXT          1
#define HC_SKIP             2
#define HC_NOREM            3
#define HC_NOREMOVE         3
#define HC_SYSMODALON       4
#define HC_SYSMODALOFF      5

/* CBT Hook Codes */
#define HCBT_MOVESIZE       0
#define HCBT_MINMAX         1
#define HCBT_QS             2
#define HCBT_CREATEWND      3
#define HCBT_DESTROYWND     4
#define HCBT_ACTIVATE       5
#define HCBT_CLICKSKIPPED   6
#define HCBT_KEYSKIPPED     7
#define HCBT_SYSCOMMAND     8
#define HCBT_SETFOCUS       9

/*
 * HCBT_CREATEWND parameters pointed to by lParam
 */
typedef struct tagCBT_CREATEWNDA
{
    struct tagCREATESTRUCTA *lpcs;
    HWND           hwndInsertAfter;
} CBT_CREATEWNDA, *LPCBT_CREATEWNDA;
/*
 * HCBT_CREATEWND parameters pointed to by lParam
 */
typedef struct tagCBT_CREATEWNDW
{
    struct tagCREATESTRUCTW *lpcs;
    HWND           hwndInsertAfter;
} CBT_CREATEWNDW, *LPCBT_CREATEWNDW;
#ifdef UNICODE
#define CBT_CREATEWND CBT_CREATEWNDW
#define LPCBT_CREATEWND LPCBT_CREATEWNDW
#else
#define CBT_CREATEWND CBT_CREATEWNDA
#define LPCBT_CREATEWND LPCBT_CREATEWNDA
#endif // UNICODE

/* WH_MSGFILTER Filter Proc Codes */
#define MSGF_DIALOGBOX      0
#define MSGF_MESSAGEBOX     1
#define MSGF_MENU           2
#define MSGF_MOVE           3
#define MSGF_SIZE           4
#define MSGF_SCROLLBAR      5
#define MSGF_NEXTWINDOW     6

/* Window Manager Hook Codes */
#define WC_INIT             1
#define WC_SWP              2
#define WC_DEFWINDOWPROC    3
#define WC_MINMAX           4
#define WC_MOVE             5
#define WC_SIZE             6
#define WC_DRAWCAPTION      7

/* Message Structure used in Journaling */
typedef struct tagEVENTMSG {
    DWORD    message;
    DWORD    paramL;
    DWORD    paramH;
    DWORD   time;
} EVENTMSG, *PEVENTMSGMSG, NEAR *NPEVENTMSGMSG, FAR *LPEVENTMSGMSG;

typedef struct tagEVENTMSG *PEVENTMSG, NEAR *NPEVENTMSG, FAR *LPEVENTMSG;

/* Message structure used by WH_CALLWNDPROC */
typedef struct tagCWPSTRUCT {
    LONG    lParam;
    DWORD   wParam;
    DWORD    message;
    HWND    hwnd;
} CWPSTRUCT, *PCWPSTRUCT, NEAR *NPCWPSTRUCT, FAR *LPCWPSTRUCT;

/* Structure used by WH_DEBUG */
typedef struct tagDEBUGHOOKSTRUCT {
    DWORD   idThread;
    DWORD   reserved;
    DWORD   lParam;
    DWORD   wParam;
    int     nCode;
} DEBUGHOOKSTRUCT, *PDEBUGHOOKSTRUCT, NEAR *NPDEBUGHOOKSTRUCT,
        FAR *LPDEBUGHOOKSTRUCT;

typedef struct tagMOUSEHOOKSTRUCT {
    POINT   point;
    HWND    hWnd;
    DWORD    wHitTestCode;
    DWORD   dwExtraInfo;
} MOUSEHOOKSTRUCT, FAR *LPMOUSEHOOKSTRUCT, *PMOUSEHOOKSTRUCT;
#endif /* NOWH */

#ifndef NODESKTOP

/*
 * Desktop-specific access flags
 */
#define DESKTOP_ENUMWINDOWS         0x0001L
#define DESKTOP_CREATEWINDOW        0x0002L
#define DESKTOP_CREATEMENU          0x0004L
#define DESKTOP_HOOKCONTROL         0x0008L
#define DESKTOP_JOURNALRECORD       0x0010L
#define DESKTOP_JOURNALPLAYBACK     0x0020L
#define DESKTOP_ENUMERATE           0x0040L

/*
 * Desktop flags
 */
#define DESKF_SAVEBITS              0x0001L
#define DESKF_TEXTMODE              0x0002L

typedef struct _DESKATTRS {
    DWORD cb;
    DWORD cx;
    DWORD cy;
    DWORD cBitsPixel;
    DWORD dwFlags;
} DESKATTRS, *PDESKATTRS, NEAR *NPDESKATTRS, FAR *LPDESKATTRS;

BOOL
APIENTRY CRITICAL XXX
CreateDesktopA(
    IN LPSTR,
    IN LPSTR,
    IN LPDESKATTRS
    );
BOOL
APIENTRY CRITICAL XXX
CreateDesktopW(
    IN LPWSTR,
    IN LPWSTR,
    IN LPDESKATTRS
    );
#ifdef UNICODE
#define CreateDesktop CreateDesktopW
#else
#define CreateDesktop CreateDesktopA
#endif // !UNICODE

HDESK
APIENTRY CRITICAL XXX
OpenDesktopA(
    IN LPSTR,
    IN DWORD
    );
HDESK
APIENTRY CRITICAL XXX
OpenDesktopW(
    IN LPWSTR,
    IN DWORD
    );
#ifdef UNICODE
#define OpenDesktop OpenDesktopW
#else
#define OpenDesktop OpenDesktopA
#endif // !UNICODE

BOOL APIENTRY CRITICAL XXX SwitchDesktop(IN HDESK);
BOOL APIENTRY CRITICAL SetThreadDesktop(IN HDESK);
HDESK APIENTRY CRITICAL GetThreadDesktop(IN DWORD);
HDESK APIENTRY CRITICAL GetInputDesktop(VOID);
BOOL APIENTRY CRITICAL XXX CloseDesktop(IN HDESK);

BOOL
APIENTRY CRITICAL XXX
EnumDesktopsA(
    IN FARPROC,
    IN LONG
    );
BOOL
APIENTRY CRITICAL XXX
EnumDesktopsW(
    IN FARPROC,
    IN LONG
    );
#ifdef UNICODE
#define EnumDesktops EnumDesktopsW
#else
#define EnumDesktops EnumDesktopsA
#endif // !UNICODE

UINT
APIENTRY CRITICAL
GetDesktopAttrsA(
    IN HDESK,
    NEXTCOUNT IN OUT OUTLPSTR,
    IN UINT,
    OUT LPDESKATTRS OPTIONAL
    );
UINT
APIENTRY CRITICAL
GetDesktopAttrsW(
    IN HDESK,
    NEXTCOUNT IN OUT OUTLPWSTR,
    IN UINT,
    OUT LPDESKATTRS OPTIONAL
    );
#ifdef UNICODE
#define GetDesktopAttrs GetDesktopAttrsW
#else
#define GetDesktopAttrs GetDesktopAttrsA
#endif // !UNICODE

UINT
APIENTRY CRITICAL
GetDesktopTypesA(
    IN LPSTR,
    NEXTCOUNT OUT LPDESKATTRS OPTIONAL,
    IN UINT
    );
UINT
APIENTRY CRITICAL
GetDesktopTypesW(
    IN LPWSTR,
    NEXTCOUNT OUT LPDESKATTRS OPTIONAL,
    IN UINT
    );
#ifdef UNICODE
#define GetDesktopTypes GetDesktopTypesW
#else
#define GetDesktopTypes GetDesktopTypesA
#endif // !UNICODE

BOOL
APIENTRY CRITICAL XXX
EnumDisplayDevicesA(
    IN FARPROC,
    IN LONG
    );
BOOL
APIENTRY CRITICAL XXX
EnumDisplayDevicesW(
    IN FARPROC,
    IN LONG
    );
#ifdef UNICODE
#define EnumDisplayDevices EnumDisplayDevicesW
#else
#define EnumDisplayDevices EnumDisplayDevicesA
#endif // !UNICODE

#endif  /* NODESKTOP */

#ifndef NOWINDOWSTATION

/*
 * Windowstation-specific access flags
 */
#define WINSTA_ENUMDESKTOPS         0x0001L
#define WINSTA_READATTRIBUTES       0x0002L
#define WINSTA_ACCESSCLIPBOARD      0x0004L
#define WINSTA_CREATEDESKTOP        0x0008L
#define WINSTA_WRITEATTRIBUTES      0x0010L
#define WINSTA_ACCESSGLOBALATOMS    0x0020L
#define WINSTA_EXITWINDOWS          0x0040L
#define WINSTA_ENUMERATE            0x0100L
#define WINSTA_READSCREEN           0x0200L

typedef struct _WINSTAATTRS {
    DWORD cb;
} WINSTAATTRS, *PWINSTAATTRS, NEAR *NPWINSTAATTRS, FAR *LPWINSTAATTRS;

HWINSTA
APIENTRY CRITICAL
OpenWindowStationA(
    IN LPSTR,
    IN DWORD
    );
HWINSTA
APIENTRY CRITICAL
OpenWindowStationW(
    IN LPWSTR,
    IN DWORD
    );
#ifdef UNICODE
#define OpenWindowStation OpenWindowStationW
#else
#define OpenWindowStation OpenWindowStationA
#endif // !UNICODE

BOOL APIENTRY CRITICAL SetProcessWindowStation(IN HWINSTA);
HWINSTA APIENTRY CRITICAL GetProcessWindowStation(VOID);
BOOL APIENTRY CRITICAL CloseWindowStation(IN HWINSTA);
BOOL APIENTRY CRITICAL XXX EnumWindowStations(IN FARPROC, IN LONG);

UINT
APIENTRY CRITICAL
GetWindowStationAttrsA(
    IN HWINSTA,
    NEXTCOUNT IN OUT OUTLPSTR,
    IN UINT,
    OUT LPWINSTAATTRS
    );
UINT
APIENTRY CRITICAL
GetWindowStationAttrsW(
    IN HWINSTA,
    NEXTCOUNT IN OUT OUTLPWSTR,
    IN UINT,
    OUT LPWINSTAATTRS
    );
#ifdef UNICODE
#define GetWindowStationAttrs GetWindowStationAttrsW
#else
#define GetWindowStationAttrs GetWindowStationAttrsA
#endif // !UNICODE

#endif  /* NOWINDOWSTATION */

#ifndef NOSECURITY

/*
 * window-specific access flags
 */
#define WIN_ACCESSWINDOW            0x0001L
#define WIN_ENUMERATE               0x0002L

/*
 * menu-specific access flags
 */
#define MENU_ACCESSMENU             0x0001L

BOOL APIENTRY CRITICAL SetObjectSecurity(IN HANDLE, IN PSECURITY_INFORMATION,
        IN PSECURITY_DESCRIPTOR);
BOOL APIENTRY CRITICAL GetObjectSecurity(IN HANDLE, IN PSECURITY_INFORMATION,
        NEXTCOUNT OUT PSECURITY_DESCRIPTOR, IN DWORD, OUT LPDWORD);

#endif  /* NOSECURITY */

typedef struct tagWNDCLASSA {
    DWORD       style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HANDLE      hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    LPSTRID      lpszMenuName;
    LPSTRID      lpszClassName;
} WNDCLASSA, *PWNDCLASSA, NEAR *NPWNDCLASSA, FAR *LPWNDCLASSA;
typedef struct tagWNDCLASSW {
    DWORD       style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HANDLE      hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    LPWSTRID     lpszMenuName;
    LPWSTRID     lpszClassName;
} WNDCLASSW, *PWNDCLASSW, NEAR *NPWNDCLASSW, FAR *LPWNDCLASSW;
#ifdef UNICODE
#define WNDCLASS WNDCLASSW
#define PWNDCLASS PWNDCLASSW
#define NPWNDCLASS NPWNDCLASSW
#define LPWNDCLASS LPWNDCLASSW
#else
#define WNDCLASS WNDCLASSA
#define PWNDCLASS PWNDCLASSA
#define NPWNDCLASS NPWNDCLASSA
#define LPWNDCLASS LPWNDCLASSA
#endif // UNICODE

#ifndef NOMSG

/* Message structure */
typedef struct tagMSG {
    HWND        hwnd;
    DWORD       message;
    DWORD       wParam;
    LONG        lParam;
    DWORD       time;
    POINT       pt;
} MSG, *PMSG, NEAR *NPMSG, FAR *LPMSG;

#define POINTSTOPOINT(pt,pts)  {(pt).x = (SHORT)LOWORD(pts); \
                                (pt).y = (SHORT)HIWORD(pts);}
#define POINTTOPOINTS(pt)      (MAKELONG((short)((pt).x), (short)((pt).y)))


#endif /* NOMSG */

#ifndef NOWINOFFSETS

/* Window field offsets for GetWindowLong() and GetWindowWord() */
#define GWL_WNDPROC         (-4)
#define GWL_HINSTANCE       (-6)
#define GWL_HWNDPARENT      (-8)
#define GWL_STYLE           (-16)
#define GWL_EXSTYLE         (-20)
#define GWL_USERDATA        (-21)
#define GWL_ID              (-12)

/* Class field offsets for GetClassLong() and GetClassWord() */
#define GCL_MENUNAME        (-8)
#define GCL_HBRBACKGROUND   (-10)
#define GCL_HCURSOR         (-12)
#define GCL_HICON           (-14)
#define GCL_HMODULE         (-16)
#define GCL_CBWNDEXTRA      (-18)
#define GCL_CBCLSEXTRA      (-20)
#define GCL_WNDPROC         (-24)
#define GCL_STYLE           (-26)

#endif /* NOWINOFFSETS */

#ifndef NOWINMESSAGES

/* Window Messages */
#define WM_NULL             0x0000
#define WM_CREATE           0x0001
#define WM_DESTROY          0x0002
#define WM_MOVE             0x0003
#define WM_SIZE             0x0005
#define WM_ACTIVATE         0x0006
#define WM_SETFOCUS         0x0007
#define WM_KILLFOCUS        0x0008
#define WM_ENABLE           0x000A
#define WM_SETREDRAW        0x000B
#define WM_SETTEXT          0x000C
#define WM_GETTEXT          0x000D
#define WM_GETTEXTLENGTH    0x000E
#define WM_PAINT            0x000F
#define WM_CLOSE            0x0010
#define WM_QUERYENDSESSION  0x0011
#define WM_QUIT             0x0012
#define WM_QUERYOPEN        0x0013
#define WM_ERASEBKGND       0x0014
#define WM_SYSCOLORCHANGE   0x0015
#define WM_ENDSESSION       0x0016
#define WM_SHOWWINDOW       0x0018
#define WM_WININICHANGE     0x001A
#define WM_DEVMODECHANGE    0x001B
#define WM_ACTIVATEAPP      0x001C
#define WM_FONTCHANGE       0x001D
#define WM_TIMECHANGE       0x001E
#define WM_CANCELMODE       0x001F
#define WM_SETCURSOR        0x0020
#define WM_MOUSEACTIVATE    0x0021
#define WM_CHILDACTIVATE    0x0022
#define WM_QUEUESYNC        0x0023
#define WM_GETMINMAXINFO    0x0024
#define WM_PAINTICON        0x0026
#define WM_ICONERASEBKGND   0x0027
#define WM_NEXTDLGCTL       0x0028
#define WM_SPOOLERSTATUS    0x002A
#define WM_DRAWITEM         0x002B
#define WM_MEASUREITEM      0x002C
#define WM_DELETEITEM       0x002D
#define WM_VKEYTOITEM       0x002E
#define WM_CHARTOITEM       0x002F
#define WM_SETFONT          0x0030
#define WM_GETFONT          0x0031


#define WM_QUERYDRAGICON    0x0037

#define WM_COMPAREITEM      0x0039
#define WM_COMPACTING       0x0041

#define WM_OTHERWINDOWCREATED   0x0042
#define WM_OTHERWINDOWDESTROYED 0x0043
#define WM_COMMNOTIFY           0x0044
#define WM_HOTKEYEVENT          0x0045
#define WM_WINDOWPOSCHANGING    0x0046
#define WM_WINDOWPOSCHANGED     0x0047
#define WM_POWER                0x0048

#define WM_NCCREATE         0x0081
#define WM_NCDESTROY        0x0082
#define WM_NCCALCSIZE       0x0083
#define WM_NCHITTEST        0x0084
#define WM_NCPAINT          0x0085
#define WM_NCACTIVATE       0x0086
#define WM_GETDLGCODE       0x0087
#define WM_NCMOUSEMOVE      0x00A0
#define WM_NCLBUTTONDOWN    0x00A1
#define WM_NCLBUTTONUP      0x00A2
#define WM_NCLBUTTONDBLCLK  0x00A3
#define WM_NCRBUTTONDOWN    0x00A4
#define WM_NCRBUTTONUP      0x00A5
#define WM_NCRBUTTONDBLCLK  0x00A6
#define WM_NCMBUTTONDOWN    0x00A7
#define WM_NCMBUTTONUP      0x00A8
#define WM_NCMBUTTONDBLCLK  0x00A9

#define WM_KEYFIRST         0x0100
#define WM_KEYDOWN          0x0100
#define WM_KEYUP            0x0101
#define WM_CHAR             0x0102
#define WM_DEADCHAR         0x0103
#define WM_SYSKEYDOWN       0x0104
#define WM_SYSKEYUP         0x0105
#define WM_SYSCHAR          0x0106
#define WM_SYSDEADCHAR      0x0107
#define WM_KEYLAST          0x0108

#define WM_INITDIALOG       0x0110
#define WM_COMMAND          0x0111
#define WM_SYSCOMMAND       0x0112
#define WM_TIMER            0x0113
#define WM_HSCROLL          0x0114
#define WM_VSCROLL          0x0115
#define WM_INITMENU         0x0116
#define WM_INITMENUPOPUP    0x0117
#define WM_MENUSELECT       0x011F
#define WM_MENUCHAR         0x0120
#define WM_ENTERIDLE        0x0121

#define WM_CTLCOLORMSGBOX       0x0132
#define WM_CTLCOLOREDIT         0x0133
#define WM_CTLCOLORLISTBOX      0x0134
#define WM_CTLCOLORBTN          0x0135
#define WM_CTLCOLORDLG          0x0136
#define WM_CTLCOLORSCROLLBAR    0x0137
#define WM_CTLCOLORSTATIC       0x0138

#define WM_MOUSEFIRST       0x0200
#define WM_MOUSEMOVE        0x0200
#define WM_LBUTTONDOWN      0x0201
#define WM_LBUTTONUP        0x0202
#define WM_LBUTTONDBLCLK    0x0203
#define WM_RBUTTONDOWN      0x0204
#define WM_RBUTTONUP        0x0205
#define WM_RBUTTONDBLCLK    0x0206
#define WM_MBUTTONDOWN      0x0207
#define WM_MBUTTONUP        0x0208
#define WM_MBUTTONDBLCLK    0x0209
#define WM_MOUSELAST        0x0209

#define WM_PARENTNOTIFY     0x0210
#define WM_MDICREATE        0x0220
#define WM_MDIDESTROY       0x0221
#define WM_MDIACTIVATE      0x0222
#define WM_MDIRESTORE       0x0223
#define WM_MDINEXT          0x0224
#define WM_MDIMAXIMIZE      0x0225
#define WM_MDITILE          0x0226
#define WM_MDICASCADE       0x0227
#define WM_MDIICONARRANGE   0x0228
#define WM_MDIGETACTIVE     0x0229
#define WM_MDISETMENU       0x0230
#define WM_DROPFILES        0x0233

#define WM_CUT              0x0300
#define WM_COPY             0x0301
#define WM_PASTE            0x0302
#define WM_CLEAR            0x0303
#define WM_UNDO             0x0304
#define WM_RENDERFORMAT     0x0305
#define WM_RENDERALLFORMATS 0x0306
#define WM_DESTROYCLIPBOARD 0x0307
#define WM_DRAWCLIPBOARD    0x0308
#define WM_PAINTCLIPBOARD   0x0309
#define WM_VSCROLLCLIPBOARD 0x030A
#define WM_SIZECLIPBOARD    0x030B
#define WM_ASKCBFORMATNAME  0x030C
#define WM_CHANGECBCHAIN    0x030D
#define WM_HSCROLLCLIPBOARD 0x030E
#define WM_QUERYNEWPALETTE  0x030F
#define WM_PALETTEISCHANGING 0x0310
#define WM_PALETTECHANGED   0x0311
#define WM_HOTKEY           0x0312
#define WM_SETFOREGROUND    0x0313

/* NOTE: All Message Numbers below 0x0400 are RESERVED. */

/* Private Window Messages Start Here: */
#define WM_USER             0x0400

#ifndef NONCMESSAGES

/* WM_SYNCTASK Commands */
#define ST_BEGINSWP         0
#define ST_ENDSWP           1

/* WinWhere() Area Codes */
#define HTERROR             (-2)
#define HTTRANSPARENT       (-1)
#define HTNOWHERE           0
#define HTCLIENT            1
#define HTCAPTION           2
#define HTSYSMENU           3
#define HTGROWBOX           4
#define HTSIZE              HTGROWBOX
#define HTMENU              5
#define HTHSCROLL           6
#define HTVSCROLL           7
#define HTREDUCE            8
#define HTZOOM              9
#define HTLEFT              10
#define HTRIGHT             11
#define HTTOP               12
#define HTTOPLEFT           13
#define HTTOPRIGHT          14
#define HTBOTTOM            15
#define HTBOTTOMLEFT        16
#define HTBOTTOMRIGHT       17
#define HTSIZEFIRST         HTLEFT
#define HTSIZELAST          HTBOTTOMRIGHT

#endif /* NONCMESSAGES */

/* WM_MOUSEACTIVATE Return Codes */
#define MA_ACTIVATE         1
#define MA_ACTIVATEANDEAT   2
#define MA_NOACTIVATE       3
#define MA_NOACTIVATEANDEAT 4

UINT
APIENTRY
RegisterWindowMessageA(
    IN LPSTR lpString
    );
UINT
APIENTRY
RegisterWindowMessageW(
    IN LPWSTR lpString
    );
#ifdef UNICODE
#define RegisterWindowMessage RegisterWindowMessageW
#else
#define RegisterWindowMessage RegisterWindowMessageA
#endif // !UNICODE

/* WM_SIZE message wParam values */
#define SIZENORMAL          0
#define SIZEICONIC          1
#define SIZEFULLSCREEN      2
#define SIZEZOOMSHOW        3
#define SIZEZOOMHIDE        4

/* WM_WINDOWPOSCHANGING/CHANGED struct pointed to by lParam */
typedef struct tagWINDOWPOS {
    HWND    hwnd;
    HWND    hwndInsertAfter;
    int     x;
    int     y;
    int     cx;
    int     cy;
    DWORD   flags;
} WINDOWPOS, *LPWINDOWPOS, *PWINDOWPOS;

/* WM_NCCALCSIZE parameter structure */
typedef struct tagNCCALCSIZE_PARAMS {
    RECT       rgrc[3];
    PWINDOWPOS lppos;
} NCCALCSIZE_PARAMS, *LPNCCALCSIZE_PARAMS;

/* WM_NCCALCSIZE "window valid rect" return values */
#define WVR_ALIGNTOP        0x0010
#define WVR_ALIGNLEFT       0x0020
#define WVR_ALIGNBOTTOM     0x0040
#define WVR_ALIGNRIGHT      0x0080
#define WVR_HREDRAW         0x0100
#define WVR_VREDRAW         0x0200
#define WVR_REDRAW          (WVR_HREDRAW | WVR_VREDRAW)
#define WVR_VALIDRECTS      0x0400

#define WVR_MINVALID        WVR_ALIGNTOP        /* ;Internal */
#define WVR_MAXVALID        WVR_VALIDRECTS      /* ;Internal */

#ifndef NOKEYSTATES

/* Key State Masks for Mouse Messages */
#define MK_LBUTTON          0x0001
#define MK_RBUTTON          0x0002
#define MK_SHIFT            0x0004
#define MK_CONTROL          0x0008
#define MK_MBUTTON          0x0010

#endif /* NOKEYSTATES */

#endif /* NOWINMESSAGES */

#ifndef NOWINSTYLES

/* Window Styles */
#define WS_OVERLAPPED       0x00000000L
#define WS_POPUP            0x80000000L
#define WS_CHILD            0x40000000L
#define WS_MINIMIZE         0x20000000L
#define WS_VISIBLE          0x10000000L
#define WS_DISABLED         0x08000000L
#define WS_CLIPSIBLINGS     0x04000000L
#define WS_CLIPCHILDREN     0x02000000L
#define WS_MAXIMIZE         0x01000000L
#define WS_CAPTION          0x00C00000L     /* WS_BORDER | WS_DLGFRAME  */
#define WS_BORDER           0x00800000L
#define WS_DLGFRAME         0x00400000L
#define WS_VSCROLL          0x00200000L
#define WS_HSCROLL          0x00100000L
#define WS_SYSMENU          0x00080000L
#define WS_THICKFRAME       0x00040000L
#define WS_GROUP            0x00020000L
#define WS_TABSTOP          0x00010000L

#define WS_MINIMIZEBOX      0x00020000L
#define WS_MAXIMIZEBOX      0x00010000L

#define WS_TILED            WS_OVERLAPPED
#define WS_ICONIC           WS_MINIMIZE
#define WS_SIZEBOX          WS_THICKFRAME

/* Common Window Styles */
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#define WS_POPUPWINDOW      (WS_POPUP | WS_BORDER | WS_SYSMENU)
#define WS_CHILDWINDOW      (WS_CHILD)

#define WS_TILEDWINDOW      (WS_OVERLAPPEDWINDOW)

/* Extended Window Styles */
#define WS_EX_DLGMODALFRAME  0x00000001L
#define WS_EX_NOPARENTNOTIFY 0x00000004L
#define WS_EX_TOPMOST        0x00000008L
#define WS_EX_ACCEPTFILES    0x00000010L
#define WS_EX_TRANSPARENT    0x00000020L
#define WS_EX_ALLEXSTYLES    (WS_EX_TRANSPARENT | WS_EX_DLGMODALFRAME | WS_EX_DRAGOBJECT | WS_EX_NOPARENTNOTIFY | WS_EX_TOPMOST | WS_EX_ACCEPTFILES) /* ;Internal */

/* Class styles */
#define CS_VREDRAW          0x0001
#define CS_HREDRAW          0x0002
#define CS_KEYCVTWINDOW     0x0004
#define CS_DBLCLKS          0x0008
                        /*  0x0010 - reserved (see user\server\usersrv.h) */
#define CS_OWNDC            0x0020
#define CS_CLASSDC          0x0040
#define CS_PARENTDC         0x0080
#define CS_NOKEYCVT         0x0100
#define CS_NOCLOSE          0x0200
#define CS_SAVEBITS         0x0800
#define CS_BYTEALIGNCLIENT  0x1000
#define CS_BYTEALIGNWINDOW  0x2000
#define CS_GLOBALCLASS      0x4000    /* Global window class */

#endif /* NOWINSTYLES */

#ifndef NOCLIPBOARD

/* Predefined Clipboard Formats */
#define CF_TEXT             1
#define CF_BITMAP           2
#define CF_METAFILEPICT     3
#define CF_SYLK             4
#define CF_DIF              5
#define CF_TIFF             6
#define CF_OEMTEXT          7
#define CF_DIB              8
#define CF_PALETTE          9
#define CF_UNICODETEXT      10

#define CF_OWNERDISPLAY     0x0080
#define CF_DSPTEXT          0x0081
#define CF_DSPBITMAP        0x0082
#define CF_DSPMETAFILEPICT  0x0083

/* "Private" formats don't get GlobalFree()'d */
#define CF_PRIVATEFIRST     0x0200
#define CF_PRIVATELAST      0x02FF

/* "GDIOBJ" formats do get DeleteObject()'d */
#define CF_GDIOBJFIRST      0x0300
#define CF_GDIOBJLAST       0x03FF

#endif /* NOCLIPBOARD */

/*
 * Defines for the fVirt field of the Accelerator table structure.
 */
#define FVIRTKEY  TRUE          /* Assumed to be == TRUE */
#define FNOINVERT 0x02
#define FSHIFT    0x04
#define FCONTROL  0x08
#define FALT      0x10

typedef struct tagACCEL {
    BYTE   fVirt;               /* Also called the flags field */
    WORD   key;
    WORD   cmd;
} ACCEL, *LPACCEL;

typedef struct tagPAINTSTRUCT {
    HDC         hdc;
    BOOL        fErase;
    RECT        rcPaint;
    BOOL        fRestore;
    BOOL        fIncUpdate;
    BYTE        rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct tagCREATESTRUCTA {
    LPVOID      lpCreateParams;
    HANDLE      hInstance;
    HANDLE      hMenu;
    HWND        hwndParent;
    int         cy;
    int         cx;
    int         y;
    int         x;
    LONG        style;
    LPSTRNULL    lpszName;
    LPSTRID      lpszClass;
    DWORD       dwExStyle;
} CREATESTRUCTA, *LPCREATESTRUCTA;
typedef struct tagCREATESTRUCTW {
    LPVOID      lpCreateParams;
    HANDLE      hInstance;
    HANDLE      hMenu;
    HWND        hwndParent;
    int         cy;
    int         cx;
    int         y;
    int         x;
    LONG        style;
    LPWSTRNULL   lpszName;
    LPWSTRID     lpszClass;
    DWORD       dwExStyle;
} CREATESTRUCTW, *LPCREATESTRUCTW;
#ifdef UNICODE
#define CREATESTRUCT CREATESTRUCTW
#define LPCREATESTRUCT LPCREATESTRUCTW
#else
#define CREATESTRUCT CREATESTRUCTA
#define LPCREATESTRUCT LPCREATESTRUCTA
#endif // UNICODE


/* Owner draw control types */
#define ODT_MENU        1
#define ODT_LISTBOX     2
#define ODT_COMBOBOX    3
#define ODT_BUTTON      4

/* Owner draw actions */
#define ODA_DRAWENTIRE  0x0001
#define ODA_SELECT      0x0002
#define ODA_FOCUS       0x0004

/* Owner draw state */
#define ODS_SELECTED    0x0001
#define ODS_GRAYED      0x0002
#define ODS_DISABLED    0x0004
#define ODS_CHECKED     0x0008
#define ODS_FOCUS       0x0010

/* MEASUREITEMSTRUCT for ownerdraw */
typedef struct tagMEASUREITEMSTRUCT {
    DWORD       CtlType;
    DWORD       CtlID;
    DWORD       itemID;
    DWORD       itemWidth;
    DWORD       itemHeight;
    DWORD       itemData;
} MEASUREITEMSTRUCT, NEAR *PMEASUREITEMSTRUCT, FAR *LPMEASUREITEMSTRUCT;


/* DRAWITEMSTRUCT for ownerdraw */
typedef struct tagDRAWITEMSTRUCT {
    DWORD       CtlType;
    DWORD       CtlID;
    DWORD       itemID;
    DWORD       itemAction;
    DWORD       itemState;
    HWND        hwndItem;
    HDC         hDC;
    RECT        rcItem;
    DWORD       itemData;
} DRAWITEMSTRUCT, NEAR *PDRAWITEMSTRUCT, FAR *LPDRAWITEMSTRUCT;

/* DELETEITEMSTRUCT for ownerdraw */
typedef struct tagDELETEITEMSTRUCT {
    DWORD      CtlType;
    DWORD      CtlID;
    DWORD      itemID;
    HWND       hwndItem;
    DWORD      itemData;
} DELETEITEMSTRUCT, NEAR *PDELETEITEMSTRUCT, FAR *LPDELETEITEMSTRUCT;

/* COMPAREITEMSTUCT for ownerdraw sorting */
typedef struct tagCOMPAREITEMSTRUCT {
    DWORD       CtlType;
    DWORD       CtlID;
    HWND        hwndItem;
    DWORD       itemID1;
    DWORD       itemData1;
    DWORD       itemID2;
    DWORD       itemData2;
} COMPAREITEMSTRUCT, NEAR *PCOMPAREITEMSTRUCT, FAR *LPCOMPAREITEMSTRUCT;

#ifndef NOMSG

/* Message Function Templates */
BOOL APIENTRY CRITICAL XXX GetMessage(OUT LPMSG lpMsg,
        IN HWNDVERBATIM hWnd OPTIONAL, IN UINT wMsgFilterMin,
        IN UINT wMsgFilterMax);
BOOL APIENTRY CRITICAL TranslateMessage(IN LPMSG lpMsg);
LONG APIENTRY CRITICAL XXX DispatchMessage(IN LPMSG lpMsg);
BOOL APIENTRY CRITICAL XXX PeekMessage(OUT LPMSG lpMsg,
        IN HWNDVERBATIM hWnd OPTIONAL, IN UINT wMsgFilterMin,
        IN UINT wMsgFilterMax, IN UINT wRemoveMsg);

/* PeekMessage() Options */
#define PM_NOREMOVE         0x0000
#define PM_REMOVE           0x0001
#define PM_NOYIELD          0x0002

#endif /* NOMSG */

BOOL APIENTRY CRITICAL RegisterHotKey(IN HWND hwnd OPTIONAL, IN int id,
        IN UINT fsModifiers, IN UINT vk);
BOOL APIENTRY CRITICAL UnregisterHotKey(IN HWND hwnd OPTIONAL, IN int id);

#define MOD_ALT         0x0001
#define MOD_CONTROL     0x0002
#define MOD_SHIFT       0x0004

#define IDHOT_SNAPWINDOW        (-1)    /* SHIFT-PRINTSCRN  */
#define IDHOT_SNAPDESKTOP       (-2)    /* PRINTSCRN        */

#ifdef WIN_INTERNAL
    #ifndef LSTRING
    #define NOLSTRING
    #endif
    #ifndef LFILEIO
    #define NOLFILEIO
    #endif
#endif


BOOL  APIENTRY CRITICAL ExitWindows(IN DWORD dwReserved, IN UINT wReturnCode);

BOOL  APIENTRY CRITICAL SwapMouseButton(IN BOOL);
DWORD APIENTRY CRITICAL GetMessagePos(void);
LONG  APIENTRY CRITICAL GetMessageTime(void);
LONG  APIENTRY CRITICAL GetMessageExtraInfo(void);

LONG  APIENTRY CRITICAL XXX SendMessageA(IN HWNDFF hWnd, IN UINT wMsg,
        IN DWORD wParam, IN LONG lParam);
LONG  APIENTRY CRITICAL XXX SendMessageW(IN HWNDFF hWnd, IN UINT wMsg,
        IN DWORD wParam, IN LONG lParam);
#ifdef UNICODE
#define SendMessage SendMessageW
#else
#define SendMessage SendMessageA
#endif // !UNICODE
BOOL  APIENTRY CRITICAL XXX SendNotifyMessage(IN HWND hwnd, IN UINT wMsg,
        IN DWORD wParam, IN LONG lParam);
BOOL  APIENTRY CRITICAL PostMessage(IN HWNDFF hWnd, IN UINT wMsg,
        IN DWORD wParam, IN LONG lParam);
BOOL  APIENTRY CRITICAL PostThreadMessage(IN DWORD idThread, IN UINT wMsg,
        IN DWORD wParam, IN LONG lParam);
#define PostAppMessage(idThread, wMsg, wParam, lParam)\
        PostThreadMessage((DWORD)idThread, wMsg, wParam, lParam)
BOOL  APIENTRY CRITICAL ReplyMessage(IN LONG);
BOOL  APIENTRY CRITICAL XXX WaitMessage(void);
DWORD APIENTRY WaitForInputIdle(HANDLE hProcess, DWORD dwMilliseconds);
LONG  APIENTRY CRITICAL XXX DefWindowProcA(IN HWND hWnd, IN UINT wMsg,
        IN DWORD wParam, IN LONG lParam);
LONG  APIENTRY CRITICAL XXX DefWindowProcW(IN HWND hWnd, IN UINT wMsg,
        IN DWORD wParam, IN LONG lParam);
#ifdef UNICODE
#define DefWindowProc DefWindowProcW
#else
#define DefWindowProc DefWindowProcA
#endif // !UNICODE
BOOL  APIENTRY CRITICAL PostQuitMessage(IN int nExitCode);
LONG  APIENTRY CRITICAL XXX CallWindowProcA(IN WNDPROC lpPrevWndFunc,
        IN HWND hWnd, IN UINT wMsg, IN DWORD wParam, IN LONG lParam);
LONG  APIENTRY CRITICAL XXX CallWindowProcW(IN WNDPROC lpPrevWndFunc,
        IN HWND hWnd, IN UINT wMsg, IN DWORD wParam, IN LONG lParam);
#ifdef UNICODE
#define CallWindowProc CallWindowProcW
#else
#define CallWindowProc CallWindowProcA
#endif // !UNICODE
BOOL  APIENTRY CRITICAL InSendMessage(void);

UINT APIENTRY CRITICAL GetDoubleClickTime(void);
BOOL  APIENTRY CRITICAL SetDoubleClickTime(IN UINT);

BOOL
APIENTRY CRITICAL
RegisterClassA(
    IN LPWNDCLASSA lpWndClass
    );
BOOL
APIENTRY CRITICAL
RegisterClassW(
    IN LPWNDCLASSW lpWndClass
    );
#ifdef UNICODE
#define RegisterClass RegisterClassW
#else
#define RegisterClass RegisterClassA
#endif // !UNICODE

BOOL
APIENTRY CRITICAL
UnregisterClassA(
    IN LPSTRID lpClassName,
    IN HANDLE hInstance
    );
BOOL
APIENTRY CRITICAL
UnregisterClassW(
    IN LPWSTRID lpClassName,
    IN HANDLE hInstance
    );
#ifdef UNICODE
#define UnregisterClass UnregisterClassW
#else
#define UnregisterClass UnregisterClassA
#endif // !UNICODE

BOOL
APIENTRY CRITICAL
GetClassInfoA(
    IN HANDLE hInstance OPTIONAL,
    IN LPSTRID lpClassName,
    OUT LPWNDCLASSA lpWndClass
    );
BOOL
APIENTRY CRITICAL
GetClassInfoW(
    IN HANDLE hInstance OPTIONAL,
    IN LPWSTRID lpClassName,
    OUT LPWNDCLASSW lpWndClass
    );
#ifdef UNICODE
#define GetClassInfo GetClassInfoW
#else
#define GetClassInfo GetClassInfoA
#endif // !UNICODE

#define CW_USEDEFAULT       ((int)0x80000000)

HWND
APIENTRY CRITICAL XXX
CreateWindowExA(
    IN DWORD dwExStyle,
    IN LPSTRID lpClassName,
    IN LPSTRID lpWindowName,
    IN DWORD dwStyle,
    IN int X,
    IN int Y,
    IN int nWidth,
    IN int nHeight,
    IN HWND hWndParent OPTIONAL,
    IN HMENU hMenu,
    IN HANDLE hInstance,
    IN LPVOID lpParam OPTIONAL
    );
HWND
APIENTRY CRITICAL XXX
CreateWindowExW(
    IN DWORD dwExStyle,
    IN LPWSTRID lpClassName,
    IN LPWSTRID lpWindowName,
    IN DWORD dwStyle,
    IN int X,
    IN int Y,
    IN int nWidth,
    IN int nHeight,
    IN HWND hWndParent OPTIONAL,
    IN HMENU hMenu,
    IN HANDLE hInstance,
    IN LPVOID lpParam OPTIONAL
    );
#ifdef UNICODE
#define CreateWindowEx CreateWindowExW
#else
#define CreateWindowEx CreateWindowExA
#endif // !UNICODE

#define CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y,\
nWidth, nHeight, hwndParent, hMenu, hInstance, lpParam)\
CreateWindowExA(0L, lpClassName, lpWindowName, dwStyle, x, y,\
nWidth, nHeight, hwndParent, hMenu, hInstance, lpParam)
#define CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y,\
nWidth, nHeight, hwndParent, hMenu, hInstance, lpParam)\
CreateWindowExW(0L, lpClassName, lpWindowName, dwStyle, x, y,\
nWidth, nHeight, hwndParent, hMenu, hInstance, lpParam)
#ifdef UNICODE
#define CreateWindow CreateWindowW
#else
#define CreateWindow CreateWindowA
#endif // !UNICODE

BOOL APIENTRY CRITICAL IsWindow(IN HWNDVERBATIM hWnd);
BOOL APIENTRY CRITICAL IsChild(IN HWND hWndParent, IN HWND hWnd);
BOOL APIENTRY CRITICAL XXX DestroyWindow(IN HWND hWnd);

BOOL APIENTRY CRITICAL XXX ShowWindow(IN HWND hWnd, IN int nCmdShow);
BOOL APIENTRY CRITICAL XXX FlashWindow(IN HWND hWnd, IN BOOL bInvert);
BOOL APIENTRY CRITICAL XXX ShowOwnedPopups(IN HWND hWnd, IN BOOL fShow);

BOOL APIENTRY CRITICAL XXX OpenIcon(IN HWND hWnd);
BOOL APIENTRY CRITICAL XXX CloseWindow(IN HWND hWnd);
BOOL APIENTRY CRITICAL XXX MoveWindow(IN HWND hWnd, IN int X, IN int Y, IN int nWidth, IN int nHeight, IN BOOL bRepaint);
BOOL APIENTRY CRITICAL XXX SetWindowPos(IN HWND hWnd, IN HWNDIA hWndInsertAfter OPTIONAL, IN int X, IN int Y, IN int cx, IN int cy, IN UINT wFlags);

#ifndef NODEFERWINDOWPOS

HWPI APIENTRY CRITICAL BeginDeferWindowPos(IN int nNumWindows);
HWPI APIENTRY CRITICAL DeferWindowPos(IN HWPI hWinPosInfo, IN HWND hWnd, IN HWNDIA hWndInsertAfter OPTIONAL, IN int x, IN int y, IN int cx, IN int cy, IN UINT wFlags);
BOOL APIENTRY CRITICAL XXX EndDeferWindowPos(IN HWPI hWinPosInfo);

#endif /* NODEFERWINDOWPOS */

BOOL APIENTRY CRITICAL IsWindowVisible(IN HWND hWnd);
BOOL APIENTRY CRITICAL IsIconic(IN HWND hWnd);
BOOL APIENTRY CRITICAL AnyPopup(void);
BOOL APIENTRY CRITICAL XXX BringWindowToTop(IN HWND hWnd);
BOOL APIENTRY CRITICAL IsZoomed(IN HWND hWnd);

/* SetWindowPos Flags */
#define SWP_NOSIZE          0x0001
#define SWP_NOMOVE          0x0002
#define SWP_NOZORDER        0x0004
#define SWP_NOREDRAW        0x0008
#define SWP_NOACTIVATE      0x0010
#define SWP_FRAMECHANGED    0x0020  /* The frame changed: send WM_NCCALCSIZE */
#define SWP_SHOWWINDOW      0x0040
#define SWP_HIDEWINDOW      0x0080
#define SWP_NOCOPYBITS      0x0100
#define SWP_NOOWNERZORDER   0x0200  /* Don't do owner Z ordering */

#define SWP_DRAWFRAME       SWP_FRAMECHANGED
#define SWP_NOREPOSITION    SWP_NOOWNERZORDER

#define SWP_NOCLIENTSIZE    0x0800  /* Client didn't resize */  /* ;Internal */
#define SWP_NOCLIENTMOVE    0x1000  /* Client didn't move   */  /* ;Internal */
#define SWP_NOSENDCHANGING  0x0400  /* Don't send WM_WINDOWPOSCHANGING */ /* ;Internal */
#define SWP_DEFERDRAWING    0x2000  /* Don't do any drawing or erasing */ /* ;Internal */
                                                                      /* ;Internal */
#define SWP_CHANGEMASK      (SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | /* ;Internal */ \
                            SWP_FRAMECHANGED |                        /* ;Internal */ \
                            SWP_SHOWWINDOW | SWP_HIDEWINDOW |         /* ;Internal */ \
                            SWP_NOCLIENTSIZE | SWP_NOCLIENTMOVE)      /* ;Internal */
                                                                      /* ;Internal */
#define SWP_NOCHANGE        (SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | /* ;Internal */ \
                            SWP_NOCLIENTSIZE | SWP_NOCLIENTMOVE)      /* ;Internal */

#ifndef NOCTLMGR

HWND
APIENTRY CRITICAL
CreateDialogParamA(
    IN HANDLE hInstance,
    IN LPSTRID lpTemplateName,
    IN HWND hWndParent OPTIONAL,
    IN WNDPROC lpDialogFunc,
    IN LONG dwInitParam
    );
HWND
APIENTRY CRITICAL
CreateDialogParamW(
    IN HANDLE hInstance,
    IN LPWSTRID lpTemplateName,
    IN HWND hWndParent OPTIONAL,
    IN WNDPROC lpDialogFunc,
    IN LONG dwInitParam
    );
#ifdef UNICODE
#define CreateDialogParam CreateDialogParamW
#else
#define CreateDialogParam CreateDialogParamA
#endif // !UNICODE

HWND
APIENTRY CRITICAL
CreateDialogIndirectParamA(
    IN HANDLE hInstance,
    IN LPDLGTEMPLATESTUBA lpTemplate,
    IN HWND hWndParent OPTIONAL,
    IN WNDPROC lpDialogFunc,
    IN LONG dwInitParam
    );
HWND
APIENTRY CRITICAL
CreateDialogIndirectParamW(
    IN HANDLE hInstance,
    IN LPDLGTEMPLATESTUBW lpTemplate,
    IN HWND hWndParent OPTIONAL,
    IN WNDPROC lpDialogFunc,
    IN LONG dwInitParam
    );
#ifdef UNICODE
#define CreateDialogIndirectParam CreateDialogIndirectParamW
#else
#define CreateDialogIndirectParam CreateDialogIndirectParamA
#endif // !UNICODE

#define CreateDialogA(hInstance, lpName, hwndParent, lpDialogFunc) \
CreateDialogParamA(hInstance, lpName, hwndParent, lpDialogFunc, 0L)
#define CreateDialogW(hInstance, lpName, hwndParent, lpDialogFunc) \
CreateDialogParamW(hInstance, lpName, hwndParent, lpDialogFunc, 0L)
#ifdef UNICODE
#define CreateDialog CreateDialogW
#else
#define CreateDialog CreateDialogA
#endif // !UNICODE

#define CreateDialogIndirectA(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
CreateDialogIndirectParamA(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0L)
#define CreateDialogIndirectW(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
CreateDialogIndirectParamW(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0L)
#ifdef UNICODE
#define CreateDialogIndirect CreateDialogIndirectW
#else
#define CreateDialogIndirect CreateDialogIndirectA
#endif // !UNICODE

int
APIENTRY CRITICAL
DialogBoxParamA(
    IN HANDLE hInstance,
    IN LPSTRID lpTemplateName,
    IN HWND hWndParent OPTIONAL,
    IN WNDPROC lpDialogFunc,
    IN LONG dwInitParam
    );
int
APIENTRY CRITICAL
DialogBoxParamW(
    IN HANDLE hInstance,
    IN LPWSTRID lpTemplateName,
    IN HWND hWndParent OPTIONAL,
    IN WNDPROC lpDialogFunc,
    IN LONG dwInitParam
    );
#ifdef UNICODE
#define DialogBoxParam DialogBoxParamW
#else
#define DialogBoxParam DialogBoxParamA
#endif // !UNICODE

int
APIENTRY CRITICAL
DialogBoxIndirectParamA(
    IN HANDLE hInstance,
    IN LPDLGTEMPLATESTUBA hDialogTemplate,
    IN HWND hWndParent OPTIONAL,
    IN WNDPROC lpDialogFunc,
    IN LONG dwInitParam
    );
int
APIENTRY CRITICAL
DialogBoxIndirectParamW(
    IN HANDLE hInstance,
    IN LPDLGTEMPLATESTUBW hDialogTemplate,
    IN HWND hWndParent OPTIONAL,
    IN WNDPROC lpDialogFunc,
    IN LONG dwInitParam
    );
#ifdef UNICODE
#define DialogBoxIndirectParam DialogBoxIndirectParamW
#else
#define DialogBoxIndirectParam DialogBoxIndirectParamA
#endif // !UNICODE

#define DialogBoxA(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
DialogBoxParamA(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0L)
#define DialogBoxW(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
DialogBoxParamW(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0L)
#ifdef UNICODE
#define DialogBox DialogBoxW
#else
#define DialogBox DialogBoxA
#endif // !UNICODE

#define DialogBoxIndirectA(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
DialogBoxIndirectParamA(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0L)
#define DialogBoxIndirectW(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
DialogBoxIndirectParamW(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0L)
#ifdef UNICODE
#define DialogBoxIndirect DialogBoxIndirectW
#else
#define DialogBoxIndirect DialogBoxIndirectA
#endif // !UNICODE

BOOL APIENTRY CRITICAL XXX EndDialog(IN HWND hDlg, IN int nResult);
HWND APIENTRY CRITICAL GetDlgItem(IN HWND hDlg, IN int nIDDlgItem);
BOOL APIENTRY CRITICAL XXX SetDlgItemInt(IN HWND hDlg, IN int nIDDlgItem,
        IN int wValue, IN BOOL bSigned);
int  APIENTRY CRITICAL XXX GetDlgItemInt(IN HWNDVERBATIM hDlg, IN int nIDDlgItem,
        OUT BOOL *lpTranslated OPTIONAL, IN BOOL bSigned);

BOOL
APIENTRY CRITICAL XXX
SetDlgItemTextA(
    IN HWND hDlg,
    IN int nIDDlgItem,
    IN LPSTR lpString OPTIONAL
    );
BOOL
APIENTRY CRITICAL XXX
SetDlgItemTextW(
    IN HWND hDlg,
    IN int nIDDlgItem,
    IN LPWSTR lpString OPTIONAL
    );
#ifdef UNICODE
#define SetDlgItemText SetDlgItemTextW
#else
#define SetDlgItemText SetDlgItemTextA
#endif // !UNICODE

int
APIENTRY CRITICAL XXX
GetDlgItemTextA(
    IN HWND hDlg,
    IN int nIDDlgItem,
    NEXTCOUNT IN OUT OUTLPSTR lpString,
    IN int nMaxCount
    );
int
APIENTRY CRITICAL XXX
GetDlgItemTextW(
    IN HWND hDlg,
    IN int nIDDlgItem,
    NEXTCOUNT IN OUT OUTLPWSTR lpString,
    IN int nMaxCount
    );
#ifdef UNICODE
#define GetDlgItemText GetDlgItemTextW
#else
#define GetDlgItemText GetDlgItemTextA
#endif // !UNICODE

BOOL APIENTRY CRITICAL XXX CheckDlgButton(IN HWND hDlg, IN int nIDButton,
        IN UINT wCheck);
BOOL APIENTRY CRITICAL XXX CheckRadioButton(IN HWND hDlg, IN int nIDFirstButton,
        IN int nIDLastButton, IN int nIDCheckButton);
UINT APIENTRY CRITICAL XXX IsDlgButtonChecked(IN HWND hDlg, IN int nIDButton);
LONG APIENTRY CRITICAL XXX SendDlgItemMessageA(IN HWND hDlg, IN int nIDDlgItem,
        IN UINT wMsg, IN DWORD wParam, IN LONG lParam);
LONG APIENTRY CRITICAL XXX SendDlgItemMessageW(IN HWND hDlg, IN int nIDDlgItem,
        IN UINT wMsg, IN DWORD wParam, IN LONG lParam);
#ifdef UNICODE
#define SendDlgItemMessage SendDlgItemMessageW
#else
#define SendDlgItemMessage SendDlgItemMessageA
#endif // !UNICODE
HWND APIENTRY CRITICAL GetNextDlgGroupItem(IN HWND hDlg, IN HWND hCtl,
        IN BOOL bPrevious);
HWND APIENTRY CRITICAL GetNextDlgTabItem(IN HWND hDlg, IN HWND hCtl,
        IN BOOL bPrevious);
int  APIENTRY CRITICAL GetDlgCtrlID(IN HWND hWnd);
long APIENTRY CRITICAL GetDialogBaseUnits(void);
LONG APIENTRY CRITICAL XXX DefDlgProcA(IN HWND hDlg, IN UINT wMsg,
        IN DWORD wParam, IN LONG lParam);
LONG APIENTRY CRITICAL XXX DefDlgProcW(IN HWND hDlg, IN UINT wMsg,
        IN DWORD wParam, IN LONG lParam);
#ifdef UNICODE
#define DefDlgProc DefDlgProcW
#else
#define DefDlgProc DefDlgProcA
#endif // !UNICODE

/*
 * Window extra byted needed for private dialog classes.
 */
#define DLGWINDOWEXTRA 30

#endif /* NOCTLMGR */

#ifndef NOMSG
BOOL APIENTRY CRITICAL CallMsgFilter(IN LPMSG lpMsg, IN int nCode);
#endif

#ifndef NOCLIPBOARD

/* Clipboard Manager Functions */
BOOL   APIENTRY CRITICAL OpenClipboard(IN HWND hWnd);
BOOL   APIENTRY CRITICAL XXX CloseClipboard(void);
HWND   APIENTRY CRITICAL GetClipboardOwner(void);
HWND   APIENTRY CRITICAL XXX SetClipboardViewer(IN HWND OPTIONAL);
HWND   APIENTRY CRITICAL GetClipboardViewer(void);
BOOL   APIENTRY CRITICAL XXX ChangeClipboardChain(IN HWND, IN HWND OPTIONAL);
HANDLE APIENTRY CRITICAL SetClipboardData(IN UINT wFormat, IN HANDLE hMem);
HANDLE APIENTRY CRITICAL XXX GetClipboardData(IN UINT wFormat);

UINT
APIENTRY CRITICAL
RegisterClipboardFormatA(
    IN LPSTR
    );
UINT
APIENTRY CRITICAL
RegisterClipboardFormatW(
    IN LPWSTR
    );
#ifdef UNICODE
#define RegisterClipboardFormat RegisterClipboardFormatW
#else
#define RegisterClipboardFormat RegisterClipboardFormatA
#endif // !UNICODE

int    APIENTRY CRITICAL CountClipboardFormats(void);
UINT APIENTRY CRITICAL EnumClipboardFormats(IN UINT);

int
APIENTRY CRITICAL
GetClipboardFormatNameA(
    IN UINT,
    NEXTCOUNT IN OUT OUTLPSTR,
    IN int
    );
int
APIENTRY CRITICAL
GetClipboardFormatNameW(
    IN UINT,
    NEXTCOUNT IN OUT OUTLPWSTR,
    IN int
    );
#ifdef UNICODE
#define GetClipboardFormatName GetClipboardFormatNameW
#else
#define GetClipboardFormatName GetClipboardFormatNameA
#endif // !UNICODE

BOOL   APIENTRY CRITICAL XXX EmptyClipboard(void);
BOOL   APIENTRY CRITICAL IsClipboardFormatAvailable(IN UINT);
int    APIENTRY CRITICAL GetPriorityClipboardFormat(NEXTCOUNT IN LPPRIORITYLIST, IN int);

#endif /* NOCLIPBOARD */


/* Character Translation Routines */

BOOL
APIENTRY
CharToOemA(
    IN LPSTR,
    OUT LPSTR
    );
BOOL
APIENTRY
CharToOemW(
    IN LPWSTR,
    OUT LPSTR
    );
#ifdef UNICODE
#define CharToOem CharToOemW
#else
#define CharToOem CharToOemA
#endif // !UNICODE

BOOL
APIENTRY
OemToCharA(
    IN LPSTR,
    OUT LPSTR
    );
BOOL
APIENTRY
OemToCharW(
    IN LPSTR,
    OUT LPWSTR
    );
#ifdef UNICODE
#define OemToChar OemToCharW
#else
#define OemToChar OemToCharA
#endif // !UNICODE

BOOL
APIENTRY
CharToOemBuffA(
    IN LPSTR,
    OUT LPSTR,
    IN DWORD
    );
BOOL
APIENTRY
CharToOemBuffW(
    IN LPWSTR,
    OUT LPSTR,
    IN DWORD
    );
#ifdef UNICODE
#define CharToOemBuff CharToOemBuffW
#else
#define CharToOemBuff CharToOemBuffA
#endif // !UNICODE

BOOL
APIENTRY
OemToCharBuffA(
    IN LPSTR,
    OUT LPSTR,
    IN DWORD
    );
BOOL
APIENTRY
OemToCharBuffW(
    IN LPSTR,
    OUT LPWSTR,
    IN DWORD
    );
#ifdef UNICODE
#define OemToCharBuff OemToCharBuffW
#else
#define OemToCharBuff OemToCharBuffA
#endif // !UNICODE

LPSTR
APIENTRY
CharUpperA(
    IN LPSTR
    );
LPWSTR
APIENTRY
CharUpperW(
    IN LPWSTR
    );
#ifdef UNICODE
#define CharUpper CharUpperW
#else
#define CharUpper CharUpperA
#endif // !UNICODE

DWORD
APIENTRY
CharUpperBuffA(
    NEXTCOUNT IN LPSTR,
    IN DWORD
    );
DWORD
APIENTRY
CharUpperBuffW(
    NEXTCOUNT IN LPWSTR,
    IN DWORD
    );
#ifdef UNICODE
#define CharUpperBuff CharUpperBuffW
#else
#define CharUpperBuff CharUpperBuffA
#endif // !UNICODE

LPSTR
APIENTRY
CharLowerA(
    IN LPSTR
    );
LPWSTR
APIENTRY
CharLowerW(
    IN LPWSTR
    );
#ifdef UNICODE
#define CharLower CharLowerW
#else
#define CharLower CharLowerA
#endif // !UNICODE

DWORD
APIENTRY
CharLowerBuffA(
    NEXTCOUNT IN LPSTR,
    IN DWORD
    );
DWORD
APIENTRY
CharLowerBuffW(
    NEXTCOUNT IN LPWSTR,
    IN DWORD
    );
#ifdef UNICODE
#define CharLowerBuff CharLowerBuffW
#else
#define CharLowerBuff CharLowerBuffA
#endif // !UNICODE

LPSTR
APIENTRY
CharNextA(
    IN LPSTR
    );
LPWSTR
APIENTRY
CharNextW(
    IN LPWSTR
    );
#ifdef UNICODE
#define CharNext CharNextW
#else
#define CharNext CharNextA
#endif // !UNICODE

LPSTR
APIENTRY
CharPrevA(
    IN LPSTR,
    IN LPSTR
    );
LPWSTR
APIENTRY
CharPrevW(
    IN LPWSTR,
    IN LPWSTR
    );
#ifdef UNICODE
#define CharPrev CharPrevW
#else
#define CharPrev CharPrevA
#endif // !UNICODE

/* Compatibility defines for character translation routines */
#define AnsiToOem CharToOemA
#define OemToAnsi OemToCharA
#define AnsiToOemBuff CharToOemBuffA
#define OemToAnsiBuff OemToCharBuffA
#define AnsiUpper CharUpperA
#define AnsiUpperBuff CharUpperBuffA
#define AnsiLower CharLowerA
#define AnsiLowerBuff CharLowerBuffA
#define AnsiNext CharNextA
#define AnsiPrev CharPrevA

#ifndef  NOLANGUAGE
/* Language dependent Routines */

BOOL
APIENTRY
IsCharAlphaA(
    IN CHAR
    );
BOOL
APIENTRY
IsCharAlphaW(
    IN WCHAR
    );
#ifdef UNICODE
#define IsCharAlpha IsCharAlphaW
#else
#define IsCharAlpha IsCharAlphaA
#endif // !UNICODE

BOOL
APIENTRY
IsCharAlphaNumericA(
    IN CHAR
    );
BOOL
APIENTRY
IsCharAlphaNumericW(
    IN WCHAR
    );
#ifdef UNICODE
#define IsCharAlphaNumeric IsCharAlphaNumericW
#else
#define IsCharAlphaNumeric IsCharAlphaNumericA
#endif // !UNICODE

BOOL
APIENTRY
IsCharUpperA(
    IN CHAR
    );
BOOL
APIENTRY
IsCharUpperW(
    IN WCHAR
    );
#ifdef UNICODE
#define IsCharUpper IsCharUpperW
#else
#define IsCharUpper IsCharUpperA
#endif // !UNICODE

BOOL
APIENTRY
IsCharLowerA(
    IN CHAR
    );
BOOL
APIENTRY
IsCharLowerW(
    IN WCHAR
    );
#ifdef UNICODE
#define IsCharLower IsCharLowerW
#else
#define IsCharLower IsCharLowerA
#endif // !UNICODE

#endif

HWND APIENTRY CRITICAL XXX SetFocus(IN HWND hWnd OPTIONAL);
HWND APIENTRY CRITICAL GetActiveWindow(void);
HWND APIENTRY CRITICAL GetFocus(void);
SHORT APIENTRY CRITICAL GetKeyState(IN int nVirtKey);
SHORT APIENTRY CRITICAL GetAsyncKeyState(IN int vKey);
BOOL APIENTRY CRITICAL GetKeyboardState(IN OUT PBYTE lpKeyState);
BOOL APIENTRY CRITICAL SetKeyboardState(IN LPBYTE lpKeyState);

int
APIENTRY
GetKeyNameTextA(
    IN LONG lParam,
    NEXTCOUNT IN OUT OUTLPSTR lpString,
    IN int nSize
    );
int
APIENTRY
GetKeyNameTextW(
    IN LONG lParam,
    NEXTCOUNT IN OUT OUTLPWSTR lpString,
    IN int nSize
    );
#ifdef UNICODE
#define GetKeyNameText GetKeyNameTextW
#else
#define GetKeyNameText GetKeyNameTextA
#endif // !UNICODE
int APIENTRY CRITICAL ToAscii(IN UINT wVirtKey, IN UINT wScanCode,
        OUT PBYTE lpKeyState, OUT LPWORD lpChar, IN UINT wFlags);

SHORT APIENTRY VkKeyScan(IN CHAR cChar);
UINT APIENTRY MapVirtualKey(IN UINT wCode, IN UINT wMapType);
BOOL APIENTRY EnableHardwareInput(BOOL);
BOOL APIENTRY CRITICAL GetInputState(void);
DWORD APIENTRY CRITICAL GetQueueStatus(UINT flags);
HWND APIENTRY CRITICAL GetCapture(void);
HWND APIENTRY CRITICAL SetCapture(IN HWND hWnd OPTIONAL);
BOOL APIENTRY CRITICAL ReleaseCapture(void);
DWORD APIENTRY CRITICAL XXX MsgWaitForMultipleObjects(IN DWORD nCount,
        PREVCOUNT IN LPHANDLE pHandles, IN BOOL fWaitAll,
        IN DWORD dwMilliseconds, IN DWORD dwWakeMask);

/* Queue status flags for GetQueueStatus() and MsgWaitForMultipleObjects() */
#define QS_KEY           0x01
#define QS_MOUSEMOVE     0x02
#define QS_MOUSEBUTTON   0x04
#define QS_MOUSE         (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#define QS_POSTMESSAGE   0x08
#define QS_TIMER         0x10
#define QS_PAINT         0x20
#define QS_SENDMESSAGE   0x40
#define QS_HOTKEY        0x80
#define QS_SETFOREGROUND (QS_HOTKEY | 0x0100)
#define QS_INPUT         (QS_MOUSE | QS_KEY)
#define QS_ALLEVENTS     (QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)


UINT APIENTRY GetSysInputMode(void);

/* GetSysInputMode return values */
#define IMD_NONE                0
#define IMD_MENU                1
#define IMD_DIALOGBOX           2
#define IMD_NEXTWINDOW          3
#define IMD_SCROLLBAR           4
#define IMD_TITLEBUTTONTRACK    5
#define IMD_MOVESIZETRACK       6
#define IMD_SYSERRDLG           7
#define IMD_DRAGOBJECT          8
#define IMD_DRAGDETECT          9


/* Windows Functions */
UINT APIENTRY CRITICAL SetTimer(IN HWND hwnd OPTIONAL, IN UINT nIDEvent, IN UINT wElapse, IN WNDPROC lpTimerFunc OPTIONAL);
BOOL APIENTRY CRITICAL KillTimer(IN HWND hWnd OPTIONAL, IN UINT nIDEvent);

BOOL APIENTRY CRITICAL XXX EnableWindow(IN HWND hWnd, IN BOOL bEnable);
BOOL APIENTRY CRITICAL IsWindowEnabled(IN HWND hWnd);

HANDLE
APIENTRY CRITICAL
LoadAcceleratorsA(
    IN HANDLE hInstance,
    IN LPSTRID lpTableName
    );
HANDLE
APIENTRY CRITICAL
LoadAcceleratorsW(
    IN HANDLE hInstance,
    IN LPWSTRID lpTableName
    );
#ifdef UNICODE
#define LoadAccelerators LoadAcceleratorsW
#else
#define LoadAccelerators LoadAcceleratorsA
#endif // !UNICODE

HACCEL APIENTRY CRITICAL CreateAcceleratorTable(NEXTCOUNT IN LPACCEL, IN int);
BOOL   APIENTRY CRITICAL DestroyAcceleratorTable(IN HACCEL);
int    APIENTRY CRITICAL CopyAcceleratorTable(IN HACCEL, NEXTCOUNT OUT LPACCEL OPTIONAL, IN int);

#ifndef NOMSG
int  APIENTRY CRITICAL XXX TranslateAccelerator(IN HWND hWnd, IN HACCEL hAccTable, IN LPMSG lpMsg);
#endif

#ifndef NOSYSMETRICS

/* GetSystemMetrics() codes */
#define SM_CXSCREEN         0
#define SM_CYSCREEN         1
#define SM_CXVSCROLL        2
#define SM_CYHSCROLL        3
#define SM_CYCAPTION        4
#define SM_CXBORDER         5
#define SM_CYBORDER         6
#define SM_CXDLGFRAME       7
#define SM_CYDLGFRAME       8
#define SM_CYVTHUMB         9
#define SM_CXHTHUMB         10
#define SM_CXICON           11
#define SM_CYICON           12
#define SM_CXCURSOR         13
#define SM_CYCURSOR         14
#define SM_CYMENU           15
#define SM_CXFULLSCREEN     16
#define SM_CYFULLSCREEN     17
#define SM_CYKANJIWINDOW    18
#define SM_MOUSEPRESENT     19
#define SM_CYVSCROLL        20
#define SM_CXHSCROLL        21
#define SM_DEBUG            22
#define SM_SWAPBUTTON       23
#define SM_RESERVED1        24
#define SM_RESERVED2        25
#define SM_RESERVED3        26
#define SM_RESERVED4        27
#define SM_CXMIN            28
#define SM_CYMIN            29
#define SM_CXSIZE           30
#define SM_CYSIZE           31
#define SM_CXFRAME          32
#define SM_CYFRAME          33
#define SM_CXMINTRACK       34
#define SM_CYMINTRACK       35
#define SM_CXDOUBLECLK       36
#define SM_CYDOUBLECLK       37
#define SM_CXICONSPACING     38
#define SM_CYICONSPACING     39
#define SM_MENUDROPALIGNMENT 40
#define SM_PENWINDOWS        41
#define SM_CMOUSEBUTTONS     42
#define SM_SECURE            43

#define SM_CMETRICS          44

int APIENTRY CRITICAL GetSystemMetrics(IN int nIndex);

#endif /* NOSYSMETRICS */

#ifndef NOMENUS

HMENU
APIENTRY CRITICAL
LoadMenuA(
    IN HANDLE hInstance,
    IN LPSTRID lpMenuName
    );
HMENU
APIENTRY CRITICAL
LoadMenuW(
    IN HANDLE hInstance,
    IN LPWSTRID lpMenuName
    );
#ifdef UNICODE
#define LoadMenu LoadMenuW
#else
#define LoadMenu LoadMenuA
#endif // !UNICODE

HMENU
APIENTRY CRITICAL
LoadMenuIndirectA(
    IN LPMENUTEMPLATEA lpMenuTemplate
    );
HMENU
APIENTRY CRITICAL
LoadMenuIndirectW(
    IN LPMENUTEMPLATEW lpMenuTemplate
    );
#ifdef UNICODE
#define LoadMenuIndirect LoadMenuIndirectW
#else
#define LoadMenuIndirect LoadMenuIndirectA
#endif // !UNICODE

HMENU APIENTRY CRITICAL GetMenu(IN HWND hWnd);
BOOL  APIENTRY CRITICAL XXX SetMenu(IN HWND hWnd, IN HMENU hMenu OPTIONAL);
BOOL  APIENTRY CRITICAL ChangeMenu(IN HMENU, IN UINT, IN CHNGMENUPOLY OPTIONAL, IN UINT, IN UINT);
BOOL  APIENTRY CRITICAL XXX HiliteMenuItem(IN HWND hWnd, IN HMENU hMenu, IN UINT wIDHiliteItem, IN UINT wHilite);

int
APIENTRY CRITICAL
GetMenuStringA(
    IN HMENU hMenu,
    IN UINT wIDItem,
    NEXTCOUNT IN OUT OUTLPSTR lpString,
    IN int nMaxCount,
    IN DWORD wFlag
    );
int
APIENTRY CRITICAL
GetMenuStringW(
    IN HMENU hMenu,
    IN UINT wIDItem,
    NEXTCOUNT IN OUT OUTLPWSTR lpString,
    IN int nMaxCount,
    IN DWORD wFlag
    );
#ifdef UNICODE
#define GetMenuString GetMenuStringW
#else
#define GetMenuString GetMenuStringA
#endif // !UNICODE

UINT APIENTRY CRITICAL GetMenuState(IN HMENU hMenu, IN UINT wId, IN UINT wFlags);
BOOL  APIENTRY CRITICAL XXX DrawMenuBar(IN HWND hWnd);
HMENU APIENTRY CRITICAL GetSystemMenu(IN HWND hWnd, IN BOOL bRevert);
HMENU APIENTRY CRITICAL CreateMenu(void);
HMENU APIENTRY CRITICAL CreatePopupMenu(void);
BOOL  APIENTRY CRITICAL DestroyMenu(IN HMENU hMenu);
BOOL  APIENTRY CRITICAL CheckMenuItem(IN HMENU hMenu, IN UINT wIDCheckItem, IN UINT wCheck);
BOOL  APIENTRY CRITICAL EnableMenuItem(IN HMENU hMenu, IN UINT wIDEnableItem, IN UINT wEnable);
HMENU APIENTRY CRITICAL GetSubMenu(IN HMENU hMenu, IN int nPos);
UINT APIENTRY CRITICAL GetMenuItemID(IN HMENU hMenu, IN int nPos);
UINT APIENTRY CRITICAL GetMenuItemCount(IN HMENU hMenu);

BOOL
APIENTRY CRITICAL
InsertMenuA(
    IN HMENU hMenu,
    IN UINT nPosition,
    IN UINT dwFlags,
    IN UINT wIDNewItem,
    IN MENUPOLYA lpNewItem OPTIONAL
    );
BOOL
APIENTRY CRITICAL
InsertMenuW(
    IN HMENU hMenu,
    IN UINT nPosition,
    IN UINT dwFlags,
    IN UINT wIDNewItem,
    IN MENUPOLYW lpNewItem OPTIONAL
    );
#ifdef UNICODE
#define InsertMenu InsertMenuW
#else
#define InsertMenu InsertMenuA
#endif // !UNICODE

BOOL
APIENTRY CRITICAL
AppendMenuA(
    IN HMENU hMenu,
    IN UINT dwFlags,
    IN UINT wIDNewItem,
    IN MENUPOLYA lpNewItem OPTIONAL
    );
BOOL
APIENTRY CRITICAL
AppendMenuW(
    IN HMENU hMenu,
    IN UINT dwFlags,
    IN UINT wIDNewItem,
    IN MENUPOLYW lpNewItem OPTIONAL
    );
#ifdef UNICODE
#define AppendMenu AppendMenuW
#else
#define AppendMenu AppendMenuA
#endif // !UNICODE

BOOL
APIENTRY CRITICAL
ModifyMenuA(
    IN HMENU hMnu,
    IN UINT nPosition,
    IN UINT dwFlags,
    IN UINT wIDNewItem,
    IN MENUPOLYA lpNewItem OPTIONAL
    );
BOOL
APIENTRY CRITICAL
ModifyMenuW(
    IN HMENU hMnu,
    IN UINT nPosition,
    IN UINT dwFlags,
    IN UINT wIDNewItem,
    IN MENUPOLYW lpNewItem OPTIONAL
    );
#ifdef UNICODE
#define ModifyMenu ModifyMenuW
#else
#define ModifyMenu ModifyMenuA
#endif // !UNICODE

BOOL  APIENTRY CRITICAL RemoveMenu(IN HMENU hMenu, IN UINT nPosition, IN UINT dwFlags);
BOOL  APIENTRY CRITICAL DeleteMenu(IN HMENU hMenu, IN UINT nPosition, IN UINT dwFlags);
BOOL  APIENTRY CRITICAL SetMenuItemBitmaps(IN HMENU hMenu, IN UINT nPosition,
        IN DWORD dwFlags, IN HBITMAP hBitmapUnchecked, IN HBITMAP hBitmapChecked);
LONG  APIENTRY CRITICAL GetMenuCheckMarkDimensions(void);
BOOL  APIENTRY CRITICAL XXX TrackPopupMenu(IN HMENU hMenu, IN UINT dwFlags,
        IN int x, IN int y, IN int nReserved, IN HWND hWnd, IN LPVOID lpReserved);

/* Flags for TrackPopupMenu */
#define TPM_LEFTBUTTON  0x0000L
#define TPM_RIGHTBUTTON 0x0002L
#define TPM_LEFTALIGN   0x0000L
#define TPM_CENTERALIGN 0x0004L
#define TPM_RIGHTALIGN  0x0008L

#endif /* NOMENUS */

BOOL APIENTRY CRITICAL DrawIcon(IN HDC, IN int, IN int, IN HICON);

int
APIENTRY CRITICAL DrawTextA(
    IN HDC hDC,
    NEXTCOUNT IN LPSTR2 lpString,
    IN int nCount,
    IN OUT LPRECT lpRect,
    IN UINT wFormat
    );
int
APIENTRY CRITICAL DrawTextW(
    IN HDC hDC,
    NEXTCOUNT IN LPWSTR2 lpString,
    IN int nCount,
    IN OUT LPRECT lpRect,
    IN UINT wFormat
    );
#ifdef UNICODE
#define DrawText DrawTextW
#else
#define DrawText DrawTextA
#endif // !UNICODE

BOOL APIENTRY GrayString(IN HDC hDC, IN HBRUSH hBrush, IN FARPROC lpOutputFunc,
        IN GSPOLY lpData, IN int nCount, IN int X, IN int Y,
        IN int nWidth, IN int nHeight);

LONG
APIENTRY CRITICAL
TabbedTextOutA(
    IN HDC hDC,
    IN int X,
    IN int Y,
    NEXTCOUNT IN LPSTR2 lpString,
    IN int nCount,
    IN int nTabPositions,
    PREVCOUNT IN LPTABS lpnTabStopPositions,
    IN int nTabOrigin
    );
LONG
APIENTRY CRITICAL
TabbedTextOutW(
    IN HDC hDC,
    IN int X,
    IN int Y,
    NEXTCOUNT IN LPWSTR2 lpString,
    IN int nCount,
    IN int nTabPositions,
    PREVCOUNT IN LPTABS lpnTabStopPositions,
    IN int nTabOrigin
    );
#ifdef UNICODE
#define TabbedTextOut TabbedTextOutW
#else
#define TabbedTextOut TabbedTextOutA
#endif // !UNICODE

DWORD
APIENTRY CRITICAL
GetTabbedTextExtentA(
    IN HDC hDC,
    NEXTCOUNT IN LPSTR2 lpString,
    IN int nCount,
    IN int nTabPositions,
    PREVCOUNT IN LPTABS lpnTabStopPositions
    );
DWORD
APIENTRY CRITICAL
GetTabbedTextExtentW(
    IN HDC hDC,
    NEXTCOUNT IN LPWSTR2 lpString,
    IN int nCount,
    IN int nTabPositions,
    PREVCOUNT IN LPTABS lpnTabStopPositions
    );
#ifdef UNICODE
#define GetTabbedTextExtent GetTabbedTextExtentW
#else
#define GetTabbedTextExtent GetTabbedTextExtentA
#endif // !UNICODE

BOOL APIENTRY CRITICAL XXX UpdateWindow(IN HWND hWnd);
HWND APIENTRY CRITICAL XXX SetActiveWindow(IN HWND hWnd OPTIONAL);

BOOL APIENTRY CRITICAL XXX SetForegroundWindow(IN HWND hWnd);

HWND APIENTRY CRITICAL WindowFromDC(IN HDC hdc);
HDC APIENTRY CRITICAL GetDC(IN HWND hWnd OPTIONAL);
HDC APIENTRY GetDCEx(IN HWND hwnd OPTIONAL, IN HRGN hrgnClip, IN DWORD flags);

/* GetDCEx() flags */
#define DCX_WINDOW          0x00000001L
#define DCX_CACHE           0x00000002L
#define DCX_NORESETATTRS    0x00000004L
#define DCX_CLIPCHILDREN    0x00000008L
#define DCX_CLIPSIBLINGS    0x00000010L
#define DCX_PARENTCLIP      0x00000020L

#define DCX_EXCLUDERGN      0x00000040L
#define DCX_INTERSECTRGN    0x00000080L

#define DCX_EXCLUDEUPDATE   0x00000100L
#define DCX_INTERSECTUPDATE 0x00000200L

#define DCX_LOCKWINDOWUPDATE 0x00000400L

#define DCX_INVALID         0x00000800L /* ;Internal */
#define DCX_INUSE           0x00001000L /* ;Internal */
#define DCX_SAVEDRGNINVALID 0x00002000L /* ;Internal */
#define DCX_OWNDC           0x00008000L /* ;Internal */

#define DCX_USESTYLE        0x00010000L
#define DCX_NEEDFONT        0x00020000L /* ;Internal */
#define DCX_NODELETERGN     0x00040000L /* ;Internal */
#define DCX_NOCLIPCHILDREN  0x00080000L /* ;Internal */
#define DCX_NORECOMPUTE     0x00100000L
#define DCX_VALIDATE        0x00200000L

#define DCX_MATCHMASK (DCX_WINDOW | DCX_CACHE |                /* ;Internal */ \
                      DCX_CLIPCHILDREN | DCX_CLIPSIBLINGS |    /* ;Internal */ \
                      DCX_NORESETATTRS | DCX_LOCKWINDOWUPDATE) /* ;Internal */

HDC APIENTRY CRITICAL GetWindowDC(IN HWND hWnd OPTIONAL);
int APIENTRY CRITICAL ReleaseDC(IN HWND hWnd OPTIONAL, IN HDC hDC);

HDC  APIENTRY CRITICAL XXX BeginPaint(IN HWND hWnd, OUT LPPAINTSTRUCT lpPaint);
BOOL APIENTRY CRITICAL EndPaint(IN HWND hWnd, IN LPPAINTSTRUCT lpPaint);
BOOL APIENTRY CRITICAL XXX GetUpdateRect(IN HWND hWnd, OUT LPRECT lpRect,
        IN BOOL bErase);
int  APIENTRY CRITICAL XXX GetUpdateRgn(IN HWND hWnd, IN HRGN hRgn,
        IN BOOL bErase);

int  APIENTRY CRITICAL ExcludeUpdateRgn(IN HDC hDC, IN HWND hWnd);

BOOL APIENTRY CRITICAL XXX InvalidateRect(IN HWND hWnd OPTIONAL,
        IN LPRECT lpRect OPTIONAL, IN BOOL bErase);
BOOL APIENTRY CRITICAL XXX ValidateRect(IN HWND hWnd OPTIONAL,
        IN LPRECT lpRect OPTIONAL);

BOOL APIENTRY CRITICAL InvalidateRgn(IN HWND hWnd, IN HRGN hRgn OPTIONAL,
        IN BOOL bErase);
BOOL APIENTRY CRITICAL ValidateRgn(IN HWND hWnd, IN HRGN hRgn OPTIONAL);


BOOL APIENTRY CRITICAL XXX RedrawWindow(IN HWND hwnd,
        IN LPRECT lprcUpdate OPTIONAL, IN HRGN hrgnUpdate, IN WORD flags);

/* RedrawWindow() flags */
#define RDW_INVALIDATE          0x0001
#define RDW_INTERNALPAINT       0x0002
#define RDW_ERASE               0x0004

#define RDW_VALIDATE            0x0008
#define RDW_NOINTERNALPAINT     0x0010
#define RDW_NOERASE             0x0020

#define RDW_NOCHILDREN          0x0040
#define RDW_ALLCHILDREN         0x0080

#define RDW_UPDATENOW           0x0100
#define RDW_ERASENOW            0x0200

#define RDW_FRAME               0x0400  /* Set WFSENDNCPAINT   */       /* ;Internal */
#define RDW_NOFRAME             0x0800  /* Clear WFSENDNCPAINT */       /* ;Internal */
                                                                        /* ;Internal */
#define RDW_REDRAWWINDOW        0x1000  /* Called from RedrawWindow()*/ /* ;Internal */
#define RDW_SUBTRACTSELF        0x2000  /* Subtract self from hrgn   */ /* ;Internal */
                                                                        /* ;Internal */
#define RDW_COPYRGN             0x4000  /* Copy the passed-in region */ /* ;Internal */
                                                                        /* ;Internal */
#define RDW_VALIDMASK           (RDW_INVALIDATE | RDW_INTERNALPAINT |   /* ;Internal */ \
                                RDW_ERASE | RDW_VALIDATE |              /* ;Internal */ \
                                RDW_NOINTERNALPAINT | RDW_NOERASE |     /* ;Internal */ \
                                RDW_NOCHILDREN | RDW_ALLCHILDREN |      /* ;Internal */ \
                                RDW_UPDATENOW | RDW_ERASENOW | RDW_COPYRGN) /* ;Internal */

/* LockWindowUpdate API */
BOOL APIENTRY CRITICAL LockWindowUpdate(HWND hwndLock);

BOOL APIENTRY CRITICAL XXX ScrollWindow(IN HWND hWnd, IN int XAmount,
        IN int YAmount, IN LPRECT lpRect OPTIONAL,
        IN LPRECT lpClipRect OPTIONAL);
BOOL APIENTRY CRITICAL ScrollDC(IN HDC hDC, IN int dx, IN int dy,
        IN LPRECT lprcScroll, IN LPRECT lprcClip OPTIONAL,
        IN HRGN hrgnUpdate OPTIONAL, OUT LPRECT lprcUpdate OPTIONAL);
int APIENTRY CRITICAL XXX ScrollWindowEx(IN HWND hwnd, IN int dx, IN int dy,
        IN LPRECT prcScroll OPTIONAL, IN LPRECT prcClip OPTIONAL,
        HRGN hrgnUpdate, OUT LPRECT prcUpdate OPTIONAL, IN WORD flags);

#define SW_SCROLLCHILDREN   0x0001  /* Scroll children within *lprcScroll. */
#define SW_INVALIDATE       0x0002  /* Invalidate after scrolling */
#define SW_ERASE            0x0004  /* If SW_INVALIDATE, don't send WM_ERASEBACKGROUND */

#define SW_SCROLLWINDOW     0x8000  /* Called from ScrollWindow() */  /* ;Internal */
#define SW_VALIDFLAGS       (SW_SCROLLWINDOW | SW_SCROLLCHILDREN | SW_INVALIDATE | SW_ERASE) /* ;Internal */

#ifndef NOSCROLL
int  APIENTRY CRITICAL XXX SetScrollPos(IN HWND hWnd, IN int nBar, IN int nPos, IN BOOL bRedraw);
int  APIENTRY CRITICAL XXX GetScrollPos(IN HWND hWnd, IN int nBar);
BOOL APIENTRY CRITICAL XXX SetScrollRange(IN HWND hWnd, IN int nBar, IN int nMinPos, IN int nMaxPos, IN BOOL bRedraw);
BOOL APIENTRY CRITICAL XXX GetScrollRange(IN HWND hWnd, IN int nBar, OUT LPINT lpMinPos, OUT LPINT lpMaxPos);
BOOL APIENTRY CRITICAL XXX ShowScrollBar(IN HWND hWnd, IN UINT wBar, IN BOOL bShow);
#endif

BOOL
APIENTRY CRITICAL
SetPropA(
    IN HWND hWnd,
    IN LPSTRID lpString,
    IN HANDLE hData
    );
BOOL
APIENTRY CRITICAL
SetPropW(
    IN HWND hWnd,
    IN LPWSTRID lpString,
    IN HANDLE hData
    );
#ifdef UNICODE
#define SetProp SetPropW
#else
#define SetProp SetPropA
#endif // !UNICODE

HANDLE
APIENTRY CRITICAL
GetPropA(
    IN HWND hWnd,
    IN LPSTRID lpString
    );
HANDLE
APIENTRY CRITICAL
GetPropW(
    IN HWND hWnd,
    IN LPWSTRID lpString
    );
#ifdef UNICODE
#define GetProp GetPropW
#else
#define GetProp GetPropA
#endif // !UNICODE

HANDLE
APIENTRY CRITICAL
RemovePropA(
    IN HWND hWnd,
    IN LPSTRID lpString
    );
HANDLE
APIENTRY CRITICAL
RemovePropW(
    IN HWND hWnd,
    IN LPWSTRID lpString
    );
#ifdef UNICODE
#define RemoveProp RemovePropW
#else
#define RemoveProp RemovePropA
#endif // !UNICODE

int
APIENTRY CRITICAL
EnumPropsExA(
    IN HWND hWnd,
    IN FARPROC lpEnumFunc,
    IN DWORD lParam
    );
int
APIENTRY CRITICAL
EnumPropsExW(
    IN HWND hWnd,
    IN FARPROC lpEnumFunc,
    IN DWORD lParam
    );
#ifdef UNICODE
#define EnumPropsEx EnumPropsExW
#else
#define EnumPropsEx EnumPropsExA
#endif // !UNICODE

int
APIENTRY CRITICAL
EnumPropsA(
    IN HWND hWnd,
    IN FARPROC lpEnumFunc
    );
int
APIENTRY CRITICAL
EnumPropsW(
    IN HWND hWnd,
    IN FARPROC lpEnumFunc
    );
#ifdef UNICODE
#define EnumProps EnumPropsW
#else
#define EnumProps EnumPropsA
#endif // !UNICODE

BOOL
APIENTRY CRITICAL XXX
SetWindowTextA(
    IN HWND hWnd,
    IN LPSTR lpString OPTIONAL
    );
BOOL
APIENTRY CRITICAL XXX
SetWindowTextW(
    IN HWND hWnd,
    IN LPWSTR lpString OPTIONAL
    );
#ifdef UNICODE
#define SetWindowText SetWindowTextW
#else
#define SetWindowText SetWindowTextA
#endif // !UNICODE

int
APIENTRY CRITICAL XXX
GetWindowTextA(
    IN HWND hWnd,
    NEXTCOUNT IN OUT OUTLPSTR lpString,
    IN int nMaxCount
    );
int
APIENTRY CRITICAL XXX
GetWindowTextW(
    IN HWND hWnd,
    NEXTCOUNT IN OUT OUTLPWSTR lpString,
    IN int nMaxCount
    );
#ifdef UNICODE
#define GetWindowText GetWindowTextW
#else
#define GetWindowText GetWindowTextA
#endif // !UNICODE

int    APIENTRY CRITICAL XXX GetWindowTextLength(IN HWND hWnd);

BOOL APIENTRY CRITICAL GetClientRect(IN HWND hWnd, OUT LPRECT lpRect);
BOOL APIENTRY CRITICAL GetWindowRect(IN HWND hWnd, OUT LPRECT lpRect);
BOOL APIENTRY CRITICAL AdjustWindowRect(IN OUT LPRECT lpRect, IN LONG dwStyle, IN BOOL bMenu);
BOOL APIENTRY CRITICAL AdjustWindowRectEx(IN OUT LPRECT lpRect, IN LONG dwStyle, IN BOOL bMenu, IN DWORD dwExStyle);

#ifndef NOMB

/* MessageBox() Flags */
#define MB_OK               0x0000L
#define MB_OKCANCEL         0x0001L
#define MB_ABORTRETRYIGNORE 0x0002L
#define MB_YESNOCANCEL      0x0003L
#define MB_YESNO            0x0004L
#define MB_RETRYCANCEL      0x0005L

#define MB_ICONHAND         0x0010L
#define MB_ICONQUESTION     0x0020L
#define MB_ICONEXCLAMATION  0x0030L
#define MB_ICONASTERISK     0x0040L

#define MB_ICONINFORMATION  MB_ICONASTERISK
#define MB_ICONSTOP         MB_ICONHAND

#define MB_DEFBUTTON1       0x0000L
#define MB_DEFBUTTON2       0x0100L
#define MB_DEFBUTTON3       0x0200L

#define MB_APPLMODAL        0x0000L
#define MB_SYSTEMMODAL      0x1000L
#define MB_TASKMODAL        0x2000L

#define MB_NOFOCUS          0x8000L
#define MB_SETFOREGROUND   0x10000L

#define MB_TYPEMASK         0x000FL
#define MB_ICONMASK         0x00F0L
#define MB_DEFMASK          0x0F00L
#define MB_MODEMASK         0x3000L
#define MB_MISCMASK         0xC000L

int
APIENTRY CRITICAL XXX
MessageBoxA(
    IN HWND hWnd OPTIONAL,
    IN LPSTR lpText,
    IN LPSTR lpCaption OPTIONAL,
    IN UINT wType
    );
int
APIENTRY CRITICAL XXX
MessageBoxW(
    IN HWND hWnd OPTIONAL,
    IN LPWSTR lpText,
    IN LPWSTR lpCaption OPTIONAL,
    IN UINT wType
    );
#ifdef UNICODE
#define MessageBox MessageBoxW
#else
#define MessageBox MessageBoxA
#endif // !UNICODE

BOOL APIENTRY CRITICAL MessageBeep(IN UINT wType);

#endif /* NOMB */

int     APIENTRY CRITICAL ShowCursor(IN BOOL bShow);
BOOL    APIENTRY CRITICAL SetCursorPos(IN int X, IN int Y);
HCURSOR APIENTRY CRITICAL SetCursor(IN HCURSOR hCursor OPTIONAL);
BOOL    APIENTRY CRITICAL GetCursorPos(OUT LPPOINT lpPoint);
BOOL    APIENTRY CRITICAL ClipCursor(IN LPRECT lpRect OPTIONAL);
BOOL    APIENTRY CRITICAL GetClipCursor(OUT LPRECT lpRect);

BOOL APIENTRY CRITICAL CreateCaret(IN HWND hWnd, IN HBITMAP hBitmap OPTIONAL,
        IN int nWidth, IN int nHeight);
UINT APIENTRY CRITICAL GetCaretBlinkTime(void);
BOOL APIENTRY CRITICAL SetCaretBlinkTime(IN UINT wMSeconds);
BOOL APIENTRY CRITICAL DestroyCaret(void);
BOOL APIENTRY CRITICAL HideCaret(IN HWND hWnd OPTIONAL);
BOOL APIENTRY CRITICAL ShowCaret(IN HWND hWnd OPTIONAL);
BOOL APIENTRY CRITICAL SetCaretPos(IN int X, IN int Y);
BOOL APIENTRY CRITICAL GetCaretPos(OUT LPPOINT lpPoint);

BOOL APIENTRY CRITICAL ClientToScreen(IN HWND hWnd, IN OUT LPPOINT lpPoint);
BOOL APIENTRY CRITICAL ScreenToClient(IN HWND hWnd, IN OUT LPPOINT lpPoint);
HWND APIENTRY CRITICAL XXX WindowFromPoint(IN POINT Point);
HWND APIENTRY CRITICAL ChildWindowFromPoint(IN HWND hWndParent, IN POINT Point);

#ifndef NOCOLOR

/* Color Types */
#define CTLCOLOR_MSGBOX         0
#define CTLCOLOR_EDIT           1
#define CTLCOLOR_LISTBOX        2
#define CTLCOLOR_BTN            3
#define CTLCOLOR_DLG            4
#define CTLCOLOR_SCROLLBAR      5
#define CTLCOLOR_STATIC         6
#define CTLCOLOR_MAX            8     /* three bits max */

#define COLOR_SCROLLBAR         0
#define COLOR_BACKGROUND        1
#define COLOR_ACTIVECAPTION     2
#define COLOR_INACTIVECAPTION   3
#define COLOR_MENU              4
#define COLOR_WINDOW            5
#define COLOR_WINDOWFRAME       6
#define COLOR_MENUTEXT          7
#define COLOR_WINDOWTEXT        8
#define COLOR_CAPTIONTEXT       9
#define COLOR_ACTIVEBORDER      10
#define COLOR_INACTIVEBORDER    11
#define COLOR_APPWORKSPACE      12
#define COLOR_HIGHLIGHT         13
#define COLOR_HIGHLIGHTTEXT     14
#define COLOR_BTNFACE           15
#define COLOR_BTNSHADOW         16
#define COLOR_GRAYTEXT          17
#define COLOR_BTNTEXT           18
#define COLOR_INACTIVECAPTIONTEXT 19
#define COLOR_BTNHIGHLIGHT      20
#define COLOR_ENDCOLORS         COLOR_BTNHIGHLIGHT

DWORD APIENTRY CRITICAL GetSysColor(IN int nIndex);
BOOL  APIENTRY CRITICAL XXX SetSysColors(IN int, IN LPSYSCOLOR, IN LPCOLORVALUES);

#endif /* NOCOLOR */

BOOL APIENTRY CRITICAL DrawFocusRect(HDC, LPRECT);
int  APIENTRY CRITICAL FillRect(HDC hdc, LPRECT lprc, HBRUSH hbr);
int  APIENTRY CRITICAL FrameRect(IN HDC hdc, IN LPRECT lprc, IN HBRUSH hbr);
BOOL APIENTRY CRITICAL InvertRect(HDC, LPRECT);
BOOL APIENTRY SetRect(LPRECT, int, int, int, int);
BOOL APIENTRY SetRectEmpty(LPRECT);
int  APIENTRY CopyRect(LPRECT, LPRECT);
BOOL APIENTRY InflateRect(LPRECT, int, int);
int  APIENTRY IntersectRect(LPRECT, LPRECT, LPRECT);
BOOL APIENTRY UnionRect(LPRECT, LPRECT, LPRECT);
BOOL APIENTRY OffsetRect(LPRECT, int, int);
BOOL APIENTRY IsRectEmpty(LPRECT);
BOOL APIENTRY EqualRect(LPRECT, LPRECT);
BOOL APIENTRY PtInRect(LPRECT, POINT);
DWORD APIENTRY CRITICAL GetCurrentTime(void);

#ifndef NOWINOFFSETS

WORD APIENTRY CRITICAL GetWindowWord(IN HWND hWnd, IN int nIndex);
WORD APIENTRY CRITICAL SetWindowWord(IN HWND hWnd, IN int nIndex, IN WORD wNewWord);
LONG  APIENTRY CRITICAL GetWindowLong(IN HWND hWnd, IN int nIndex);
LONG  APIENTRY CRITICAL SetWindowLong(IN HWND hWnd, IN int nIndex, IN LONG dwNewLong);
WORD APIENTRY CRITICAL GetClassWord(IN HWND hWnd, IN int nIndex);
WORD APIENTRY CRITICAL SetClassWord(IN HWND hWnd, IN int nIndex, IN WORD wNewWord);
DWORD APIENTRY CRITICAL GetClassLong(IN HWND hWnd, IN int nIndex);
DWORD APIENTRY CRITICAL SetClassLong(IN HWND hWnd, IN int nIndex, IN LONG dwNewLong);
HWND APIENTRY CRITICAL GetDesktopWindow(void);
BOOL APIENTRY CRITICAL SetDeskWallpaper(IN LPSTR lpString OPTIONAL);

#endif /* NOWINOFFSETS */

HWND APIENTRY CRITICAL GetParent(IN HWND hWnd);
HWND APIENTRY CRITICAL XXX SetParent(IN HWND hWndChild, IN HWND hWndNewParent OPTIONAL);
BOOL APIENTRY CRITICAL XXX EnumChildWindows(IN HWND hWndParent, IN FARPROC lpEnumFunc, IN LONG lParam);

HWND
APIENTRY CRITICAL XXX
FindWindowA(
    IN LPSTRID lpClassName OPTIONAL,
    IN LPSTR lpWindowName OPTIONAL
    );
HWND
APIENTRY CRITICAL XXX
FindWindowW(
    IN LPWSTRID lpClassName OPTIONAL,
    IN LPWSTR lpWindowName OPTIONAL
    );
#ifdef UNICODE
#define FindWindow FindWindowW
#else
#define FindWindow FindWindowA
#endif // !UNICODE

BOOL APIENTRY CRITICAL XXX EnumWindows(IN FARPROC lpEnumFunc, IN LONG lParam);
BOOL APIENTRY CRITICAL XXX EnumThreadWindows(IN DWORD dwThreadId, IN FARPROC lpfn, IN LONG lParam);
#define EnumTaskWindows(hTask, lpfn, lParam) EnumThreadWindows((DWORD)hTask, lpfn, lParam)

int
APIENTRY CRITICAL
GetClassNameA(
    IN HWND hWnd,
    NEXTCOUNT IN OUT OUTLPSTR lpClassName,
    IN int nMaxCount
    );
int
APIENTRY CRITICAL
GetClassNameW(
    IN HWND hWnd,
    NEXTCOUNT IN OUT OUTLPWSTR lpClassName,
    IN int nMaxCount
    );
#ifdef UNICODE
#define GetClassName GetClassNameW
#else
#define GetClassName GetClassNameA
#endif // !UNICODE

HWND APIENTRY CRITICAL GetTopWindow(IN HWND hWnd);
#define GetNextWindow(hwnd, wCmd) GetWindow(hwnd, wCmd)
#define GetSysModalWindow() (NULL)
#define SetSysModalWindow(hwnd) (NULL)
DWORD APIENTRY CRITICAL GetWindowThreadProcessId(IN HWND hWnd,
        IN LPDWORD lpdwProcessId OPTIONAL);
#define GetWindowTask(hwnd)\
        ((HANDLE)GetWindowThreadProcessId(hwnd, NULL))

HWND APIENTRY CRITICAL GetLastActivePopup(IN HWND hWnd);

/* GetWindow() Constants */
#define GW_HWNDFIRST        0
#define GW_HWNDLAST         1
#define GW_HWNDNEXT         2
#define GW_HWNDPREV         3
#define GW_OWNER            4
#define GW_CHILD            5

HWND APIENTRY CRITICAL GetWindow(IN HWND hWnd, IN UINT wCmd);

#ifndef NOWH

PROC
APIENTRY CRITICAL
SetWindowsHookA(
    IN int nFilterType,
    IN PROC pfnFilterProc
    );
PROC
APIENTRY CRITICAL
SetWindowsHookW(
    IN int nFilterType,
    IN PROC pfnFilterProc
    );
#ifdef UNICODE
#define SetWindowsHook SetWindowsHookW
#else
#define SetWindowsHook SetWindowsHookA
#endif // !UNICODE

BOOL  APIENTRY CRITICAL UnhookWindowsHook(IN int nCode, IN PROC pfnFilterProc);

HHOOK
APIENTRY CRITICAL
SetWindowsHookExA(
    IN HANDLE hmod,
    IN DWORD dwThreadId,
    IN int nFilterType,
    IN PROC pfnFilterProc
    );
HHOOK
APIENTRY CRITICAL
SetWindowsHookExW(
    IN HANDLE hmod,
    IN DWORD dwThreadId,
    IN int nFilterType,
    IN PROC pfnFilterProc
    );
#ifdef UNICODE
#define SetWindowsHookEx SetWindowsHookExW
#else
#define SetWindowsHookEx SetWindowsHookExA
#endif // !UNICODE

BOOL  APIENTRY CRITICAL UnhookWindowsHookEx(IN HHOOK hhk);
DWORD APIENTRY CRITICAL XXX CallNextHookProc(IN int nCode, IN DWORD wParam,
        IN LONG lParam);

/*
 * Macros for source-level compatibility with old functions.
 */
#define DefHookProc(nCode, wParam, lParam, ppfnNextHook)\
        CallNextHookProc(nCode, wParam, lParam)
#endif

#ifndef NOMENUS

/* Menu flags for Add/Check/EnableMenuItem() */
#define MF_INSERT          0x00000000L
#define MF_CHANGE          0x00000080L
#define MF_APPEND          0x00000100L
#define MF_DELETE          0x00000200L
#define MF_REMOVE          0x00001000L

#define MF_BYCOMMAND       0x00000000L
#define MF_BYPOSITION      0x00000400L


#define MF_SEPARATOR       0x00000800L

#define MF_ENABLED         0x00000000L
#define MF_GRAYED          0x00000001L
#define MF_DISABLED        0x00000002L

#define MF_UNCHECKED       0x00000000L
#define MF_CHECKED         0x00000008L
#define MF_USECHECKBITMAPS 0x00000200L

#define MF_STRING          0x00000000L
#define MF_BITMAP          0x00000004L
#define MF_OWNERDRAW       0x00000100L

#define MF_POPUP           0x00000010L
#define MF_MENUBARBREAK    0x00000020L
#define MF_MENUBREAK       0x00000040L

#define MF_UNHILITE        0x00000000L
#define MF_HILITE          0x00000080L

#define MF_SYSMENU         0x00002000L
#define MF_HELP            0x00004000L
#define MF_MOUSESELECT     0x00008000L

/* Menu item resource format */
typedef struct {
    WORD versionNumber;
    WORD offset;
} MENUITEMTEMPLATEHEADER;

typedef struct {
    WORD mtOption;
    WORD mtID;
    char mtString[1];
} MENUITEMTEMPLATE;

#define MF_END             0x00000080L

#endif /* NOMENUS */

#ifndef NOSYSCOMMANDS

/* System Menu Command Values */
#define SC_SIZE         0xF000
#define SC_MOVE         0xF010
#define SC_MINIMIZE     0xF020
#define SC_MAXIMIZE     0xF030
#define SC_NEXTWINDOW   0xF040
#define SC_PREVWINDOW   0xF050
#define SC_CLOSE        0xF060
#define SC_VSCROLL      0xF070
#define SC_HSCROLL      0xF080
#define SC_MOUSEMENU    0xF090
#define SC_KEYMENU      0xF100
#define SC_ARRANGE      0xF110
#define SC_RESTORE      0xF120
#define SC_TASKLIST     0xF130
#define SC_SCREENSAVE   0xF140
#define SC_HOTKEY       0xF150

#define SC_ICON         SC_MINIMIZE
#define SC_ZOOM         SC_MAXIMIZE

#endif /* NOSYSCOMMANDS */

/* Resource Loading Routines */

HBITMAP
APIENTRY
LoadBitmapA(
    IN HANDLE hInstance,
    IN LPSTRID lpBitmapName
    );
HBITMAP
APIENTRY
LoadBitmapW(
    IN HANDLE hInstance,
    IN LPWSTRID lpBitmapName
    );
#ifdef UNICODE
#define LoadBitmap LoadBitmapW
#else
#define LoadBitmap LoadBitmapA
#endif // !UNICODE

HCURSOR
APIENTRY CRITICAL
LoadCursorA(
    IN HANDLE hInstance,
    IN LPSTRID lpCursorName
    );
HCURSOR
APIENTRY CRITICAL
LoadCursorW(
    IN HANDLE hInstance,
    IN LPWSTRID lpCursorName
    );
#ifdef UNICODE
#define LoadCursor LoadCursorW
#else
#define LoadCursor LoadCursorA
#endif // !UNICODE

HCURSOR APIENTRY CRITICAL CreateCursor(IN HANDLE, IN int, IN int, IN int, IN int,
        IN LPMONO1BITS, IN LPMONO2BITS);
HCURSOR APIENTRY CRITICAL CreateDIBCursor(NEXTCOUNT IN LPSTR lpCursorRes,
        IN DWORD cb, IN UINT xHotspot, IN UINT yHotspot);
BOOL    APIENTRY CRITICAL DestroyCursor(IN HCURSOR);

/* Standard Cursor IDs */
#define IDC_ARROW           MAKEINTRESOURCE(32512)
#define IDC_IBEAM           MAKEINTRESOURCE(32513)
#define IDC_WAIT            MAKEINTRESOURCE(32514)
#define IDC_CROSS           MAKEINTRESOURCE(32515)
#define IDC_UPARROW         MAKEINTRESOURCE(32516)
#define IDC_SIZE            MAKEINTRESOURCE(32640)
#define IDC_ICON            MAKEINTRESOURCE(32641)
#define IDC_SIZENWSE        MAKEINTRESOURCE(32642)
#define IDC_SIZENESW        MAKEINTRESOURCE(32643)
#define IDC_SIZEWE          MAKEINTRESOURCE(32644)
#define IDC_SIZENS          MAKEINTRESOURCE(32645)
#define IDC_SIZEALL         MAKEINTRESOURCE(32646)
#define IDC_NO              MAKEINTRESOURCE(32648)

typedef struct _ICONINFO {
    BOOL    fIcon;
    DWORD   xHotspot;
    DWORD   yHotspot;
    HBITMAP hbmMask;
    HBITMAP hbmColor;
} ICONINFO;
typedef ICONINFO *PICONINFO;

HICON
APIENTRY CRITICAL
LoadIconA(
    IN HANDLE hInstance,
    IN LPSTRID lpIconName
    );
HICON
APIENTRY CRITICAL
LoadIconW(
    IN HANDLE hInstance,
    IN LPWSTRID lpIconName
    );
#ifdef UNICODE
#define LoadIcon LoadIconW
#else
#define LoadIcon LoadIconA
#endif // !UNICODE

HICON APIENTRY CRITICAL CreateIcon(IN HANDLE, IN int, IN int, IN BYTE, IN BYTE, IN LPBYTE, IN LPBYTE);
BOOL  APIENTRY CRITICAL DestroyIcon(IN HICON);
int   APIENTRY LookupIconIdFromDirectory(IN PBYTE presbits, IN BOOL fIcon);
HICON APIENTRY CreateIconFromResource(PBYTE presbits, DWORD dwResSize,
        BOOL fIcon, DWORD dwVer);
HICON APIENTRY CreateIconIndirect(IN PICONINFO piconinfo);
BOOL  APIENTRY GetIconInfo(IN HICON hIcon, OUT PICONINFO piconinfo);

#ifdef OEMRESOURCE

/* OEM Resource Ordinal Numbers */
#define OBM_CLOSE           32754
#define OBM_UPARROW         32753
#define OBM_DNARROW         32752
#define OBM_RGARROW         32751
#define OBM_LFARROW         32750
#define OBM_REDUCE          32749
#define OBM_ZOOM            32748
#define OBM_RESTORE         32747
#define OBM_REDUCED         32746
#define OBM_ZOOMD           32745
#define OBM_RESTORED        32744
#define OBM_UPARROWD        32743
#define OBM_DNARROWD        32742
#define OBM_RGARROWD        32741
#define OBM_LFARROWD        32740
#define OBM_MNARROW         32739
#define OBM_COMBO           32738
#define OBM_UPARROWI        32737
#define OBM_DNARROWI        32736
#define OBM_RGARROWI        32735
#define OBM_LFARROWI        32734

#define OBM_OLD_CLOSE       32767
#define OBM_SIZE            32766
#define OBM_OLD_UPARROW     32765
#define OBM_OLD_DNARROW     32764
#define OBM_OLD_RGARROW     32763
#define OBM_OLD_LFARROW     32762
#define OBM_BTSIZE          32761
#define OBM_CHECK           32760
#define OBM_CHECKBOXES      32759
#define OBM_BTNCORNERS      32758
#define OBM_OLD_REDUCE      32757
#define OBM_OLD_ZOOM        32756
#define OBM_OLD_RESTORE     32755

#define OCR_NORMAL          32512
#define OCR_IBEAM           32513
#define OCR_WAIT            32514
#define OCR_CROSS           32515
#define OCR_UP              32516
#define OCR_SIZE            32640
#define OCR_ICON            32641
#define OCR_SIZENWSE        32642
#define OCR_SIZENESW        32643
#define OCR_SIZEWE          32644
#define OCR_SIZENS          32645
#define OCR_SIZEALL         32646
#define OCR_ICOCUR          32647
#define OCR_NO              32648

#define OIC_SAMPLE          32512
#define OIC_HAND            32513
#define OIC_QUES            32514
#define OIC_BANG            32515
#define OIC_NOTE            32516

#endif /* OEMRESOURCE */

#define ORD_LANGDRIVER    1     /* The ordinal number for the entry point of
                                ** language drivers.
                                */

#ifndef NOICONS

/* Standard Icon IDs */
#define IDI_APPLICATION   MAKEINTRESOURCE(32512)
#define IDI_HAND          MAKEINTRESOURCE(32513)
#define IDI_QUESTION      MAKEINTRESOURCE(32514)
#define IDI_EXCLAMATION   MAKEINTRESOURCE(32515)
#define IDI_ASTERISK      MAKEINTRESOURCE(32516)

#endif /* NOICONS */

int
APIENTRY
LoadStringA(
    IN HANDLE hInstance,
    IN UINT wID,
    NEXTCOUNT IN OUT OUTLPSTR lpBuffer,
    IN int nBufferMax
    );
int
APIENTRY
LoadStringW(
    IN HANDLE hInstance,
    IN UINT wID,
    NEXTCOUNT IN OUT OUTLPWSTR lpBuffer,
    IN int nBufferMax
    );
#ifdef UNICODE
#define LoadString LoadStringW
#else
#define LoadString LoadStringA
#endif // !UNICODE

#ifndef NOKANJI

#define CP_HWND           0
#define CP_OPEN           1
#define CP_DIRECT         2

/* VK from the keyboard driver */
#define VK_KANA           0x15
#define VK_ROMAJI         0x16
#define VK_ZENKAKU        0x17
#define VK_HIRAGANA       0x18
#define VK_KANJI          0x19

/* VK to send to Applications */
#define VK_CONVERT        0x1C
#define VK_NONCONVERT     0x1D
#define VK_ACCEPT         0x1E
#define VK_MODECHANGE     0x1F

/* Conversion function numbers */
#define KNJ_START         0x01
#define KNJ_END           0x02
#define KNJ_QUERY         0x03

#define KNJ_LEARN_MODE    0x10
#define KNJ_GETMODE       0x11
#define KNJ_SETMODE       0x12

#define KNJ_CODECONVERT   0x20
#define KNJ_CONVERT       0x21
#define KNJ_NEXT          0x22
#define KNJ_PREVIOUS      0x23
#define KNJ_ACCEPT        0x24

#define KNJ_LEARN         0x30
#define KNJ_REGISTER      0x31
#define KNJ_REMOVE        0x32
#define KNJ_CHANGE_UDIC   0x33

/* NOTE: DEFAULT        = 0
 *       JIS1           = 1
 *       JIS2           = 2
 *       SJIS2          = 3
 *       JIS1KATAKANA   = 4
 *       SJIS2HIRAGANA  = 5
 *       SJIS2KATAKANA  = 6
 *       OEM            = F
 */

#define KNJ_JIS1toJIS1KATAKANA  0x14
#define KNJ_JIS1toSJIS2         0x13
#define KNJ_JIS1toSJIS2HIRAGANA 0x15
#define KNJ_JIS1toSJIS2KATAKANA 0x16
#define KNJ_JIS1toDEFAULT       0x10
#define KNJ_JIS1toSJIS2OEM      0x1F
#define KNJ_JIS2toSJIS2         0x23
#define KNJ_SJIS2toJIS2         0x32

#define KNJ_MD_ALPHA            0x01
#define KNJ_MD_HIRAGANA         0x02
#define KNJ_MD_HALF             0x04
#define KNJ_MD_JIS              0x08
#define KNJ_MD_SPECIAL          0x10

#define KNJ_CVT_NEXT            0x01
#define KNJ_CVT_PREV            0x02
#define KNJ_CVT_KATAKANA        0x03
#define KNJ_CVT_HIRAGANA        0x04
#define KNJ_CVT_JIS1            0x05
#define KNJ_CVT_SJIS2           0x06
#define KNJ_CVT_DEFAULT         0x07
#define KNJ_CVT_TYPED           0x08

typedef struct {
    int         fnc;
    int         wParam;
    LPSTR       lpSource;
    LPSTR       lpDest;
    int         wCount;
    LPSTRNULL  lpReserved1;
    LPSTRNULL  lpReserved2;
} KANJISTRUCT, FAR *LPKANJISTRUCT;

int  APIENTRY ConvertRequest(HWND, LPKANJISTRUCT);
BOOL APIENTRY SetConvertParams(int, int);
VOID APIENTRY SetConvertHook(BOOL);

#endif

/* Key Conversion Window */
BOOL APIENTRY IsTwoByteCharPrefix(char);

/* Dialog Box Command IDs */
#define IDOK                1
#define IDCANCEL            2
#define IDABORT             3
#define IDRETRY             4
#define IDIGNORE            5
#define IDYES               6
#define IDNO                7

#ifndef NOCTLMGR

/* Control Manager Structures and Definitions */

#ifndef NOWINSTYLES

/* Edit Control Styles */
#define ES_LEFT             0x0000L
#define ES_CENTER           0x0001L
#define ES_RIGHT            0x0002L
#define ES_MULTILINE        0x0004L
#define ES_UPPERCASE        0x0008L
#define ES_LOWERCASE        0x0010L
#define ES_PASSWORD         0x0020L
#define ES_AUTOVSCROLL      0x0040L
#define ES_AUTOHSCROLL      0x0080L
#define ES_NOHIDESEL        0x0100L
#define ES_OEMCONVERT       0x0400L
#define ES_READONLY         0x0800L


#endif /* NOWINSTYLES */

/* Edit Control Notification Codes */
#define EN_SETFOCUS         0x0100
#define EN_KILLFOCUS        0x0200
#define EN_CHANGE           0x0300
#define EN_UPDATE           0x0400
#define EN_ERRSPACE         0x0500
#define EN_MAXTEXT          0x0501
#define EN_HSCROLL          0x0601
#define EN_VSCROLL          0x0602

#ifndef NOWINMESSAGES

/* Edit Control Messages */
#define EM_GETSEL           0x00B0
#define EM_SETSEL           0x00B1
#define EM_GETRECT          0x00B2
#define EM_SETRECT          0x00B3
#define EM_SETRECTNP        0x00B4
#define EM_SCROLL           0x00B5
#define EM_LINESCROLL       0x00B6
#define EM_GETMODIFY        0x00B8
#define EM_SETMODIFY        0x00B9
#define EM_GETLINECOUNT     0x00BA
#define EM_LINEINDEX        0x00BB
#define EM_SETHANDLE        0x00BC
#define EM_GETHANDLE        0x00BD
#define EM_GETTHUMB         0x00BE
#define EM_LINELENGTH       0x00C1
#define EM_REPLACESEL       0x00C2
#define EM_SETFONT          0x00C3
#define EM_GETLINE          0x00C4
#define EM_LIMITTEXT        0x00C5
#define EM_CANUNDO          0x00C6
#define EM_UNDO             0x00C7
#define EM_FMTLINES         0x00C8
#define EM_LINEFROMCHAR     0x00C9
#define EM_SETWORDBREAK     0x00CA
#define EM_SETTABSTOPS      0x00CB
#define EM_SETPASSWORDCHAR  0x00CC
#define EM_EMPTYUNDOBUFFER  0x00CD
#define EM_GETFIRSTVISIBLE  0x00CE
#define EM_SETREADONLY      0x00CF
#define EM_MSGMAX           0x00D0

#endif /* NOWINMESSAGES */

/* Button Control Styles */
#define BS_PUSHBUTTON      0x00L
#define BS_DEFPUSHBUTTON   0x01L
#define BS_CHECKBOX        0x02L
#define BS_AUTOCHECKBOX    0x03L
#define BS_RADIOBUTTON     0x04L
#define BS_3STATE          0x05L
#define BS_AUTO3STATE      0x06L
#define BS_GROUPBOX        0x07L
#define BS_USERBUTTON      0x08L
#define BS_AUTORADIOBUTTON 0x09L
#define BS_PUSHBOX         0x0AL
#define BS_OWNERDRAW       0x0BL
#define BS_LEFTTEXT        0x20L


/* User Button Notification Codes */
#define BN_CLICKED         0
#define BN_PAINT           1
#define BN_HILITE          2
#define BN_UNHILITE        3
#define BN_DISABLE         4
#define BN_DOUBLECLICKED   5

/* Button Control Messages */
#define BM_GETCHECK        0x00F0
#define BM_SETCHECK        0x00F1
#define BM_GETSTATE        0x00F2
#define BM_SETSTATE        0x00F3
#define BM_SETSTYLE        0x00F4

/* Static Control Constants */
#define SS_LEFT            0x00L
#define SS_CENTER          0x01L
#define SS_RIGHT           0x02L
#define SS_ICON            0x03L
#define SS_BLACKRECT       0x04L
#define SS_GRAYRECT        0x05L
#define SS_WHITERECT       0x06L
#define SS_BLACKFRAME      0x07L
#define SS_GRAYFRAME       0x08L
#define SS_WHITEFRAME      0x09L
#define SS_USERITEM        0x0AL
#define SS_SIMPLE          0x0BL
#define SS_LEFTNOWORDWRAP  0x0CL
#define SS_NOPREFIX        0x80L    /* Don't do "&" character translation */

#ifndef NOWINMESSAGES
/* Static Control Mesages */
#define STM_SETICON        0x0D0
#define STM_GETICON        0x0D1
#define STM_MSGMAX         0x0D2
#endif /* NOWINMESSAGES */
/* Dialog Manager Routines */

#ifndef NOMSG
BOOL APIENTRY CRITICAL XXX IsDialogMessage(IN HWND hDlg, IN LPMSG lpMsg);
#endif

BOOL APIENTRY CRITICAL MapDialogRect(IN HWND hDlg, IN OUT LPRECT lpRect);

int
APIENTRY CRITICAL XXX
DlgDirListA(
    IN HWND hDlg,
    IN OUT LPSTR lpPathSpec,
    IN int nIDListBox,
    IN int nIDStaticPath,
    IN UINT wFileType
    );
int
APIENTRY CRITICAL XXX
DlgDirListW(
    IN HWND hDlg,
    IN OUT LPWSTR lpPathSpec,
    IN int nIDListBox,
    IN int nIDStaticPath,
    IN UINT wFileType
    );
#ifdef UNICODE
#define DlgDirList DlgDirListW
#else
#define DlgDirList DlgDirListA
#endif // !UNICODE

BOOL
APIENTRY CRITICAL XXX
DlgDirSelectExA(
    IN HWND hDlg,
    NEXTCOUNT IN OUT OUTLPSTR lpString,
    IN int nCount,
    IN int nIDListBox
    );
BOOL
APIENTRY CRITICAL XXX
DlgDirSelectExW(
    IN HWND hDlg,
    NEXTCOUNT IN OUT OUTLPWSTR lpString,
    IN int nCount,
    IN int nIDListBox
    );
#ifdef UNICODE
#define DlgDirSelectEx DlgDirSelectExW
#else
#define DlgDirSelectEx DlgDirSelectExA
#endif // !UNICODE

int
APIENTRY CRITICAL XXX
DlgDirListComboBoxA(
    IN HWND hDlg,
    IN OUT LPSTR lpPathSpec,
    IN int nIDComboBox,
    IN int nIDStaticPath,
    IN UINT wFiletype
    );
int
APIENTRY CRITICAL XXX
DlgDirListComboBoxW(
    IN HWND hDlg,
    IN OUT LPWSTR lpPathSpec,
    IN int nIDComboBox,
    IN int nIDStaticPath,
    IN UINT wFiletype
    );
#ifdef UNICODE
#define DlgDirListComboBox DlgDirListComboBoxW
#else
#define DlgDirListComboBox DlgDirListComboBoxA
#endif // !UNICODE

BOOL
APIENTRY CRITICAL XXX
DlgDirSelectComboBoxExA(
    IN HWND hDlg,
    NEXTCOUNT IN OUT OUTLPSTR lpString,
    IN int nCount,
    IN int nIDComboBox
    );
BOOL
APIENTRY CRITICAL XXX
DlgDirSelectComboBoxExW(
    IN HWND hDlg,
    NEXTCOUNT IN OUT OUTLPWSTR lpString,
    IN int nCount,
    IN int nIDComboBox
    );
#ifdef UNICODE
#define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#else
#define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#endif // !UNICODE


/* Dialog Styles */
#define DS_ABSALIGN         0x01L
#define DS_SYSMODAL         0x02L
#define DS_LOCALEDIT        0x20L   /* Edit items get Local storage. */
#define DS_SETFONT          0x40L   /* User specified font for Dlg controls */
#define DS_MODALFRAME       0x80L   /* Can be combined with WS_CAPTION  */
#define DS_NOIDLEMSG        0x100L  /* WM_ENTERIDLE message will not be sent */
#define DS_SETFOREGROUND    0x200L

#define DM_GETDEFID         (WM_USER+0)
#define DM_SETDEFID         (WM_USER+1)
#define DC_HASDEFID         0x534B

/* Dialog Codes */
#define DLGC_WANTARROWS     0x0001      /* Control wants arrow keys         */
#define DLGC_WANTTAB        0x0002      /* Control wants tab keys           */
#define DLGC_WANTALLKEYS    0x0004      /* Control wants all keys           */
#define DLGC_WANTMESSAGE    0x0004      /* Pass message to control          */
#define DLGC_HASSETSEL      0x0008      /* Understands EM_SETSEL message    */
#define DLGC_DEFPUSHBUTTON  0x0010      /* Default pushbutton               */
#define DLGC_UNDEFPUSHBUTTON 0x0020     /* Non-default pushbutton           */
#define DLGC_RADIOBUTTON    0x0040      /* Radio button                     */
#define DLGC_WANTCHARS      0x0080      /* Want WM_CHAR messages            */
#define DLGC_STATIC         0x0100      /* Static item: don't include       */
#define DLGC_BUTTON         0x2000      /* Button item: can be checked      */

#define LB_CTLCODE          0L

/* Listbox Return Values */
#define LB_OKAY             0
#define LB_ERR              (-1)
#define LB_ERRSPACE         (-2)

/*
**  The idStaticPath parameter to DlgDirList can have the following values
**  ORed if the list box should show other details of the files along with
**  the name of the files;
*/
                                  /* all other details also will be returned */


/* Listbox Notification Codes */
#define LBN_ERRSPACE        (-2)
#define LBN_SELCHANGE       1
#define LBN_DBLCLK          2
#define LBN_SELCANCEL       3
#define LBN_SETFOCUS        4
#define LBN_KILLFOCUS       5



#ifndef NOWINMESSAGES

/* Listbox messages */
#define LB_ADDSTRING            0x0180
#define LB_INSERTSTRING         0x0181
#define LB_DELETESTRING         0x0182
#define LB_RESETCONTENT         0x0184
#define LB_SETSEL               0x0185
#define LB_SETCURSEL            0x0186
#define LB_GETSEL               0x0187
#define LB_GETCURSEL            0x0188
#define LB_GETTEXT              0x0189
#define LB_GETTEXTLEN           0x018A
#define LB_GETCOUNT             0x018B
#define LB_SELECTSTRING         0x018C
#define LB_DIR                  0x018D
#define LB_GETTOPINDEX          0x018E
#define LB_FINDSTRING           0x018F
#define LB_GETSELCOUNT          0x0190
#define LB_GETSELITEMS          0x0191
#define LB_SETTABSTOPS          0x0192
#define LB_GETHORIZONTALEXTENT  0x0193
#define LB_SETHORIZONTALEXTENT  0x0194
#define LB_SETCOLUMNWIDTH       0x0195
#define LB_SETTOPINDEX          0x0197
#define LB_GETITEMRECT          0x0198
#define LB_GETITEMDATA          0x0199
#define LB_SETITEMDATA          0x019A
#define LB_SELITEMRANGE         0x019B
#define LB_SETITEMHEIGHT        0x01A0
#define LB_GETITEMHEIGHT        0x01A1
#define LB_MSGMAX               0x01A2

#endif /* NOWINMESSAGES */

#ifndef NOWINSTYLES

/* Listbox Styles */
#define LBS_NOTIFY            0x0001L
#define LBS_SORT              0x0002L
#define LBS_NOREDRAW          0x0004L
#define LBS_MULTIPLESEL       0x0008L
#define LBS_OWNERDRAWFIXED    0x0010L
#define LBS_OWNERDRAWVARIABLE 0x0020L
#define LBS_HASSTRINGS        0x0040L
#define LBS_USETABSTOPS       0x0080L
#define LBS_NOINTEGRALHEIGHT  0x0100L
#define LBS_MULTICOLUMN       0x0200L
#define LBS_WANTKEYBOARDINPUT 0x0400L
#define LBS_EXTENDEDSEL       0x0800L
#define LBS_DISABLENOSCROLL   0x1000L
#define LBS_STANDARD          (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

#endif /* NOWINSTYLES */


/* Combo Box return Values */
#define CB_OKAY             0
#define CB_ERR              (-1)
#define CB_ERRSPACE         (-2)


/* Combo Box Notification Codes */
#define CBN_ERRSPACE        (-1)
#define CBN_SELCHANGE       1
#define CBN_DBLCLK          2
#define CBN_SETFOCUS        3
#define CBN_KILLFOCUS       4
#define CBN_EDITCHANGE      5
#define CBN_EDITUPDATE      6
#define CBN_DROPDOWN        7
#define CBN_CLOSEUP         8

/* Combo Box styles */
#ifndef NOWINSTYLES
#define CBS_SIMPLE            0x0001L
#define CBS_DROPDOWN          0x0002L
#define CBS_DROPDOWNLIST      0x0003L
#define CBS_OWNERDRAWFIXED    0x0010L
#define CBS_OWNERDRAWVARIABLE 0x0020L
#define CBS_AUTOHSCROLL       0x0040L
#define CBS_OEMCONVERT        0x0080L
#define CBS_SORT              0x0100L
#define CBS_HASSTRINGS        0x0200L
#define CBS_NOINTEGRALHEIGHT  0x0400L
#define CBS_DISABLENOSCROLL   0x0800L
#endif  /* NOWINSTYLES */


/* Combo Box messages */
#ifndef NOWINMESSAGES
#define CB_GETEDITSEL               0x0140
#define CB_LIMITTEXT                0x0141
#define CB_SETEDITSEL               0x0142
#define CB_ADDSTRING                0x0143
#define CB_DELETESTRING             0x0144
#define CB_DIR                      0x0145
#define CB_GETCOUNT                 0x0146
#define CB_GETCURSEL                0x0147
#define CB_GETLBTEXT                0x0148
#define CB_GETLBTEXTLEN             0x0149
#define CB_INSERTSTRING             0x014A
#define CB_RESETCONTENT             0x014B
#define CB_FINDSTRING               0x014C
#define CB_SELECTSTRING             0x014D
#define CB_SETCURSEL                0x014E
#define CB_SHOWDROPDOWN             0x014F
#define CB_GETITEMDATA              0x0150
#define CB_SETITEMDATA              0x0151
#define CB_GETDROPPEDCONTROLRECT    0x0152
#define CB_SETITEMHEIGHT            0x0153
#define CB_GETITEMHEIGHT            0x0154
#define CB_SETEXTENDEDUI            0x0155
#define CB_GETEXTENDEDUI            0x0156
#define CB_GETDROPPEDSTATE          0x0157
#define CB_MSGMAX                   0x0158
#endif  /* NOWINMESSAGES */



#ifndef NOWINSTYLES

/* Scroll Bar Styles */
#define SBS_HORZ                    0x0000L
#define SBS_VERT                    0x0001L
#define SBS_TOPALIGN                0x0002L
#define SBS_LEFTALIGN               0x0002L
#define SBS_BOTTOMALIGN             0x0004L
#define SBS_RIGHTALIGN              0x0004L
#define SBS_SIZEBOXTOPLEFTALIGN     0x0002L
#define SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#define SBS_SIZEBOX                 0x0008L
#endif /* NOWINSTYLES */

/* Scroll bar messages */
#ifndef NOWINMESSAGES
#define SBM_SETPOS                  0x00E0
#define SBM_GETPOS                  0x00E1
#define SBM_SETRANGE                0x00E2
#define SBM_GETRANGE                0x00E3
#define SBM_ENABLE_ARROWS           0x00E4
#endif
#endif /* NOCTLMGR */

#ifndef NOMDI

/* MDI client style bits */
#define MDIS_ALLCHILDSTYLES    0x0001

/* wParam Flags for WM_MDITILE and WM_MDICASCADE messages. */
#define MDITILE_VERTICAL       0x0000
#define MDITILE_HORIZONTAL     0x0001
#define MDITILE_SKIPDISABLED   0x0002

typedef struct tagMDICREATESTRUCTA {
    LPSTRID   szClass;
    LPSTRNULL   szTitle;
    HANDLE hOwner;
    int x;
    int y;
    int cx;
    int cy;
    LONG style;
    LONG lParam;        /* app-defined stuff */
} MDICREATESTRUCTA, *LPMDICREATESTRUCTA;
typedef struct tagMDICREATESTRUCTW {
    LPWSTRID  szClass;
    LPWSTRNULL  szTitle;
    HANDLE hOwner;
    int x;
    int y;
    int cx;
    int cy;
    LONG style;
    LONG lParam;        /* app-defined stuff */
} MDICREATESTRUCTW, *LPMDICREATESTRUCTW;
#ifdef UNICODE
#define MDICREATESTRUCT MDICREATESTRUCTW
#define LPMDICREATESTRUCT LPMDICREATESTRUCTW
#else
#define MDICREATESTRUCT MDICREATESTRUCTA
#define LPMDICREATESTRUCT LPMDICREATESTRUCTA
#endif // UNICODE

typedef struct tagCLIENTCREATESTRUCT {
    HANDLE hWindowMenu;
    UINT idFirstChild;
} CLIENTCREATESTRUCT, *LPCLIENTCREATESTRUCT;

LONG APIENTRY CRITICAL XXX DefFrameProcA(IN HWND hWnd, IN HWND hWndMDIClient OPTIONAL, IN UINT wMsg, IN DWORD wParam, IN LONG lParam);
LONG APIENTRY CRITICAL XXX DefFrameProcW(IN HWND hWnd, IN HWND hWndMDIClient OPTIONAL, IN UINT wMsg, IN DWORD wParam, IN LONG lParam);
#ifdef UNICODE
#define DefFrameProc DefFrameProcW
#else
#define DefFrameProc DefFrameProcA
#endif // !UNICODE
LONG APIENTRY CRITICAL XXX DefMDIChildProcA(IN HWND hWnd, IN UINT wMsg, IN DWORD wParam, IN LONG lParam);
LONG APIENTRY CRITICAL XXX DefMDIChildProcW(IN HWND hWnd, IN UINT wMsg, IN DWORD wParam, IN LONG lParam);
#ifdef UNICODE
#define DefMDIChildProc DefMDIChildProcW
#else
#define DefMDIChildProc DefMDIChildProcA
#endif // !UNICODE

#ifndef NOMSG
BOOL APIENTRY CRITICAL XXX TranslateMDISysAccel(IN HWND hWndClient, IN LPMSG lpMsg);
#endif

UINT APIENTRY CRITICAL XXX ArrangeIconicWindows(IN HWND hWnd);

#endif /* NOMDI */

#endif /* NOUSER */

#ifndef NOHELP

/*  Help engine section.  */

typedef DWORD HELPPOLY;
typedef struct tagMULTIKEYHELP {
    DWORD mkSize;
    BYTE  mkKeylist;
    BYTE  szKeyphrase[1];
} MULTIKEYHELP;

//
// Commands to pass WinHelp()
//

#define HELP_CONTEXT    0x0001L   /* Display topic in ulTopic */
#define HELP_QUIT       0x0002L   /* Terminate help */
#define HELP_INDEX      0x0003L   /* Display index */
#define HELP_HELPONHELP 0x0004L   /* Display help on using help */
#define HELP_SETINDEX   0x0005L   /* Set the current Index for multi index help */
#define HELP_KEY        0x0101L   /* Display topic for keyword in offabData */
#define HELP_MULTIKEY   0x0201L

BOOL
APIENTRY CRITICAL XXX
WinHelpA(
    IN HWND hwndMain,
    IN LPSTR lpszHelp,
    IN DWORD dwCommand,
    IN HELPPOLY dwData
    );
BOOL
APIENTRY CRITICAL XXX
WinHelpW(
    IN HWND hwndMain,
    IN LPWSTR lpszHelp,
    IN DWORD dwCommand,
    IN HELPPOLY dwData
    );
#ifdef UNICODE
#define WinHelp WinHelpW
#else
#define WinHelp WinHelpA
#endif // !UNICODE

#endif /* NOHELP */

#ifndef NOPROFILER

/* function declarations for profiler routines contained in Windows libraries */
int  APIENTRY ProfInsChk(void);
void APIENTRY ProfSetup(int,int);
void APIENTRY ProfSampRate(int,int);
void APIENTRY ProfStart(void);
void APIENTRY ProfStop(void);
void APIENTRY ProfClear(void);
void APIENTRY ProfFlush(void);
void APIENTRY ProfFinish(void);

#endif /* NOPROFILER */

#ifndef NOSYSPARAMSINFO
/* Parameter for SystemParametersInfo() */

#define SPI_GETBEEP                 1
#define SPI_SETBEEP                 2
#define SPI_GETMOUSE                3
#define SPI_SETMOUSE                4
#define SPI_GETBORDER               5
#define SPI_SETBORDER               6
#define SPI_TIMEOUTS                7
#define SPI_KANJIMENU               8   /*; Internal */
#define SPI_GETKEYBOARDSPEED       10
#define SPI_SETKEYBOARDSPEED       11
#define SPI_LANGDRIVER             12
#define SPI_ICONHORIZONTALSPACING  13
#define SPI_GETSCREENSAVETIMEOUT   14
#define SPI_SETSCREENSAVETIMEOUT   15
#define SPI_GETSCREENSAVEACTIVE    16
#define SPI_SETSCREENSAVEACTIVE    17
#define SPI_GETGRIDGRANULARITY     18
#define SPI_SETGRIDGRANULARITY     19
#define SPI_SETDESKWALLPAPER       20
#define SPI_SETDESKPATTERN         21
#define SPI_GETKEYBOARDDELAY       22
#define SPI_SETKEYBOARDDELAY       23
#define SPI_ICONVERTICALSPACING    24
#define SPI_GETICONTITLEWRAP       25
#define SPI_SETICONTITLEWRAP       26
#define SPI_GETMENUDROPALIGNMENT   27
#define SPI_SETMENUDROPALIGNMENT   28
#define SPI_SETDOUBLECLKWIDTH      29
#define SPI_SETDOUBLECLKHEIGHT     30
#define SPI_GETICONTITLELOGFONT    31
#define SPI_SETDOUBLECLICKTIME     32
#define SPI_SETMOUSEBUTTONSWAP     33


BOOL CRITICAL XXX SystemParametersInfo(UINT, UINT, LONG, UINT);

/* Flags */
#define SPIF_UPDATEINIFILE    0x0001
#define SPIF_SENDWININICHANGE 0x0002

#endif  /* NOSYSPARAMSINFO  */

#endif // _WINUSER_
