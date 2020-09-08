#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
int const maxn = 1e5 + 5, maxc = 1e6 + 5;
ll mod[2], P[2], p[2][maxc], rev_P[2];
vector<ll> h[2][maxn];
vector<int> sorted[maxn];
string s[maxn];
int nxt[maxc];
int a[maxc], dp[2][maxc], inf = 1e9 + 7;
int MOD = 1e9 + 7;

ll st(ll x, int y, int ok)
{
    if (y == 0)
        return 1;
    if (y % 2 == 0)
    {
        ll d = st(x, y / 2, ok);
        return d * d % mod[ok];
    }
    return x * st(x, y - 1, ok) % mod[ok];
}

inline char get_c(int i, int x, int numb)
{
    if (numb < x)
        return s[i][numb];
    if (numb + 1 < (int)s[i].size())
        return s[i][numb + 1];
    return ' ';
}

inline ll get_hash(int t, int i, int x, int len)
{
    if (len < x)
        return h[t][i][len];
    return (h[t][i][x] + (h[t][i][len + 1] - h[t][i][x + 1] + mod[t]) * rev_P[t]) % mod[t];
}

inline pair<ll, ll> get_h(int i, int x, int len)
{
    return {get_hash(0, i, x, len), get_hash(1, i, x, len)};
}

inline int check(int i, int x, int j, int y)
{
    int len1 = (int)s[i].size(), len2 = (int)s[j].size();
    if (x != len1)
        len1--;
    if (y != len2)
        len2--;
    int lef = 0, righ = min(len1, len2) + 1;
    while (righ - lef > 1)
    {
        int mid = (righ + lef) / 2;
        if (get_h(i, x, mid) == get_h(j, y, mid))
            lef = mid;
        else
            righ = mid;
    }
    return get_c(i, x, lef) >= get_c(j, y, lef);
}
int
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mod[0] = 1e9 + 7, mod[1] = 1e9 + 9, P[0] = 29, P[1] = 31, rev_P[0] = st(P[0], mod[0] - 2, 0), rev_P[1] = st(P[1], mod[1] - 2, 1);
    p[0][0] = 1, p[1][0] = 1;
    for (int i = 1; i < maxc; ++i)
    {
        for (int j = 0; j <= 1; ++j)
            p[j][i] = p[j][i - 1] * P[j] % mod[j];
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        for (int j = 0; j <= 1; ++j)
        {
            h[j][i].push_back(0);
            for (int pos = 0; pos < (int)s[i].size(); ++pos)
            {
                h[j][i].push_back((h[j][i][pos] + p[j][pos] * (s[i][pos] - 'a' + 1)) % mod[j]);
            }
        }
        nxt[(int)s[i].size() - 1] = (int)s[i].size() - 1;
        for (int pos = (int)s[i].size() - 2; pos >= 0; --pos)
        {
            if (s[i][pos] != s[i][pos + 1])
                nxt[pos] = pos + 1;
            else
                nxt[pos] = nxt[pos + 1];
        }
        int l = 0, r = (int)s[i].size() - 1;
        for (int j = 0; j < (int)s[i].size(); ++j)
        {
            if (s[i][nxt[j]] <= s[i][j])
                a[l++] = j;
            else
                a[r--] = j;
        }
        for (int j = 0; j < (int)s[i].size(); ++j)
        {
            sorted[i].push_back(a[j]);
            if (a[j] == (int)s[i].size() - 1)
                sorted[i].push_back((int)s[i].size());
        }
    }
    for (int i = 0; i <= (int)s[1].size(); ++i)
    {
        dp[0][i] = 1;
    }
    for (int i = 2; i <= n; ++i)
    {
        int oks = (i - 1) % 2, ptr = 0, sum = 0, cur = -1;
        for (auto key : sorted[i])
        {
            cur++;
            while (ptr < (int)sorted[i - 1].size() && check(i, key, i - 1, sorted[i - 1][ptr]))
            {
                sum += dp[(1 ^ oks)][ptr];
                if (sum >= MOD)
                    sum -= MOD;
                ptr++;
            }
            dp[oks][cur] = sum;
        }
    }
    int ans = 0;
    for (int i = 0; i <= (int)s[n].size(); ++i)
    {
        ans += dp[(n - 1) % 2][i];
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << ans << '\n';
    return 0;
}