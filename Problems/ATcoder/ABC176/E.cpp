#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include<map>
#include <queue>
using namespace std;
const int MAX = 3e5 + 20;
typedef long long ll;
struct ppp{
    int val, id;
    bool operator < (ppp a) const {
        return val > a.val;
    }
};
ppp hang[MAX], lie[MAX];
map <int,int> pic[MAX];
int main()
{
    int h, w, m;
    cin >> h >> w >> m;
    for (int i = 1; i <= m;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        pic[x][y] = 1;
        hang[x].val++, lie[y].val++;
    }
    for (int i = 1; i <= max(h, w);i++)
        hang[i].id = i, lie[i].id = i;
    sort(hang + 1, hang + 1 + h);
    sort(lie + 1, lie + 1 + w);
    int ans = hang[1].val + lie[1].val - 1;
    {
        for (int i = 1; i <= h;i++)
        {
            if (i != 1 and hang[i].val != hang[i-1].val)
                break;
            for (int j = 1; j <= w;j++)
            {
                if (j!=1 and lie[j].val != lie[j-1].val)
                    break;
                if(pic[hang[i].id].count(lie[j].id) == 0)
                {
                    ans++;
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
