/*++ BUILD Version: 0003    // Increment this if a change has global effects

Copyright (c) 1991, Microsoft Corporation

Module Name:

    winnls.h

Abstract:

    Procedure declarations, constant definitions, and macros for the
    NLS component.

Author:

    Julie Bennett (julieb) 31-May-1991

--*/

#ifndef _WINNLS_
#define _WINNLS_

#ifndef NONLS


/***************************************************************************\
* Constants
*
* Define all constants for the NLS component here.
\***************************************************************************/

/*
 *  String Length Maximums.
 */
#define MAX_LANG_LEN         255            /* maximum language length */
#define MAX_CTRY_LEN         255            /* maximum country length */
#define MAX_CP_LEN           255            /* maximum codepage length */


/*
 *  MBCS and Unicode Translation Flags.
 */
#define MB_PRECOMPOSED       0x00000001     /* use precomposed chars */
#define MB_COMPOSITE         0x00000002     /* use composite chars */

#define WC_DISCARDNS         0x00000010     /* discard non-spacing chars */
#define WC_SEPCHARS          0x00000020     /* generate seperate chars */
#define WC_REPLACEBASE       0x00000040     /* replace base char w/ default */


/*
 *  Character Type Flags.
 */
#define CT_CTYPE1            0x00000001     /* ctype 1 information */
#define CT_CTYPE2            0x00000002     /* ctype 2 information */

/*
 *  CType 1 Flag Bits.
 */
#define C1_UPPERCASE         0x0001         /* upper case */
#define C1_LOWERCASE         0x0002         /* lower case */
#define C1_DIGIT             0x0004         /* 0-9 */
#define C1_WHITESPACE        0x0008         /* tab,CR,NL,vertical tab,form feed */
#define C1_PUNCTUATION       0x0010         /* punctuation character */
#define C1_CONTROLCHAR       0x0020         /* control character */
#define C1_ALPHA             0x0100         /* A-Z, a-z */
#define C1_NONSPACING        0x0200         /* nonspacing character */
#define C1_SYMBOL            0x0400         /* ! @ # $ % ^ & * ( ) etc. */
#define C1_ISNUMERIC         0x0800         /* numeric value */

/*
 *  CType 2 Flag Bits.
 */
#define C2_LEFTTORIGHT       0x0001         /* left to right */
#define C2_RIGHTTOLEFT       0x0002         /* right to left */

#define C2_EUROPENUMBER      0x0004         /* European number, digit */
#define C2_EUROPESEPERATOR   0x0008         /* European numeric seperator */
#define C2_EUROPETERMINATOR  0x0010         /* European numeric terminator */
#define C2_ARABICNUMBER      0x0020         /* Arabic number */
#define C2_COMMONSEPERATOR   0x0040         /* common numeric seperator */

#define C2_BLOCKSEPERATOR    0x0080         /* block seperator paragraph */
#define C2_SEGMENTSEPERATOR  0x0100         /* segment seperator */
#define C2_WHITESPACE        0x0200         /* white space */
#define C2_OTHERNEUTRAL      0x0400         /* other neutrals */


/*
 *  String Flags.
 */
#define STR_IGNORECASE       0x00000001     /* ignore case */
#define STR_IGNORENONSPACE   0x00000002     /* ignore nonspacing chars */
#define STR_IGNORESYMBOLS    0x00000004     /* ignore symbols */

/*
 *  Mapping Flags.
 */
#define MAP_UPPERCASE        0x00000010     /* upper case letters */
#define MAP_LOWERCASE        0x00000020     /* lower case letters */
#define MAP_CTYPE1           0x00000040     /* ctype 1 info */
#define MAP_CTYPE2           0x00000080     /* ctype 2 info */

#define MAP_COLLATE          0x00000100     /* collation (sort) table */
#define MAP_SORTKEY          0x00000200     /* sort key */

#define MAP_UCTOMB           0x00000400     /* UC to MB table */
#define MAP_MBTOUC           0x00000800     /* MB to UC table */

#define MAP_FOLDCZONE        0x00001000     /* fold compatibility zone chars */
#define MAP_PRECOMPOSED      0x00002000     /* accented to precomposed chars */
#define MAP_COMPOSITE        0x00004000     /* accented to composite chars */
#define MAP_ASCIIDIGITS      0x00008000     /* all digits to ASCII 0-9 */


/*
 *  Locale Information Flags.
 */
