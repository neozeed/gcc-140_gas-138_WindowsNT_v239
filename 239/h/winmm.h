/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1990-91, Microsoft Corporation

Module Name:

    winmm.h

Abstract:

    This include file defines all the support for Multimedia applications.

    24-Apr-91 MMTIME structure added. NigelT.

--*/

#ifndef _WINMM_
#define _WINMM_

/****************************************************************************

    Multimedia Systems Window Messages

****************************************************************************/

#ifndef WM_MM_RESERVED_FIRST
// taken from windows.h
/* The following message range reserved for multi-media */
#define WM_MM_RESERVED_FIRST 0x03B0
#define WM_MM_RESERVED_LAST  0x03EF
#endif

#define MM_MCINOTIFY	    (WM_MM_RESERVED_FIRST + 9)
#define MM_MCISYSTEM_STRING (WM_MM_RESERVED_FIRST + 26)

/****************************************************************************

    PlaySound API and flags

****************************************************************************/

BOOL APIENTRY PlaySound(LPSTR lpszName, HANDLE hModule, DWORD dwFlags);

// sound types

#define SND_ALIAS       0x00000001      // name is a WIN.INI [sounds] entry
#define SND_FILENAME    0x00000002      // name is a file name
#define SND_RESOURCE    0x00000003      // name is a resource name or atom
#define SND_TYPE_MASK   0x000000FF

#define SND_ASYNC       0x00000000      // sound plays asynchronously
#define SND_SYNC        0x00000100      // sound plays synchronously

#define SND_NODEFAULT   0x00001000      // don't use the default sound
#define SND_NOWAIT      0x00002000      // don't wait if the driver is busy

/***************************************************************************

    Time structure used by Multimedia APIs

***************************************************************************/

typedef struct _MMTIME {
    WORD    wType;              // the contents of the union
    union {
        DWORD ms;               // milliseconds
        DWORD sample;           // samples
        DWORD cb;               // byte count
        struct {                // SMPTE
            BYTE hour;          // hours
            BYTE minutes;       // minutes - can't use min as it's a macro
            BYTE sec;           // seconds
            BYTE frame;         // frames
            BYTE fps;           // frames per second (24, 25, 29(30 drop) or 30)
            BYTE dummy;
            } smpte;
        struct {                // MIDI
        DWORD songptrpos;       // song pointer position
            } midi;
        } u;
    } MMTIME, *PMMTIME, *LPMMTIME;

//
// types for MMTIME struct
//

#define TIME_MS         0x0001  // time counted in Milliseconds
#define TIME_SAMPLES    0x0002  // number of wave samples
#define TIME_BYTES      0x0004  // current byte offset
#define TIME_SMPTE      0x0008  // smpte time
#define TIME_MIDI       0x0010  // midi time

/***************************************************************************

    MMIO types, structures and APIs

***************************************************************************/

typedef DWORD           FOURCC;         // a four character code
typedef HANDLE          HMMIO;          // a handle to an open file

#define CFSEPCHAR       '+'             // compound file name separator char.

typedef LONG (*LPMMIOPROC)(
            LPSTR lpmmioinfo,
            WORD wMsg,
            LONG lParam1,
            LONG lParam2
            );

typedef struct _MMIOINFO        // structure for representing MMIO state
{
        /* general fields */
        DWORD           dwFlags;        // general status flags
        FOURCC          fccIOProc;      // ptr. to I/O procedure
        LPMMIOPROC      pIOProc;        // ptr. to I/O procedure
        WORD            wErrorRet;      // place for error to be returned
        WORD            wReserved;      // <for structure alignment>

        /* fields maintained by MMIO functions during buffered I/O */
        LONG            cchBuffer;      // size of I/O buffer (or 0L)
        LPSTR           pchBuffer;      // start of I/O buffer (or NULL)
        LPSTR           pchNext;        // ptr. to next byte to read/write
        LPSTR           pchEndRead;     // ptr. to last valid byte to read
        LPSTR           pchEndWrite;    // ptr. to last available byte to write
        LONG            lBufOffset;     // disk offset of start of buffer

        /* fields maintained by I/O procedure */
        LONG            lDiskOffset;    // disk offset of next read or write
        DWORD           adwInfo[3];     // data specific to type of MMIOPROC

        /* other fields maintained by MMIO */
        DWORD           dwReserved1;    // reserved for MMIO use
        DWORD           dwReserved2;    // reserved for MMIO use
        HMMIO           hmmio;          // handle to open file
} MMIOINFO, FAR * LPMMIOINFO;

typedef struct _MMCKINFO        // structure for representing RIFF chunk info.
{
        FOURCC          ckid;           // chunk ID
        DWORD           cksize;         // chunk size
        FOURCC          fccType;        // form type or list type
        DWORD           dwDataOffset;   // offset of data portion of chunk
        DWORD           dwFlags;        // flags used by MMIO functions
} MMCKINFO, FAR *LPMMCKINFO;

/* <dwFlags> field of MMIOINFO structure -- many same as OpenFile() flags */
/* Low word of flags will be passed to OpenFile() -- therefore, any MMIO-
    specific flags should be in the high word.  */
#define MMIO_RWMODE     0x00000003      // open file for reading/writing/both
#define MMIO_SHAREMODE  0x00000070      // file sharing mode number
#define MMIO_CREATE     0x00001000      // create new file (or truncate file)
#define MMIO_DELETE     0x00000200      // create new file (or truncate file)
#define MMIO_ALLOCBUF   0x00010000      // mmioOpen() should allocate a buffer
#define MMIO_DIRTY      0x10000000      // I/O buffer is dirty
/* MMIO_DIRTY is also used in the <dwFlags> field of MMCKINFO structure */

/* read/write mode numbers (bit field MMIO_RWMODE) */
#define MMIO_READ       0x00000000      // open file for reading only
#define MMIO_WRITE      0x00000001      // open file for writing only
#define MMIO_READWRITE  0x00000002      // open file for reading and writing

/* share mode numbers (bit field MMIO_SHAREMODE) */
#define MMIO_COMPAT     0x00000000      // compatibility mode
#define MMIO_EXCLUSIVE  0x00000010      // exclusive-access mode
#define MMIO_DENYWRITE  0x00000020      // deny writing to other processes
#define MMIO_DENYREAD   0x00000030      // deny reading to other processes
#define MMIO_DENYNONE   0x00000040      // deny nothing to other processes

