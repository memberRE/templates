#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 2e5 + 10;
char s[MAX], t[MAX],buff[MAX];
int pic[MAX];
int ls, lt;
bool check()
{
    int j = 0;
    for (int i = 0; i < ls;i++)
    {
        if(buff[i] == t[j])
            j++;
        if(j==lt)
            return true;
    }
    return false;
}
int main()
{
    scanf("%s", s);
    scanf("%s", t);
    ls = strlen(s);
    lt = strlen(t);
    for (int i = 1; i <= ls;i++)
    {
        scanf("%d", &pic[i]);
        buff[i - 1] = s[i - 1];
    }
        
    int l = 0, r = ls;  // l is dele
    int lsmid = 0;
    while(l<r)
    {
        int mid = (l + r) >> 1;
        if(mid*2 < l+r )
        	mid +=1;
        if (mid<lsmid) 
        {
            for (int i = lsmid; i >= mid;i--)
            {
                if(i==0)
                    continue;
                buff[pic[i] - 1] = s[pic[i] - 1];
            }
        }
        else 
        {
            for (int i = lsmid; i < mid;i++)
            {
                if(i==0)
                    continue;
                buff[pic[i] - 1] = 0;
            }
        }
        lsmid = mid;
        if(check())
        {
            l = mid;
        }
        else
        {
            r = mid-1;
        }
    }
    cout << l-1;
}
/*
riolu
riolu
2 1 4 3 5
*/