#define LI_CPDATA            0x00000001     /* code page data */
#define LI_CTRYDATA          0x00000002     /* country data */
#define LI_LANGDATA          0x00000004     /* language data */
#define LI_LCMONETARY        0x00000008     /* monetary conventions */
#define LI_LCNUMERIC         0x00000010     /* numeric conventions */
#define LI_DATETIMEFMT       0x00000020     /* date/time formats */
#define LI_DATETIMESTR       0x00000040     /* date/time strings */


/*
 *  Qualified Locale Flags.
 */
#define QF_LCID              0x00000001     /* LCID structure */
#define QF_STRINGS           0x00000002     /* LCSTRINGS structure */


/*
 *  Language IDs.
 *
 *  The following two combinations of primary language ID and
 *  sublanguage ID have special semantics: 
 *
 *    Primary Language ID   Sublanguage ID      Result
 *    -------------------   ---------------     ------------------------
 *    LANG_NEUTRAL          SUBLANG_NEUTRAL     Language neutral
 *    LANG_NEUTRAL          SUBLANG_DEFAULT     Process default language
 */

/*
 *  Primary language IDs.
 */
#define LANG_NEUTRAL                     0x00

#define LANG_ALBANIAN                    0x1c
#define LANG_ARABIC                      0x01
#define LANG_BAHASA                      0x21
#define LANG_BULGARIAN                   0x02
#define LANG_CATALAN                     0x03
#define LANG_CHINESE                     0x04
#define LANG_CZECH                       0x05
#define LANG_DANISH                      0x06
#define LANG_DUTCH                       0x13
#define LANG_ENGLISH                     0x09
#define LANG_FINNISH                     0x0b
#define LANG_FRENCH                      0x0c
#define LANG_GERMAN                      0x07
#define LANG_GREEK                       0x08
#define LANG_HEBREW                      0x0d
#define LANG_HUNGARIAN                   0x0e
#define LANG_ICELANDIC                   0x0f
#define LANG_ITALIAN                     0x10
#define LANG_JAPANESE                    0x11
#define LANG_KOREAN                      0x12
#define LANG_NORWEGIAN                   0x14
#define LANG_POLISH                      0x15
#define LANG_PORTUGUESE                  0x16
#define LANG_RHAETO_ROMAN                0x17
#define LANG_ROMANIAN                    0x18
#define LANG_RUSSIAN                     0x19
#define LANG_SERBO_CROATIAN              0x1a
#define LANG_SLOVAK                      0x1b
#define LANG_SPANISH                     0x0a
#define LANG_SWEDISH                     0x1d
#define LANG_THAI                        0x1e
#define LANG_TURKISH                     0x1f
#define LANG_URDU                        0x20

/*
 *  Sublanguage IDs.
 *
 *  The name immediately following SUBLANG_ dictates which primary
 *  language ID that sublanguage ID can be combined with to form a
 *  valid language ID.
 */
#define SUBLANG_DEFAULT                  0x01    /* language/process default */
#define SUBLANG_NEUTRAL                  0x00    /* language neutral */

#define SUBLANG_CHINESE_SIMPLIFIED       0x02    /* Chinese (Simplified) */
#define SUBLANG_CHINESE_TRADITIONAL      0x01    /* Chinese (Traditional) */ 
#define SUBLANG_DUTCH                    0x01    /* Dutch */
#define SUBLANG_DUTCH_BELGIAN            0x02    /* Dutch (Belgian) */
#define SUBLANG_ENGLISH_US               0x01    /* English (USA) */
#define SUBLANG_ENGLISH_UK               0x02    /* English (UK) */
#define SUBLANG_ENGLISH_AUS              0x03    /* English (Australian) */
#define SUBLANG_ENGLISH_CAN              0x04    /* English (Canadian) */
#define SUBLANG_FRENCH                   0x01    /* French */
#define SUBLANG_FRENCH_BELGIAN           0x02    /* French (Belgian) */
#define SUBLANG_FRENCH_CANADIAN          0x03    /* French (Canadian) */
#define SUBLANG_FRENCH_SWISS             0x04    /* French (Swiss) */
#define SUBLANG_GERMAN                   0x01    /* German */
#define SUBLANG_GERMAN_SWISS             0x02    /* German (Swiss) */
#define SUBLANG_ITALIAN                  0x01    /* Italian */
#define SUBLANG_ITALIAN_SWISS            0x02    /* Italian (Swiss) */
#define SUBLANG_NORWEGIAN_BOKMAL         0x01    /* Norwegian (Bokmal) */
#define SUBLANG_NORWEGIAN_NYNORSK        0x02    /* Norwegian (Nynorsk) */
#define SUBLANG_PORTUGUESE               0x02    /* Portuguese */
#define SUBLANG_PORTUGUESE_BRAZILIAN     0x01    /* Portuguese (Brazilian) */
#define SUBLANG_SERBO_CROATIAN_CYRILLIC  0x02    /* Serbo-Croatian (Cyrillic) */
#define SUBLANG_SERBO_CROATIAN_LATIN     0x01    /* Croato-Serbian (Latin) */
#define SUBLANG_SPANISH                  0x01    /* Spanish */
#define SUBLANG_SPANISH_MEXICAN          0x02    /* Spanish (Mexican) */
#define SUBLANG_SPANISH_MODERN           0x03    /* Spanish (Modern) */



