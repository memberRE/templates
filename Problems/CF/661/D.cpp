#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long  ll;
const int MAX = 2e5 + 20;
char S[MAX];
int n, ans[MAX],num;
int stk_0[MAX], stk_1[MAX], top_0, top_1;
inline void init()
{
    num = 0;
    top_0 = top_1 = 0;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        init();
        cin >> n;
        scanf("%s", S);
        for (int i = 0; S[i];i++)
        {
            if (S[i] == '0')
            {
                if (top_1 == 0)
                {
                    num++;
                    ans[i] = num;
                    stk_0[top_0++] = num;
                }
                else
                {
                    ans[i] = stk_1[top_1 - 1];
                    stk_0[top_0++] = ans[i];
                    top_1--;
                }
            }
            else
            {
                if (top_0 == 0)
                {
                    num++;
                    ans[i] = num;
                    stk_1[top_1++] = num;
                }
                else
                {
                    ans[i] = stk_0[top_0 - 1];
                    stk_1[top_1++] = ans[i];
                    top_0--;
                }
            }
        }
        printf("%d\n", num);
        for (int i = 1; i <= n;i++)
            printf("%d ", ans[i - 1]);
        putchar('\n');
    }
    return 0;
}