/*++ BUILD Version: 0004    // Increment this if a change has global effects

Copyright (c) 1985-91, Microsoft Corporation

Module Name:

    wingdi.h

Abstract:

    Procedure declarations, constant definitions and macros for the GDI
    component.

--*/

#ifndef _WINGDI_
#define _WINGDI_

#ifndef NOGDI

#ifndef NORASTEROPS

/* Binary raster ops */
#define R2_BLACK            1   /*  0       */
#define R2_NOTMERGEPEN      2   /* DPon     */
#define R2_MASKNOTPEN       3   /* DPna     */
#define R2_NOTCOPYPEN       4   /* PN       */
#define R2_MASKPENNOT       5   /* PDna     */
#define R2_NOT              6   /* Dn       */
#define R2_XORPEN           7   /* DPx      */
#define R2_NOTMASKPEN       8   /* DPan     */
#define R2_MASKPEN          9   /* DPa      */
#define R2_NOTXORPEN        10  /* DPxn     */
#define R2_NOP              11  /* D        */
#define R2_MERGENOTPEN      12  /* DPno     */
#define R2_COPYPEN          13  /* P        */
#define R2_MERGEPENNOT      14  /* PDno     */
#define R2_MERGEPEN         15  /* DPo      */
#define R2_WHITE            16  /*  1       */
#define R2_LAST             16

/*  Ternary raster operations */
#define SRCCOPY             (DWORD)0x00CC0020 /* dest = source                   */
#define SRCPAINT            (DWORD)0x00EE0086 /* dest = source OR dest           */
#define SRCAND              (DWORD)0x008800C6 /* dest = source AND dest          */
#define SRCINVERT           (DWORD)0x00660046 /* dest = source XOR dest          */
#define SRCERASE            (DWORD)0x00440328 /* dest = source AND (NOT dest )   */
#define NOTSRCCOPY          (DWORD)0x00330008 /* dest = (NOT source)             */
#define NOTSRCERASE         (DWORD)0x001100A6 /* dest = (NOT src) AND (NOT dest) */
#define MERGECOPY           (DWORD)0x00C000CA /* dest = (source AND pattern)     */
#define MERGEPAINT          (DWORD)0x00BB0226 /* dest = (NOT source) OR dest     */
#define PATCOPY             (DWORD)0x00F00021 /* dest = pattern                  */
#define PATPAINT            (DWORD)0x00FB0A09 /* dest = DPSnoo                   */
#define PATINVERT           (DWORD)0x005A0049 /* dest = pattern XOR dest         */
#define DSTINVERT           (DWORD)0x00550009 /* dest = (NOT dest)               */
#define BLACKNESS           (DWORD)0x00000042 /* dest = BLACK                    */
#define WHITENESS           (DWORD)0x00FF0062 /* dest = WHITE                    */
#endif /* NORASTEROPS */

#define GDI_ERROR (0xFFFFFFFFL)

/* Region Flags */
#define ERROR               0
#define NULLREGION          1
#define SIMPLEREGION        2
#define COMPLEXREGION       3
#define RGN_ERROR ERROR

/* CombineRgn() Styles */
#define RGN_AND             1
#define RGN_OR              2
#define RGN_XOR             3
#define RGN_DIFF            4
#define RGN_COPY            5
#define RGN_MIN             RGN_AND
#define RGN_MAX             RGN_COPY

/* StretchBlt() Modes */
#define BLACKONWHITE                 1
#define WHITEONBLACK                 2
#define COLORONCOLOR                 3
#define BLEND                        4
#define HALFTONE                     5
#define MAXSTRETCHBLTMODE            5

/* PolyFill() Modes */
#define ALTERNATE                    1
#define WINDING                      2
#define POLYFILL_LAST                2

/* Text Alignment Options */
#define TA_NOUPDATECP                0
#define TA_UPDATECP                  1

#define TA_LEFT                      0
#define TA_RIGHT                     2
#define TA_CENTER                    6

#define TA_TOP                       0
#define TA_BOTTOM                    8
#define TA_BASELINE                  24
#define TA_MASK       (TA_BASELINE+TA_CENTER+TA_UPDATECP)

#define ETO_GRAYED                   1
#define ETO_OPAQUE                   2
#define ETO_CLIPPED                  4

#define ASPECT_FILTERING             0x0001

#ifndef NOMETAFILE

/* Metafile Functions */
#define META_SETBKCOLOR              0x0201
#define META_SETBKMODE               0x0102
#define META_SETMAPMODE              0x0103
#define META_SETROP2                 0x0104
#define META_SETRELABS               0x0105
#define META_SETPOLYFILLMODE         0x0106
#define META_SETSTRETCHBLTMODE       0x0107
#define META_SETTEXTCHAREXTRA        0x0108
#define META_SETTEXTCOLOR            0x0209
#define META_SETTEXTJUSTIFICATION    0x020A
#define META_SETWINDOWORG            0x020B
#define META_SETWINDOWEXT            0x020C
#define META_SETVIEWPORTORG          0x020D
#define META_SETVIEWPORTEXT          0x020E
#define META_OFFSETWINDOWORG         0x020F
#define META_SCALEWINDOWEXT          0x0400
#define META_OFFSETVIEWPORTORG       0x0211
#define META_SCALEVIEWPORTEXT        0x0412
#define META_LINETO                  0x0213
#define META_MOVETO                  0x0214
#define META_EXCLUDECLIPRECT         0x0415
#define META_INTERSECTCLIPRECT       0x0416
#define META_ARC                     0x0817
#define META_ELLIPSE                 0x0418
#define META_FLOODFILL               0x0419
#define META_PIE                     0x081A
#define META_RECTANGLE               0x041B
#define META_ROUNDRECT               0x061C
#define META_PATBLT                  0x061D
#define META_SAVEDC                  0x001E
#define META_SETPIXEL                0x041F
#define META_OFFSETCLIPRGN           0x0220
#define META_TEXTOUT                 0x0521
#define META_BITBLT                  0x0922
#define META_STRETCHBLT              0x0B23
#define META_POLYGON                 0x0324
#define META_POLYLINE                0x0325
#define META_ESCAPE                  0x0626
#define META_RESTOREDC               0x0127
#define META_FILLREGION              0x0228
#define META_FRAMEREGION             0x0429
#define META_INVERTREGION            0x012A
#define META_PAINTREGION             0x012B
#define META_SELECTCLIPREGION        0x012C
#define META_SELECTOBJECT            0x012D
#define META_SETTEXTALIGN            0x012E
#define META_DRAWTEXT                0x062F

#define META_CHORD                   0x0830
#define META_SETMAPPERFLAGS          0x0231
#define META_EXTTEXTOUT              0x0a32
#define META_SETDIBTODEV             0x0d33
#define META_SELECTPALETTE           0x0234
#define META_REALIZEPALETTE          0x0035
#define META_ANIMATEPALETTE          0x0436
#define META_SETPALENTRIES           0x0037
#define META_POLYPOLYGON             0x0538
#define META_RESIZEPALETTE           0x0139

#define META_DIBBITBLT               0x0940
#define META_DIBSTRETCHBLT           0x0b41
#define META_DIBCREATEPATTERNBRUSH   0x0142
#define META_STRETCHDIB              0x0f43

#define META_DELETEOBJECT            0x01f0

#define META_CREATEPALETTE           0x00f7
#define META_CREATEBRUSH             0x00F8
#define META_CREATEPATTERNBRUSH      0x01F9
#define META_CREATEPENINDIRECT       0x02FA
#define META_CREATEFONTINDIRECT      0x02FB
#define META_CREATEBRUSHINDIRECT     0x02FC
#define META_CREATEBITMAPINDIRECT    0x02FD
#define META_CREATEBITMAP            0x06FE
#define META_CREATEREGION            0x06FF

#endif /* NOMETAFILE */

/* GDI Escapes */
#define NEWFRAME                     1
#define ABORTDOC                     2
#define NEXTBAND                     3
#define SETCOLORTABLE                4
#define GETCOLORTABLE                5
#define FLUSHOUTPUT                  6
#define DRAFTMODE                    7
#define QUERYESCSUPPORT              8
#define SETABORTPROC                 9
#define STARTDOC                     10
#define ENDDOC                       11
#define GETPHYSPAGESIZE              12
#define GETPRINTINGOFFSET            13
#define GETSCALINGFACTOR             14
#define MFCOMMENT                    15
#define GETPENWIDTH                  16
#define SETCOPYCOUNT                 17
#define SELECTPAPERSOURCE            18
#define DEVICEDATA                   19
#define PASSTHROUGH                  19
#define GETTECHNOLGY                 20
#define GETTECHNOLOGY                20
#define SETENDCAP                    21
#define SETLINEJOIN                  22
#define SETMITERLIMIT                23
#define BANDINFO                     24
#define DRAWPATTERNRECT              25
#define GETVECTORPENSIZE             26
#define GETVECTORBRUSHSIZE           27
#define ENABLEDUPLEX                 28
#define GETSETPAPERBINS              29
#define GETSETPRINTORIENT            30
#define ENUMPAPERBINS                31
#define SETDIBSCALING                32
#define EPSPRINTING                  33
#define ENUMPAPERMETRICS             34
#define GETSETPAPERMETRICS           35
#define POSTSCRIPT_DATA              37
#define POSTSCRIPT_IGNORE            38
#define GETEXTENDEDTEXTMETRICS       256
#define GETEXTENTTABLE               257
#define GETPAIRKERNTABLE             258
#define GETTRACKKERNTABLE            259
#define EXTTEXTOUT                   512
#define ENABLERELATIVEWIDTHS         768
#define ENABLEPAIRKERNING            769
#define SETKERNTRACK                 770
#define SETALLJUSTVALUES             771
#define SETCHARSET                   772

