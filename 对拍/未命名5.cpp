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
       // system("start sjmaker.exe");
        //Sleep(200);
        system("start baoli.exe");
        system("start zhengjie.exe");
        Sleep(500);
        if(system("fc baoli.out zhengjie.out"))
        {
            system("pause");
            break;
        }
        system("pause");
    }
}
