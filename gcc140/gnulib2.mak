OBJS = _adddi3.obj _subdi3.obj _muldi3.obj _divdi3.obj _moddi3.obj _udivdi3.obj _umoddi3.obj _negdi2.obj \
    _anddi3.obj _iordi3.obj _xordi3.obj _lshrdi3.obj _lshldi3.obj _ashldi3.obj _ashrdi3.obj _one_cmpldi2.obj  \
    _bdiv.obj _cmpdi2.obj _ucmpdi2.obj _fixunsdfdi.obj _fixdfdi.obj _floatdidf.obj _varargs.obj



# .c.obj:
# %.obj: %.c




gnulib2.lib: $(OBJS)
	lib /out:gnulib2.lib gnulib2\*.obj


_adddi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_subdi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_muldi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_divdi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_moddi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_udivdi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_umoddi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_negdi2.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_anddi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_iordi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_xordi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_lshrdi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_lshldi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_ashldi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_ashrdi3.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_one_cmpldi2.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_bdiv.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_cmpdi2.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_ucmpdi2.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_fixunsdfdi.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_fixdfdi.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_floatdidf.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj
_varargs.obj:
	xgcc -B. -Iconfig -DL$* -c gnulib2.c -ognulib2/$*.obj

