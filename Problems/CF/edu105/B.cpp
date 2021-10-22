#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
using namespace std;
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
    int t = read();
    while(t--){
        int n = read(),u= read(),r= read(),d= read(),l= read();
        if (n == 1){
            if (u+r+d+l == 0 or u+r+d+l == 4){
                puts("YES");
                continue;
            }
            else{
                puts("NO");
                continue;
            }
        }
        if ((u == 0 or d == 0) and (l == n or r == n)){
            puts("NO");
            continue;
        }
        if ((l == 0 or r == 0) and (u == n or d == n)){
            puts("NO");
            continue;
        }
        int flag = 1;
        for(int i = 1;i<=4;i++){
            if (u == 0){
                int tem = 0;
                if (l == n-1)
                    tem++;
                if (r == n-1)
                    tem++;
                if (tem > d){
                    puts("NO");
                    flag = -1;
                    break;
                }
            }
            if (u == 1){
                int tem = 0;
                if (l == n){
                    tem++;
                    if (r == n){
                        puts("NO");
                        flag = -1;
                        break;

                    }
                    if (r == n-1)
                        tem++;
                    if (tem > d){
                        puts("NO");
                        flag = -1;
                        break;

                    }
                }
                tem = 0;
                swap(l,r);
                if (l == n){
                    tem++;
                    if (r == n){
                        puts("NO");
                        flag = -1;
                        break;

                    }
                    if (r == n-1)
                        tem++;
                    if (tem > d){
                        puts("NO");
                        flag = -1;
                        break;
                    }
                }
                swap(l,r);
                if (d == 0)
                {
                    puts("NO");
                    flag = -1;
                    break;
                }
            }
            int uu = u,ll = l,dd = d,rr = r;
            u = ll;
            l = dd;
            d = rr;
            r = uu;
        }
        if (flag != -1){
            puts("YES");
        }

    }
    return 0;
}
