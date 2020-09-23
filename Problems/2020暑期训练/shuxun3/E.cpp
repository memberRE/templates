#define DIN freopen("input.txt", "r", stdin);
#define DOUT freopen("output.txt", "w", stdout);
#include <bits/stdc++.h>
#include <cstdio>
#define mem(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define REP_(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef std::vector<int> VI;
typedef std::pair<int, int> P;
int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while ((c > '9' || c < '0') && c != '-')
        c = getchar();
    if (c == '-')
        flag = 0, c = getchar();
    while (c <= '9' && c >= '0')
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return flag ? x : -x;
}

bool f[1005][51][51][4];
bool isQ[1005][51][51][4];
short ff[1005][51][51][4];
bool g[51][51][4];
int h[1005];
int n, x0, y0, t;
char s[10];
struct node
{
    int d, x, y, dir;
};
P ans[100005];
int tot = 0;

bool isC(int x, int y)
{
    if (x == 0 && y == 2)
        return 1;
    if (x == 2 && y == 0)
        return 1;
    if (x == 1 && y == 3)
        return 1;
    if (x == 3 && y == 1)
        return 1;
    return 0;
}

int main()
{
    n = read(), x0 = read(), y0 = read(), t = read();
    REP(i, 1, n)
    {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        if (x1 == x2)
        {
            REP(y, min(y1, y2), max(y1, y2))
            {
                if (y != max(y1, y2))
                    g[x1][y][0] = 1;
                if (y != min(y1, y2))
                    g[x1][y][2] = 1;
            }
        }
        else
        {
            REP(x, min(x1, x2), max(x1, x2))
            {
                if (x != min(x1, x2))
                    g[x][y1][3] = 1;
                if (x != max(x1, x2))
                    g[x][y1][1] = 1;
            }
        }
    }
    int sum = 0;
    REP(i, 0, 1000)
    h[i] = -1;
    REP(i, 1, t)
    {
        int d = read();
        scanf("%s", s);
        sum += d;
        if (s[0] == 'N')
            h[sum] = 0;
        else if (s[0] == 'E')
            h[sum] = 1;
        else if (s[0] == 'S')
            h[sum] = 2;
        else
            h[sum] = 3;
    }

    queue<node> que;
    for (int j = 0; j < 4; j++)
    {
        f[0][x0][y0][j] = 1;
        que.push((node){0, x0, y0, j});
    }
    while (!que.empty())
    {
        node nd = que.front();
        que.pop();
        int x = nd.x, y = nd.y, d = nd.d, dir = nd.dir;

        if (d > sum)
            break;
        if (h[d] > -1 && dir != h[d] && ff[d][x][y][dir] != h[d])
            continue;
        //if(f[d][x][y][dir]==1) continue;
        if (g[x][y][dir] == 0)
            continue;

        f[d][x][y][dir] = 1;
        int xx, yy;
        if (dir == 0)
            xx = x, yy = y + 1;
        else if (dir == 1)
            xx = x + 1, yy = y;
        else if (dir == 2)
            xx = x, yy = y - 1;
        else
            xx = x - 1, yy = y;

        for (int j = 0; j < 4; j++)
        {
            if (isC(j, dir))
                continue;
            if (g[xx][yy][j])
            {
                if (isQ[d + 1][xx][yy][j])
                    continue;
                que.push((node){d + 1, xx, yy, j});
                isQ[d + 1][xx][yy][j] = 1;
                ff[d + 1][xx][yy][j] = dir;
            }
        }
    }
    /*
    REP(i,1,2) REP(j,1,2)
    {
        REP(k,0,3) cout<<f[9][i][j][k]<<' ';
        cout<<endl;
    }
*/
    REP(i, 0, 50)
    REP(j, 0, 50)
    {
        int tm = 0;
        REP(k, 0, 3)
        tm += f[sum][i][j][k];
        if (tm > 0)
            ans[++tot] = P(i, j);
    }
    //cout<<tot<<endl;
    sort(ans + 1, ans + tot + 1);
    REP(i, 1, tot)
    {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}
