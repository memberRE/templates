#include <algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct ppp{
    int val, type;
} pic[512];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        int has[2] = {0, 0};
        cin >> n;
        for (int i = 1; i <= n;i++)
            scanf("%d", &pic[i].val);
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &pic[i].type);
            has[pic[i].type] = 1;
        }
        if (has[0]*has[1] == 1)
            cout << "Yes" << endl;
        else
        {
            int flag = 0;
            for (int i = 1; i <= n;i++)
                if(pic[i-1].val > pic[i].val)
                {
                    cout << "No" << endl;
                    flag = 1;
                    break;
                }
            if(!flag)
                cout << "Yes" << endl;
        }
    }
    return 0;
}