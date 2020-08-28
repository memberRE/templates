#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAX = 1e5 + 20;
int pic[MAX];
int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n;i++)
            scanf("%d", &pic[i]);
        sort(pic + 1, pic + 1 + n);
        int ans = 1;
        int tem = 0;
        for (int i = 1; i <= n;i++)
        {
            if(ans>=pic[i])
                ans++;
            else
            {
                if (tem + ans >= pic[i])
                {
                    ans += tem + 1;
                    tem = 0;
                }
                else
                    tem++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
