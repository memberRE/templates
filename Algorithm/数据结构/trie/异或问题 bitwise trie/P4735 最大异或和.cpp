#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 10;
const int MAXLEN = 23;
int n, m, s[MAX << 1];
int trie[80 * MAX][2], tot, root[MAX << 1], las[80 * MAX];
void insert(int x, int jkl, int p, int q)
{
	if (jkl < 0)
	{
		las[q] = x;
		return;
	}
	int k = (s[x] >> jkl) & 1;
	if (p)
		trie[q][k ^ 1] = trie[p][k ^ 1];
	trie[q][k] = ++tot;
	insert(x, jkl - 1, trie[p][k], trie[q][k]);
	las[q] = max(las[trie[q][0]], las[trie[q][1]]);
}
int query(int l, int node, int x, int k)
{
	if (k < 0)
		return s[las[node]] ^ x;
	int c = (x >> k) & 1;
	if (las[trie[node][c ^ 1]] >= l)
		return query(l, trie[node][c ^ 1], x, k - 1);
	else
		return query(l, trie[node][c], x, k - 1);
}
int main()
{
	scanf("%d%d", &n, &m);
	las[0] = -1;
	root[0] = ++tot;
	insert(0, MAXLEN, 0, root[0]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s[i]);
		s[i] ^= s[i - 1];
		root[i] = ++tot;
		insert(i, MAXLEN, root[i - 1], root[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		char op[2];
		scanf("%s", op);
		if (op[0] == 'A')
		{
			int jkl;
			scanf("%d", &jkl);
			n++;
			s[n] = jkl ^ s[n - 1];
			root[n] = ++tot;
			insert(n, MAXLEN, root[n - 1], root[n]);
		}
		else
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", query(l - 1, root[r - 1], x ^ s[n], 23));
		}
	}
	return 0;
}