/* flags for other functions */
#define MMIO_FHOPEN             0x0010  // mmioClose(): keep file handle open
#define MMIO_EMPTYBUF           0x0010  // mmioFlush(): empty the I/O buffer
#define MMIO_TOUPPER            0x0010  // mmioStringToFOURCC(): cvt. to u-case
#define MMIO_INSTALLPROC    0x00010000  // mmioInstallIOProc(): install MMIOProc
#define MMIO_REMOVEPROC     0x00020000  // mmioInstallIOProc(): remove MMIOProc
#define MMIO_FINDPROC       0x00040000  // mmioInstallIOProc(): find an MMIOProc
#define MMIO_FINDCHUNK          0x0010  // mmioDescend(): find a chunk by ID
#define MMIO_FINDRIFF           0x0020  // mmioDescend(): find a LIST chunk
#define MMIO_FINDLIST           0x0040  // mmioDescend(): find a RIFF chunk
#define MMIO_CREATERIFF         0x0020  // mmioCreateChunk(): make a LIST chunk
#define MMIO_CREATELIST         0x0040  // mmioCreateChunk(): make a RIFF chunk

/* message numbers for MMIOPROC */
#define MMIOM_READ      MMIO_READ       // read (must equal MMIO_READ!)
#define MMIOM_WRITE    MMIO_WRITE       // write (must equal MMIO_WRITE!)
#define MMIOM_SEEK              2       // seek to a new position in file
#define MMIOM_OPEN              3       // open file
#define MMIOM_CLOSE             4       // close file
#define MMIOM_WRITEFLUSH        5       // write and flush
#define MMIOM_USER         0x8000       // beginning of user-defined messages

/* standard four character codes */
#define FOURCC_RIFF     mmioFOURCC('R', 'I', 'F', 'F')
#define FOURCC_LIST     mmioFOURCC('L', 'I', 'S', 'T')

/* four character codes used to identify standard built-in I/O procedures */
#define FOURCC_DOS      mmioFOURCC('D', 'O', 'S', ' ')
#define FOURCC_MEM      mmioFOURCC('M', 'E', 'M', ' ')

/* error numbers */
#define MMIOERR_BASE            256
#define MMIOERR_FILENOTFOUND    (MMIOERR_BASE + 1)  // file not found
#define MMIOERR_OUTOFMEMORY     (MMIOERR_BASE + 2)  // out of memory
#define MMIOERR_CANNOTOPEN      (MMIOERR_BASE + 3)  // cannot open
#define MMIOERR_CANNOTCLOSE     (MMIOERR_BASE + 4)  // cannot close
#define MMIOERR_CANNOTREAD      (MMIOERR_BASE + 5)  // cannot read
#define MMIOERR_CANNOTWRITE     (MMIOERR_BASE + 6)  // cannot write
#define MMIOERR_CANNOTSEEK      (MMIOERR_BASE + 7)  // cannot seek
#define MMIOERR_CANNOTEXPAND    (MMIOERR_BASE + 8)  // cannot expand file
#define MMIOERR_CHUNKNOTFOUND   (MMIOERR_BASE + 9)  // chunk not found
#define MMIOERR_UNBUFFERED      (MMIOERR_BASE + 10) // file is unbuffered

/* other constants */
#define MMIO_DEFAULTBUFFER      8192    // default buffer size

/* macros */
#define mmioFOURCC( ch0, ch1, ch2, ch3 )                                \
                ( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) |    \
                ( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )

/* MMIO prototypes */
FOURCC mmioStringToFOURCC(LPSTR sz, WORD wFlags);
LPMMIOPROC mmioInstallIOProc(FOURCC fccIOProc, LPMMIOPROC pIOProc,
        DWORD dwFlags);
HMMIO mmioOpen(LPSTR szFileName, LPMMIOINFO lpmmioinfo,
        DWORD dwOpenFlags);
WORD mmioClose(HMMIO hmmio, WORD wFlags);
LONG mmioRead(HMMIO hmmio, LPSTR pch, LONG cch);
LONG mmioWrite(HMMIO hmmio, LPSTR pch, LONG cch);
LONG mmioSeek(HMMIO hmmio, LONG lOffset, int iOrigin);
WORD mmioGetInfo(HMMIO hmmio, LPMMIOINFO lpmmioinfo, WORD wFlags);
WORD mmioSetInfo(HMMIO hmmio, LPMMIOINFO lpmmioinfo, WORD wFlags);
WORD mmioSetBuffer(HMMIO hmmio, LPSTR pchBuffer, LONG cchBuffer,
        WORD wFlags);
WORD mmioFlush(HMMIO hmmio, WORD wFlags);
WORD mmioAdvance(HMMIO hmmio, LPMMIOINFO lpmmioinfo, WORD wFlags);
LONG mmioSendMessage(HANDLE hmmio, WORD wMsg,
        LONG lParam1, LONG lParam2);

/* RIFF I/O prototypes */
WORD mmioDescend(HANDLE hmmio, LPMMCKINFO lpck,
        LPMMCKINFO lpckParent, WORD wFlags);
WORD mmioAscend(HANDLE hmmio, LPMMCKINFO lpck, WORD wFlags);
WORD mmioCreateChunk(HANDLE hmmio, LPMMCKINFO lpck, WORD wFlags);

/***************************************************************************

    WAVE file specific defines

***************************************************************************/

#define ckidWAVE mmioFOURCC('W','A','V','E') // RIFF WAVE file id

//
// basic wave format for sampled audio
//

typedef struct _WAVEFORMAT {
    USHORT FormatTag;        // format type (WAVE_FORMAT_PCM)
    USHORT Channels;         // number of channels
    ULONG SamplesPerSec;     // sample rate
    ULONG AvgBytesPerSec;    // for buffer estimation
    USHORT BlockAlign;       // block size of data
} WAVEFORMAT, *PWAVEFORMAT;

//
// wave format for PCM sampled audio
//

typedef struct _PCMWAVEFORMAT {
    USHORT FormatTag;        // format type (WAVE_FORMAT_PCM)
    USHORT Channels;         // number of channels
    ULONG SamplesPerSec;     // sample rate
    ULONG AvgBytesPerSec;    // for buffer estimation
    USHORT BlockAlign;       // block size of data
    USHORT BitsPerSample;    // bits per sample
} PCMWAVEFORMAT, *PPCMWAVEFORMAT;

#define WAVE_FORMAT_PCM 1

/****************************************************************************

    String resource number bases

****************************************************************************/

