#include <algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int row[64], cla[64];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        memset(row, 0, sizeof(row));
        memset(cla, 0, sizeof(cla));
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= m;j++)
            {
                int tem;
                cin >> tem;
                if(tem)
                {
                    row[i] = 1;
                    cla[j] = 1;
                }
            }
        int tem = 0,ans = 0;
        for (int i = 1; i <= n;i++)
        {
            if(row[i] == 0)
                tem++;
        }
        ans = tem;
        tem = 0;
        for (int i = 1; i <= m;i++)
        {
            if(cla[i] == 0)
                tem++;
        }
        ans = min(ans, tem);
        if(ans&1) {
            cout << "Ashish" << endl;
        }
        else
            cout << "Vivek"<<endl;
    }
    return 0;
}