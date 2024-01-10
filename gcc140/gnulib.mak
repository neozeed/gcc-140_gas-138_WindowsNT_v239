OBJS = _eprintf.obj _builtin_new.obj _builtin_New2.obj _builtin_del.obj\
	_umulsi3.obj _mulsi3.obj _udivsi3.obj _divsi3.obj _umodsi3.obj _modsi3.obj\
	_lshrsi3.obj _lshlsi3.obj _ashrsi3.obj _ashlsi3.obj\
	_divdf3.obj _muldf3.obj _negdf2.obj _adddf3.obj _subdf3.obj _cmpdf2.obj\
	_fixunsdfsi.obj _fixdfsi.obj _floatsidf.obj _truncdfsf2.obj _extendsfdf2.obj\
	_addsf3.obj _negsf2.obj _subsf3.obj _cmpsf2.obj _mulsf3.obj _divsf3.obj


# .c.obj:
# %.obj: %.c




gnulib.lib: $(OBJS)
	lib /out:gnulib.lib gnulib\*.obj


_eprintf.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_builtin_new.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj 
_builtin_New2.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_builtin_del.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_umulsi3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_mulsi3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj 
_udivsi3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_divsi3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_umodsi3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_modsi3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_lshrsi3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_lshlsi3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_ashrsi3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj 
_ashlsi3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_divdf3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_muldf3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_negdf2.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_adddf3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_subdf3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_cmpdf2.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_fixunsdfsi.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_fixdfsi.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_floatsidf.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_truncdfsf2.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_extendsfdf2.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_addsf3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_negsf2.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_subsf3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_cmpsf2.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_mulsf3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj
_divsf3.obj:
	cl /Iconfig /DL$* /c gnulib.c /Fognulib\$*.obj
#	lib /out:gnulib.lib gnulib\$*.obj