#define STRETCHBLT                   2048
#define BEGIN_PATH                   4096
#define CLIP_TO_PATH                 4097
#define END_PATH                     4098
#define EXT_DEVICE_CAPS              4099
#define RESTORE_CTM                  4100
#define SAVE_CTM                     4101
#define SET_ARC_DIRECTION            4102
#define SET_BACKGROUND_COLOR         4103
#define SET_POLY_MODE                4104
#define SET_SCREEN_ANGLE             4105
#define SET_SPREAD                   4106
#define TRANSFORM_CTM                4107
#define SET_CLIP_BOX                 4108
#define SET_BOUNDS                   4109
#define SET_MIRROR_MODE              4110

/* Spooler Error Codes */
#define SP_NOTREPORTED               0x4000
#define SP_ERROR                     (-1)
#define SP_APPABORT                  (-2)
#define SP_USERABORT                 (-3)
#define SP_OUTOFDISK                 (-4)
#define SP_OUTOFMEMORY               (-5)

#define PR_JOBSTATUS                 0x0000

/* Object Definitions for EnumObjects(), GetObjectType() */
#define OBJ_PEN             1
#define OBJ_BRUSH           2
#define OBJ_DC              3
#define OBJ_METADC          4
#define OBJ_PAL             5
#define OBJ_FONT            6
#define OBJ_BITMAP          7
#define OBJ_REGION          8
#define OBJ_METAFILE        9
#define OBJ_MEMDC           10

/* xform stuff */
#define MWT_IDENTITY        1
#define MWT_LEFTMULTIPLY    2
#define MWT_RIGHTMULTIPLY   3

#define MWT_MIN             MWT_IDENTITY
#define MWT_MAX             MWT_RIGHTMULTIPLY

#define _XFORM_
typedef struct  tagXFORM
  {
    FLOAT   eM11;
    FLOAT   eM12;
    FLOAT   eM21;
    FLOAT   eM22;
    FLOAT   eDx;
    FLOAT   eDy;
  } XFORM, *PXFORM, FAR *LPXFORM;

/* Bitmap Header Definition */
typedef struct tagBITMAP
  {
    LONG        bmType;
    LONG        bmWidth;
    LONG        bmHeight;
    LONG        bmWidthBytes;
    WORD        bmPlanes;
    WORD        bmBitsPixel;
    LPSTR       bmBits;
  } BITMAP, *PBITMAP, NEAR *NPBITMAP, FAR *LPBITMAP;

typedef struct tagRGBTRIPLE {
        BYTE    rgbtBlue;
        BYTE    rgbtGreen;
        BYTE    rgbtRed;
} RGBTRIPLE;

typedef struct tagRGBQUAD {
        BYTE    rgbBlue;
        BYTE    rgbGreen;
        BYTE    rgbRed;
        BYTE    rgbReserved;
} RGBQUAD;

/* structures for defining DIBs */
typedef struct tagBITMAPCOREHEADER {
        DWORD   bcSize;                 /* used to get to color table */
        WORD    bcWidth;
        WORD    bcHeight;
        WORD    bcPlanes;
        WORD    bcBitCount;
} BITMAPCOREHEADER, FAR *LPBITMAPCOREHEADER, *PBITMAPCOREHEADER;


typedef struct tagBITMAPINFOHEADER{
        DWORD      biSize;
        DWORD      biWidth;
        DWORD      biHeight;
        WORD       biPlanes;
        WORD       biBitCount;

        DWORD      biCompression;
        DWORD      biSizeImage;
        DWORD      biXPelsPerMeter;
        DWORD      biYPelsPerMeter;
        DWORD      biClrUsed;
        DWORD      biClrImportant;
} BITMAPINFOHEADER, FAR *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

/* constants for the biCompression field */
#define BI_RGB      0L
#define BI_RLE8     1L
#define BI_RLE4     2L

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[1];
} BITMAPINFO, FAR *LPBITMAPINFO, *PBITMAPINFO;

typedef struct tagBITMAPCOREINFO {
    BITMAPCOREHEADER    bmciHeader;
    RGBTRIPLE           bmciColors[1];
} BITMAPCOREINFO, FAR *LPBITMAPCOREINFO, *PBITMAPCOREINFO;

#pragma pack(2)
typedef struct tagBITMAPFILEHEADER {
        WORD    bfType;
        DWORD   bfSize;
        WORD    bfReserved1;
        WORD    bfReserved2;
        DWORD   bfOffBits;
} BITMAPFILEHEADER, FAR *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;
#pragma pack()

#define MAKEPOINTS(l)       (*((POINTS FAR *)&(l)))

#ifndef NOMETAFILE

/* Clipboard Metafile Picture Structure */
typedef struct tagHANDLETABLE
  {
    HANDLE      objectHandle[1];
  } HANDLETABLE, *PHANDLETABLE, FAR *LPHANDLETABLE;

typedef struct tagMETARECORD
  {
    DWORD       rdSize;
    WORD        rdFunction;
    WORD        rdParm[1];
  } METARECORD, *PMETARECORD, FAR *LPMETARECORD;

typedef struct tagMETAFILEPICT
  {
    DWORD       mm;
    DWORD       xExt;
    DWORD       yExt;
    HANDLE      hMF;
  } METAFILEPICT, FAR *LPMETAFILEPICT;

typedef struct tagMETAHEADER
{
    WORD        mtType;
    WORD        mtHeaderSize;
    WORD        mtVersion;
    DWORD       mtSize;
    WORD        mtNoObjects;
    DWORD       mtMaxRecord;
    WORD        mtNoParameters;
} METAHEADER;

#endif /* NOMETAFILE */

#ifndef NOTEXTMETRIC

typedef struct tagTEXTMETRICA
{
    LONG        tmHeight;
    LONG        tmAscent;
    LONG        tmDescent;
    LONG        tmInternalLeading;
    LONG        tmExternalLeading;
    LONG        tmAveCharWidth;
    LONG        tmMaxCharWidth;
    LONG        tmWeight;
    LONG        tmOverhang;
    LONG        tmDigitizedAspectX;
    LONG        tmDigitizedAspectY;
    BYTE        tmFirstChar;
    BYTE        tmLastChar;
    BYTE        tmDefaultChar;
    BYTE        tmBreakChar;
    BYTE        tmItalic;
    BYTE        tmUnderlined;
    BYTE        tmStruckOut;
    BYTE        tmPitchAndFamily;
    BYTE        tmCharSet;
} TEXTMETRICA, *PTEXTMETRICA, NEAR *NPTEXTMETRICA, FAR *LPTEXTMETRICA;
typedef struct tagTEXTMETRICW
{
    LONG        tmHeight;
    LONG        tmAscent;
    LONG        tmDescent;
    LONG        tmInternalLeading;
    LONG        tmExternalLeading;
    LONG        tmAveCharWidth;
    LONG        tmMaxCharWidth;
    LONG        tmWeight;
    LONG        tmOverhang;
    LONG        tmDigitizedAspectX;
    LONG        tmDigitizedAspectY;
    WCHAR       tmFirstChar;
    WCHAR       tmLastChar;
    WCHAR       tmDefaultChar;
    WCHAR       tmBreakChar;
    BYTE        tmItalic;
    BYTE        tmUnderlined;
    BYTE        tmStruckOut;
    BYTE        tmPitchAndFamily;
    BYTE        tmCharSet;
} TEXTMETRICW, *PTEXTMETRICW, NEAR *NPTEXTMETRICW, FAR *LPTEXTMETRICW;
#ifdef UNICODE
#define TEXTMETRIC TEXTMETRICW
#define PTEXTMETRIC PTEXTMETRICW
#define NPTEXTMETRIC NPTEXTMETRICW
#define LPTEXTMETRIC LPTEXTMETRICW
#else
#define TEXTMETRIC TEXTMETRICA
#define PTEXTMETRIC PTEXTMETRICA
#define NPTEXTMETRIC NPTEXTMETRICA
#define LPTEXTMETRIC LPTEXTMETRICA
#endif // UNICODE

#endif /* NOTEXTMETRIC */

/* GDI Logical Objects: */

/* Pel Array */
typedef struct tagPELARRAY
  {
    LONG        paXCount;
    LONG        paYCount;
    LONG        paXExt;
    LONG        paYExt;
    BYTE        paRGBs;
  } PELARRAY, *PPELARRAY, NEAR *NPPELARRAY, FAR *LPPELARRAY;

/* Logical Brush (or Pattern) */
typedef struct tagLOGBRUSH
  {
    DWORD       lbStyle;
    DWORD       lbColor;
    LONG        lbHatch;
  } LOGBRUSH, *PLOGBRUSH, NEAR *NPLOGBRUSH, FAR *LPLOGBRUSH;

typedef LOGBRUSH            PATTERN;
typedef PATTERN             *PPATTERN;
typedef PATTERN NEAR        *NPPATTERN;
typedef PATTERN FAR         *LPPATTERN;

/* Logical Pen */
typedef struct tagLOGPEN
  {
    DWORD       lopnStyle;
    POINT       lopnWidth;
    DWORD       lopnColor;
  } LOGPEN, *PLOGPEN, NEAR *NPLOGPEN, FAR *LPLOGPEN;

