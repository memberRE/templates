#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
typedef unsigned long long  ull;
using namespace std;
const int MOD=19260817,base=131;
struct ppp{
    int L_A, R_A, L_B, R_B;
}pic[8192];
char s[4096][300];
int dp[4002][4002];
int dir[4002][4002];
ull A[4096], B[4096];
ull tarA[4096], tarB[4096];
int n = 0, totA = 0, totB = 0,totpic = 0;
ull bkdrhash(char S[])
{
	ull hash=0;
	for(int i=0;S[i];i++)
		hash=hash*base+S[i];
	return hash;
}
void check_merge()
{
    for (int i = 1; i <= totA;i++)
        dp[i][0] = 0;
    for (int i = 1; i <= totB;i++)
        dp[0][i] = 0;
    for (int i = 1; i <= totA;i++)
        for (int j = 1; j <= totB;j++)
        {
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1,dir[i][j] = 1;
            else if (dp[i-1][j] >= dp[i][j-1])
                dp[i][j] = dp[i - 1][j], dir[i][j] = 2;
            else
                dp[i][j] = dp[i][j - 1], dir[i][j] = 3;
        }
    int i = totA, j = totB;
    while(i>0 && j >0)
    {
        if (dir[i][j] == 2)
            i--;
        else if (dir[i][j] == 3)
            j--;
        else
        {
            tarA[i] = 1;
            tarB[i] = 1;
            i--;
            j--;
        }
    }
    i = 0, j = 0;
    int flag = -1;
    for (; i <= totA;i++)
    {
        if (tarA[i] == 1)
            continue;
        
    }
    for (int i = 1; i <= totA; i++)
        tarA[i] = 0;
    for (int j = 1; j <= totB;j++)
        tarB[j] = 0;
}
int main()
{
    
    int begin_flag = 0;
    while (scanf("%s", s[n++]) != EOF)
    {
        if (strcmp(s[n-1],"<<<<<<< branch1") == 0)
            begin_flag = 1;
        else if (strcmp(s[n-1],"=======") == 0)
            begin_flag = 2;
        else if (strcmp(s[n-1], ">>>>>>> branch2") == 0)
        {
            begin_flag = 0;
            check_merge();
            totA = totB = 0;
        }
        else
        {
            if (begin_flag == 0)
                continue;
            ull tem = bkdrhash(s[n - 1]);
            if (begin_flag == 1)
                A[++totA] = tem;
            if (begin_flag == 2)
                B[++totB] = tem;
        }
    }
    int j = 0;
    for (int i = 0; i < n;i++)
    {
        if(i < pic[j].L_A and i < pic[j].L_B)
            puts(s[i]);
        else 
        
    }
}