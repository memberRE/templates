#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
const int MAX = 2e5 + 20;
vector<int> pic[MAX];
int colo[MAX], tot_cal;
int n, m;
int p[MAX],val[MAX];
map<int,int> temm;
int findd(int x)
{
    return p[x] == x ? x : p[x] = findd(p[x]);
}
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
// void dfs(int u)
// {
//     if (tot_cal == 4)
//         return;
//     int tem[5] = {0, 0, 0, 0, 0};
//     for (auto v : pic[u])
//         tem[colo[v]]++;
//     for (int i = 1; i <= 4; i++)
//     {
//         if (tem[i] == 0)
//         {
//             colo[u] = i;
//             tot_cal = max(i, tot_cal);
//             break;
//         }
//     }
//     if (colo[u] == 0)
//         return;
//     for (auto v : pic[u])
//     {
//         if (colo[v] == 0)
//             dfs(v);
//     }
// }
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
        p[i] = i,val[i] = 1;
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read();
        int xx = findd(x);
        int yy = findd(y);
        if (xx == yy)
            continue;
        p[xx] = yy;
        val[yy] += val[xx];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, val[i]);
    cout << ans << endl;
    return 0;
}