#include<iostream>
#include <cstdio>
#include <algorithm>
#include<cstring>
using namespace std;
const int MAX = 1e5 + 200;
char S[MAX], T[MAX];
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}
int main()
{
    while(scanf("%s",S)!=EOF)
    {
        scanf("%s", T);
        int lenS = strlen(S);
        int lenT = strlen(T);
        long long tem = ((long long)lenS * (long long)lenT) / (long long)gcd(lenS, lenT);
        int ans = 0;
        for (int i = 0; i < 2*max(lenS,lenT);i++)
        {
            if(S[i%lenS] > T[i%lenT])
            {
                ans = 1;
                break;
            }
            else if(S[i%lenS] < T[i%lenT])
            {
                ans = -1;
                break;
            }
        }
        /*for (int i = 0; i < tem;i++)
        {
            if(S[i%lenS] > T[i%lenT])
            {
                ans = 1;
                break;
            }
            else if(S[i%lenS] < T[i%lenT])
            {
                ans = -1;
                break;
            }
        }*/
        if (ans == -1)
            cout << '<' << endl;
        if(ans == 0)
            cout << "=" << endl;
        if(ans == 1)
            cout << ">" << endl;
    }
    return 0;
}
