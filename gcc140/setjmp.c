//#include <setjmp.h>
typedef  int  jmp_buf[8];
int setjmp(jmp_buf xx)
	{
	return (_setjmp(xx));
}
