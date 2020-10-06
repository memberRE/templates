#define DIN freopen("input.txt", "r", stdin);
#define DOUT freopen("output.txt", "w", stdout);
#include <bits/stdc++.h>
#include <cstdio>
#define mem(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define REP_(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef std::vector<int> VI;
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

const int M = 1e9 + 7, P = 10007;
const int maxn = 1e5 + 5;
int HASH(string s)
{
    int ret = 0;
    for (int i = 0; i < s.length(); i++)
        ret = (1ll * ret * P + s[i]) % M;
    return ret;
}
double dp[205], dd[205];
int ans[maxn], n, t;
vector<double> f[maxn];
VI s[maxn];
char q[maxn];

map<int, int> tree[maxn];
int tot = 0, siz[maxn], maxx[maxn];
map<int, int> num[maxn];

void solvedp()
{
    for (int i = 0; i < t; i++)
    {
        dp[i] = dd[i];
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k <= min(t - i + 1, (int)s[j].size()); k++)
            {
                dp[i + k + 1] += f[j][k] / n;
            }
        }
        for (int j = i + 1; j <= t; j++)
            dd[j] = max(dd[j], dp[j] + dp[i]);
        for (int j = 0; j <= t; j++)
            dp[j] = 0;
        //REP(i,0,t) cout<<dd[i]<<' ';
        //cout<<endl;
    }
}

void insert(int k)
{
    int len = s[k].size(), p = 0;
    siz[p]++;
    num[p][ans[k]] += 1;
    for (int i = 0; i < len; i++)
    {
        int x = s[k][i];
        if (tree[p].count(x))
        {
            p = tree[p][x];
        }
        else
        {
            tree[p][x] = ++tot;
            p = tot;
        }
        siz[p]++;
        num[p][ans[k]] += 1;
    }
}

void solve(int k)
{
    int p = 0, v = 0;
    f[k][v] = (double)maxx[p] / siz[p];
    for (int i = 0; i < s[k].size(); i++)
    {
        int x = s[k][i];
        p = tree[p][x];
        v++;
        f[k][v] = (double)maxx[p] / siz[p];
    }
}

void init()
{
    REP(i, 1, n)
    insert(i);
    for (int i = 0; i <= tot; i++)
    {
        for (auto it = num[i].begin(); it != num[i].end(); it++)
        {
            maxx[i] = max(maxx[i], it->second);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
}

int main()
{
    t = read(), n = read();
    REP(i, 1, n)
    {
        while (1)
        {
            scanf("%s", q);
            string x;
            for (int j = 0; q[j]; j++)
                x += q[j];
            s[i].pb(HASH(x));
            if (q[x.length() - 1] == '?')
                break;
        }
        scanf("%s", q);
        string x;
        for (int j = 0; q[j]; j++)
            x += q[j];
        ans[i] = HASH(x);
        f[i].resize(s[i].size() + 3);
    }
    /*
    REP(i,1,n)
    {
        for(int j:s[i]) cout<<j<<' ';
        cout<<endl;
    } */
    init();
    /*  REP(i,1,n)
    {
        REP(j,0,3) cout<<f[i][j]<<' ';
        cout<<endl;
    }*/
    solvedp();

    printf("%.8f", dd[t]);

    return 0;
}
