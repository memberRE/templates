#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
#define FOR(x, y) for (x = 0; x < (int)y;x++)
#define FORR(x, y)   for (auto x : y)
#define ALL(x) x.begin(),x.end()
#define ZERO(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;
ll from[4063][70];
ll to[4063][70];
map<int, int> T;
const ll MOD = 1000000007;
class BasePlacement
{
	public:
		int count(int R, int C, int B)
		{
			if (C > R)
				swap(R, C);
			vector<int> cand;
			vector<int> state;
			int i;
			int mask;
			FOR(mask, 1 << C)
			{
				if (mask & (mask << 1))
					continue;
				if (mask & (mask << 2))
					continue;
				cand.push_back(mask);
			}
			FORR(a, cand)
			FORR(b, cand)
			{
				if (a & b)
					continue;
				if ((a << 1) & b)
					continue;
				if (a & (b << 1))
					continue;
				int i;
				int mask2 = 0;
				int c = 1;
				FOR(i, C)
				{
					if (b & (1 << i))
					{
						mask2 += 2 * c;
					}
					else
					{
						int num = 0;
						if (b & (2 << i))
							num++;
						if (i && (b & (1 << (i - 1))))
							num++;
						if (a & (1 << i))
							num++;
						mask2 += num * c;
					}
					c *= 3;
				}
				state.push_back(mask2);
			}
			sort(ALL(state));
			state.erase(unique(ALL(state)), state.end());

			vector<vector<pair<int, int>>> nex;
			nex.resize(state.size());
			int j;
			T.clear();
			FOR(j, state.size())
			T[state[j]] = j;
			FOR(j, state.size())
			{
				int s = state[j];
				FORR(c, cand)
				{
					int p = 1;
					int t = 0, add = 0;
					FOR(i, C)
					{
						int cur = s / p % 3;

						if (cur == 2)
						{
							if (c & (1 << i))
								break;
							if (c & (2 << i))
								break;
							if (i && (c & (1 << (i - 1))))
								break;
							add += p;
						}
						else if (cur == 1)
						{
							if (c & (1 << i))
								break;
							int num = 0;
							if (c & (2 << i))
								num++;
							if (i && (c & (1 << (i - 1))))
								num++;
							add += p * num;
						}
						else
						{
							if (c & (1 << i))
							{
								add += 2 * p;
								t++;
							}
							else
							{
								int num = 0;
								if (c & (2 << i))
									num++;
								if (i && (c & (1 << (i - 1))))
									num++;
								add += p * num;
							}
						}
						p = p * 3;
					}

					if (i == C)
					{
						nex[j].push_back({T[add], t});
					}
				}
			}

			ZERO(from);
			from[T[0]][0] = 1;
			int x, y;
			FOR(y, R)
			{
				FOR(i, state.size())
				FOR(x, R * C / 3 + 3) to[i][x] = 0;
				FOR(i, state.size())
				FOR(x, R * C / 3 + 3) if (from[i][x])
				{
					FORR(n, nex[i])
					{
						(to[n.first][x + n.second] += from[i][x]) %= MOD;
					}
				}
				swap(from, to);
			}

			ll ret = 0;
			FOR(i, state.size())
			for (j = B; j <= 69; j++) ret += from[i][j];
			return ret % MOD;
		}
};
//int main()
//{
//	cout<<"  $$  "<<(new BasePlacement)->count(2, 95, 48)<<"   ###";
//}
