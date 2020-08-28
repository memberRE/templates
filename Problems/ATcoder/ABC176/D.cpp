#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include<vector>
using namespace std;
const int MAX = 1005;
struct ppp
{
    int x, y, step;
    bool operator < (ppp a) const {
        return step > a.step;
    }
};
char pic[MAX][MAX];
int vztd[MAX][MAX];
int dirx[] = {-1, 1, 0, 0}, diry[] = {0, 0, -1, 1};
int n, m, bx, by, ex, ey;
priority_queue<ppp> que;
int ans = 0x7f7f7f7f;
// void dfs(int x, int y, int step)
// {
//     for (int i = 0; i < 4; i++)
//     {
//         int xx = x + dirx[i];
//         int yy = y + diry[i];
//         if (xx >= 1 and xx <= n and yy >= 1 and yy <= m and (vztd[xx][yy] == -1 || vztd[xx][yy] > step) and pic[xx][yy] == '.')
//         {
//             if (xx == ex and yy == ey)
//             {
//                 ans = min(step, ans);
//                 break;
//             }
//             vztd[xx][yy] = step;
//             dfs(xx, yy, step);
//         }
//     }
//     if (step + 1 >= ans)
//         return;
//     for (int i = x - 2; i <= x + 2; i++)
//         for (int j = y - 2; j <= y + 2; j++)
//         {
//             int xx = i, yy = j;
//             if (xx >= 1 and xx <= n and yy >= 1 and yy <= m and (vztd[xx][yy] == -1 || vztd[xx][yy] > step + 1) and pic[xx][yy] == '.')
//             {
//                 if (xx == ex and yy == ey)
//                 {
//                     ans = min(step + 1, ans);
//                     break;
//                 }
//                 vztd[xx][yy] = step + 1;
//                 dfs(xx, yy, step + 1);
//             }
//         }
// }
int main()
{
    cin >> n >> m;
    cin >> bx >> by >> ex >> ey;
    memset(vztd, -1, sizeof(vztd));
    for (int i = 1; i <= n; i++)
        scanf("%s", pic[i] + 1);
    vztd[bx][by] = 0;
    //dfs(bx, by, 0);
    que.push((ppp){bx, by, 0});
    while (!que.empty())
    {
        ppp tem = que.top();
        que.pop();
        int x = tem.x, y = tem.y;
        vztd[x][y] = tem.step;
        if (x == ex and y == ey)
            ans = tem.step;
        if (tem.step >= ans)
            break;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dirx[i];
            int yy = y + diry[i];
            if (xx >= 1 and xx <= n and yy >= 1 and yy <= m and (vztd[xx][yy] == -1 || vztd[xx][yy] > tem.step) and pic[xx][yy] == '.')
            {
                if (xx == ex and yy == ey)
                {
                    ans = min(tem.step, ans);
                    break;
                }
                //vztd[xx][yy] = tem.step;
                ppp jkl = (ppp){xx, yy, tem.step};
                que.push(jkl);
            }
        }
        for (int i = x - 2; i <= x + 2; i++)
            for (int j = y - 2; j <= y + 2; j++)
            {
                int xx = i, yy = j;
                if (xx >= 1 and xx <= n and yy >= 1 and yy <= m and (vztd[xx][yy] == -1 || vztd[xx][yy] > tem.step + 1) and pic[xx][yy] == '.')
                {
                    if (xx == ex and yy == ey)
                    {
                        ans = min(tem.step + 1, ans);
                        //break;
                    }
                    //vztd[xx][yy] = tem.step + 1;
                    ppp jkl = (ppp){xx, yy, tem.step + 1};
                    que.push(jkl);
                }
            }
    }
    cout << ((ans == 0x7f7f7f7f) ? -1 : ans) << endl;
    return 0;
}