#define MAXERRORLENGTH         128    // maximum error text length (including
				      // terminating null)
// error string resources
#define MMSYSERR_BASE          0
#define WAVERR_BASE            32
#define MIDIERR_BASE           64
#define TIMERR_BASE            128
#define JOYERR_BASE            160
#define MCIERR_BASE            256

#define MCI_STRING_OFFSET      512    // general mci string resources
#define MCI_VD_OFFSET          544    // videodisc command string resources
#define MCI_CD_OFFSET          576    // redbook audio command string resources
#define MCI_WAVE_OFFSET        608    // wave audio command string resources

// THIS NUMBER IS HARDCODED WHERE THE MCI_SEQ_<x>'s ARE #define'd
// You must change those definitions if you change this number
#define MCI_SEQ_OFFSET	       640    // sequencer command string resources

// THIS NUMBER IS HARDCODED WHERE THE MCI_FORMAT_<x>'s ARE #define'd
// You must change those definitions if you change this number
#define MCI_FORMATS_OFFSET     672    // MCI Time Formats

/****************************************************************************

		MCI

****************************************************************************/


//
//  MCI error return values
//


#define MCIERR_INVALID_DEVICE_ID        (MCIERR_BASE + 1)
#define MCIERR_UNRECOGNIZED_KEYWORD     (MCIERR_BASE + 3)
#define MCIERR_UNRECOGNIZED_COMMAND     (MCIERR_BASE + 5)
#define MCIERR_HARDWARE                 (MCIERR_BASE + 6)
#define MCIERR_INVALID_DEVICE_NAME      (MCIERR_BASE + 7)
#define MCIERR_OUT_OF_MEMORY            (MCIERR_BASE + 8)
#define MCIERR_DEVICE_OPEN              (MCIERR_BASE + 9)
#define MCIERR_CANNOT_LOAD_DRIVER       (MCIERR_BASE + 10)
#define MCIERR_MISSING_COMMAND_STRING   (MCIERR_BASE + 11)
#define MCIERR_PARAM_OVERFLOW           (MCIERR_BASE + 12)
#define MCIERR_MISSING_STRING_ARGUMENT  (MCIERR_BASE + 13)
#define MCIERR_BAD_INTEGER              (MCIERR_BASE + 14)
#define MCIERR_PARSER_INTERNAL          (MCIERR_BASE + 15)
#define MCIERR_DRIVER_INTERNAL          (MCIERR_BASE + 16)
#define MCIERR_MISSING_PARAMETER        (MCIERR_BASE + 17)
#define MCIERR_UNSUPPORTED_FUNCTION     (MCIERR_BASE + 18)
#define MCIERR_FILE_NOT_FOUND           (MCIERR_BASE + 19)
#define MCIERR_DEVICE_NOT_READY         (MCIERR_BASE + 20)
#define MCIERR_INTERNAL                 (MCIERR_BASE + 21)
#define MCIERR_DRIVER                   (MCIERR_BASE + 22)
#define MCIERR_CANNOT_USE_ALL           (MCIERR_BASE + 23)
#define MCIERR_MULTIPLE                 (MCIERR_BASE + 24)
#define MCIERR_EXTENSION_NOT_FOUND      (MCIERR_BASE + 25)
#define MCIERR_OUTOFRANGE	        (MCIERR_BASE + 26)
#define MCIERR_FLAGS_NOT_COMPATIBLE     (MCIERR_BASE + 28)
#define MCIERR_FILE_NOT_SAVED           (MCIERR_BASE + 30)
#define MCIERR_DEVICE_TYPE_REQUIRED     (MCIERR_BASE + 31)
#define MCIERR_DEVICE_LOCKED            (MCIERR_BASE + 32)
#define MCIERR_DUPLICATE_ALIAS          (MCIERR_BASE + 33)
#define MCIERR_BAD_CONSTANT             (MCIERR_BASE + 34)
#define MCIERR_MUST_USE_SHAREABLE       (MCIERR_BASE + 35)
#define MCIERR_MISSING_DEVICE_NAME      (MCIERR_BASE + 36)
#define MCIERR_BAD_TIME_FORMAT          (MCIERR_BASE + 37)
#define MCIERR_NO_CLOSING_QUOTE         (MCIERR_BASE + 38)
#define MCIERR_DUPLICATE_FLAGS          (MCIERR_BASE + 39)
#define	MCIERR_INVALID_FILE		(MCIERR_BASE + 40)
#define MCIERR_NULL_PARAMETER_BLOCK     (MCIERR_BASE + 41)
#define	MCIERR_UNNAMED_RESOURCE		(MCIERR_BASE + 42)
#define MCIERR_NEW_REQUIRES_ALIAS       (MCIERR_BASE + 43)
#define MCIERR_NOTIFY_ON_AUTO_OPEN      (MCIERR_BASE + 44)
#define MCIERR_NO_ELEMENT_ALLOWED       (MCIERR_BASE + 45)

#define MCIERR_WAVE_OUTPUTSINUSE        (MCIERR_BASE + 64)
#define MCIERR_WAVE_SETOUTPUTINUSE      (MCIERR_BASE + 65)
#define MCIERR_WAVE_INPUTSINUSE         (MCIERR_BASE + 66)
#define MCIERR_WAVE_SETINPUTINUSE       (MCIERR_BASE + 67)
#define MCIERR_WAVE_OUTPUTUNSPECIFIED   (MCIERR_BASE + 68)
#define MCIERR_WAVE_INPUTUNSPECIFIED    (MCIERR_BASE + 69)
#define MCIERR_WAVE_OUTPUTSUNSUITABLE   (MCIERR_BASE + 70)
#define MCIERR_WAVE_SETOUTPUTUNSUITABLE (MCIERR_BASE + 71)
#define MCIERR_WAVE_INPUTSUNSUITABLE    (MCIERR_BASE + 72)
#define MCIERR_WAVE_SETINPUTUNSUITABLE  (MCIERR_BASE + 73)


#define MCIERR_SEQ_DIV_INCOMPATIBLE	(MCIERR_BASE + 80)
#define MCIERR_SEQ_PORT_INUSE		(MCIERR_BASE + 81)
#define MCIERR_SEQ_PORT_NONEXISTENT	(MCIERR_BASE + 82)
#define MCIERR_SEQ_PORT_MAPNODEVICE	(MCIERR_BASE + 83)
#define MCIERR_SEQ_PORT_MISCERROR	(MCIERR_BASE + 84)
#define MCIERR_SEQ_TIMER		(MCIERR_BASE + 85)
#define MCIERR_SEQ_PORTUNSPECIFIED      (MCIERR_BASE + 86)

