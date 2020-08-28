#include <algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 1e5 + 50;
int pic[MAX];
int ans[MAX], top;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        top = 0;
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &pic[i]);
        }
        ans[top++] = pic[1];
        //int dir = pic[2] - pic[1];
        int dir = 1;
        for (int i = 2; i < n;i++)
        {
            if ((pic[dir + 1] > pic[dir]) ^ (pic[i + 1] < pic[i]))
                continue;
            /*if((pic[i] - pic[i-1])*dir < 0)
            {
                ans[top++] = pic[i-1];
                dir = pic[i] - pic[i - 1];
            }*/
            dir = i;
            ans[top++] = pic[i];
        }
        ans[top++] = pic[n];
        printf("%d\n", top);
        for (int i = 0; i < top;i++)
        {
            printf("%d ", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}