@echo off
echo Cleaning...
del main.gb

echo Compiling...
D:\Software\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o main.o main.c
D:\Software\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o main.gb main.o

del main.lst
del main.map
del main.o
del main.sym

echo Running...
D:\Software\gbdk\bgb.exe main.gb