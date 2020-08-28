#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
char pic[256][256];
int main()
{
    int t;
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n;
        for (int i = 1; i <= n;i++)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}