#define MCIERR_NO_WINDOW                (MCIERR_BASE + 90)
#define MCIERR_CREATEWINDOW             (MCIERR_BASE + 91)
#define MCIERR_FILE_READ                (MCIERR_BASE + 92) 
#define MCIERR_FILE_WRITE               (MCIERR_BASE + 93)

// All custom device driver errors must be greater than this value
#define MCIERR_CUSTOM_DRIVER_BASE       (MCIERR_BASE + 256)

/****************************************************************************

    MCI command message identifiers

*****************************************************************************/
// Message numbers are hard coded because the resource compiler
// will otherwise fail on the RCDATA command table in mmsystem.rc

// They must be in the range between MCI_FIRST and MCI_LAST

#define MCI_FIRST                       0x0800
// Messages 0x801 and 0x802 are reserved
#define MCI_OPEN                        0x0803
#define MCI_CLOSE                       0x0804
#define MCI_ESCAPE                      0x0805
#define MCI_PLAY                        0x0806
#define MCI_SEEK                        0x0807
#define MCI_STOP                        0x0808
#define MCI_PAUSE                       0x0809
#define MCI_INFO                        0x080A
#define MCI_GETDEVCAPS                  0x080B
#define MCI_SPIN                        0x080C
#define MCI_SET                         0x080D
#define MCI_STEP                        0x080E
#define MCI_RECORD                      0x080F
#define MCI_SYSINFO                     0x0810
#define MCI_BREAK                       0x0811
#define MCI_SOUND                       0x0812
#define MCI_SAVE                        0x0813
#define MCI_STATUS                      0x0814

#define MCI_CUE                         0x0830

#define MCI_REALIZE                     0x0840
#define MCI_WINDOW                      0x0841
#define MCI_PUT                         0x0842
#define MCI_WHERE                       0x0843
#define MCI_FREEZE                      0x0844
#define MCI_UNFREEZE                    0x0845

#define MCI_LOAD                        0x0850
#define MCI_CUT                         0x0851
#define MCI_COPY                        0x0852
#define MCI_PASTE                       0x0853
#define MCI_UPDATE                      0x0854
#define MCI_RESUME                      0x0855
#define MCI_DELETE                      0x0856

#define MCI_LAST                        0x0FFF

// the next 0x400 message ID's are reserved for custom drivers
#define MCI_USER_MESSAGES               (0x400 + MCI_FIRST)

/****************************************************************************

    Structures for the lpdwParams (dwParam2) of mciSendCommand for those
    command messages that may be parsed in string form.

*****************************************************************************/

// string resource ID's for the MCI core

#define MCI_FALSE                       (MCI_STRING_OFFSET + 0)
#define MCI_TRUE                        (MCI_STRING_OFFSET + 1)
#define MCI_NONE                        (MCI_STRING_OFFSET + 2)

#define MCI_ALL_DEVICE_ID               0xFFFF

#define MCI_DEVTYPE_VCR                 (MCI_STRING_OFFSET + 3)
#define MCI_DEVTYPE_VIDEODISC           (MCI_STRING_OFFSET + 4)
#define MCI_DEVTYPE_OVERLAY             (MCI_STRING_OFFSET + 5)
#define MCI_DEVTYPE_CD_AUDIO            (MCI_STRING_OFFSET + 6)
#define MCI_DEVTYPE_DAT                 (MCI_STRING_OFFSET + 7)
#define MCI_DEVTYPE_SCANNER             (MCI_STRING_OFFSET + 8)
#define MCI_DEVTYPE_ANIMATION           (MCI_STRING_OFFSET + 9)
#define MCI_DEVTYPE_DIGITAL_VIDEO       (MCI_STRING_OFFSET + 10)
#define MCI_DEVTYPE_OTHER               (MCI_STRING_OFFSET + 11)
#define MCI_DEVTYPE_WAVEFORM_AUDIO      (MCI_STRING_OFFSET + 12)
#define MCI_DEVTYPE_SEQUENCER           (MCI_STRING_OFFSET + 13)

#define MCI_DEVTYPE_FIRST               MCI_DEVTYPE_VCR
#define MCI_DEVTYPE_LAST                MCI_DEVTYPE_SEQUENCER
#define MCI_DEVTYPE_FIRST_USER          0x1000

#define MCI_MODE_NOT_READY              (MCI_STRING_OFFSET + 20)
#define MCI_MODE_STOP                   (MCI_STRING_OFFSET + 21)
#define MCI_MODE_PLAY                   (MCI_STRING_OFFSET + 22)
#define MCI_MODE_RECORD                 (MCI_STRING_OFFSET + 23)
#define MCI_MODE_SEEK                   (MCI_STRING_OFFSET + 24)
#define MCI_MODE_PAUSE                  (MCI_STRING_OFFSET + 25)
#define MCI_MODE_OPEN                   (MCI_STRING_OFFSET + 26)

// These are not based on MCI_FORMATS_OFFSET because of resource
// compiler limitations
#define MCI_FORMAT_MILLISECONDS         672
#define MCI_FORMAT_HMS                  673
#define MCI_FORMAT_MSF                  674
#define MCI_FORMAT_FRAMES               675
#define MCI_FORMAT_SMPTE_24		676
#define MCI_FORMAT_SMPTE_25		677
#define MCI_FORMAT_SMPTE_30		678
#define MCI_FORMAT_SMPTE_30DROP	        679
#define MCI_FORMAT_BYTES                680
#define MCI_FORMAT_SAMPLES              681
#define MCI_FORMAT_TMSF                 682

#define MCI_MSF_MINUTE(msf)             ((BYTE)(msf))
#define MCI_MSF_SECOND(msf)             ((BYTE)(((WORD)(msf)) >> 8))
#define MCI_MSF_FRAME(msf)              ((BYTE)((msf)>>16))

#define MCI_MAKE_MSF(m, s, f)           ((DWORD)(((BYTE)(m) | \
                                                  ((WORD)(s)<<8)) | \
                                                 (((DWORD)(BYTE)(f))<<16)))
                                        
#define MCI_TMSF_TRACK(tmsf)            ((BYTE)(tmsf))
#define MCI_TMSF_MINUTE(tmsf)           ((BYTE)(((WORD)(tmsf)) >> 8))
#define MCI_TMSF_SECOND(tmsf)           ((BYTE)((tmsf)>>16))
#define MCI_TMSF_FRAME(tmsf)            ((BYTE)((tmsf)>>24))

