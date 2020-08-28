#include <algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 1e5 + 20;
int pic[MAX],n,x;
int div3[MAX];
// bool check(int cnt)
// {
//     int tem = 0;
//     for (int i = 1; i <= cnt;i++)
//         tem += pic[i];
//     if (tem % x != 0)
//         return true;
//     for (int i = 1; i + cnt <= n;i++)
//     {
//         tem += pic[i + cnt];
//         tem -= pic[i];
//         if (tem % x != 0)
//         return true;
//     }
//     return false;
// }
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n,&x);
        int tem = 0;
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &pic[i]);
            tem += pic[i];
            if (pic[i] % x == 0)
                div3[i] = 1;
            else
                div3[i] = 0;
        }
        if(tem%x!=0)
        {
            cout << n << endl;
            continue;
        }
        int prepos = 1,laspos = n;
        for (prepos = 1; prepos <= n;prepos++)
            if(div3[prepos] == 0)
                break;
        for (laspos = n; laspos >= 1;laspos--)
            if(div3[laspos] == 0)
                break;
        if (prepos == n + 1)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            int ans = max(n - prepos, laspos - 1);
            cout << ans << endl;
        }
    }
    return 0;
}