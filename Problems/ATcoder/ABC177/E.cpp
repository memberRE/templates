#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#include<set>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
const int MAX = 1e6 + 20;
int pri[MAX];
int is_prii[MAX];
int hass[MAX], pic[MAX];
set<int> t;
void Prime()
{
    for (int i = 2; i < MAX; i++)
    {
        if (!is_prii[i])
            pri[++pri[0]] = i; //纪录素数， 这个pri[0] 相当于 cnt，用来计数
        for (int j = 1; j <= pri[0] && i * pri[j] < MAX; j++)
        {
            is_prii[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
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
int main()
{
    Prime();
    int n = read();
    int gcdd = 0;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        pic[i] = read();
        gcdd = gcdd == 0 ? pic[i] : __gcd(gcdd, pic[i]);
    }
    for (int j = n; j >= 1; j--)
    {
        int tem = pic[j];
        if (flag == 1)
            break;
        for (int i = 1; pri[i]*pri[i] <= tem; i++)
        {
            if (tem <= 1)
                break;
            if (tem % pri[i] == 0)
            {
                if (t.count(pri[i]))
                {
                    flag = 1;
                    break;
                }
                t.insert(pri[i]);
                while (tem % pri[i] == 0)
                    tem /= pri[i];
            }
        }
        if (tem > 1)
        {
            if (t.count(tem))
            {
                flag = 1;
                break;
            }
            t.insert(tem);
        }
    }
    if (flag == 0)
    {
        puts("pairwise coprime");
    }
    else if (gcdd == 1)
        puts("setwise coprime");
    else
        puts("not coprime");
    return 0;
}