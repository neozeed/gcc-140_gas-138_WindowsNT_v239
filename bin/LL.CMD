@cls
xgcc -B. -v -c hi.c -o hi.obj
link -debug:full -subsystem:console -entry:mainCRTStartup -out:hi.exe hi.obj C:\nt\mstools\lib\base.lib C:\nt\mstools\lib\console.lib C:\nt\mstools\lib\ntdll.lib	  C:\nt\mstools\lib\libcmt.lib
