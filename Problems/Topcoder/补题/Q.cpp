#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
#define FOR(x, y) for (x = 0; x < (int)y; x++)
#define FORR(x, y) for (auto x : y)
#define ALL(x) x.begin(), x.end()
#define ZERO(x) memset(x, 0, sizeof(x))
typedef long long ll;
using namespace std;
ll from[102][52][52][27];
ll to[102][52][52][27];
int flag[31];
const ll MOD = 1e9 + 7;

class ShortBugPaths
{
public:
    int count(int N, vector<int> D, int J)
    {
        ZERO(flag);
        ZERO(from);
        FORR(d, D)
        flag[d] = 1;
        from[1][1][0][0] = 1;
        int h, w, y, x, i, dy, dx;

        while (J--)
        {
            ZERO(to);
            for (h = 1; h <= 101; h++)
                for (w = 1; w <= 51; w++)
                {
                    for (y = 0; y * 2 <= h; y++)
                        for (x = 0; x * 2 <= w; x++)
                            if (from[h][w][y][x])
                            {
                                for (dy = -10; dy <= 10; dy++)
                                {
                                    for (dx = -10; dx <= 10; dx++)
                                        if (flag[abs(dy) + abs(dx)])
                                        {
                                            int th = h, tw = w;
                                            int ty = y + dy;
                                            int tx = x + dx;
                                            if (ty < 0)
                                                th += -ty, ty = 0;
                                            if (ty >= th)
                                                th = ty + 1;
                                            if (tx < 0)
                                                tw += -tx, tx = 0;
                                            if (tx >= tw)
                                                tw = tx + 1;
                                            if (th - 1 - ty < ty)
                                                ty = th - 1 - ty;
                                            if (tw - 1 - tx < tx)
                                                tx = tw - 1 - tx;
                                            if (tw > th)
                                                swap(th, tw), swap(ty, tx);
                                            (to[th][tw][ty][tx] += from[h][w][y][x]) %= MOD;
                                        }
                                }
                            }
                }
            swap(from, to);
        }

        ll ret = 0;
        for (h = 1; h <= 101; h++)
            for (w = 1; w <= 51; w++)
            {
                ll sum = 0;
                for (y = 0; y * 2 <= h; y++)
                    for (x = 0; x * 2 <= w; x++)
                        sum += from[h][w][y][x];
                sum %= MOD;
                if (h > N)
                    continue;
                if (w > N)
                    continue;
                (ret += 1LL * (N + 1 - h) * (N + 1 - w) % MOD * sum) %= MOD;
            }
        return ret;
    }
};
// int main()
// {
//     cout<<(new ShortBugPaths())->count(3, {1}, 1);
// }