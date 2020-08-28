#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long ll;
int t, n, k;
int nx, nn;
int lzy[N*5], sum[N*5], val[N*5];
ll ans;
map<int, int> m;
struct node
{
	int p, w;
	node() {}
	node(int a, int b)
	{
		p = a;
		w = b;
	}
} mx[N], mn[N];
void push_up(int id)
{
	val[id] = min(val[id<<1], val[id<<1|1]);
	if(val[id<<1] == val[id<<1|1]) sum[id] = sum[id<<1]+sum[id<<1|1];
	else if(val[id<<1] < val[id<<1|1]) sum[id] = sum[id<<1];
	else sum[id] = sum[id<<1|1];
}
void push_down(int id)
{
	lzy[id<<1] += lzy[id];
	lzy[id<<1|1] += lzy[id];
	val[id<<1] += lzy[id];
	val[id<<1|1] += lzy[id];
	lzy[id] = 0;
}
void insert(int id, int l, int r, int p)
{
	if(l == r)
	{
		val[id] = -1;
		sum[id] = 1;
		return ;
	}
	if(lzy[id]) push_down(id);
	int mid = l+r>>1;
	if(p<=mid) insert(id<<1, l, mid, p);
	else insert(id<<1|1, mid+1, r, p);
	push_up(id);
}
void update(int id, int l, int r, int ql, int qr, int v)
{
	if(ql<=l && r<=qr)
	{
		lzy[id] += v;
		val[id] += v;
		return ;
	}
	if(lzy[id]) push_down(id);
	int mid = l+r>>1;
	if(ql<=mid) update(id<<1, l, mid, ql, qr, v);
	if(qr>mid) update(id<<1|1, mid+1, r, ql, qr, v);
	push_up(id);
}
int main()
{
	scanf("%d", &t);
	for(int casee = 1; casee <= t; casee++)
	{
		ans = nx = nn = 0;
		m.clear();
		scanf("%d", &n);
		memset(lzy, 0, sizeof(int)*(5*n+2));
		memset(sum, 0, sizeof(int)*(5*n+2));
		memset(val, 0x3f3f3f3f, sizeof(int)*(5*n+2));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &k);
			insert(1, 1, n, i);
			int p = i, v;
			while(nx > 0 && mx[nx].w <= k)
			{
				p = mx[nx].p, v = k-mx[nx].w;
				nx--;
				update(1, 1, n, mx[nx].p+1, p, v);
			}
			mx[++nx] = node(i, k);
			p = i;
			while(nn > 0 && mn[nn].w >= k)
			{
				p = mn[nn].p, v = k-mn[nn].w;
				nn--;
				update(1, 1, n, mn[nn].p+1, p, -v);
			}
			mn[++nn] = node(i, k);
			int l;
			if(m.find(k) != m.end()) l = m[k]+1;
			else l = 1;
			if(l <= i-1) update(1, 1, n, l, i-1, -1);
			m[k] = i;
			ans += sum[1];
		}
		printf("Case #%d: %lld\n", casee, ans);
	}
}
