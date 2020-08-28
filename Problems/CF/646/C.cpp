#include<iostream>
#include<algorithm>
#include <cstring>
#include<vector>
using namespace std;
const int MAX = 1024;
//int head[MAX], nex[MAX << 1], to[MAX << 1];
int ans[MAX],top;
int tot, n, x;
/*void add(int u,int v)
{
    tot++;
    to[tot] = v;
    nex[tot] = head[u];
    head[u] = tot;
}
int dfs(int u,int fa)
{
    int tem = 0;
    for (int i = head[u]; i; i =nex[i])
    {
        if (to[i] != fa)
            tem += dfs(to[i], u);
    }
    return tem + 1;
}*/
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        //memset(head, 0, sizeof(head));
        //pic.clear();
        top = 0;
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n - 1;i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u == x || v == x)
                top++;
            // add(u, v);
            // add(v, u);
        }
        // for (int i = head[x]; i; i = nex[i])
        // {
        //     ans[top++] = dfs(to[i], x);
        // }
        if (top <= 1)
        {
            cout << "Ayush" << endl;
            continue;
        }
        if(n&1)
        {
            cout << "Ashish" << endl;
            continue;
        }
        else
        {
            cout << "Ayush" << endl;
            continue;
        }
    }
    return 0;
}