#define MCI_MAKE_TMSF(t, m, s, f)       ((DWORD)(((BYTE)(t) | \
                                                  ((WORD)(m)<<8)) | \
                                                 (((DWORD) \
                                                   (BYTE)(s) | \
                                                   ((WORD)(f)<<8)) \
                                                   <<16)))

#define MCI_HMS_HOUR(hms)               ((BYTE)(hms))
#define MCI_HMS_MINUTE(hms)             ((BYTE)(((WORD)(hms)) >> 8))
#define MCI_HMS_SECOND(hms)             ((BYTE)((hms)>>16))

#define MCI_MAKE_HMS(h, m, s)           ((DWORD)(((BYTE)(h) | \
                                                  ((WORD)(m)<<8)) | \
                                                 (((DWORD)(BYTE)(s))<<16)))
                                        

// Flags for mciDriverNotify

#define MCI_NOTIFY_SUCCESSFUL           0x0001
#define MCI_NOTIFY_SUPERSEDED           0x0002
#define MCI_NOTIFY_ABORTED              0x0004
#define MCI_NOTIFY_FAILURE              0x0008

// NOTE: All flags must have an "L" suffix in order to be parsed as
// DWORDs by the resource compiler

#define MCI_NOTIFY                      0x00000001L
#define MCI_WAIT                        0x00000002L
#define MCI_FROM                        0x00000004L
#define MCI_TO                          0x00000008L
#define MCI_TRACK                       0x00000010L

#define MCI_OPEN_SHAREABLE              0x00000100L
#define MCI_OPEN_ELEMENT                0x00000200L
#define MCI_OPEN_ALIAS                  0x00000400L
#define MCI_OPEN_ELEMENT_ID             0x00000800L
#define MCI_OPEN_TYPE_ID                0x00001000L
#define MCI_OPEN_TYPE                   0x00002000L

#define MCI_SEEK_TO_START               0x00000100L
#define MCI_SEEK_TO_END                 0x00000200L

#define MCI_STATUS_ITEM                 0x00000100L
#define MCI_STATUS_START                0x00000200L

#define MCI_STATUS_LENGTH               0x00000001L
#define MCI_STATUS_POSITION             0x00000002L
#define MCI_STATUS_NUMBER_OF_TRACKS     0x00000003L
#define MCI_STATUS_MODE                 0x00000004L
#define MCI_STATUS_MEDIA_PRESENT        0x00000005L
#define MCI_STATUS_TIME_FORMAT          0x00000006L
#define MCI_STATUS_READY                0x00000007L
#define MCI_STATUS_CURRENT_TRACK        0x00000008L

#define MCI_INFO_PRODUCT                0x00000100L
#define MCI_INFO_FILE                   0x00000200L

#define MCI_GETDEVCAPS_ITEM             0x00000100L

#define MCI_GETDEVCAPS_CAN_RECORD       0x00000001L
#define MCI_GETDEVCAPS_HAS_AUDIO        0x00000002L
#define MCI_GETDEVCAPS_HAS_VIDEO        0x00000003L
#define MCI_GETDEVCAPS_DEVICE_TYPE      0x00000004L
#define MCI_GETDEVCAPS_USES_FILES       0x00000005L
#define MCI_GETDEVCAPS_COMPOUND_DEVICE  0x00000006L
#define MCI_GETDEVCAPS_CAN_EJECT        0x00000007L
#define MCI_GETDEVCAPS_CAN_PLAY         0x00000008L
#define MCI_GETDEVCAPS_CAN_SAVE         0x00000009L

#define MCI_SYSINFO_QUANTITY            0x00000100L
#define MCI_SYSINFO_OPEN                0x00000200L
#define MCI_SYSINFO_NAME                0x00000400L
#define MCI_SYSINFO_INSTALLNAME         0x00000800L

#define MCI_SET_DOOR_OPEN               0x00000100L
#define MCI_SET_DOOR_CLOSED             0x00000200L
#define MCI_SET_TIME_FORMAT             0x00000400L
#define MCI_SET_AUDIO                   0x00000800L
#define MCI_SET_VIDEO                   0x00001000L
#define MCI_SET_ON                      0x00002000L
#define MCI_SET_OFF                     0x00004000L

#define MCI_SET_AUDIO_ALL               0x00004001L
#define MCI_SET_AUDIO_LEFT              0x00004002L
#define MCI_SET_AUDIO_RIGHT             0x00004003L

#define MCI_BREAK_KEY                   0x00000100L
#define MCI_BREAK_HWND                  0x00000200L
#define MCI_BREAK_OFF                   0x00000400L

#define MCI_RECORD_INSERT               0x00000100L
#define MCI_RECORD_OVERWRITE            0x00000200L

#define MCI_SOUND_NAME                  0x00000100L

#define MCI_SAVE_FILE                   0x00000100L  

#define MCI_LOAD_FILE                   0x00000100L  

typedef struct {
    DWORD   dwCallback;
} MCI_GENERIC_PARMS;
typedef MCI_GENERIC_PARMS FAR *LPMCI_GENERIC_PARMS;

typedef struct {
    DWORD   dwCallback;
    WORD    wDeviceID;       
    WORD    wReserved0;
    LPSTR   lpstrDeviceType; 
    LPSTR   lpstrElementName;
    LPSTR   lpstrAlias;      
} MCI_OPEN_PARMS;
typedef MCI_OPEN_PARMS FAR *LPMCI_OPEN_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwFrom;         
    DWORD   dwTo;           
} MCI_PLAY_PARMS;
typedef MCI_PLAY_PARMS FAR *LPMCI_PLAY_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwTo;           
} MCI_SEEK_PARMS;
typedef MCI_SEEK_PARMS FAR *LPMCI_SEEK_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwReturn;
    DWORD   dwItem;
    DWORD   dwTrack;
} MCI_STATUS_PARMS;
typedef MCI_STATUS_PARMS FAR * LPMCI_STATUS_PARMS;

typedef struct {
    DWORD   dwCallback;
    LPSTR   lpstrReturn;
    DWORD   dwRetSize;
} MCI_INFO_PARMS;
typedef MCI_INFO_PARMS FAR * LPMCI_INFO_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwReturn;
    DWORD   dwItem;
} MCI_GETDEVCAPS_PARMS;
typedef MCI_GETDEVCAPS_PARMS FAR * LPMCI_GETDEVCAPS_PARMS;

