CC = cl386

OBJS = _eprintf.obj _builtin_new.obj _builtin_New2.obj _builtin_del.obj\
	_umulsi3.obj _mulsi3.obj _udivsi3.obj _divsi3.obj _umodsi3.obj _modsi3.obj\
	_lshrsi3.obj _lshlsi3.obj _ashrsi3.obj _ashlsi3.obj\
	_divdf3.obj _muldf3.obj _negdf2.obj _adddf3.obj _subdf3.obj _cmpdf2.obj\
	_fixunsdfsi.obj _fixdfsi.obj _floatsidf.obj _truncdfsf2.obj _extendsfdf2.obj\
	_addsf3.obj _negsf2.obj _subsf3.obj _cmpsf2.obj _mulsf3.obj _divsf3.obj


# .c.obj:
# %.obj: %.c




gnulib.lib: $(OBJS)
	move _*.obj gnulib
	lib /out:gnulib.lib gnulib\*.obj


_eprintf.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c
	ren gnulib.obj $*.obj
_builtin_new.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_builtin_New2.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_builtin_del.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_umulsi3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_mulsi3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_udivsi3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_divsi3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_umodsi3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_modsi3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_lshrsi3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_lshlsi3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_ashrsi3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_ashlsi3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_divdf3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_muldf3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_negdf2.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_adddf3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_subdf3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_cmpdf2.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_fixunsdfsi.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_fixdfsi.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_floatsidf.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_truncdfsf2.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_extendsfdf2.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_addsf3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_negsf2.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_subsf3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_cmpsf2.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_mulsf3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj
_divsf3.obj:
	$(CC) /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
	ren gnulib.obj $*.obj





