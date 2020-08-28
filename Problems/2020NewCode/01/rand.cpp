#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<time.h>
using namespace std;
/*
int main()
{
    for (int i = 1; i <= 10;i++)
    {
        cout << 100000 << endl;
        for (int j = 1; j <= 100000;j++)
            cout << ((rand() / 16575 == 0) ? 'a' : 'b');
        cout << endl;
    }
}*/
typedef long long ll;
typedef long double db;
const int N = 2e6 + 5, M = 1e9 + 7;

int sa[N], rk[N], oldrk[N << 1], id[N], px[N], cnt[N],sec[N];
// px[i] = rk[id[i]]（用于排序的数组所以叫 px）
/*
bool cmp(int x, int y, int w)
{
    return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}

void da(int *s, int n, int m)
{
    int i, p, w;
    for (int i = 0; i <= n; i++)
        cnt[i] = 0;
    for (i = 1; i <= n; ++i)
        ++cnt[rk[i] = s[i]];
    for (i = 1; i <= m; ++i)
        cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; --i)
        sa[cnt[rk[i]]--] = i;

    for (w = 1; w < n; w <<= 1, m = p)
    { // m=p 就是优化计数排序值域
        for (p = 0, i = n; i > n - w; --i)
            id[++p] = i;
        for (i = 1; i <= n; ++i)
            if (sa[i] > w)
                id[++p] = sa[i] - w;
        //memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i <= n; i++)
            cnt[i] = 0;
        for (i = 1; i <= n; ++i)
            ++cnt[px[i] = rk[id[i]]];
        for (i = 1; i <= m; ++i)
            cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i)
            sa[cnt[px[i]]--] = id[i];
        for (int i = 0; i <= n; i++)
            oldrk[i] = rk[i];
        //memcpy(oldrk, rk, sizeof(rk));
        for (p = 0, i = 1; i <= n; ++i)
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
}*/
void binsort(int n,int m)
{
	for(int i=0;i<=m;i++)	cnt[i]=0;
	for(int i=1;i<=n;i++)	cnt[rk[i]]++;
	for(int i=1;i<=m;i++)	cnt[i]+=cnt[i-1];
	for(int i=n;i>=1;i--)	sa[cnt[rk[sec[i]]]--]=sec[i];
}
void suffix_array(int b_suf[],int n,int m)
{
	//M='z';
	for(int i=1;i<=n;i++)	rk[i]=b_suf[i] + 1,sec[i]=i;
	binsort(n,m);
	for(int w=1,p=0;p<n;w<<=1,m=p)
	{
		p=0;
		for(int i=1;i<=w;i++)	sec[++p]=n-w+i;
		for(int i=1;i<=n;i++)	if(sa[i]>w)	sec[++p]=sa[i]-w;
		binsort(n,m);
		swap(rk,sec);
        rk[sa[1]] = p = 1;
        for(int i=2;i<=n;i++)//重排rk 
			rk[sa[i]]=(sec[sa[i-1]]==sec[sa[i]] and sec[sa[i-1]+w]==sec[sa[i]+w]) ? p : ++p;
	}
}

int n;
struct node
{
    int x, y;
    bool operator<(const node &b) const
    {
        if (y - x == b.y - b.x)
        {
            return rk[y + 1] < rk[b.y + 1];
        }
        return y - x < b.y - b.x;
    }
} a[N];
int b[N];
char s[N];
int main()
{
    clock_t str = clock();
    ios::sync_with_stdio(0);cin.tie(0);
    while (cin >> n)
    {
        cin >> s + 1;
        int x = -1, y = -1;
        for (int i = 1; i <= n; i++)
        {
            b[i] = 0;
            if (s[i] == 'a')
            {
                if (x != -1)
                    b[i] = i - x;
                x = i;
            }
            else
            {
                if (y != -1)
                    b[i] = i - y;
                y = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            b[i]++;
        }
        
        suffix_array(b, n, n); //后缀数组求出rank数组
        
        for (int i = 1; i <= n; i++)
            x = y = n + 1;
        for (int i = n; i >= 1; i--)
        {
            if (s[i] == 'a')
            {
                a[i] = {i, y};
                x = i;
            }
            else
            {
                a[i] = {i, x};
                y = i;
            }
        }
        rk[n + 1] = -1;
        rk[n + 2] = -2;
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            cout << a[i].x << ' ';
        }
        cout << '\n';
    }
    // clock_t endd = clock();
    // cout << endd - str << endl;
}