typedef struct {
    DWORD   dwCallback;    
    LPSTR   lpstrReturn;
    DWORD   dwRetSize;
    DWORD   dwNumber;
    WORD    wDeviceType;        
    WORD    wReserved0;
} MCI_SYSINFO_PARMS;
typedef MCI_SYSINFO_PARMS FAR * LPMCI_SYSINFO_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwTimeFormat;
    DWORD   dwAudio;
} MCI_SET_PARMS;
typedef MCI_SET_PARMS FAR *LPMCI_SET_PARMS;

typedef struct {
    DWORD   dwCallback;     
    int     nVirtKey;
    WORD    wReserved0;
    HWND    hwndBreak;
    WORD    wReserved1;
} MCI_BREAK_PARMS;
typedef MCI_BREAK_PARMS FAR * LPMCI_BREAK_PARMS;

typedef struct {
    DWORD   dwCallback;
    LPSTR   lpstrSoundName;
} MCI_SOUND_PARMS;
typedef MCI_SOUND_PARMS FAR * LPMCI_SOUND_PARMS;
    
typedef struct {
    DWORD   dwCallback;
    LPSTR   lpfilename;
} MCI_SAVE_PARMS;
typedef MCI_SAVE_PARMS FAR * LPMCI_SAVE_PARMS;

typedef struct {
    DWORD   dwCallback;
    LPSTR   lpfilename;
} MCI_LOAD_PARMS;
typedef MCI_LOAD_PARMS FAR * LPMCI_LOAD_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwFrom;         
    DWORD   dwTo;           
} MCI_RECORD_PARMS;
typedef MCI_RECORD_PARMS FAR *LPMCI_RECORD_PARMS;

/*****************************************************************************

    Standard command parameters for videodisc drivers

*****************************************************************************/

// string resource ID's for videodisc players 
// return ID's for videodisc status command

#define MCI_VD_MODE_PARK                (MCI_VD_OFFSET + 3)

// return ID's for videodisc MCI_GETDEVCAPS command

#define MCI_VD_MEDIA_CLV                (MCI_VD_OFFSET + 10)
#define MCI_VD_MEDIA_CAV                (MCI_VD_OFFSET + 11)
#define MCI_VD_MEDIA_OTHER              (MCI_VD_OFFSET + 12)
#define	MCI_VD_FORMAT_TRACK_S		(MCI_VD_OFFSET + 13)

#define MCI_VD_FORMAT_TRACK             0x4001

#define MCI_VD_PLAY_REVERSE             0x00010000L  
#define MCI_VD_PLAY_FAST                0x00020000L  
#define MCI_VD_PLAY_SPEED               0x00040000L  
#define MCI_VD_PLAY_SCAN                0x00080000L  
#define MCI_VD_PLAY_SLOW                0x00100000L  

#define MCI_VD_SEEK_REVERSE             0x00010000L

#define MCI_VD_STATUS_SPEED             0x00004002L
#define MCI_VD_STATUS_FORWARD           0x00004003L
#define MCI_VD_STATUS_MEDIA_TYPE        0x00004004L
#define MCI_VD_STATUS_SIDE              0x00004005L
#define MCI_VD_STATUS_DISC_SIZE         0x00004006L

#define MCI_VD_GETDEVCAPS_CLV           0x00010000L
#define MCI_VD_GETDEVCAPS_CAV           0x00020000L

#define MCI_VD_SPIN_UP                  0x00010000L
#define MCI_VD_SPIN_DOWN                0x00020000L

#define MCI_VD_GETDEVCAPS_CAN_REVERSE   0x00004002L
#define MCI_VD_GETDEVCAPS_FAST_RATE     0x00004003L
#define MCI_VD_GETDEVCAPS_SLOW_RATE     0x00004004L
#define MCI_VD_GETDEVCAPS_NORMAL_RATE   0x00004005L

#define MCI_VD_STEP_FRAMES              0x00010000L
#define MCI_VD_STEP_REVERSE             0x00020000L

#define MCI_VD_ESCAPE_STRING            0x00000100L

typedef struct {
    DWORD   dwCallback;
    DWORD   dwFrom;         
    DWORD   dwTo;           
    DWORD   dwSpeed;         
    } MCI_VD_PLAY_PARMS;
typedef MCI_VD_PLAY_PARMS FAR *LPMCI_VD_PLAY_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwFrames;
} MCI_VD_STEP_PARMS;
typedef MCI_VD_STEP_PARMS FAR *LPMCI_VD_STEP_PARMS;

typedef struct {
    DWORD   dwCallback;
    LPSTR   lpstrCommand;           
} MCI_VD_ESCAPE_PARMS;
typedef MCI_VD_ESCAPE_PARMS FAR *LPMCI_VD_ESCAPE_PARMS;

/*****************************************************************************
  
    Standard command parameters for waveform audio drivers
  
*****************************************************************************/

#define	MCI_WAVE_PCM			(MCI_WAVE_OFFSET+0)
#define	MCI_WAVE_MAPPER			(MCI_WAVE_OFFSET+1)

#define MCI_WAVE_OPEN_BUFFER            0x00010000L

#define MCI_WAVE_SET_FORMATTAG          0x00010000L
#define MCI_WAVE_SET_CHANNELS           0x00020000L
#define MCI_WAVE_SET_SAMPLESPERSEC      0x00040000L
#define MCI_WAVE_SET_AVGBYTESPERSEC     0x00080000L
#define MCI_WAVE_SET_BLOCKALIGN         0x00100000L
#define MCI_WAVE_SET_BITSPERSAMPLE      0x00200000L

#define MCI_WAVE_STATUS_FORMATTAG       0x00004001L
#define MCI_WAVE_STATUS_CHANNELS        0x00004002L
#define MCI_WAVE_STATUS_SAMPLESPERSEC   0x00004003L
#define MCI_WAVE_STATUS_AVGBYTESPERSEC  0x00004004L
#define MCI_WAVE_STATUS_BLOCKALIGN      0x00004005L
#define MCI_WAVE_STATUS_BITSPERSAMPLE   0x00004006L
#define MCI_WAVE_STATUS_LEVEL           0x00004007L

#define MCI_WAVE_INPUT                  0x00400000L
#define MCI_WAVE_OUTPUT                 0x00800000L


#define MCI_WAVE_SET_ANYINPUT           0x04000000L
#define MCI_WAVE_SET_ANYOUTPUT          0x08000000L

