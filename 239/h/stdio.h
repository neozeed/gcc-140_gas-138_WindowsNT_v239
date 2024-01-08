/***
*stdio.h - definitions/declarations for standard I/O routines
*
*	Copyright (c) 1985-1991, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This file defines the structures, values, macros, and functions
*	used by the level 2 I/O ("standard I/O") routines.
*	[ANSI/System V]
*
****/

#ifndef _INC_STDIO

#ifdef __cplusplus
extern "C" {
#endif


#if (_MSC_VER <= 600)
#define __cdecl _cdecl
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif

#ifndef _VA_LIST_DEFINED
typedef char * va_list;
#define _VA_LIST_DEFINED
#endif


/* buffered I/O macros */

#define BUFSIZ	512
#ifdef	_MT
#define _NFILE	40
#else
#define _NFILE	20
#endif
#define EOF	(-1)

#ifndef _FILE_DEFINED
struct _iobuf {
	char *_ptr;
	int   _cnt;
	char *_base;
	int   _flag;
	int   _file;
	int   _charbuf;
	int   _bufsiz;
	int   __tmpnum;
	};
typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif

/* P_tmpnam: Directory where temporary files may be created.
 * L_tmpnam size =  size of P_tmpdir
 *	+ 1 (in case P_tmpdir does not end in "\\")
 *	+ 6 (for the temp number string)
 *	+ 1 (for the null terminator)
 */

#define _P_tmpdir "\\"
#define L_tmpnam sizeof(_P_tmpdir)+8

#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0

#define FILENAME_MAX 63
#define FOPEN_MAX 20
#define _SYS_OPEN 20
#define TMP_MAX 32767


/* define NULL pointer value */

#ifndef NULL
#ifdef __cplusplus
#define NULL	0
#else
#define NULL	((void *)0)
#endif
#endif


/* declare _iob[] array */

#ifndef _STDIO_DEFINED
extern FILE _iob[];
#endif


/* define file position type */

#ifndef _FPOS_T_DEFINED
typedef long fpos_t;
#define _FPOS_T_DEFINED
#endif


#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])


#define _IOREAD 	0x0001
#define _IOWRT		0x0002

#define _IOFBF		0x0000
#define _IOLBF		0x0040
#define _IONBF		0x0004

#define _IOMYBUF	0x0008
#define _IOEOF		0x0010
#define _IOERR		0x0020
#define _IOSTRG 	0x0040
#define _IORW		0x0080


/* function prototypes */

#ifndef _STDIO_DEFINED
int _filbuf(FILE *);
int _flsbuf(int, FILE *);
FILE * _fsopen(const char *, const char *, int);
void clearerr(FILE *);
int fclose(FILE *);
int _fcloseall(void);
FILE * _fdopen(int, const char *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int _fgetchar(void);
int fgetpos(FILE *, fpos_t *);
char * fgets(char *, int, FILE *);
int _fileno(FILE *);
int _flushall(void);
FILE * fopen(const char *, const char *);
int fprintf(FILE *, const char *, ...);
int fputc(int, FILE *);
int _fputchar(int);
int fputs(const char *, FILE *);
size_t fread(void *, size_t, size_t, FILE *);
FILE * freopen(const char *, const char *, FILE *);
int fscanf(FILE *, const char *, ...);
int fsetpos(FILE *, const fpos_t *);
int fseek(FILE *, long, int);
long ftell(FILE *);
size_t fwrite(const void *, size_t, size_t, FILE *);
int getc(FILE *);
int getchar(void);
char * gets(char *);
int _getw(FILE *);
void perror(const char *);
int _pclose(FILE *);
FILE * _popen(const char *, const char *);
int printf(const char *, ...);
int putc(int, FILE *);
int putchar(int);
int puts(const char *);
int _putw(int, FILE *);
int remove(const char *);
int rename(const char *, const char *);
void rewind(FILE *);
int _rmtmp(void);
int scanf(const char *, ...);
void setbuf(FILE *, char *);
int setvbuf(FILE *, char *, int, size_t);
int _snprintf(char *, size_t, const char *, ...);
int sprintf(char *, const char *, ...);
int sscanf(const char *, const char *, ...);
char * _tempnam(char *, char *);
FILE * tmpfile(void);
char * tmpnam(char *);
int ungetc(int, FILE *);
int _unlink(const char *);
int vfprintf(FILE *, const char *, va_list);
int vprintf(const char *, va_list);
int _vsnprintf(char *, size_t, const char *, va_list);
int vsprintf(char *, const char *, va_list);
#define _STDIO_DEFINED
#endif


/* macro definitions */

#define feof(_stream)	  ((_stream)->_flag & _IOEOF)
#define ferror(_stream)   ((_stream)->_flag & _IOERR)
#define _fileno(_stream)  ((_stream)->_file)
#define getc(_stream)	  (--(_stream)->_cnt >= 0 ? 0xff & *(_stream)->_ptr++ \
	: _filbuf(_stream))
#define putc(_c,_stream)  (--(_stream)->_cnt >= 0 \
	? 0xff & (*(_stream)->_ptr++ = (char)(_c)) :  _flsbuf((_c),(_stream)))
#define getchar()	  getc(stdin)
#define putchar(_c)	  putc((_c),stdout)

#ifdef _MT
#undef	getc
#undef	putc
#undef	getchar
#undef	putchar
#endif

#if !__STDC__
/* Non-ANSI names for compatibility */

#define P_tmpdir  _P_tmpdir
#define SYS_OPEN  _SYS_OPEN

#define fcloseall _fcloseall
#define fdopen	  _fdopen
#define fgetchar  _fgetchar
#define fileno	  _fileno
#define flushall  _flushall
#define fputchar  _fputchar
#define getw	  _getw
#define putw	  _putw
#define rmtmp	  _rmtmp
#define tempnam   _tempnam
#define unlink	  _unlink

#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#define _INC_STDIO
#endif	/* _INC_STDIO */