typedef struct tagPALETTEENTRY {
    BYTE        peRed;
    BYTE        peGreen;
    BYTE        peBlue;
    BYTE        peFlags;
} PALETTEENTRY, *PPALETTEENTRY, FAR *LPPALETTEENTRY;

/* Logical Palette */
typedef struct tagLOGPALETTE {
    WORD        palVersion;
    WORD        palNumEntries;
    PALETTEENTRY        palPalEntry[1];
} LOGPALETTE, *PLOGPALETTE, NEAR *NPLOGPALETTE, FAR *LPLOGPALETTE;


/* Logical Font */
#define LF_FACESIZE         32


typedef struct tagLOGFONTA
{
    LONG      lfHeight;
    LONG      lfWidth;
    LONG      lfEscapement;
    LONG      lfOrientation;
    LONG      lfWeight;
    BYTE      lfItalic;
    BYTE      lfUnderline;
    BYTE      lfStrikeOut;
    BYTE      lfCharSet;
    BYTE      lfOutPrecision;
    BYTE      lfClipPrecision;
    BYTE      lfQuality;
    BYTE      lfPitchAndFamily;
    BYTE      lfFaceName[LF_FACESIZE];
} LOGFONTA, *PLOGFONTA, NEAR *NPLOGFONTA, FAR *LPLOGFONTA;
typedef struct tagLOGFONTW
{
    LONG      lfHeight;
    LONG      lfWidth;
    LONG      lfEscapement;
    LONG      lfOrientation;
    LONG      lfWeight;
    BYTE      lfItalic;
    BYTE      lfUnderline;
    BYTE      lfStrikeOut;
    BYTE      lfCharSet;
    BYTE      lfOutPrecision;
    BYTE      lfClipPrecision;
    BYTE      lfQuality;
    BYTE      lfPitchAndFamily;
    WCHAR     lfFaceName[LF_FACESIZE];
} LOGFONTW, *PLOGFONTW, NEAR *NPLOGFONTW, FAR *LPLOGFONTW;
#ifdef UNICODE
#define LOGFONT LOGFONTW
#define PLOGFONT PLOGFONTW
#define NPLOGFONT NPLOGFONTW
#define LPLOGFONT LPLOGFONTW
#else
#define LOGFONT LOGFONTA
#define PLOGFONT PLOGFONTA
#define NPLOGFONT NPLOGFONTA
#define LPLOGFONT LPLOGFONTA
#endif // UNICODE


#define OUT_DEFAULT_PRECIS      0
#define OUT_STRING_PRECIS       1
#define OUT_CHARACTER_PRECIS    2
#define OUT_STROKE_PRECIS       3

#define CLIP_DEFAULT_PRECIS     0
#define CLIP_CHARACTER_PRECIS   1
#define CLIP_STROKE_PRECIS      2

#define DEFAULT_QUALITY         0
#define DRAFT_QUALITY           1
#define PROOF_QUALITY           2

#define DEFAULT_PITCH           0
#define FIXED_PITCH             1
#define VARIABLE_PITCH          2

#define ANSI_CHARSET            0
#define SYMBOL_CHARSET          2
#define SHIFTJIS_CHARSET        128
#define OEM_CHARSET             255

/* Font Families */
#define FF_DONTCARE         (0<<4)  /* Don't care or don't know. */
#define FF_ROMAN            (1<<4)  /* Variable stroke width, serifed. */
                                    /* Times Roman, Century Schoolbook, etc. */
#define FF_SWISS            (2<<4)  /* Variable stroke width, sans-serifed. */
                                    /* Helvetica, Swiss, etc. */
#define FF_MODERN           (3<<4)  /* Constant stroke width, serifed or sans-serifed. */
                                    /* Pica, Elite, Courier, etc. */
#define FF_SCRIPT           (4<<4)  /* Cursive, etc. */
#define FF_DECORATIVE       (5<<4)  /* Old English, etc. */

/* Font Weights */
#define FW_DONTCARE         0
#define FW_THIN             100
#define FW_EXTRALIGHT       200
#define FW_LIGHT            300
#define FW_NORMAL           400
#define FW_MEDIUM           500
#define FW_SEMIBOLD         600
#define FW_BOLD             700
#define FW_EXTRABOLD        800
#define FW_HEAVY            900

#define FW_ULTRALIGHT       FW_EXTRALIGHT
#define FW_REGULAR          FW_NORMAL
#define FW_DEMIBOLD         FW_SEMIBOLD
#define FW_ULTRABOLD        FW_EXTRABOLD
#define FW_BLACK            FW_HEAVY


typedef struct tagCHARSET {
    DWORD   aflBlock[3];
    DWORD   flLang;
} CHARSET, *LPCHARSET;

typedef struct tagPANOSE {
    ULONG ulCulture;
    BYTE  bFamilyType;
    BYTE  bSerifStyle;
    BYTE  bWeight;
    BYTE  bProportion;
    BYTE  bContrast;
    BYTE  bStrokeVariation;
    BYTE  bArmStyle;
    BYTE  bLetterform;
    BYTE  bMidline;
    BYTE  bXHeight;
} PANOSE, *LPPANOSE;

#define PAN_ANY                         0   /* Any */
#define PAN_NO_FIT                      1   /* No Fit */

#define PAN_FAMILY_TEXT_DISPLAY         2   /* Text and Display */
#define PAN_FAMILY_SCRIPT               3   /* Script */
#define PAN_FAMILY_DECORATIVE           4   /* Decorative */
#define PAN_FAMILY_PICTORIAL            5   /* Pictorial */

#define PAN_SERIF_COVE                  2   /* Cove */
#define PAN_SERIF_OBTUSE_COVE           3   /* Obtuse Cove */
#define PAN_SERIF_SQUARE_COVE           4   /* Square Cove */
#define PAN_SERIF_OBTUSE_SQUARE_COVE    5   /* Obtuse Square Cove */
#define PAN_SERIF_SQUARE                6   /* Square */
#define PAN_SERIF_THIN                  7   /* Thin */
#define PAN_SERIF_BONE                  8   /* Bone */
#define PAN_SERIF_EXAGGERATED           9   /* Exaggerated */
#define PAN_SERIF_TRIANGLE             10   /* Triangle */
#define PAN_SERIF_NORMAL_SANS          11   /* Normal Sans */
#define PAN_SERIF_OBTUSE_SANS          12   /* Obtuse Sans */
#define PAN_SERIF_PERP_SANS            13   /* Prep Sans */
#define PAN_SERIF_FLARED               14   /* Flared */
#define PAN_SERIF_ROUNDED              15   /* Rounded */

#define PAN_WEIGHT_VERY_LIGHT           2   /* Very Light */
#define PAN_WEIGHT_LIGHT                3   /* Light */
#define PAN_WEIGHT_THIN                 4   /* Thin */
#define PAN_WEIGHT_BOOK                 5   /* Book */
#define PAN_WEIGHT_MEDIUM               6   /* Medium */
#define PAN_WEIGHT_DEMI                 7   /* Demi */
#define PAN_WEIGHT_BOLD                 8   /* Bold */
#define PAN_WEIGHT_HEAVY                9   /* Heavy */
#define PAN_WEIGHT_BLACK               10   /* Black */
#define PAN_WEIGHT_NORD                11   /* Nord */

#define PAN_PROP_OLD_STYLE              2   /* Old Style */
#define PAN_PROP_MODERN                 3   /* Modern */
#define PAN_PROP_EVEN_WIDTH             4   /* Even Width */
#define PAN_PROP_EXPANDED               5   /* Expanded */
#define PAN_PROP_CONDENSED              6   /* Condensed */
#define PAN_PROP_VERY_EXPANDED          7   /* Very Expanded */
#define PAN_PROP_VERY_CONDENSED         8   /* Very Condensed */
#define PAN_PROP_MONOSPACED             9   /* Monospaced */

#define PAN_CONTRAST_NONE               2   /* None */
#define PAN_CONTRAST_VERY_LOW           3   /* Very Low */
#define PAN_CONTRAST_LOW                4   /* Low */
#define PAN_CONTRAST_MEDIUM_LOW         5   /* Medium Low */
#define PAN_CONTRAST_MEDIUM             6   /* Medium */
#define PAN_CONTRAST_MEDIUM_HIGH        7   /* Mediim High */
#define PAN_CONTRAST_HIGH               8   /* High */
#define PAN_CONTRAST_VERY_HIGH          9   /* Very High */

#define PAN_STROKE_GRADUAL_DIAG         2   /* Gradual/Diagonal */
#define PAN_STROKE_GRADUAL_TRAN         3   /* Gradual/Transitional */
#define PAN_STROKE_GRADUAL_VERT         4   /* Gradual/Vertical */
#define PAN_STROKE_GRADUAL_HORZ         5   /* Gradual/Horizontal */
#define PAN_STROKE_RAPID_VERT           6   /* Rapid/Vertical */
#define PAN_STROKE_RAPID_HORZ           7   /* Rapid/Horizontal */
#define PAN_STROKE_INSTANT_VERT         8   /* Instant/Vertical */

