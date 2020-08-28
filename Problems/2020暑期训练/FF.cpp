#include <iostream>
#include <cstdio>
#include<algorithm>
#include <queue>
using namespace std;
const int MAX = 2e4 + 20;
int vztd[MAX],pic[MAX];
queue<int> que;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
int main()
{
    int n = read(), tar = read(),gcdd = 1;
    int maxx = -1, maxx_var = -1;
    for (int i = 1; i <= n;i++)
    {
        pic[i] = read();
        if (maxx < pic[i])
            maxx = pic[i], maxx_var = i;
        gcdd = (i == 1) ? pic[i] : __gcd(gcdd, pic[i]);
    }
    if (tar % gcdd == 0 || tar > maxx)
    {
        printf("-1");
        return 0;
    }
    if(tar == maxx)
    {
        printf("1\n1 %d", maxx_var);
        return 0;
    }
    que.push(0);
    while(!que.empty())
    {
        
    }
}
