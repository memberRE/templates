#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct data
{
	int z, y, xh;
	bool operator<(const data &x) const
	{
		if (y < x.y)
			return 1;
		else
			return 0;
	}
} s[501001];
int c[500011];
int a[500101];
int h[500101];

map<int, int> Map;
int n;
int lowbit(int i)
{
	return i & (-i);
}
void add(int i, int x)
{
	while (i <= n)
	{
		c[i] += x;
		i += lowbit(i);
	}
}
int sum(int x)
{
	int ans = 0;
	while (x > 0)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= m; ++i)
	{
		cin >> s[i].z >> s[i].y;
		s[i].xh = i;
	}

	sort(s + 1, s + 1 + m);
	int last = 0;
	for (int i = 1; i <= m; ++i)
	{
		++last;
		for (int j = last; j <= s[i].y; ++j)
		{
			if (Map[a[j]])
			{
				add(Map[a[j]], -1);
				Map[a[j]] = j;
				add(Map[a[j]], 1);
			}
			else
			{
				Map[a[j]] = j;
				add(j, 1);
			}
		}
		h[s[i].xh] = sum(s[i].y) - sum(s[i].z - 1);
		last = s[i].y;
	}
	for (int i = 1; i <= m; ++i)
		cout << h[i] << endl;
}
