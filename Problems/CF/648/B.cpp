#include <algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct ppp{
    int val, type;
} pic[512];
void SWAPP(int i,int j)
{
    swap(pic[i].val, pic[j].val);
    swap(pic[i].type, pic[j].type);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++)
            scanf("%d", &pic[i].val);
        for (int i = 1; i <= n;i++)
            scanf("%d", &pic[i].type);
        int flag = 1;
        for (int i = n; i >= 2;i--)
        {
            if(flag == 0)
                break;
            int temid = 1;
            for (int j = 2; j <= i;j++)
            {
                if(pic[j].val > pic[temid].val)
                    temid = j;
                else if (pic[j].val == pic[temid].val)
                {
                    if (j != i && pic[j].type != pic[i].type)
                        temid = j;
                }
            }// find the max element
            if (temid == i)
                continue;
            if(pic[temid].type != pic[i].type)
                SWAPP(temid, i);
            else
            {
                for (int j = 1; j < i;j++)
                    if (pic[j].type != pic[i].type)
                        SWAPP(i, j);
                if(pic[temid].type != pic[i].type)
                {
                    SWAPP(temid, i);
                    continue;
                }
                for (int j = n; j > i;j--)
                {
                    if(pic[j].type!=pic[i].type)
                    {
                        SWAPP(temid, j);
                        SWAPP(i, temid);
                        SWAPP(j, i);
                        continue;
                    }
                }
                for (int j = 1; j <= n;j++)
                    if(pic[j-1].val>pic[j].val)
                    {
                        cout << "No" << endl;
                        flag = 0;
                    }
                if(flag)
                {
                    cout << "Yes" << endl;
                    flag = 0;
                }
            }
        }
        if(flag!=0)
        {
            for (int j = 1; j <= n;j++)
                if(pic[j-1].val>pic[j].val)
                {
                    cout << "No" << endl;
                    flag = 0;
                }
            if(flag)
            {
                cout << "Yes" << endl;
                flag = 0;
            }
        }
    }
}