#define PAN_STRAIGHT_ARMS_HORZ          2   /* Straight Arms/Horizontal */
#define PAN_STRAIGHT_ARMS_WEDGE         3   /* Straight Arms/Wedge */
#define PAN_STRAIGHT_ARMS_VERT          4   /* Straight Arms/Vertical */
#define PAN_STRAIGHT_ARMS_SINGLE_SERIF  5   /* Straight Arms/Single-Serif */
#define PAN_STRAIGHT_ARMS_DOUBLE_SERIF  6   /* Straight Arms/Double-Serif */
#define PAN_BENT_ARMS_HORZ              7   /* Non-Straight Arms/Horizontal */
#define PAN_BENT_ARMS_WEDGE             8   /* Non-Straight Arms/Wedge */
#define PAN_BENT_ARMS_VERT              9   /* Non-Straight Arms/Vertical */
#define PAN_BENT_ARMS_SINGLE_SERIF     10   /* Non-Straight Arms/Single-Serif */
#define PAN_BENT_ARMS_DOUBLE_SERIF     11   /* Non-Straight Arms/Double-Serif */

#define PAN_LETT_NORMAL_CONTACT         2   /* Normal/Contact */
#define PAN_LETT_NORMAL_WEIGHTED        3   /* Normal/Weighted */
#define PAN_LETT_NORMAL_BOXED           4   /* Normal/Boxed */
#define PAN_LETT_NORMAL_FLATTENED       5   /* Normal/Flattened */
#define PAN_LETT_NORMAL_ROUNDED         6   /* Normal/Rounded */
#define PAN_LETT_NORMAL_OFF_CENTER      7   /* Normal/Off Center */
#define PAN_LETT_NORMAL_SQUARE          8   /* Normal/Square */
#define PAN_LETT_OBLIQUE_CONTACT        9   /* Oblique/Contact */
#define PAN_LETT_OBLIQUE_WEIGHTED      10   /* Oblique/Weighted */
#define PAN_LETT_OBLIQUE_BOXED         11   /* Oblique/Boxed */
#define PAN_LETT_OBLIQUE_FLATTENED     12   /* Oblique/Flattened */
#define PAN_LETT_OBLIQUE_ROUNDED       13   /* Oblique/Rounded */
#define PAN_LETT_OBLIQUE_OFF_CENTER    14   /* Oblique/Off Center */
#define PAN_LETT_OBLIQUE_SQUARE        15   /* Oblique/Square */

#define PAN_MIDLINE_STANDARD_TRIMMED    2   /* Standard/Trimmed */
#define PAN_MIDLINE_STANDARD_POINTED    3   /* Standard/Pointed */
#define PAN_MIDLINE_STANDARD_SERIFED    4   /* Standard/Serifed */
#define PAN_MIDLINE_HIGH_TRIMMED        5   /* High/Trimmed */
#define PAN_MIDLINE_HIGH_POINTED        6   /* High/Pointed */
#define PAN_MIDLINE_HIGH_SERIFED        7   /* High/Serifed */
#define PAN_MIDLINE_CONSTANT_TRIMMED    8   /* Constant/Trimmed */
#define PAN_MIDLINE_CONSTANT_POINTED    9   /* Constant/Pointed */
#define PAN_MIDLINE_CONSTANT_SERIFED   10   /* Constant/Serifed */
#define PAN_MIDLINE_LOW_TRIMMED        11   /* Low/Trimmed */
#define PAN_MIDLINE_LOW_POINTED        12   /* Low/Pointed */
#define PAN_MIDLINE_LOW_SERIFED        13   /* Low/Serifed */

#define PAN_XHEIGHT_CONSTANT_SMALL      2   /* Constant/Small */
#define PAN_XHEIGHT_CONSTANT_STD        3   /* Constant/Standard */
#define PAN_XHEIGHT_CONSTANT_LARGE      4   /* Constant/Large */
#define PAN_XHEIGHT_DUCKING_SMALL       5   /* Ducking/Small */
#define PAN_XHEIGHT_DUCKING_STD         6   /* Ducking/Standard */
#define PAN_XHEIGHT_DUCKING_LARGE       7   /* Ducking/Large */


#define ELF_FAMILY_SIZE 32

/* The extended logical font */

typedef struct tagEXTLOGFONTA {
    LOGFONTA    elfLogFont;
    DWORD       elfSize;
    DWORD       elfTech;
    DWORD       elfXHeight;
    PANOSE      elfPanose;
    CHARSET     elfCharset;
    BYTE        elfFamily[ELF_FAMILY_SIZE];
} EXTLOGFONTA, *LPEXTLOGFONTA;
typedef struct tagEXTLOGFONTW {
    LOGFONTW    elfLogFont;
    DWORD       elfSize;
    DWORD       elfTech;
    DWORD       elfXHeight;
    PANOSE      elfPanose;
    CHARSET     elfCharset;
    WCHAR       elfFamily[ELF_FAMILY_SIZE];
} EXTLOGFONTW, *LPEXTLOGFONTW;
#ifdef UNICODE
#define EXTLOGFONT EXTLOGFONTW
#define LPEXTLOGFONT LPEXTLOGFONTW
#else
#define EXTLOGFONT EXTLOGFONTA
#define LPEXTLOGFONT LPEXTLOGFONTA
#endif // UNICODE

/* Allowed values for EXTLOGFONT::elfTech */
#define ELF_ANY             0
#define ELF_OUTLINE         1
#define ELF_BITMAP          2
#define ELF_STICK           3

/* complete set font attribute weights */
typedef struct tagFMWEIGHTSET {
    WORD wtFaceName;
    WORD wtFamilyName;
    WORD wtAvgWidth;
    WORD wtXHeight;
    WORD wtSize;
    WORD wtTech;
    WORD wtPanose;
    WORD wtPanFamily;
    WORD wtPanSerif;
    WORD wtPanWeight;
    WORD wtPanProp;
    WORD wtPanContrast;
    WORD wtPanStrokeVar;
    WORD wtPanArmStyle;
    WORD wtPanLetter;
    WORD wtPanMidline;
    WORD wtPanXHeight;
    WORD wtCharSet;
} FMWEIGHTSET, *LPFMWEIGHTSET;

/* the complete set of font attribute distances */
typedef struct tagFMDISTANCESET {
    WORD dFaceName;
    WORD dFamilyName;
    WORD dAvgWidth;
    WORD dXHeight;
    WORD dSize;
    WORD dTech;
    WORD dPanose;
    WORD dPanFamily;
    WORD dPanSerif;
    WORD dPanWeight;
    WORD dPanProp;
    WORD dPanContrast;
    WORD dPanStrokeVar;
    WORD dPanArmStyle;
    WORD dPanLetter;
    WORD dPanMidline;
    WORD dPanXHeight;
    WORD dCharSet;
} FMDISTANCESET, *LPFMDISTANCESET;

typedef struct tagFMCONTROLS {
    DWORD           size;
    DWORD           distsetSumMax;
    FMDISTANCESET   distsetMax;
    FMWEIGHTSET     wtsetNear;
    FMWEIGHTSET     wtsetFar;
} FMCONTROLS, *LPFMCONTROLS;

#define SIZEOFFMCONTROLS sizeof(FMCONTROLS)

typedef struct tagFMATCHA {
    DWORD           size;
    DWORD           type;
    DWORD           distsetSum;
    FMDISTANCESET   distset;
    EXTLOGFONTA     ExtLogFont;
} FMATCHA,*LPFMATCHA;
typedef struct tagFMATCHW {
    DWORD           size;
    DWORD           type;
    DWORD           distsetSum;
    FMDISTANCESET   distset;
    EXTLOGFONTW     ExtLogFont;
} FMATCHW,*LPFMATCHW;
#ifdef UNICODE
#define FMATCH FMATCHW
#define LPFMATCH LPFMATCHW
#else
#define FMATCH FMATCHA
#define LPFMATCH LPFMATCHA
#endif // UNICODE

/* Allowed values for FMATCH::wType */
#define FMATCH_EXACT    0
#define FMATCH_NEAR     1
#define FMATCH_FAR      2



/* EnumFonts Masks */
#define RASTER_FONTTYPE     0x0001
#define DEVICE_FONTTYPE     0X0002

#define RGB(r,g,b)          ((DWORD)(((BYTE)(r)|((WORD)(g)<<8))|(((DWORD)(BYTE)(b))<<16)))
#define PALETTERGB(r,g,b)   (0x02000000 | RGB(r,g,b))
#define PALETTEINDEX(i)     ((DWORD)(0x01000000 | (WORD)(i)))

/* palette entry flags */

#define PC_RESERVED     0x01    /* palette index used for animation */
#define PC_EXPLICIT     0x02    /* palette index is explicit to device */
#define PC_NOCOLLAPSE   0x04    /* do not match color to system palette */

#define GetRValue(rgb)      ((BYTE)(rgb))
#define GetGValue(rgb)      ((BYTE)(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      ((BYTE)((rgb)>>16))

/* Background Modes */
#define TRANSPARENT         1
#define OPAQUE              2
#define BKMODE_LAST         2

/* PolyDraw and GetPath point types */
#define PT_CLOSEFIGURE      0x01
#define PT_LINETO           0x02
#define PT_BEZIERTO         0x04
#define PT_MOVETO           0x06

/* Mapping Modes */
#define MM_TEXT             1
#define MM_LOMETRIC         2
#define MM_HIMETRIC         3
#define MM_LOENGLISH        4
#define MM_HIENGLISH        5
#define MM_TWIPS            6

#define MM_ISOTROPIC        7
#define MM_ANISOTROPIC	    8

