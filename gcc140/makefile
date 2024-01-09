# Nmake macros for building Windows 32-Bit apps
CPU=i386
!include <ntwin32.mak>
#
#CFLAGS= /Ic:\xenixnt\h /I. /Iconfig
#CFLAGS= /Ic:\msvc32s\include /I. /Iconfig
CFLAGS= /I. /Iconfig

#CC = cl /Od
CC = cl386 /u /Od

CC1OBJ = c-tab.obj c-decl.obj c-typeck.obj c-conv.obj toplev.obj version.obj \
	tree.obj pr-tree.obj stor-lay.obj fold-con.obj rtl.obj rtlanal.obj \
	expr.obj stmt.obj expmed.obj explow.obj optabs.obj varasm.obj symout.obj \
	dbxout.obj sdbout.obj emit-rtl.obj intgrate.obj jump.obj cse.obj \
	loop.obj flow.obj stupid.obj combine.obj regclass.obj localall.obj glblallc.obj \
	reload.obj reload1.obj callersv.obj final.obj recog.obj pragma.obj \
	errno.obj

CC1INSNOBJ = insn-emt.obj insn-xrt.obj insn-out.obj insn-pep.obj insn-rcg.obj \
	obstack.obj

CC1DEPS: insn-flg.h insn-cod.h insn-cnf.h insn-emt.c insn-pep.c insn-rcg.c \
	insn-xrt.c insn-out.c insn-out.obj

CCCPOBJ = cccp.obj cexp.obj version.obj obstack.obj alloca.obj

default: cc1.exe

cc1: cc1.exe

cc1.exe: $(CC1DEPS) $(CC1OBJ) $(CC1INSNOBJ) insn-flg.h insn-cnf.h
	cvtomf -g symout.obj
	$(link) $(conflags) -out:cc1.exe $(CC1OBJ) $(CC1INSNOBJ) alloca.obj $(conlibs)

cccp.exe: $(CCCPOBJ)
	cvtomf -g cccp.obj 
	cvtomf -g cexp.obj 
	cvtomf -g version.obj 
	cvtomf -g obstack.obj 
	cvtomf -g alloca.obj
	$(link) $(conflags) -out:cccp.exe $(CCCPOBJ) $(conlibs)

cc1x.exe: $(CC1DEPS) $(CC1OBJ) $(CC1INSNOBJ) insn-flg.h insn-cnf.h
	link /NODEFAULTLIB:libc.lib /NODEFAULTLIB:OLDNAMES.LIB  -out:cc1.exe $(CC1OBJ) $(CC1INSNOBJ) alloca.obj $(conlibs)


genflags.exe: c-tab.obj c-decl.obj c-typeck.obj c-conv.obj toplev.obj \
	version.obj tree.obj pr-tree.obj stor-lay.obj fold-con.obj \
	rtl.obj rtlanal.obj genflags.obj obstack.obj \
	genflags.obj rtl.obj obstack.obj alloca.obj
	cvtomf -g c-tab.obj
	cvtomf -g c-decl.obj
	cvtomf -g c-typeck.obj 
	cvtomf -g c-conv.obj
	cvtomf -g toplev.obj
	cvtomf -g version.obj 
	cvtomf -g tree.obj 
	cvtomf -g pr-tree.obj 
	cvtomf -g stor-lay.obj 
	cvtomf -g fold-con.obj
	cvtomf -g rtl.obj 
	cvtomf -g rtlanal.obj 
	cvtomf -g genflags.obj 
	cvtomf -g obstack.obj
	cvtomf -g genflags.obj 
	cvtomf -g rtl.obj 
	cvtomf -g obstack.obj 
	cvtomf -g alloca.obj
	$(link) $(conflags) -out:genflags.exe genflags.obj rtl.obj obstack.obj alloca.obj $(conlibs)

%.obj: %.c
	cl386 $(CFLAGS) /c $<
	cvtomf -g $*.obj

gencodes.exe: gencodes.obj rtl.obj obstack.obj alloca.obj
	cvtomf -g gencodes.obj
	cvtomf -g rtl.obj
	cvtomf -g obstack.obj
	cvtomf -g alloca.obj
	$(link) $(conflags) -out:gencodes.exe gencodes.obj rtl.obj obstack.obj alloca.obj $(conlibs)

genconf.exe: genconf.obj rtl.obj obstack.obj alloca.obj
	cvtomf -g genconf.obj
	cvtomf -g rtl.obj
	cvtomf -g obstack.obj
	cvtomf -g alloca.obj
	$(link) $(conflags) -out:genconf.exe genconf.obj rtl.obj obstack.obj alloca.obj $(conlibs)