/***************************************************************************\
* Typedefs
*
* Define all types for the NLS component here.
\***************************************************************************/

/*
 *  Handles.
 */
typedef HANDLE     HLOCALE;                 /* locale handle */
typedef HANDLE     HLCID;                   /* lcid handle */


/*
 *  Locale ID.
 */
typedef struct _lcid {
    WORD wLanguage;                         /* language id */
    UINT Country;                           /* country id */ 
    UINT CodePage;                          /* codepage id */
} LCID, *LPLCID;


/*
 *  Locale Strings.
 */
typedef struct _lcstrings {
    CHAR szLanguage[MAX_LANG_LEN];          /* language name */
    CHAR szCountry[MAX_CTRY_LEN];           /* country name */
    CHAR szCodePage[MAX_CP_LEN];            /* codepage name */
} LCSTRINGS, *LPLCSTRINGS;



/***************************************************************************\
* Macros
*
* Define all macros for the NLS component here.
\***************************************************************************/

/*
 *  A language ID is a 16 bit value which is the combination of a
 *  primary language ID and a secondary language ID.  The bits are
 *  allocated as follows:
 *
 *       +-----------------------+-------------------------+
 *       |      Sublanguage ID   |   Primary Language ID   |
 *       +-----------------------+-------------------------+
 *        15                   10 9                       0   bit
 */

/*
 *  Language ID creation/extraction macros:
 *
 *    MAKELANGID - construct language id from primary language id and
 *                 sublanguage id.
 *    PRIMARYLANGID - extract primary language id from a language id.
 *    SUBLANGID - extract sublanguage id from a language id.
 */
#define MAKELANGID(p, s)     ((((USHORT)(s)) << 10) | (USHORT)(p))
#define PRIMARYLANGID(lgid)  ((USHORT)(lgid) & 0x1ff)
#define SUBLANGID(lgid)      ((USHORT)(lgid) >> 10)



/***************************************************************************\
* Function Prototypes
*
* Only prototypes for the NLS APIs should go here.
\***************************************************************************/

/*
 *  MBCS Translation APIs.
 */
int     APIENTRY MultiByteToWideChar(UINT, LPSTR, int, LPWSTR, int *, DWORD);
int     APIENTRY WideCharToMultiByte(UINT, LPWSTR, int, LPSTR, int *, LPSTR,
                                     LPBOOL, DWORD);
int     APIENTRY MultiByteToMultiByte(UINT, UINT, LPSTR, int, UINT, LPSTR,
                                      int *);
int     APIENTRY GetDBCSLeadBytes(UINT, UINT *, LPBYTE, int *);


/*
 *  High Level APIs.
 */
HLOCALE APIENTRY OpenLocale(LPLCID);
BOOL    APIENTRY CloseLocale(HLOCALE);
BOOL    APIENTRY GetCharType(HLOCALE, DWORD, WCHAR, LPWORD);
int     APIENTRY CompareString(HLOCALE, DWORD, LPWSTR, int, LPWSTR, int);
int     APIENTRY MapString(HLOCALE, DWORD, LPWSTR, int, LPWSTR, int *);
int     APIENTRY QueryMap(HLOCALE, DWORD, DWORD, WCHAR, WCHAR, LPVOID, LPDWORD);


/*
 *  Low Level APIs.
 */
HLCID APIENTRY BeginEnumLocale(DWORD, LPLCID);
BOOL  APIENTRY GetNextLocale(HLCID, LPLCID);
BOOL  APIENTRY EndEnumLocale(HLCID);
int   APIENTRY GetLocaleInfo(LPLCID, DWORD, LPVOID, LPDWORD);
BOOL  APIENTRY GetQualifiedLocale(DWORD, LPVOID, LPLCID, LPLCSTRINGS);



#endif   // NONLS

#endif   // _WINNLS_
