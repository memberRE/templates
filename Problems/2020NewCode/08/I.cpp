#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1e5 + 20;
int A[MAX], B[MAX];
int pic_discret[MAX << 1], ufs[MAX << 1],edge_num[MAX << 1],uni[MAX << 1],uni_node[MAX << 1];
int n, N;
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
void discrete(int tem[], int lenth)
{
    sort(tem + 1, tem + 1 + lenth * 2);
    N = unique(tem + 1, tem + 1 + lenth * 2) - tem - 1;
}
void init()
{
    N = 0;
    for (int i = 1; i <= n*2; i++)
        ufs[i] = i, edge_num[i] = 0, uni[i] = -1, uni_node[i] = 0;
}
int find(int x)
{
    return ufs[x] == x ? x : ufs[x] = find(ufs[x]);
}
int main()
{
    int t, T;
    cin >> t;
    T = t;
    while (t--)
    {
        scanf("%d", &n);
        init();
        for (int i = 1; i <= n; i++)
        {
            A[i] = read();
            B[i] = read();
            pic_discret[++N] = A[i];
            pic_discret[++N] = B[i];
        }
        discrete(pic_discret, n);
        for (int i = 1; i <= n; i++)
        {
            int a = lower_bound(pic_discret + 1, pic_discret + 1 + N, A[i]) - pic_discret;
            int b = lower_bound(pic_discret + 1, pic_discret + 1 + N, B[i]) - pic_discret;
            int fa_a = find(a);
            int fa_b = find(b);
            if (fa_a == fa_b)
                edge_num[fa_a]++;
            else
                ufs[fa_a] = fa_b, edge_num[fa_b] += edge_num[fa_a] + 1;
        }
        for (int i = 1; i <= N;i++)
        {
            int fa = find(i);
            uni[fa] = edge_num[fa];
            uni_node[fa]++;
        }
        int ans = N;
        for (int i = 1; i <= N;i++)
        {
            if (uni[i] == -1)
                continue;
            if (uni[i] < uni_node[i])
                ans--;
        }
        printf("Case #%d: %d\n", T - t, ans);
    }
    return 0;
}