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
int n, m;
int A[111], B[111];
int main()
{
    int mid1 = (n + m + 1) / 2;
    int mid2 = min1 + 1;
    int ans1, ans2,ans;
    int i = 1, j = 1;
    while (i <= n and j <= m)
    {
        int tem;
        if (A[i] <= B[j])
            tem = A[i], i++;
        else
            tem = B[j], j++;
        if (i + j - 2 == mid1)
            ans1 = tem;
        if (i + j - 2 == mid2)
            ans2 = tem;
    }
    while (i <= n)
    {
        i++;
        if (i + j - 2 == mid1)
            ans1 = A[i - 1];
        if (i + j - 2 == mid2)
            ans2 = A[i - 1];
    }
    while (j <= m)
    {
        j++;
        if (i + j - 2 == mid1)
            ans1 = A[i - 1];
        if (i + j - 2 == mid2)
            ans2 = A[i - 1];
    }
    if ((n+m)%2 == 1)
        ans = ans1;
    else
        ans = (ans1 + ans2) / 2;
}