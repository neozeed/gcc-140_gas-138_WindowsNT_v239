# 1 "hi.c"
 
# 1 "/xenixnt/h/stdio.h" 1
 























typedef unsigned int size_t;




typedef char * va_list;




 










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



 



















 










 


extern FILE _iob[];



 


typedef long fpos_t;























 


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




 


















# 228 "/xenixnt/h/stdio.h"








# 2 "hi.c" 2


void main()
{
printf("hi!\n");
}
