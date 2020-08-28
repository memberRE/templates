#include<iostream>
#include<cstdio>
#include<windows.h>
using namespace std;
int main()
{
    int cnt=0;
    while(cnt<=100)
    {
        cnt++;
        system("start rand.exe>data.in");
        Sleep(200);
        system("start std.exe<data.in>std.out");
        Sleep(200);
        system("start my.exe<data.in>my.out");
        Sleep(200);
        if(system("fc my.out std.out"))
        {
            system("pause");
            break;
        }
    }
}
