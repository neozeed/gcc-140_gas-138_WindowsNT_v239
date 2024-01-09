

SYSTEM=c:\msvc32s\c386\include
CC = cl386 /I$(SYSTEM)


# CFLAGS = /DUSG /DXPFILE=\"BISON.SIM\" /DXPFILE1=\"BISON.HAR\" /DMSDOS=1 /D__STDC__
# CFLAGS = /DUSG /DMSDOS /D__STDC__

CFLAGS = /DUSG /DMSDOS

OBJS = allocate.obj bcopy.obj closure.obj conflct.obj derives.obj files.obj getargs.obj getopt.obj \
	getopt1.obj gram.obj lalr.obj lex.obj LR0.obj main.obj nullable.obj output.obj \
	print.obj reader.obj reduce.obj symtab.obj version.obj warshall.obj alloca.obj


bison.exe: $(OBJS)
	link -out:bison.exe $(OBJS) libc.lib oldnames.lib

clean:
	-del /F $(OBJS)