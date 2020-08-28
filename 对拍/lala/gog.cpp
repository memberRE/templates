#include<iostream>
#include<cstdio>
#include<windows.h>
using namespace std;
int main()
{
    int cnt=0;
	if(system("fc my.out std.out"))
        {
            system("pause");
            //break;
        }
//    while(cnt<=100)
//    {
//        cnt++;
//        system("start rand.exe");
//        Sleep(200);
//        system("start std.exe");
//        Sleep(200);
//        system("start my.exe");
//        Sleep(200);
//        
//        }
//    }
}
