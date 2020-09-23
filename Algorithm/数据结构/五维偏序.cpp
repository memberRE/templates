/*
    题意：给定3e4个五维点，对于每个点，求出有多少个点，其每个维度的值都小于该点。
    题解：暴力的不行，，，考虑n^2算法，对每个点，扫描一遍所有的点，求出答案。
        换一种n^2思路，对于每个点，分别对每一维度求出有哪些点比他小，然后求这5个集合的交集
        bitset多维偏序就是指用bitset优化这个方法。将其时间复杂度/32，
*/
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 30010;
int Rank[maxn][6], sa[maxn][6], ans;
bitset<maxn + 2> Set[maxn][6], tmp;
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= 5; j++)
        {
            scanf("%d", &sa[i][j]);
            Rank[sa[i][j]][j] = i;
        }
    for (j = 1; j <= 5; j++)
        for (i = 2; i <= n; i++)
        {
            Set[i][j] = Set[i - 1][j];
            Set[i][j].set(Rank[i - 1][j]);
        }
    for (i = 1; i <= n; i++)
    {
        tmp = Set[sa[i][1]][1];
        for (j = 2; j <= 5; j++)
            tmp &= Set[sa[i][j]][j];
        printf("%d\n", tmp.count());
    }
    return 0;
}