/*
   Current mapping occurs in 'logical' scale.	To
   use 'actual' scale, OR this to modes 2-6 above.
*/
#define MM_REAL_UNITS	    16

/* Min and Max Mapping Mode values */
#define MM_MIN              MM_TEXT
#define MM_MAX              MM_ANISOTROPIC
#define MM_MAX_FIXEDSCALE   MM_TWIPS
#define MM_REAL_MIN	    (MM_REAL_UNITS | MM_LOMETRIC)
#define MM_REAL_MAX	    (MM_REAL_UNITS | MM_TWIPS)

/* Coordinate Modes */
#define ABSOLUTE            1
#define RELATIVE            2

/* Stock Logical Objects */
#define WHITE_BRUSH         0
#define LTGRAY_BRUSH        1
#define GRAY_BRUSH          2
#define DKGRAY_BRUSH        3
#define BLACK_BRUSH         4
#define NULL_BRUSH          5
#define HOLLOW_BRUSH        NULL_BRUSH
#define WHITE_PEN           6
#define BLACK_PEN           7
#define NULL_PEN            8
#define OEM_FIXED_FONT      10
#define ANSI_FIXED_FONT     11
#define ANSI_VAR_FONT       12
#define SYSTEM_FONT         13
#define DEVICE_DEFAULT_FONT 14
#define DEFAULT_PALETTE     15
#define SYSTEM_FIXED_FONT   16
#define STOCK_LAST          16

#define CLR_INVALID     0x80000000

/* Brush Styles */
#define BS_SOLID            0
#define BS_NULL             1
#define BS_HOLLOW           BS_NULL
#define BS_HATCHED          2
#define BS_PATTERN          3
#define BS_INDEXED          4
#define BS_DIBPATTERN       5

/* Hatch Styles */
#define HS_HORIZONTAL       0       /* ----- */
#define HS_VERTICAL         1       /* ||||| */
#define HS_FDIAGONAL        2       /* \\\\\ */
#define HS_BDIAGONAL        3       /* ///// */
#define HS_CROSS            4       /* +++++ */
#define HS_DIAGCROSS        5       /* xxxxx */
#define HS_FDIAGONAL1       6
#define HS_BDIAGONAL1       7
#define HS_SOLID            8
#define HS_DENSE1           9
#define HS_DENSE2           10
#define HS_DENSE3           11
#define HS_DENSE4           12
#define HS_DENSE5           13
#define HS_DENSE6           14
#define HS_DENSE7           15
#define HS_DENSE8           16
#define HS_NOSHADE          17
#define HS_HALFTONE         18
#define HS_API_MAX          19

/* Pen Styles */
#define PS_SOLID            0
#define PS_DASH             1       /* -------  */
#define PS_DOT              2       /* .......  */
#define PS_DASHDOT          3       /* _._._._  */
#define PS_DASHDOTDOT       4       /* _.._.._  */
#define PS_NULL             5
#define PS_INSIDEFRAME      6

/* Device Parameters for GetDeviceCaps() */
#define DRIVERVERSION 0     /* Device driver version                    */
#define TECHNOLOGY    2     /* Device classification                    */
#define HORZSIZE      4     /* Horizontal size in millimeters           */
#define VERTSIZE      6     /* Vertical size in millimeters             */
#define HORZRES       8     /* Horizontal width in pixels               */
#define VERTRES       10    /* Vertical width in pixels                 */
#define BITSPIXEL     12    /* Number of bits per pixel                 */
#define PLANES        14    /* Number of planes                         */
#define NUMBRUSHES    16    /* Number of brushes the device has         */
#define NUMPENS       18    /* Number of pens the device has            */
#define NUMMARKERS    20    /* Number of markers the device has         */
#define NUMFONTS      22    /* Number of fonts the device has           */
#define NUMCOLORS     24    /* Number of colors the device supports     */
#define PDEVICESIZE   26    /* Size required for device descriptor      */
#define CURVECAPS     28    /* Curve capabilities                       */
#define LINECAPS      30    /* Line capabilities                        */
#define POLYGONALCAPS 32    /* Polygonal capabilities                   */
#define TEXTCAPS      34    /* Text capabilities                        */
#define CLIPCAPS      36    /* Clipping capabilities                    */
#define RASTERCAPS    38    /* Bitblt capabilities                      */
#define ASPECTX       40    /* Length of the X leg                      */
#define ASPECTY       42    /* Length of the Y leg                      */
#define ASPECTXY      44    /* Length of the hypotenuse                 */

#define LOGPIXELSX    88    /* Logical pixels/inch in X                 */
#define LOGPIXELSY    90    /* Logical pixels/inch in Y                 */

#define SIZEPALETTE  104    /* Number of entries in physical palette	*/
#define NUMRESERVED  106    /* Number of reserved entries in palette    */
#define COLORRES     108    /* Actual color resolution                  */


// Printing related DeviceCaps. These replace the appropriate Escapes

#define PHYSICALWIDTH   110 // Physical Width in device units
#define PHYSICALHEIGHT  111 // Physical Height in device units
#define PHYSICALOFFSETX 112 // Physical Printable Area x margin
#define PHYSICALOFFSETY 113 // Physical Printable Area y margin
#define SCALINGFACTORX  114 // Scaling factor x
#define SCALINGFACTORY  115 // Scaling factor y

#ifndef NOGDICAPMASKS

/* Device Capability Masks: */

/* Device Technologies */
#define DT_PLOTTER          0   /* Vector plotter                   */
#define DT_RASDISPLAY       1   /* Raster display                   */
#define DT_RASPRINTER       2   /* Raster printer                   */
#define DT_RASCAMERA        3   /* Raster camera                    */
#define DT_CHARSTREAM       4   /* Character-stream, PLP            */
#define DT_METAFILE         5   /* Metafile, VDM                    */
#define DT_DISPFILE         6   /* Display-file                     */

/* Curve Capabilities */
#define CC_NONE             0   /* Curves not supported             */
#define CC_CIRCLES          1   /* Can do circles                   */
#define CC_PIE              2   /* Can do pie wedges                */
#define CC_CHORD            4   /* Can do chord arcs                */
#define CC_ELLIPSES         8   /* Can do ellipese                  */
#define CC_WIDE             16  /* Can do wide lines                */
#define CC_STYLED           32  /* Can do styled lines              */
#define CC_WIDESTYLED       64  /* Can do wide styled lines         */
#define CC_INTERIORS        128 /* Can do interiors                 */

/* Line Capabilities */
#define LC_NONE             0   /* Lines not supported              */
#define LC_POLYLINE         2   /* Can do polylines                 */
#define LC_MARKER           4   /* Can do markers                   */
#define LC_POLYMARKER       8   /* Can do polymarkers               */
#define LC_WIDE             16  /* Can do wide lines                */
#define LC_STYLED           32  /* Can do styled lines              */
#define LC_WIDESTYLED       64  /* Can do wide styled lines         */
#define LC_INTERIORS        128 /* Can do interiors                 */

/* Polygonal Capabilities */
#define PC_NONE             0   /* Polygonals not supported         */
#define PC_POLYGON          1   /* Can do polygons                  */
#define PC_RECTANGLE        2   /* Can do rectangles                */
#define PC_WINDPOLYGON      4   /* Can do winding polygons          */
#define PC_TRAPEZOID        4   /* Can do trapezoids                */
#define PC_SCANLINE         8   /* Can do scanlines                 */
#define PC_WIDE             16  /* Can do wide borders              */
#define PC_STYLED           32  /* Can do styled borders            */
#define PC_WIDESTYLED       64  /* Can do wide styled borders       */
#define PC_INTERIORS        128 /* Can do interiors                 */

/* Polygonal Capabilities */
#define CP_NONE             0   /* No clipping of output            */
#define CP_RECTANGLE        1   /* Output clipped to rects          */

/* Text Capabilities */
#define TC_OP_CHARACTER     0x0001  /* Can do OutputPrecision   CHARACTER      */
#define TC_OP_STROKE        0x0002  /* Can do OutputPrecision   STROKE         */
#define TC_CP_STROKE        0x0004  /* Can do ClipPrecision     STROKE         */
#define TC_CR_90            0x0008  /* Can do CharRotAbility    90             */
#define TC_CR_ANY           0x0010  /* Can do CharRotAbility    ANY            */
#define TC_SF_X_YINDEP      0x0020  /* Can do ScaleFreedom      X_YINDEPENDENT */
#define TC_SA_DOUBLE        0x0040  /* Can do ScaleAbility      DOUBLE         */
#define TC_SA_INTEGER       0x0080  /* Can do ScaleAbility      INTEGER        */
#define TC_SA_CONTIN        0x0100  /* Can do ScaleAbility      CONTINUOUS     */
#define TC_EA_DOUBLE        0x0200  /* Can do EmboldenAbility   DOUBLE         */
#define TC_IA_ABLE          0x0400  /* Can do ItalisizeAbility  ABLE           */
#define TC_UA_ABLE          0x0800  /* Can do UnderlineAbility  ABLE           */
#define TC_SO_ABLE          0x1000  /* Can do StrikeOutAbility  ABLE           */
#define TC_RA_ABLE          0x2000  /* Can do RasterFontAble    ABLE           */
#define TC_VA_ABLE          0x4000  /* Can do VectorFontAble    ABLE           */
#define TC_RESERVED         0x8000

#endif /* NOGDICAPMASKS */

