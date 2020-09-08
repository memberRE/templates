#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
const int MAX = 1e6 + 10;
int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while ((c > '9' || c < '0') && c != '-')
        c = getchar();
    if (c == '-')
        flag = 0, c = getchar();
    while (c <= '9' && c >= '0')
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return flag ? x : -x;
}
int n, ans;
char s[MAX];
vector<int> temm[MAX];
int p[MAX], maxx[MAX],dp[2][MAX];
inline int find(int x)
{   
    return p[x] == x ? x : p[x] = find(p[x]);
}
int main()
{
    n = read();
    scanf("%s", s + 1);
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == '?')
        {
            dp[0][i] = dp[0][i + 1] + 1;
            dp[1][i] = dp[1][i + 1] + 1;
        }
        if (s[i] == '1')
        {
            dp[0][i] = 0;
            dp[1][i] = dp[1][i + 1] + 1;
        }
        if (s[i] == '0')
        {
            dp[0][i] = dp[0][i + 1] + 1;
            dp[1][i] = 0;
        }
        maxx[i] = max(dp[0][i], dp[1][i]);
        temm[maxx[i]].push_back(i);
    }
    for (int i = 1; i <= n + 1; i++)
        p[i] = i;
    for (int i = 1, pos; i <= n; i++)
    {
        ans = 0;
        pos = 1;
        while (pos <= n)
        {
            pos = find(pos);
            if (pos > n)
                break;
            ans++;
            pos += i;
        }
        printf("%d ", ans);
        for (auto id : temm[i])
            p[id] = id + 1;
    }
    return 0;
}