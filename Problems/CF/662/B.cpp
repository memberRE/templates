#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include<map>
#include <stdio.h>
using namespace std;
const int MAX = 1e5 + 200;
int num[MAX];
map <int,int> pic2;
map<int, int> pic4;
int main()
{
    int n,m;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        int tem;
        scanf("%d", &tem);
        num[tem]++;
    }
    for (int i = 1; i <= n;i++)
    {
        if (num[i] >= 4)
            pic4[i] = num[i];
        else if (num[i] >= 2)
            pic2[i] = num[i];
    }
    cin >> m;
    for (int i = 1; i <= m;i++)
    {
        char S[5];
        int tem = 0;
        scanf("%s%d", S, &tem);
        if (S[0] == '+')
        {
            num[tem]++;
            if (num[tem] == 4)
                pic2.erase(tem),pic4[tem] = num[tem];
            else if (num[tem] == 2)
                pic2[tem] = num[tem];
            else if (pic4.count(tem))
                pic4[tem] = num[tem];
            else if (pic2.count(tem))
                pic2[tem] = num[tem];
        }
        else
        {
            num[tem]--;
            if (num[tem] == 3)
                pic4.erase(tem),pic2[tem] = num[tem];
            else if (num[tem] == 1)
                pic2.erase(tem);
            else if (pic4.count(tem))
                pic4[tem] = num[tem];
            else if (pic2.count(tem))
                pic2[tem] = num[tem];
        }
        if (pic4.size() == 0)
                puts("NO");
        else if (pic2.size() >= 2)
        {
            puts("YES");   
        }
        else if (pic2.size() == 1)
        {
            map<int, int>::iterator it;
            int flag = 0;
            for (it = pic4.begin(); it != pic4.end();it++)
            {
                if (it->second >=6)
                {
                    puts("YES");
                    flag = 114;
                    break;
                }
                else if (flag == 1)
                {
                    puts("YES");
                    flag = 114;
                    break;
                }
                else
                    flag = 1;
            }
            if (flag != 114)
                puts("NO");
        }
        else
        {
            map<int, int>::iterator it;
            int flag4 = 0,flag2 = 0;
            for (it = pic4.begin(); it != pic4.end();it++)
            {
                if (it->second >= 8)
                {
                    puts("YES");
                    flag2 = 114;
                    break;
                }
                if (flag4 == 0)
                {
                    flag4 = 1;
                    if (it->second >= 6)
                        flag2++;
                    continue;
                }
                else
                {
                    puts("YES");
                    flag2 = 114;
                    break;
                }
            }
            if (flag2 != 114)
                puts("NO");
        }
    }
    return 0;
}
