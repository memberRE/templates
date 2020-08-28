#include <algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 2e5 + 200;
int A[MAX],B[MAX],ans[MAX],op[MAX];
int main()
{
    int n;
    cin >> n;
    memset(op, 0, sizeof(op));
    for (int i = 1; i <= n;i++)
    {
        int tem;
        scanf("%d", &tem);
        A[tem] = i;
    }
    for (int i = 1; i <= n;i++)
    {
        int tem;
        scanf("%d", &tem);
        B[tem] = i;
    }
    for (int i = 1; i <= n;i++)
    {
        ans[i] = A[i] - B[i];
        if(ans[i] < 0)
            ans[i] += n;
        else
            ans[i] %= n;
        op[ans[i]]++;
    }
    int jkl = 0;
    for (int i = 0; i <= n;i++)
        jkl = max(jkl, op[i]);
    cout << jkl;
    return 0;
}