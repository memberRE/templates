#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
char s[1024];
int num[1024], tot;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        tot = 0;
        int tem = 0;
        for (int i = 0; s[i];i++)
        {
            if (s[i] == '1')
                tem++;
            else
            {
                if (tem != 0)
                {
                    num[tot++] = tem;
                    tem = 0;
                }
            }
        }
        if(tem != 0)
            num[tot++] = tem;
        sort(num, num + tot);
        int ans = 0;
        for (int i = tot - 1; i >= 0;i-=2)
        {
            ans += num[i];
        }
        cout << ans << endl;
    }
    return 0;
}