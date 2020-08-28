#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 2e5 + 20;
struct SEG{
    int a, b, c;
    void init (int aa,int bb,int cc) {
        a = aa;
        b = bb;
        c = cc;
    }
}pic[MAX];
bool cam (SEG a,SEG b)
{
    return a.a < b.a;
}
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        pic[i].init(x, y, z);
    }
    sort(pic + 1, pic + 1 + n, cam);
    
}