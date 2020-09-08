#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
const int maxl = 1e6 + 6;
const int mod = 1e9 + 7;
using ll = long long;
using pii = pair<int, int>;

string s[maxn];
int nxt[maxl];
vector<int> sorted[maxn];
int dp[2][maxl];
vector<ll> h[maxn][2];

ll Pow(ll a, ll b, int p)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

ll p[2][maxl], pp[2], mods[2], revp[2];
void init()
{
    mods[0] = 1e9 + 7, mods[1] = 1e9 + 9;
    pp[0] = 29, pp[1] = 31;
    for (int i = 0; i < 2; i++)
    {
        p[i][0] = 1;
        for (int j = 1; j < maxl; j++)
            p[i][j] = p[i][j - 1] * pp[i] % mods[i];
    }
}

pii getHash(int i, int x, int delPos)
{
    if (delPos > x)
        return make_pair(h[i][0][x], h[i][1][x]);
    int ret0 = ((h[i][0][x + 1] - h[i][0][delPos + 1] + mods[0]) * revp[0] +
                h[i][0][delPos]) %
               mods[0];
    int ret1 = ((h[i][1][x + 1] - h[i][1][delPos + 1] + mods[1]) * revp[1] +
                h[i][1][delPos]) %
               mods[1];
    return make_pair(ret0, ret1);
}
bool equal(int i, int x, int j, int y, int mid)
{
    return getHash(i, mid, x) == getHash(j, mid, y);
}
int getch(int i, int x, int len)
{
    if (x > len)
        return s[i][len] - 'a' + 1;
    if (len + 1 < s[i].size())
        return s[i][len + 1] - 'a' + 1;
    return 0;
}
bool check(int i, int x, int j, int y)
{
    int len1 = s[i].size(), len2 = s[j].size();
    if (x != len1)
        len1--;
    if (y != len2)
        len2--;
    int l = 0, r = min(len1, len2), len;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (equal(i, x, j, y, mid))
        {
            len = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    int c1 = getch(i, x, len), c2 = getch(j, y, len);
    return c1 >= c2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    init();
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        int len = s[i].size();

        for (int j = 0; j < 2; j++)
        {
            revp[j] = Pow(pp[j], mods[j] - 2, mods[j]);
            h[i][j].push_back(0);
            for (int t = 0; t < len; t++)
            {
                h[i][j].push_back((h[i][j][t] + (s[i][t] - 'a' + 1) * p[j][t]) %
                                  mods[j]);
            }
        }

        nxt[len - 1] = len;
        for (int j = len - 2; j >= 0; j--)
        {
            if (s[i][j] == s[i][j + 1])
                nxt[j] = nxt[j + 1];
            else
                nxt[j] = j + 1;
        }
        vector<int> tmp;
        for (int j = 0; j < len; j++)
        {
            if (nxt[j] == len || s[i][j] > s[i][nxt[j]])
                sorted[i].push_back(j);
            else
                tmp.push_back(j);
        }
        sorted[i].push_back(len);
        for (int j = tmp.size() - 1; j >= 0; j--)
            sorted[i].push_back(tmp[j]);
    }
    for (int i = 0; i < sorted[0].size(); i++)
        dp[0][i] = 1;

    for (int i = 1; i < n; i++)
    {
        int id = i & 1;
        int sum = 0, ptr = 0;
        for (int j = 0; j < sorted[i].size(); j++)
        {
            while (ptr < sorted[i - 1].size() &&
                   check(i, sorted[i][j], i - 1, sorted[i - 1][ptr]))
            {
                (sum += dp[id ^ 1][ptr]) %= mod;
                ptr++;
            }
            dp[id][j] = sum;
        }
    }
    int ans = 0;
    for (int i = 0, id = (n - 1) & 1; i < sorted[n - 1].size(); i++)
        (ans += dp[id][i]) %= mod;
    cout << ans << endl;
}