/* Raster Capabilities */
#define RC_BITBLT           1       /* Can do standard BLT.             */
#define RC_BANDING          2       /* Device requires banding support  */
#define RC_SCALING          4       /* Device requires scaling support  */
#define RC_BITMAP64         8       /* Device can support >64K bitmap   */
#define RC_GDI20_OUTPUT     0x0010      /* has 2.0 output calls         */
#define RC_DI_BITMAP        0x0080      /* supports DIB to memory       */
#define RC_PALETTE          0x0100      /* supports a palette           */
#define RC_DIBTODEV         0x0200      /* supports DIBitsToDevice      */
#define RC_BIGFONT          0x0400      /* supports >64K fonts          */
#define RC_STRETCHBLT       0x0800      /* supports StretchBlt          */
#define RC_FLOODFILL        0x1000      /* supports FloodFill           */
#define RC_STRETCHDIB       0x2000      /* supports StretchDIBits       */

/* DIB color table identifiers */

#define DIB_RGB_COLORS  0       /* color table in RGBTriples */
#define DIB_PAL_COLORS  1       /* color table in palette indices */
#define DIB_PAL_INDICES 2       /* no color table, the indices are in      */
                                /* the DC the bitmap will be selected into */


/* constants for Get/SetSystemPaletteUse() */

#define SYSPAL_ERROR    0
#define SYSPAL_STATIC   1
#define SYSPAL_NOSTATIC 2

/* constants for CreateDIBitmap */
#define CBM_INIT        0x04L   /* initialize bitmap */

#ifndef NODRAWTEXT

/* DrawText() Format Flags */
#define DT_TOP              0x0000
#define DT_LEFT             0x0000
#define DT_CENTER           0x0001
#define DT_RIGHT            0x0002
#define DT_VCENTER          0x0004
#define DT_BOTTOM           0x0008
#define DT_WORDBREAK        0x0010
#define DT_SINGLELINE       0x0020
#define DT_EXPANDTABS       0x0040
#define DT_TABSTOP          0x0080
#define DT_NOCLIP           0x0100
#define DT_EXTERNALLEADING  0x0200
#define DT_CALCRECT         0x0400
#define DT_NOPREFIX         0x0800
#define DT_INTERNAL         0x1000

#endif /* NODRAWTEXT */

/* ExtFloodFill style flags */
#define  FLOODFILLBORDER   0
#define  FLOODFILLSURFACE  1

typedef struct _devicemode {
    char dmDeviceName[32];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    DWORD dmFields;
    short dmOrientation;
    short dmPaperSize;
    short dmPaperLength;
    short dmPaperWidth;
    short dmScale;
    short dmCopies;
    short dmDefaultSource;
    short dmPrintQuality;
    short dmColor;
    short dmDuplex;
} DEVMODE, *PDEVMODE, *NPDEVMODE, *LPDEVMODE;

/* GetRegionData/ExtCreateRegion */

#define RDH_RECTANGLES	1

typedef struct _RGNDATAHEADER {
    DWORD   dwSize;
    DWORD   iType;
    DWORD   nCount;
} RGNDATAHEADER, *PRGNDATAHEADER;

typedef struct _RGNDATA {
    RGNDATAHEADER   rdh;
    char	    Buffer[1];
} RGNDATA, *PRGNDATA, NEAR *NPRGNDATA, FAR *LPRGNDATA;

int APIENTRY AddFontResourceA(IN LPSTR);
int APIENTRY AddFontResourceW(IN LPWSTR);
#ifdef UNICODE
#define AddFontResource AddFontResourceW
#else
#define AddFontResource AddFontResourceA
#endif // !UNICODE

int     APIENTRY AddFontModule(IN HMODULE);
BOOL    APIENTRY AnimatePalette(IN HPALETTE, IN UINT, IN UINT, IN LPPALETTEENTRY);
BOOL BATCH APIENTRY Arc(IN HDC, IN int, IN int, IN int, IN int, IN int, IN int, IN int, IN int);
BOOL BATCH APIENTRY BitBlt(IN HDC, IN int, IN int, IN int, IN int, IN HDC, IN int, IN int, IN DWORD);
BOOL BATCH APIENTRY Chord(IN HDC, IN int, IN int, IN int, IN int, IN int, IN int, IN int, IN int);
HMF     APIENTRY CloseMetaFile(IN HDC);
int     APIENTRY CombineRgn(IN HRGN, IN HRGN, IN HRGN, IN int);
HMF     APIENTRY CopyMetaFile(IN HMF, IN LPSTR);
HBITMAP APIENTRY CreateBitmap(IN int, IN int, IN UINT, IN UINT, IN LPBYTE);
HBITMAP APIENTRY CreateBitmapIndirect(IN LPBITMAP);
HBRUSH  APIENTRY CreateBrushIndirect(IN LPLOGBRUSH);
HBITMAP APIENTRY CreateCompatibleBitmap(IN HDC, IN int, IN int);
HBITMAP APIENTRY CreateDiscardableBitmap(IN HDC, IN int, IN int);
HDC     APIENTRY CreateCompatibleDC(IN HDC);
HDC     APIENTRY CreateDC(IN LPSTR, IN LPSTR OPTIONAL, IN LPSTR OPTIONAL, IN LPDEVMODE OPTIONAL);
HBITMAP APIENTRY CreateDIBitmap(IN HDC, IN LPBITMAPINFOHEADER, IN DWORD, IN LPBYTE, IN LPBITMAPINFO, IN DWORD);
HBITMAP APIENTRY CreateDIBSection(IN HDC, IN LPBITMAPINFO, IN DWORD, IN DWORD, OUT LPBYTE *);
HBRUSH  APIENTRY CreateDIBPatternBrush(IN GLOBALHANDLE, IN DWORD);
HBRUSH  APIENTRY CreateDIBPatternBrushPt(IN LPVOID, IN DWORD);
HRGN    APIENTRY CreateEllipticRgn(IN int, IN int, IN int, IN int);
HRGN    APIENTRY CreateEllipticRgnIndirect(IN LPRECT);

HFONT   APIENTRY CreateFontIndirectA(IN LPLOGFONTA);
HFONT   APIENTRY CreateFontIndirectW(IN LPLOGFONTW);
#ifdef UNICODE
#define CreateFontIndirect CreateFontIndirectW
#else
#define CreateFontIndirect CreateFontIndirectA
#endif // !UNICODE
HFONT   APIENTRY CreateFontA(IN int, IN int, IN int, IN int, IN int, IN DWORD,
                             IN DWORD, IN DWORD, IN DWORD, IN DWORD, IN DWORD,
                             IN DWORD, IN DWORD, IN LPSTR);
HFONT   APIENTRY CreateFontW(IN int, IN int, IN int, IN int, IN int, IN DWORD,
                             IN DWORD, IN DWORD, IN DWORD, IN DWORD, IN DWORD,
                             IN DWORD, IN DWORD, IN LPWSTR);
#ifdef UNICODE
#define CreateFont CreateFontW
#else
#define CreateFont CreateFontA
#endif // !UNICODE

HBRUSH  APIENTRY CreateHatchBrush(IN int, IN COLORREF);
HDC     APIENTRY CreateIC(IN LPSTR, IN LPSTR OPTIONAL, IN LPSTR OPTIONAL, IN LPDEVMODE OPTIONAL);
HMF     APIENTRY CreateMetaFile(IN LPSTR);
HPALETTE APIENTRY CreatePalette(IN LPLOGPALETTE);
HPEN    APIENTRY CreatePen(IN int, IN int, IN COLORREF);
HPEN    APIENTRY CreatePenIndirect(IN LPLOGPEN);
HRGN    APIENTRY CreatePolyPolygonRgn(IN LPPOINT, IN LPINT, IN int, IN int);
HBRUSH  APIENTRY CreatePatternBrush(IN HBITMAP);
HRGN    APIENTRY CreateRectRgn(IN int, IN int, IN int, IN int);
HRGN    APIENTRY CreateRectRgnIndirect(IN LPRECT);
HRGN    APIENTRY CreateRoundRectRgn(IN int, IN int, IN int, IN int, IN int, IN int);
HBRUSH  APIENTRY CreateSolidBrush(IN COLORREF);

BOOL APIENTRY DeleteDC(IN HDC);
BOOL APIENTRY DeleteMetaFile(IN HMF);
BOOL APIENTRY DeleteObject(IN HANDLE);
int  APIENTRY DeviceCapabilitiesEx(IN LPSTR, IN LPSTR, IN LPSTR, IN int, OUT LPSTR, IN LPDEVMODE OPTIONAL);
BOOL APIENTRY DeviceModeEx(IN HWND, IN LPSTR, IN LPSTR, IN LPSTR);

BOOL BATCH APIENTRY Ellipse(IN HDC, IN int, IN int, IN int, IN int);

int  APIENTRY EnumFontsA(IN HDC, IN LPSTR,  IN PROC, IN LPVOID);
int  APIENTRY EnumFontsW(IN HDC, IN LPWSTR,  IN PROC, IN LPVOID);
#ifdef UNICODE
#define EnumFonts EnumFontsW
#else
#define EnumFonts EnumFontsA
#endif // !UNICODE

