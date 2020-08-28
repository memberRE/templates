#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
int n, p;
int pic[2048];
int sum[4096];
queue<int> que;
int main()
{
    cin >> n >> p;
    int maxx = 0;
    for (int i = 1; i <= n;i++)
    {
        cin >> pic[i];
        maxx = max(maxx, pic[i]);
        sum[pic[i]]++;
    }
    for (int i = 1; i <= 2048;i++)
        sum[i] = sum[i] + sum[i - 1];
    int ans = 0;
    for (int i = maxx - n + 1; i < maxx;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if (sum[i + j - 1] - j + 1 <= 0)
                break;
            if ((sum[i + j - 1] - j + 1) % p == 0)
                break;
            if(j == n)
            {
                que.push(i);
                ans++;
            }
        }
    }
    cout << ans << endl;
    while(!que.empty())
    {
        cout << que.front() << ' ';
        que.pop();
    }
    return 0;
}