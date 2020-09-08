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
const int MAXN = 1e5 + 20;
const int MAXL = 1e6 + 9;
const int MOD = 1e9 + 7;

string s[MAXN];
vector<ll> hash_code[MAXN][2];
vector<int> sortedd[MAXN];
int nextt[MAXL], dp[2][MAXL];

namespace HASH
{
    ll p[2][MAXL], rev_p[2], mods[2], jz[2];
    //rev_p是逆元，用来通过(hash[b] - hash[a])*rev_p来算a~b的hash
    //p[][i]是字符串第i位要乘以多少，即jz^^i

    ll q_pow(ll a, ll b, int p) //a^b mod p
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

    void init()
    {
        mods[0] = 1e9 + 7, mods[1] = 1e9 + 9; //双hash
        jz[0] = 29, jz[1] = 31;               //每一位乘多少，即:进制
        for (int i = 0; i < 2; i++)
        {
            p[i][0] = 1;
            for (int j = 1; j < MAXL; j++)
                p[i][j] = p[i][j - 1] * jz[i] % mods[i];
            rev_p[i] = q_pow(jz[i], mods[i] - 2, mods[i]);
        }
    }

    pair<int, int> getHash(int i, int x, int delPos)
    {
        if (delPos > x)
            return make_pair(hash_code[i][0][x], hash_code[i][1][x]);
        int ret0 = ((hash_code[i][0][x + 1] - hash_code[i][0][delPos + 1] + mods[0]) * rev_p[0] + hash_code[i][0][delPos]) % mods[0];
        int ret1 = ((hash_code[i][1][x + 1] - hash_code[i][1][delPos + 1] + mods[1]) * rev_p[1] + hash_code[i][1][delPos]) % mods[1];
        return make_pair(ret0, ret1);
    }
    bool equal(int i, int x, int j, int y, int mid)
    {
        return getHash(i, mid, x) == getHash(j, mid, y);
    }

} // namespace HASH

inline int getch(int i, int x, int len)
{
    if (x > len)
        return s[i][len] - 'a' + 1;
    if (len + 1 < s[i].size())
        return s[i][len + 1] - 'a' + 1;
    return 0;
}

bool bin_check(int i, int x, int j, int y)
{
    int len1 = s[i].size(), len2 = s[j].size();
    if (x != len1)
        len1--;
    if (y != len2)
        len2--;
    int l = 0, r = min(len1, len2), len;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (HASH::equal(i, x, j, y, mid))
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    HASH::init();
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        int len = s[i].size();
        //计算hash值
        for (int j = 0; j < 2; j++)
        {
            hash_code[i][j].push_back(0);
            for (int t = 0; t < len; t++)
                hash_code[i][j].push_back((hash_code[i][j][t] + (s[i][t] - 'a' + 1) * HASH::p[j][t]) % HASH::mods[j]);
        }
        //下面是dp优化的init,nextt[i]表第i个字符后面第一个和他不一样的
        nextt[len - 1] = len;
        for (int j = len - 2; j >= 0; j--)
        {
            if (s[i][j] == s[i][j + 1])
                nextt[j] = nextt[j + 1];
            else
                nextt[j] = j + 1;
        }
        vector<int> tmpp;
        for (int j = 0; j < len; j++)
        {
            if (nextt[j] == len || s[i][j] > s[i][nextt[j]])
                sortedd[i].push_back(j);
            else
                tmpp.push_back(j);
        }
        sortedd[i].push_back(len);
        for (int j = tmpp.size() - 1; j >= 0; j--)
            sortedd[i].push_back(tmpp[j]);
    }
    for (int i = 0; i < sortedd[0].size(); i++)
        dp[0][i] = 1;
    for (int i = 1; i < n; i++)
    {
        int id = i & 1;
        int sum = 0, ptr = 0;
        for (int j = 0; j < sortedd[i].size(); j++)
        {
            while (ptr < sortedd[i - 1].size() &&
                   bin_check(i, sortedd[i][j], i - 1, sortedd[i - 1][ptr]))
            {
                (sum += dp[id ^ 1][ptr]) %= MOD;
                ptr++;
            }
            dp[id][j] = sum;
        }
    }
    int ans = 0;
    for (int i = 0, id = (n - 1) & 1; i < sortedd[n - 1].size(); i++)
        (ans += dp[id][i]) %= MOD;
    cout << ans << endl;
}