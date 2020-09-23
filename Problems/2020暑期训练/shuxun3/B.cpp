#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
const int MAX = 1e3;
int stk[2][MAX], topp[2];
char s[MAX];
int ans;
int main()
{
    scanf("%s", s);
    scanf("%d", &ans);
    stk[0][topp[0]++] = s[0] - '0';
    stk[1][topp[1]++] = s[0] - '0';
    for (int i = 1; s[i];i+=2)
    {
        if(s[i] == '+')
        {
            stk[0][topp[0] - 1] += s[i+1] - '0';
            stk[1][topp[1]++] = s[i+1] - '0';
        }
        else
        {
            stk[0][topp[0] - 1] *= s[i+1] - '0';
            stk[1][topp[1] - 1] *= s[i + 1] - '0';
        }
    }
    int ans2 = 0,ans1 = stk[0][0];
    for (int i = 0; i < topp[1];i++)
        ans2 += stk[1][i];
    if (ans2 == ans1 and ans == ans1)
    {
        puts("U");
    }
    else if (ans1 != ans and ans2 != ans)
        puts("I");
    else if (ans == ans1)
    {
        puts("L");
    }
    else
    {
        puts("M");
    }
    return 0;
}
