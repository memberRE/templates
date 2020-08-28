@echo off  
:loop  
    rand.exe>data.in  
    std.exe<data.in>std.out
    my.exe<data.in>my.out  
    std.out
    my.out
goto loop