int  APIENTRY EnumObjects(IN HDC, IN int, IN PROC, IN LPVOID);
BOOL APIENTRY EqualRgn(IN HRGN, IN HRGN);
int  APIENTRY Escape(IN HDC,IN int,IN int,IN LPSTR,OUT LPSTR);
int  APIENTRY ExcludeClipRect(IN HDC, IN int, IN int, IN int, IN int);
HRGN APIENTRY ExtCreateRegion(IN LPXFORM, IN DWORD, IN LPRGNDATA);
LONG APIENTRY ExtDeviceModeEx(IN HWND, IN LPSTR, OUT LPDEVMODE, IN LPSTR, IN LPSTR, IN LPDEVMODE, IN LPSTR, IN DWORD);
BOOL BATCH APIENTRY ExtFloodFill(IN HDC, IN int, IN int, IN COLORREF, IN UINT);
BOOL BATCH  APIENTRY FillRgn(IN HDC, IN HRGN, IN HBRUSH);
BOOL BATCH  APIENTRY FloodFill(IN HDC, IN int, IN int, IN COLORREF);
BOOL BATCH  APIENTRY FrameRgn(IN HDC, IN HRGN, IN HBRUSH, IN int, IN int);
int   APIENTRY GetROP2(IN HDC);
BOOL  APIENTRY GetAspectRatioFilterEx(IN HDC, OUT LPSIZE);
COLORREF APIENTRY GetBkColor(IN HDC);
int   APIENTRY GetBkMode(IN HDC);
DWORD APIENTRY GetBitmapBits(IN HBITMAP, IN DWORD, OUT LPBYTE);
BOOL  APIENTRY GetBitmapDimensionEx(IN HBITMAP, OUT LPSIZE);
BOOL  APIENTRY GetBrushOrgEx(IN HDC, OUT LPPOINT);

BOOL  APIENTRY GetCharWidthA(IN HDC, IN UINT, IN UINT, OUT LPINT);
BOOL  APIENTRY GetCharWidthW(IN HDC, IN UINT, IN UINT, OUT LPINT);
#ifdef UNICODE
#define GetCharWidth GetCharWidthW
#else
#define GetCharWidth GetCharWidthA
#endif // !UNICODE
BOOL  APIENTRY GetCharWidthW(IN HDC, IN UINT, IN UINT, OUT LPINT);

int   APIENTRY GetClipBox(IN HDC, OUT LPRECT);
int   APIENTRY GetClipRgn(IN HDC, IN HRGN);
HANDLE APIENTRY GetCurrentObject(IN HDC, IN UINT);
BOOL  APIENTRY GetCurrentPositionEx(IN HDC, OUT LPPOINT);
int   APIENTRY GetDeviceCaps(IN HDC, IN int);
BOOL  APIENTRY GetDIBits(IN HDC, IN HBITMAP, IN UINT, IN UINT, OUT LPBYTE, IN LPBITMAPINFO, IN UINT);
int   APIENTRY GetMapMode(IN HDC);
DWORD APIENTRY GetMetaFileBits(IN HMF, IN DWORD, OUT LPBYTE);
HMF   APIENTRY GetMetaFile(IN LPSTR);
COLORREF APIENTRY GetNearestColor(IN HDC, IN COLORREF);
UINT  APIENTRY GetNearestPaletteIndex(IN HPALETTE, IN COLORREF);
DWORD APIENTRY GetObjectType(HANDLE h);
UINT  APIENTRY GetPaletteEntries(IN HPALETTE, IN UINT, IN UINT, OUT LPPALETTEENTRY);
DWORD APIENTRY GetPixel(IN HDC, IN int, IN int);
int   APIENTRY GetPolyFillMode(IN HDC);
DWORD APIENTRY GetRegionData(IN HRGN, IN DWORD, OUT LPRGNDATA);
int   APIENTRY GetRgnBox(IN HRGN, OUT LPRECT);
HANDLE APIENTRY GetStockObject(IN int);
int   APIENTRY GetStretchBltMode(IN HDC);
UINT  APIENTRY GetSystemPaletteEntries(IN HDC, IN UINT, IN UINT, OUT LPPALETTEENTRY);
UINT  APIENTRY GetSystemPaletteUse(IN HDC);
int   APIENTRY GetTextCharacterExtra(IN HDC);
UINT  APIENTRY GetTextAlign(IN HDC);
COLORREF APIENTRY GetTextColor(IN HDC);

BOOL  APIENTRY GetTextExtentPointA(
                    IN HDC,
                    IN LPSTR,
                    IN int,
                    OUT LPSIZE
                    );
BOOL  APIENTRY GetTextExtentPointW(
                    IN HDC,
                    IN LPWSTR,
                    IN int,
                    OUT LPSIZE
                    );
#ifdef UNICODE
#define GetTextExtentPoint GetTextExtentPointW
#else
#define GetTextExtentPoint GetTextExtentPointA
#endif // !UNICODE

BOOL  APIENTRY GetViewportExtEx(IN HDC, OUT LPSIZE);
BOOL  APIENTRY GetViewportOrgEx(IN HDC, OUT LPPOINT);
BOOL  APIENTRY GetWindowExtEx(IN HDC, OUT LPSIZE);
BOOL  APIENTRY GetWindowOrgEx(IN HDC, OUT LPPOINT);

int  APIENTRY IntersectClipRect(IN HDC, IN int, IN int, IN int, IN int);
BOOL BATCH APIENTRY InvertRgn(IN HDC, IN HRGN);
BOOL APIENTRY LineDDA(IN int, IN int, IN int, IN int, IN PROC, IN LPVOID);
BOOL BATCH APIENTRY LineTo(IN HDC, IN int, IN int);
BOOL APIENTRY MaskBlt(IN HDC, IN int, IN int, IN int, IN int,
              IN HDC, IN int, IN int, IN HBITMAP, IN int, IN int, IN DWORD);
BOOL APIENTRY PlgBlt(IN HDC, IN LPPOINT, IN HDC, IN int, IN int, IN int,
                     IN int, IN HBITMAP, IN int, IN int);

int  APIENTRY OffsetClipRgn(IN HDC, IN int, IN int);
int  APIENTRY OffsetRgn(IN HRGN, IN int, IN int);
BOOL BATCH APIENTRY PatBlt(IN HDC, IN int, IN int, IN int, IN int, IN DWORD);
BOOL BATCH APIENTRY Pie(IN HDC, IN int, IN int, IN int, IN int, IN int, IN int, IN int, IN int);
BOOL APIENTRY PlayMetaFile(IN HDC, IN HMF);
BOOL BATCH APIENTRY PaintRgn(IN HDC, IN HRGN);
BOOL BATCH APIENTRY PolyPolygon(IN HDC, IN LPPOINT, IN LPINT, IN int);
BOOL APIENTRY PtInRegion(IN HRGN, IN int, IN int);
BOOL APIENTRY PtVisible(IN HDC, IN int, IN int);

BOOL APIENTRY RectInRegion(IN HRGN, IN LPRECT);
BOOL APIENTRY RectVisible(IN HDC, IN LPRECT);
BOOL BATCH APIENTRY Rectangle(IN HDC, IN int, IN int, IN int, IN int);
BOOL APIENTRY RestoreDC(IN HDC, IN int);
int  APIENTRY RealizePalette(IN HDC);
BOOL APIENTRY RemoveFontModule(IN HMODULE);
BOOL APIENTRY RemoveFontResourceA(IN LPSTR);
BOOL APIENTRY RemoveFontResourceW(IN LPWSTR);
#ifdef UNICODE
#define RemoveFontResource RemoveFontResourceW
#else
#define RemoveFontResource RemoveFontResourceA
#endif // !UNICODE
BOOL BATCH APIENTRY RoundRect(IN HDC, IN int, IN int, IN int, IN int, IN int, IN int);
BOOL APIENTRY ResizePalette(IN HPALETTE, IN UINT);

int  APIENTRY SaveDC(IN HDC);
int  APIENTRY SelectClipRgn(IN HDC, IN HRGN);
int  APIENTRY ExtSelectClipRgn(IN HDC, IN HRGN, IN int);
HANDLE APIENTRY SelectObject(IN HDC, IN HANDLE);
HPALETTE APIENTRY SelectPalette(IN HDC, IN HPALETTE, IN BOOL);
COLORREF APIENTRY SetBkColor(IN HDC, IN COLORREF);
int   APIENTRY SetBkMode(IN HDC, IN int);
int   APIENTRY SetBitmapBits(IN HBITMAP, IN DWORD, IN LPBYTE);

int   APIENTRY SetDIBits(IN HDC, IN HBITMAP, IN UINT, IN UINT, IN LPBYTE, IN LPBITMAPINFO, IN UINT);
int   APIENTRY SetDIBitsToDevice(IN HDC, IN int, IN int, IN DWORD, IN DWORD, IN int, IN int, IN DWORD, IN DWORD, IN LPBYTE, IN LPBITMAPINFO, IN DWORD);
DWORD APIENTRY SetMapperFlags(IN HDC, IN DWORD);
int   APIENTRY SetMapMode(IN HDC, IN int);
HMF   APIENTRY SetMetaFileBits(IN DWORD, IN LPBYTE);
UINT  APIENTRY SetPaletteEntries(IN HPALETTE, IN UINT, IN UINT, IN LPPALETTEENTRY);
COLORREF APIENTRY SetPixel(IN HDC, IN int, IN int, IN COLORREF);
BOOL BATCH  APIENTRY SetPixelV(IN HDC, IN int, IN int, IN COLORREF);
int   APIENTRY SetPolyFillMode(IN HDC, IN int);
BOOL BATCH  APIENTRY StretchBlt(IN HDC, IN int, IN int, IN int, IN int, IN HDC, IN int, IN int, IN int, IN int, IN DWORD);
BOOL BATCH  APIENTRY SetRectRgn(IN HRGN, IN int, IN int, IN int, IN int);
int   APIENTRY StretchDIBits(IN HDC, IN int, IN int, IN int, IN int, IN int, IN int, IN int, IN int, IN LPBYTE, IN LPBITMAPINFO, IN DWORD, IN DWORD);
int   APIENTRY SetROP2(IN HDC, IN int);
int   APIENTRY SetStretchBltMode(IN HDC, IN int);
UINT  APIENTRY SetSystemPaletteUse(IN HDC, IN UINT);
int   APIENTRY SetTextCharacterExtra(IN HDC, IN int);
COLORREF APIENTRY SetTextColor(IN HDC, IN COLORREF);
UINT  APIENTRY SetTextAlign(IN HDC, IN UINT);
BOOL  APIENTRY SetTextJustification(IN HDC, IN int, IN int);
BOOL  APIENTRY UpdateColors(IN HDC);