#define MCI_WAVE_GETDEVCAPS_INPUTS      0x00004001L
#define MCI_WAVE_GETDEVCAPS_OUTPUTS     0x00004002L

typedef struct {
    DWORD   dwCallback;
    WORD    wDeviceID;       
    WORD    wReserved0;
    LPSTR   lpstrDeviceType; 
    LPSTR   lpstrElementName;
    LPSTR   lpstrAlias;      
    DWORD   dwBufferSeconds;
} MCI_WAVE_OPEN_PARMS;
typedef MCI_WAVE_OPEN_PARMS FAR *LPMCI_WAVE_OPEN_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwFrom;         
    DWORD   dwTo;           
} MCI_WAVE_CUT_PARMS;
typedef MCI_WAVE_CUT_PARMS FAR *LPMCI_WAVE_CUT_PARMS;


typedef struct {
    DWORD   dwCallback;
    DWORD   dwTimeFormat;
    DWORD   dwAudio;
    WORD    wInput;
    WORD    wReserved0;
    WORD    wOutput;
    WORD    wReserved1;
    WORD    wFormatTag;       
    WORD    wReserved2;
    WORD    nChannels;	      
    WORD    wReserved3;
    DWORD   nSamplesPerSec;   
    DWORD   nAvgBytesPerSec;  
    WORD    nBlockAlign;      
    WORD    wReserved4;
    WORD    wBitsPerSample;   
    WORD    wReserved5;
} MCI_WAVE_SET_PARMS;
typedef MCI_WAVE_SET_PARMS FAR * LPMCI_WAVE_SET_PARMS;

/*****************************************************************************

   Standard command parameters for CD audio drivers

*****************************************************************************/

// None

/*****************************************************************************

    Standard command parameters for Sequencer drivers

*****************************************************************************/

// string resource ID's for sequencers
// return ids for status division type

#define     MCI_SEQ_DIV_PPQN	        (0 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_24        (1 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_25        (2 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_30DROP    (3 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_30        (4 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_MAPPER_S            (5 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_FILE_S              (6 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_MIDI_S              (7 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_SMPTE_S             (8 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_FORMAT_SONGPTR_S    (9 + MCI_SEQ_OFFSET)

#define     MCI_SEQ_FORMAT_SONGPTR      0x4002
#define     MCI_SEQ_FILE    	        0x4003      
#define     MCI_SEQ_MIDI                0x4004
#define     MCI_SEQ_SMPTE	        0x4005    

#define     MCI_SEQ_NONE		65533
#define     MCI_SEQ_MAPPER 	        65535

#define MCI_SEQ_STATUS_TEMPO		0x00004002L
#define MCI_SEQ_STATUS_PORT		0x00004003L
#define MCI_SEQ_STATUS_SLAVE		0x00004007L
#define MCI_SEQ_STATUS_MASTER		0x00004008L
#define MCI_SEQ_STATUS_OFFSET		0x00004009L
#define MCI_SEQ_STATUS_DIVTYPE		0x0000400AL

#define MCI_SEQ_SET_TEMPO		0x00010000L
#define MCI_SEQ_SET_PORT		0x00020000L
#define MCI_SEQ_SET_SLAVE        	0x00040000L
#define MCI_SEQ_SET_MASTER        	0x00080000L
#define MCI_SEQ_SET_OFFSET		0x01000000L

typedef struct {
    DWORD   dwCallback;
    DWORD   dwTimeFormat;
    DWORD   dwAudio;
    DWORD   dwTempo;
    DWORD   dwPort;
    DWORD   dwSlave;
    DWORD   dwMaster;
    DWORD   dwOffset;
} MCI_SEQ_SET_PARMS;
typedef MCI_SEQ_SET_PARMS FAR * LPMCI_SEQ_SET_PARMS;

/*****************************************************************************

    Standard command parameters for animation

*****************************************************************************/


#define MCI_ANIM_OPEN_WS                0x00010000L  // MCI_OPEN 
#define MCI_ANIM_OPEN_PARENT            0x00020000L  
#define MCI_ANIM_OPEN_NOSTATIC          0x00040000L  

#define MCI_ANIM_PLAY_SPEED             0x00010000L  // MCI_PLAY 
#define MCI_ANIM_PLAY_REVERSE           0x00020000L  
#define MCI_ANIM_PLAY_FAST              0x00040000L  
#define MCI_ANIM_PLAY_SLOW              0x00080000L  
#define MCI_ANIM_PLAY_SCAN              0x00100000L  

#define MCI_ANIM_STEP_REVERSE           0x00010000L  // MCI_STEP
#define MCI_ANIM_STEP_FRAMES            0x00020000L

#define MCI_ANIM_STATUS_SPEED           0x00004001L  // MCI_STATUS 
#define MCI_ANIM_STATUS_FORWARD         0x00004002L
#define MCI_ANIM_STATUS_HWND            0x00004003L
#define MCI_ANIM_STATUS_HPAL            0x00004004L

#define MCI_ANIM_INFO_TEXT              0x00010000L  // MCI_INFO

#define MCI_ANIM_GETDEVCAPS_CAN_REVERSE 0x00004001L  // MCI_GETDEVCAPS
#define MCI_ANIM_GETDEVCAPS_FAST_RATE   0x00004002L
#define MCI_ANIM_GETDEVCAPS_SLOW_RATE   0x00004003L
#define MCI_ANIM_GETDEVCAPS_NORMAL_RATE 0x00004004L
#define MCI_ANIM_GETDEVCAPS_PALETTES    0x00004006L
#define MCI_ANIM_GETDEVCAPS_CAN_STRETCH 0x00004007L
#define MCI_ANIM_GETDEVCAPS_MAX_WINDOWS 0x00004008L

#define MCI_ANIM_REALIZE_NORM           0x00010000L  // MCI_REALIZE
#define MCI_ANIM_REALIZE_BKGD           0x00020000L

#define MCI_ANIM_WINDOW_HWND            0x00010000L  // MCI_WINDOW
#define MCI_ANIM_WINDOW_DEFAULT         0x00020000L
#define MCI_ANIM_WINDOW_STATE           0x00040000L
#define MCI_ANIM_WINDOW_TEXT            0x00080000L

#define MCI_ANIM_RECT                   0x00010000L  // MCI_SOURCE,MCI_DESTINATION, MCI_UPDATE