genemit.exe: expr.obj stmt.obj expmed.obj explow.obj optabs.obj varasm.obj \
	symout.obj dbxout.obj sdbout.obj emit-rtl.obj genemit.obj \
	insn-cnf.h insn-flg.h
	cvtomf -g expr.obj
	cvtomf -g stmt.obj
	cvtomf -g expmed.obj
	cvtomf -g explow.obj
	cvtomf -g optabs.obj
	cvtomf -g varasm.obj
	cvtomf -g symout.obj
	cvtomf -g dbxout.obj
	cvtomf -g sdbout.obj
	cvtomf -g emit-rtl.obj
	cvtomf -g genemit.obj
	$(link) $(conflags) -out:genemit.exe genemit.obj rtl.obj obstack.obj alloca.obj $(conlibs)

genpep.exe: insn-emt.obj intgrate.obj jump.obj cse.obj loop.obj \
	flow.obj stupid.obj combine.obj regclass.obj localall.obj \
	glblallc.obj reload.obj reload1.obj callersv.obj genpep.obj \
	rtl.obj obstack.obj alloca.obj
	cvtomf -g insn-emt.obj
	cvtomf -g intgrate.obj 
	cvtomf -g jump.obj 
	cvtomf -g cse.obj 
	cvtomf -g loop.obj 
	cvtomf -g flow.obj 
	cvtomf -g stupid.obj 
	cvtomf -g combine.obj 
	cvtomf -g regclass.obj 
	cvtomf -g localall.obj
	cvtomf -g glblallc.obj 
	cvtomf -g reload.obj 
	cvtomf -g reload1.obj 
	cvtomf -g callersv.obj 
	cvtomf -g genpep.obj
	cvtomf -g rtl.obj 
	cvtomf -g obstack.obj 
	cvtomf -g alloca.obj
	cvtomf -g genpep.obj
	$(link) $(conflags) -out:genpep.exe genpep.obj rtl.obj obstack.obj alloca.obj $(conlibs)

genrecog.exe: insn-pep.obj final.obj recog.obj genrecog.obj alloca.obj
	cvtomf -g insn-pep.obj
	cvtomf -g final.obj
	cvtomf -g recog.obj 
	cvtomf -g genrecog.obj 
	cvtomf -g alloca.obj
	$(link) $(conflags) -out:genrecog.exe genrecog.obj rtl.obj obstack.obj alloca.obj $(conlibs)

genxtrt.exe: insn-rcg.obj genxtrt.obj alloca.obj
	cvtomf -g insn-rcg.obj 
	cvtomf -g genxtrt.obj 
	cvtomf -g alloca.obj
	$(link) $(conflags) -out:genxtrt.exe genxtrt.obj rtl.obj obstack.obj alloca.obj $(conlibs)

genoutpt.exe: insn-xrt.obj genoutpt.obj genoutpt.obj rtl.obj obstack.obj alloca.obj
	cvtomf -g insn-xrt.obj 
	cvtomf -g genoutpt.obj 
	cvtomf -g genoutpt.obj 
	cvtomf -g rtl.obj 
	cvtomf -g obstack.obj 
	cvtomf -g alloca.obj
	$(link) $(conflags) -out:genoutpt.exe genoutpt.obj rtl.obj obstack.obj alloca.obj $(conlibs)

expr.obj: insn-flg.h insn-cnf.h insn-cod.h

insn-out.c: genoutpt.exe
	genoutpt.exe md > insn-out.c

insn-xrt.c: genxtrt.exe
	genxtrt md > insn-xrt.c

insn-rcg.c: genrecog.exe
	genrecog md > insn-rcg.c

insn-flg.h: genflags.exe
	genflags md > insn-flg.h

insn-cod.h: gencodes.exe
	gencodes md > insn-cod.h

insn-cnf.h: genconf.exe
	genconf md > insn-cnf.h

insn-emt.c: genemit.exe
	genemit md > insn-emt.c

insn-pep.c: genpep.exe
	genpep md > insn-pep.c


insn-out.obj: insn-out.c
	cl386 /u /D__STDC__ /I. /Iconfig /c insn-out.c

c-tab.c: c-parse.y
	copy /Y c-tab.k c-tab.c
#	..\bin\bison -v ./c-parse.y -o c-tab.c

clean:
	del /F *.obj
	del /F *.exe
	del /F insn-*
	del /F stamp-*
	del /F c-parse.output c-tab.c
