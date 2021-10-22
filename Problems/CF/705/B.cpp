#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
int relf[10] = {0,1,5,-1,-1,2,-1,-1,8,-1};
int HH,MM;
inline bool check(int h,int m){
    int nexH = 0,nexM = 0;
    int j1 = m%10;
    int j2 = m/10;
    if (relf[j1] == -1 || relf[j2] == -1)
        return false;
    nexH = relf[j1]*10+relf[j2];
    j1 = h%10;
    j2 = h/10;
    if (relf[j1] == -1 || relf[j2] == -1)
        return false;
    nexM = relf[j1]*10+relf[j2];
    if (nexH < HH and nexM < MM)
        return true;
    return false;

}
int main()
{
    int t = read();
    while(t--)
    {
        HH = read(),MM = read();
        int h,m;
        scanf("%d:%d",&h,&m);
        while(1){
            if (check(h,m)){
                printf("%02d:%02d\n",h,m);
                break;
            }
            m++;
            if (m/MM > 0){
                m = 0;
                h++;
                if (h/HH > 0)
                    h = 0;
            }
        }
    }
    return 0;
}
