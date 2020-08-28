#include<iostream>
#include <cstdio>
#include <algorithm>
#include<cmath>
using namespace std;
const int MAX = 2e5 + 20;
int pic[MAX];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int flag = 0,pos = -1;
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &pic[i]);
            if(pic[i]!=i && flag == 0)
                flag = 1,pos = i;
        }
        if(flag == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            int posend = 0;
            for (int i = n; i >= 1;i--)
                if(pic[i]!=i)
                {
                    posend = i;
                    break;
                }
            for (int i = pos; i <= posend;i++)
            {
                if(pic[i] == i)
                {
                    flag = 114514;
                    break;
                }
            }
            if(flag == 114514)
            {
                cout<<2<<endl;
            }
            else
                cout << 1 << endl;
        }
    }
    return 0;
}