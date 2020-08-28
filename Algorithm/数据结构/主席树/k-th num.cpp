#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 20;
struct ppp
{
	int ls, rs;
	int sum;
} tree[MAX * 20];
int root[MAX], n, m, tot;
int pic[MAX], tem[MAX], N;
void discrete()
{
	//memcpy(tem,pic,sizeof(pic));
	for (int i = 1; i <= n; i++)
		tem[i] = pic[i];
	sort(tem + 1, tem + 1 + n);
	N = unique(tem + 1, tem + 1 + n) - tem - 1;
}
int build(int l, int r)
{
	int node = ++tot;
	if (l == r)
		return node;
	int mid = (l + r) >> 1;
	tree[node].ls = build(l, mid);
	tree[node].rs = build(mid + 1, r);
	return node;
}
int insert(int node, int l, int r, int x, int num)
{
	int p = ++tot;
	tree[p] = tree[node];
	if (l == r)
	{
		tree[p].sum += num;
		return p;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
		tree[p].ls = insert(tree[node].ls, l, mid, x, num);
	else
		tree[p].rs = insert(tree[node].rs, mid + 1, r, x, num);
	tree[p].sum = tree[tree[p].ls].sum + tree[tree[p].rs].sum;
	return p;
}
int query(int noder, int nodel, int l, int r, int x)
{
	if (l == r)
		return l;
	int mid = (l + r) >> 1;
	int cnt = tree[tree[noder].ls].sum - tree[tree[nodel].ls].sum;
	if (cnt >= x)
		return query(tree[noder].ls, tree[nodel].ls, l, mid, x);
	else
		return query(tree[noder].rs, tree[nodel].rs, mid + 1, r, x - cnt);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &pic[i]);
	discrete();
	root[0] = build(1, N);
	for (int i = 1; i <= n; i++)
	{
		int x = lower_bound(tem + 1, tem + 1 + N, pic[i]) - tem;
		root[i] = insert(root[i - 1], 1, N, x, 1);
	}
	for (int i = 1; i <= m; i++)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		int ans = query(root[r], root[l - 1], 1, N, k);
		printf("%d\n", tem[ans]);
	}
	return 0;
}
