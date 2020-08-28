#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
int pic[312][312];
int sumx[312], sumy[312];
int n, k, x0 = 1, y0 = 1;
void getnext(int &x,int &y)
{
    int x1 = x + 1;
    int y1 = y + 1;
    if(x1 > n || y1 > n)
    {
        if(x0 == y0)
        {
            x0 += 1;
        }
        else if(x0 > y0)
        {
            swap(x0, y0);
            y0 = n - y0 + 2;
        }
        else
        {
            swap(x0, y0);
            x0 = n - x0 + 2;
            x0 += 1;
        }
        x = x0;
        y = y0;
        return;
    }

    x = x1;
    y = y1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        x0 = y0 = 1;
        int x = 0, y = 0;
        memset(pic, 0, sizeof(pic));
        memset(sumx, 0, sizeof(sumx));
        memset(sumy, 0, sizeof(sumy));
        for (int i = 1; i <= k;i++)
        {
            getnext(x, y);
            pic[x][y] = 1;
            sumx[x]++;
            sumy[y]++;
        }
        sort(sumx + 1, sumx + 1 + n);
        sort(sumy + 1, sumy + 1 + n);
        cout << (sumx[1] - sumx[n]) * (sumx[1] - sumx[n]) + (sumy[1] - sumy[n]) * (sumy[1] - sumy[n]) << endl;

        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n;j++)
                printf("%d", pic[i][j]);
            putchar('\n');
        }
    }
    return 0;
}