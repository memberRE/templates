#include <algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int pic[64][64];
int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};
int n, m,ans;
int vztd[10020];
void bfs()
{
    memset(vztd, 0, sizeof(vztd));
    queue<int> que;
    ans = 0;
    que.push(n * 100 + m);
    vztd[n * 100 + m] = 1;
    if(pic[n][m] == '#')
        return;
    while(!que.empty())
    {
        int x = que.front() / 100;
        int y = que.front() % 100;
        que.pop();
        if(pic[x][y] == 'G')
            ans++;
        for (int i = 0; i < 4;i++)
        {
            int xx = x + dirx[i];
            int yy = y + diry[i];
            int id = xx * 100 + yy;
            if(vztd[id] || pic[xx][yy] == '#')
                continue;
            vztd[id] = 1;
            if(xx >= 1 && xx <= n && yy >=1 && yy <= m)
                que.push(id);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%d%d\n", &n, &m);
        int G_cnt = 0;
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= m;j++)
            {
                pic[i][j] = (int)getchar();
                if(pic[i][j] == 'G')
                    G_cnt++;
            }
            getchar();
        }
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= m;j++)
            {
                if(pic[i][j] == 'B')
                {
                    if(pic[i - 1][j] != 'B')
                        pic[i - 1][j] = '#';
                    if(pic[i + 1][j] != 'B')
                        pic[i + 1][j] = '#';
                    if(pic[i][j-1] != 'B')
                        pic[i][j-1] = '#';
                    if(pic[i][j+1] != 'B')
                        pic[i][j+1] = '#';
                }      
            }
        bfs();
        if (ans == G_cnt)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
