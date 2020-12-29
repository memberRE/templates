#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
const int MAXN = 1e7 + 20;
const int MAX = 2e5 + 20;
using namespace std;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
int pic[MAX];
int ans[MAXN];
int n;
int main()
{
    freopen("A.in","r",stdin);
	n = read();
    int final_ans = 0;
    for (int i = 1; i <= n;i++)
        pic[i] = read();
    sort(pic + 1, pic + 1 + n);
    for (int i = 1; i <= n;i++)
    {
        int x = pic[i];
        if (ans[x] != 0)
        {
            ans[x]++;
            final_ans = max(final_ans, ans[x]);
            continue;
        }
        ans[x]++;
        int temans = 0;
        for (int j = 2; j*j <= x;j++)
        {
            if (j == x)
                break;
            if (x%j == 0)
            {
                temans = max(temans, ans[j]);
                temans = max(temans, ans[x / j]);
            }
        }
        if (x != 1)
            temans = max(temans, ans[1]);
        ans[x] += temans;
        final_ans = max(final_ans, ans[x]);
        //cout << x << ' ' << ans[x] << endl;
    }
    cout << final_ans << endl;
    fclose(stdin);
    return 0;
}