#define MCI_ANIM_PUT_SOURCE             0x00020000L  // MCI_PUT
#define MCI_ANIM_PUT_DESTINATION        0x00040000L 

#define MCI_ANIM_WHERE_SOURCE           0x00020000L  // MCI_WHERE
#define MCI_ANIM_WHERE_DESTINATION      0x00040000L 

#define MCI_ANIM_UPDATE_HDC             0x00020000L  // MCI_UPDATE

typedef struct {
    DWORD   dwCallback;
    WORD    wDeviceID;       
    WORD    wReserved0;
    LPSTR   lpstrDeviceType; 
    LPSTR   lpstrElementName;
    LPSTR   lpstrAlias;      
    DWORD   dwStyle;
    WORD    hWndParent;          
    WORD    wReserved1;
} MCI_ANIM_OPEN_PARMS;
typedef MCI_ANIM_OPEN_PARMS FAR *LPMCI_ANIM_OPEN_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwFrom;         
    DWORD   dwTo;           
    DWORD   dwSpeed;          
} MCI_ANIM_PLAY_PARMS;
typedef MCI_ANIM_PLAY_PARMS FAR *LPMCI_ANIM_PLAY_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwFrames;
} MCI_ANIM_STEP_PARMS;
typedef MCI_ANIM_STEP_PARMS FAR *LPMCI_ANIM_STEP_PARMS;

typedef struct {
    DWORD   dwCallback;
    DWORD   dwTimeFormat;
    DWORD   dwAudio;
} MCI_ANIM_SET_PARMS;
typedef MCI_ANIM_SET_PARMS FAR * LPMCI_ANIM_SET_PARMS;

typedef struct {
    DWORD   dwCallback;
    WORD    hWnd;          
    WORD    wReserved1;
    WORD    nCmdShow;          
    WORD    wReserved2;
    LPSTR   lpstrText;
} MCI_ANIM_WINDOW_PARMS;
typedef MCI_ANIM_WINDOW_PARMS FAR * LPMCI_ANIM_WINDOW_PARMS;

typedef struct {
    DWORD   dwCallback;
    RECT    rc;
} MCI_ANIM_RECT_PARMS;
typedef MCI_ANIM_RECT_PARMS FAR * LPMCI_ANIM_RECT_PARMS;

typedef struct {
    DWORD   dwCallback;
    RECT    rc;
    HDC     hDC;
} MCI_ANIM_UPDATE_PARMS;
typedef MCI_ANIM_UPDATE_PARMS FAR * LPMCI_ANIM_UPDATE_PARMS;


/*****************************************************************************

    Standard command parameters for overlay

*****************************************************************************/


#define MCI_OVLY_OPEN_WS                0x00010000L  // MCI_OPEN 
#define MCI_OVLY_OPEN_PARENT            0x00020000L  

#define MCI_OVLY_STATUS_HWND            0x00004001L

#define MCI_OVLY_INFO_TEXT              0x00010000L  // MCI_INFO

#define MCI_OVLY_GETDEVCAPS_CAN_STRETCH 0x00004001L
#define MCI_OVLY_GETDEVCAPS_CAN_FREEZE  0x00004002L
#define MCI_OVLY_GETDEVCAPS_MAX_WINDOWS 0x00004003L

#define MCI_OVLY_WINDOW_HWND            0x00010000L  // MCI_WINDOW
#define MCI_OVLY_WINDOW_DEFAULT         0x00020000L
#define MCI_OVLY_WINDOW_STATE           0x00040000L
#define MCI_OVLY_WINDOW_TEXT            0x00080000L

#define MCI_OVLY_RECT                   0x00010000L  // MCI_WHERE, MCI_UPDATE, MCI_FREEZE, MCI_UNFREEZE

#define MCI_OVLY_PUT_SOURCE             0x00020000L  // MCI_PUT
#define MCI_OVLY_PUT_DESTINATION        0x00040000L 
#define MCI_OVLY_PUT_FRAME              0x00080000L 

#define MCI_OVLY_WHERE_SOURCE           0x00020000L  // MCI_WHERE
#define MCI_OVLY_WHERE_DESTINATION      0x00040000L 
#define MCI_OVLY_WHERE_FRAME            0x00080000L 

#define MCI_OVLY_UPDATE_HDC             0x00020000L  // MCI_UPDATE

typedef struct {
    DWORD   dwCallback;
    WORD    wDeviceID;       
    WORD    wReserved0;
    LPSTR   lpstrDeviceType; 
    LPSTR   lpstrElementName;
    LPSTR   lpstrAlias;      
    DWORD   dwStyle;
    WORD    hWndParent;          
    WORD    wReserved1;
 } MCI_OVLY_OPEN_PARMS;
typedef MCI_OVLY_OPEN_PARMS FAR *LPMCI_OVLY_OPEN_PARMS;

typedef struct {
    DWORD   dwCallback;
    WORD    hWnd;          
    WORD    wReserved1;
    WORD    nCmdShow;          
    WORD    wReserved2;
    LPSTR   lpstrText;
} MCI_OVLY_WINDOW_PARMS;
typedef MCI_OVLY_WINDOW_PARMS FAR * LPMCI_OVLY_WINDOW_PARMS;

typedef struct {
    DWORD   dwCallback;
    RECT    rc;
} MCI_OVLY_RECT_PARMS;
typedef MCI_OVLY_RECT_PARMS FAR * LPMCI_OVLY_RECT_PARMS;

typedef struct {
    DWORD   dwCallback;
    RECT    rc;
    HDC     hDC;
} MCI_OVLY_UPDATE_PARMS;
typedef MCI_OVLY_UPDATE_PARMS FAR * LPMCI_OVLY_UPDATE_PARMS;

 
/*****************************************************************************

    MCI support functions

*****************************************************************************/


extern DWORD mciSendCommand (WORD wDeviceID, WORD wMessage,
                                       DWORD dwParam1, DWORD dwParam2);

extern DWORD mciSendString (LPSTR lpstrCommand,
                                  LPSTR lpstrReturnString,
                                  WORD wReturnLength,
                                  HANDLE hCallback);

extern WORD mciGetDeviceID (LPSTR lpstrName);

extern WORD mciGetDeviceIDFromElementID (DWORD dwElementID,
                                         LPSTR lpstrType);

extern WORD mciGetErrorString (DWORD wError, 
                               LPSTR lpstrBuffer,
                               WORD wLength);

extern BOOL mciExecute (LPSTR lpstrCommand);



#endif // _WINMM_
