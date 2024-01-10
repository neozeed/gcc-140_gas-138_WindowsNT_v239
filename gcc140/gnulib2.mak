OBJS = _adddi3.obj _subdi3.obj _muldi3.obj _divdi3.obj _moddi3.obj _udivdi3.obj _umoddi3.obj _negdi2.obj \
    _anddi3.obj _iordi3.obj _xordi3.obj _lshrdi3.obj _lshldi3.obj _ashldi3.obj _ashrdi3.obj _one_cmpldi2.obj  \
    _bdiv.obj _cmpdi2.obj _ucmpdi2.obj _fixunsdfdi.obj _fixdfdi.obj _floatdidf.obj _varargs.obj



# .c.obj:
# %.obj: %.c



CPPFLAGS = /Iconfig

gnulib2.lib: $(OBJS)
	move _*.obj gnulib2
	lib /out:gnulib2.lib gnulib2\*.obj


_adddi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s

_subdi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_muldi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_divdi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_moddi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_udivdi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_umoddi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_negdi2.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_anddi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_iordi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_xordi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_lshrdi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_lshldi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_ashldi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_ashrdi3.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_one_cmpldi2.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_bdiv.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_cmpdi2.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_ucmpdi2.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_fixunsdfdi.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_fixdfdi.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_floatdidf.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s
_varargs.obj:
	CL386 /E /u -D__GNUC__ -Di386 -DL$* $(CPPFLAGS) gnulib2.c > $*.i
	cc1 -version -quiet -o $*.s $*.i
	ax386 -version -o $*.obj $*.s

