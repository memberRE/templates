#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
const int MAX = 1e3 + 20;
char pic[MAX][MAX];
int dis[MAX][MAX],goal,ans = -1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
inline void add(int h, int wo, int w, int d)
{
    if (dis[h][w] != -1 || pic[h][w - 1] == '#')
        return;
    pair<int, int> tem = make_pair(d, h * wo + w - 1);
    que.push(tem);
}

int main()
{
    int h = read(), w = read(), ch = read(), cw = read(), dh = read(), dw = read();
    memset(dis, -1, sizeof(dis));
    goal = dh * w + dw - 1;
    for (int i = 1; i <= h; i++)
        scanf("%s", pic[i]);
    pair<int, int> tem = make_pair(0, ch * w + (cw - 1));
    que.push(tem);
    while (!que.empty())
    {
        if (que.top().second == goal)
        {
            ans = que.top().first;
            break;
        }
        int d = que.top().first;
        int xx = que.top().second / w;
        int yy = que.top().second % w + 1;
        que.pop();
        if (dis[xx][yy] != -1)
            continue;
        dis[xx][yy] = d;
        add(xx + 1, w, yy, d);
        add(xx - 1, w, yy, d);
        add(xx, w, yy - 1, d);
        add(xx, w, yy + 1, d);
        for (int i = -2; i <= 2; i++)
        {
            int xxx = xx + i;
            
            if (xxx > h)
                break;
            if (xxx <= 0)
                continue;
            for (int j = -2; j <= 2; j++)
            {
                int yyy = yy + j;
                if (yyy > w)
                    break;
                if (yyy <= 0)
                    continue;
                add(xxx, w, yyy, d + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
