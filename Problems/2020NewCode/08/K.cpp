#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX = 1e5 + 20;
typedef long long ll;
int n;
int A[MAX], B[MAX];
int st_max[20][100008], st_min[20][100008];
ll sum[MAX];
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
// void ST(int **st, int eu[], int k, int getmin(int a, int b))
// {
//     for (int i = 1; i <= k; i++)
//         st[0][i] = eu[i];
//     for (int j = 1; (1 << j) <= k; j++)
//         for (int i = 1; i + (1 << j) <= k; i++)
//             st[j][i] = getmin(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
// }
inline int get_max(int a,int b)
{
	return sum[a] > sum[b] ? a: b;
}
inline int get_min(int a,int b)
{
	return B[a] < B[b] ? a: b;
}
int rmq_max(int l,int r)//下标
{
    int k=trunc(log2(r-l+1));
    return get_max(st_max[k][l],st_max[k][r-(1<<k)+1]);
}
int rmq_min(int l,int r)
{
    int k=trunc(log2(r-l+1));
    return get_min(st_min[k][l],st_min[k][r-(1<<k)+1]);
}

inline void print(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
int main()
{
    //ios::sync_with_stdio(0);
    int t, T;
    cin >> t;
    T = t;
    while (t--)
    {
        n = read();
        for (int i = 1; i <= n; i++)
        {
            A[i] = read();
            sum[i] = (ll)A[i] + sum[i - 1];
        }
        for (int i = 1; i <= n; i++)
            B[i] = read();

        for (int i = 1; i <= n; i++)
            st_max[0][i] = i; /*sum[i]*/
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                st_max[j][i] = get_max(st_max[j - 1][i], st_max[j - 1][i + (1 << j - 1)]);
        
        for (int i = 1; i <= n; i++)
            st_min[0][i] = i;
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                st_min[j][i] = get_min(st_min[j - 1][i], st_min[j - 1][i + (1 << j - 1)]);

        int num = B[1];
        __int128_t ans = 0;
        int max_pos = rmq_max(1, n);
        int tem = num;
        while (tem > 0)
        {
            int min_num_pos = rmq_min(1, max_pos);
            int real_min_num = B[min_num_pos] - (num - tem);
            ans += (__int128_t)sum[max_pos] * (__int128_t)real_min_num;
            tem -= real_min_num;
            if (tem <= 0)
            	break;
            max_pos = rmq_max(1, min_num_pos - 1);
        }
        //printf("Case #%d: %d %lld\n", T - t, num, ans);
        printf("Case #%d: %d ", T - t, num);
        //cout << "Case #" << T - t << ": " << num << " ";
        print(ans);
        putchar('\n');
    }
    return 0;
}
