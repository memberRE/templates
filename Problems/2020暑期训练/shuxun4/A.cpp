#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXL = 1e4 + 20;
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
namespace HASH
{
    ull p[2][MAXL], rev_p[2], mods[2], jz[2];
    ull hash_code[2][MAXL];
    ll q_pow(ll a, ll b, ll p)
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
        mods[0] = 1e9 + 7, mods[1] = 0xffffffffffffffff /**1e9 + 9*/;
        jz[0] = 29, jz[1] = 31;

        for (int i = 0; i < 2; i++)
        {
            p[i][0] = 1;
            for (int j = 1; j < MAXL; j++)
                p[i][j] = p[i][j - 1] * jz[i] % mods[i];
            rev_p[i] = q_pow(jz[i], mods[i] - 2, mods[i]);
        }
    }

    ll gethash(int r, int l)
    {
        if (r < l)
            return 0;
        return (hash_code[0][r] - hash_code[0][l - 1] * p[0][r - l + 1]);
        //return (hash_code[0][r]-hash_code[0][l-1] * p[0][r-l+1] + mods[0])%mods[0];
        //return ((hash_code[0][r] - hash_code[0][l] + mods[0]) * rev_p[0] + hash_code[0][l]) % mods[0];
        //return ((hash_code[0][r] - hash_code[0][l - 1] + mods[0]) * rev_p[0]) % mods[0];
    }
} // namespace HASH
char S[MAXL], quer[MAXL];
int anss[MAXL];
int topp = 1, n;

int main()
{
    n = read();
    scanf("%s", quer);
    HASH::init();
    for (int i = 0; quer[i]; i++)
    {
        char op = quer[i];
        if (op == '-')
        {
            topp--;
            printf("%d ", anss[topp - 1]);
        }
        else
        {
            int temans = 1;
            S[topp] = quer[i];
            //for (int j = 0; j <= 1; j++)
            HASH::hash_code[0][topp] = (HASH::hash_code[0][topp - 1] * HASH::jz[0] + (quer[i] - 'a' + 1)) /*% HASH::mods[0]*/;
            HASH::hash_code[1][topp] = (HASH::hash_code[1][topp - 1] * HASH::jz[1] + (quer[i] - 'a' + 1)) % HASH::mods[0];
            int tem_hash = 0, lashash = 0;
            int temhash1 = 0, lashash1 = 0;
            for (int len = 1;; len++)
            {
                if (len + len - 1 > topp)
                    break;
                lashash = tem_hash;
                lashash1 = temhash1;
                tem_hash = (tem_hash * HASH::jz[0] + (S[topp - len + 1] - 'a' + 1)) /* % HASH::mods[0]*/;
                // ji
                if (len != 1)
                    if (HASH::gethash(topp - len, topp - len - len + 2) == lashash)
                    {
                        temans++;
                    }
                // ou
                if (len + len > topp)
                    break;
                if (HASH::gethash(topp - len, topp - len - len + 1) == tem_hash)
                    temans++;
            }
            anss[topp] = anss[topp - 1] + temans;
            printf("%d ", anss[topp]);
            topp++;
        }
    }
    return 0;
}
