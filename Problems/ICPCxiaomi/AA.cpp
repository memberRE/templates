#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <set>
#include <cmath>
#include <vector>

#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
const int MAXN = 1e7 + 20;
const int MAX = 2e5 + 20;
const int MAXP = 2e4 + 20;
int prime[MAXP];
bool isPrime[MAXP];
using namespace std;

void getPrime()
{
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= MAXP; i++)
	{
		if (!prime[i])prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && prime[j] <= MAXP / i; j++)
		{
			prime[prime[j] * i] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	for (int i : prime)
	{
		if (i != 0)
			isPrime[i] = true;
	}
}

int read()
{
	int x = 0, flag = 1;
	char c = getchar();
	while ((c > '9' || c < '0') && c != '-') c = getchar();
	if (c == '-') flag = 0, c = getchar();
	while (c <= '9' && c >= '0')
	{
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return flag ? x : -x;
}

int pic[MAX];
int ans[MAXN];
int n;

int main()
{
	freopen("A.in","r",stdin);
	n = read();
	int final_ans = 0;
	getPrime();
	for (int i = 1; i <= n; i++)
		pic[i] = read();
	sort(pic + 1, pic + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		int val = 1;
		int x = pic[i];
		if(ans[x])
		{
			//cout << x << ' ' << (ans[x]+1) + ans[1] << endl;
			final_ans = max(final_ans, ans[1] + (++ans[x]));
			continue;
		}
		if(x == 1)
		{
			final_ans = max(final_ans, ans[x] = val);
			continue;
		}
		set<int> s;
		int xx = x;
		for(int j = 1; prime[j] * prime[j] <= x; j++)
		{
			if(isPrime[x]) break;
			if(x % prime[j] == 0)
			{
				while(x % prime[j] == 0)
				{
					int k = prime[j];
					if (ans[k] != 0)
					{
						bool have = false;
						for (int ss : s)
						{
							if (ss % k == 0)
							{
								have = true;
								break;
							}
						}
						if (!have)
						{
							for (auto it = s.begin(); it != s.end();)
							{
								if (*it % k == 0) s.erase(it++);
								else it++;
							}
							s.insert(k);
						}
					}
					if (x / k == k) break;
					k = x / k;
					if (ans[k] != 0)
					{
						bool have = false;
						for (int ss : s)
						{
							if (ss % k == 0)
							{
								have = true;
								break;
							}
						}
						if (!have)
						{
							for (auto it = s.begin(); it != s.end();)
							{
								if (*it % k == 0) s.erase(it++);
								else it++;
							}
							s.insert(k);
						}
					}
					x /= prime[j];
				}
			}
		}
		int ma =0;
		for(int ss : s) ma = max(ans[ss], ma);
		val += ma;
		final_ans = max(final_ans, (ans[xx] = val) + ans[1]);
		//cout << xx << ' ' << (ans[xx]) + ans[1] << endl;
	}
	cout << final_ans << endl;
	fclose(stdin);
	return 0;
}
