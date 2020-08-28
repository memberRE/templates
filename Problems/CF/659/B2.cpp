#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 3e5;
int pic[MAX];
int ear[MAX], lat[MAX];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, l;
        cin >> n >> k >> l;
        for (int i = 1; i <= n;i++)
        {
            cin >> pic[i];
        }
        /*for (int i = 0; i <= k-1;i++)
            depth[i] = k-i;
        depth[k] = 0;
        for (int i = k + 1; i <= 2 * k;i++)
            depth[i] = i - k;
        for (int i = 0; i <= 2 * k;i++)
            cout << depth[i] << ' ';*/

        ear[0] = 0;
        lat[0] = 2 * k - 1;
        int flag = 1;
        for (int i = 1; i <= n;i++)
        {
            int tem = k - (l - pic[i]);
            ear[i] = max(0, tem);
            lat[i] = min(2 * k - 1, k + (l - pic[i]));
            if (l < pic[i])
                flag = 0;
            if (ear[i-1] == 0 && lat[i-1] == 2*k-1)
                continue;
            ear[i] = max(ear[i], ear[i - 1] + 1);
            lat[i] = min(lat[i], lat[i - 1] + 1);
            if(ear[i] > lat[i])
                flag = 0;
        }
        if (flag == 1)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