#ifndef NOMETAFILE

// TEMPORARY include file containing the new Metafile definitions.
// Eventually it will be folded into wingdi.h and the old metafile
// definitions will be removed when the metafile stuff settles down.
#include <winmeta.h>

BOOL APIENTRY PlayMetaFileRecord(IN HDC, IN LPHANDLETABLE, IN LPMETARECORD, IN UINT);
BOOL APIENTRY EnumMetaFile(IN HDC, IN HMF, IN PROC, IN LPVOID);
#endif

#ifndef NOTEXTMETRIC

BOOL APIENTRY GetTextMetricsA(IN HDC, OUT LPTEXTMETRICA);
BOOL APIENTRY GetTextMetricsW(IN HDC, OUT LPTEXTMETRICW);
#ifdef UNICODE
#define GetTextMetrics GetTextMetricsW
#else
#define GetTextMetrics GetTextMetricsA
#endif // !UNICODE

#endif

/* new GDI */
BOOL BATCH APIENTRY AngleArc(IN HDC, IN int, IN int, IN DWORD, IN FLOAT, IN FLOAT);
BOOL APIENTRY GetWorldTransform(IN HDC, OUT LPXFORM);
BOOL BATCH APIENTRY PolyPolyline(IN HDC, IN LPPOINT, IN LPDWORD, IN DWORD);
BOOL APIENTRY SetWorldTransform(IN HDC, IN LPXFORM);
BOOL APIENTRY ModifyWorldTransform(IN HDC,IN LPXFORM OPTIONAL, IN DWORD);
BOOL APIENTRY StartDoc(IN HDC, IN LPSTR);
BOOL APIENTRY EndDoc(IN HDC);
BOOL APIENTRY StartPage(IN HDC);
BOOL APIENTRY EndPage(IN HDC);
BOOL APIENTRY GdiFlush(VOID);
BOOL APIENTRY GdiSetBatchLimit(IN DWORD);
BOOL APIENTRY ArcTo(IN HDC, IN int, IN int, IN int, IN int, IN int, IN int,IN int, IN int);
BOOL APIENTRY BeginPath(IN HDC);
BOOL APIENTRY CloseFigure(IN HDC);
BOOL APIENTRY EndPath(IN HDC);
BOOL APIENTRY FillPath(IN HDC);
BOOL APIENTRY FlattenPath(IN HDC);
int  APIENTRY GetPath(IN HDC, OUT LPPOINT, OUT LPBYTE, IN int);
HRGN APIENTRY PathToRegion(IN HDC);
BOOL APIENTRY PolyDraw(IN HDC, IN LPPOINT, IN LPBYTE, IN int);
BOOL APIENTRY SelectClipPath(IN HDC, IN int);
BOOL APIENTRY SetFlatness(IN HDC, IN FLOAT, OUT PFLOAT);
BOOL APIENTRY SetMiterLimit(IN HDC, IN FLOAT, OUT PFLOAT);
BOOL APIENTRY StrokeAndFillPath(IN HDC);
BOOL APIENTRY StrokePath(IN HDC);
BOOL APIENTRY WidenPath(IN HDC);

/* if the thank compiler is reading this file, don't define these */
#ifndef THANKS

int     APIENTRY GetObjectA(IN HANDLE, IN int, OUT LPVOID);
int     APIENTRY GetObjectW(IN HANDLE, IN int, OUT LPVOID);
#ifdef UNICODE
#define GetObject GetObjectW
#else
#define GetObject GetObjectA
#endif // !UNICODE

BOOL    APIENTRY MoveToEx(IN HDC, IN int, IN int, OUT LPPOINT);

BOOL    BATCH APIENTRY TextOutA(
                        IN HDC,
                        IN int,
                        IN int,
                        IN LPSTR,
                        IN int
                        );
BOOL    BATCH APIENTRY TextOutW(
                        IN HDC,
                        IN int,
                        IN int,
                        IN LPWSTR,
                        IN int
                        );
#ifdef UNICODE
#define TextOut TextOutW
#else
#define TextOut TextOutA
#endif // !UNICODE

BOOL    BATCH APIENTRY ExtTextOutA(
                            IN HDC,
                            IN int,
                            IN int,
                            IN UINT,
                            IN LPRECT,
                            IN LPSTR,
                            IN int,
                            IN LPINT
                            );
BOOL    BATCH APIENTRY ExtTextOutW(
                            IN HDC,
                            IN int,
                            IN int,
                            IN UINT,
                            IN LPRECT,
                            IN LPWSTR,
                            IN int,
                            IN LPINT
                            );
#ifdef UNICODE
#define ExtTextOut ExtTextOutW
#else
#define ExtTextOut ExtTextOutA
#endif // !UNICODE

HRGN  APIENTRY CreatePolygonRgn(IN LPPOINT, IN int, IN int);
BOOL  APIENTRY DPtoLP(IN HDC, IN OUT LPPOINT, IN int);
BOOL  APIENTRY LPtoDP(IN HDC, IN OUT LPPOINT, IN int);
BOOL  APIENTRY Polygon(IN HDC, IN LPPOINT, IN int);
BOOL  APIENTRY Polyline(IN HDC, IN LPPOINT, IN int);

BOOL  APIENTRY PolyBezier(IN HDC, IN LPPOINT, IN DWORD);
BOOL  APIENTRY PolyBezierTo(IN HDC, IN LPPOINT, IN DWORD);
BOOL  APIENTRY PolylineTo(IN HDC, IN LPPOINT, IN DWORD);

BOOL  APIENTRY SetViewportExtEx(IN HDC, IN int, IN int, OUT LPSIZE);
BOOL  APIENTRY SetViewportOrgEx(IN HDC, IN int, IN int, OUT LPPOINT);
BOOL  APIENTRY SetWindowExtEx(IN HDC, IN int, IN int, OUT LPSIZE);
BOOL  APIENTRY SetWindowOrgEx(IN HDC, IN int, IN int, OUT LPPOINT);

BOOL  APIENTRY OffsetViewportOrgEx(IN HDC, IN int, IN int, OUT LPPOINT);
BOOL  APIENTRY OffsetWindowOrgEx(IN HDC, IN int, IN int, OUT LPPOINT);
BOOL  APIENTRY ScaleViewportExtEx(IN HDC, IN int, IN int, IN int, IN int, OUT LPSIZE);
BOOL  APIENTRY ScaleWindowExtEx(IN HDC, IN int, IN int, IN int, IN int, OUT LPSIZE);
BOOL  APIENTRY SetBitmapDimensionEx(IN HBITMAP, IN int, IN int, OUT LPSIZE);
BOOL  APIENTRY SetBrushOrg(IN HDC, IN int, IN int, OUT LPPOINT);

int   APIENTRY GetTextFaceA(IN HDC, IN int, OUT LPSTR);
int   APIENTRY GetTextFaceW(IN HDC, IN int, OUT LPWSTR);
#ifdef UNICODE
#define GetTextFace GetTextFaceW
#else
#define GetTextFace GetTextFaceA
#endif // !UNICODE

DWORD  APIENTRY EnumNearestFontsA(IN HDC,IN LPEXTLOGFONTA,IN DWORD,OUT LPFMATCHA);
DWORD  APIENTRY EnumNearestFontsW(IN HDC,IN LPEXTLOGFONTW,IN DWORD,OUT LPFMATCHW);
#ifdef UNICODE
#define EnumNearestFonts EnumNearestFontsW
#else
#define EnumNearestFonts EnumNearestFontsA
#endif // !UNICODE

HFONT  APIENTRY ExtCreateFontIndirectA(IN LPEXTLOGFONTA);
HFONT  APIENTRY ExtCreateFontIndirectW(IN LPEXTLOGFONTW);
#ifdef UNICODE
#define ExtCreateFontIndirect ExtCreateFontIndirectW
#else
#define ExtCreateFontIndirect ExtCreateFontIndirectA
#endif // !UNICODE

BOOL   APIENTRY SetFontMapperControls(IN LPFMCONTROLS);
BOOL   APIENTRY GetFontMapperControls(OUT LPFMCONTROLS,IN DWORD);

#endif /* THANKS */
#endif /* NOGDI */

#ifdef LATER
/*
 * JimA - 11/30/90
 *   gdidelta.doc lists these as obsolete
 */
DWORD   APIENTRY GetDCOrg(HDC);
#endif  /* LATER */


#endif /* _WINGDI_ */
