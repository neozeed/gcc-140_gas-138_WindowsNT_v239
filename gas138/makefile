# Nmake macros for building Windows 32-Bit apps
CPU=i386
!include <ntwin32.mak>
#
CC = cl386
#CC = cl
#INCLUDE =  /xenixnt/h
#INCLUDE = /MSVC32S/C386/INCLUDE
INCLUDE = /MSVC32S/INCLUDE
#INCLUDE = /nt/mstools/h

# old 1991 NT's have something missing in ctype.h I never did find it
# I side stepped it  use  /DUSEBROKENCTYPE if needed
CTYPE = # /DUSEBROKENCTYPE
#CC = cl
CFLAGS = /I. /I$(INCLUDE) /DUSG /DWORKING_DOT_WORD $(CTYPE)
#CFLAGS = /DUSG /DWORKING_DOT_WORD

OBJS = app.obj append.obj as.obj atof-gen.obj atof-iee.obj bignum-c.obj expr.obj \
flonumct.obj flonumcp.obj flonumul.obj frags.obj hash.obj hex-val.obj i386.obj \
input-fl.obj input-sc.obj messages.obj obstack.obj _omf8.OBJ output-f.obj read.obj \
subsegs.obj symbols.obj version.obj write.obj xenixomf.obj xmalloc.obj xrealloc.obj \
alloca.obj 


ax386.exe: $(OBJS)
	$(link) $(conflags) -out:ax386.exe $(OBJS) $(conlibs)


clean:
	-del /F $(OBJS)