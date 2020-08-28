#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int pic[100050];
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> pic[i];
        if (pic[1] + pic[2] <= pic[n])
            printf("1 2 %d\n", n);
        else
            puts("-1");
    }
    return 0;
}