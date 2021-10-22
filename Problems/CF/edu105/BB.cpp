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
        int flag = 0;
        for(int lud = 0;lud<=1;lud++)
            for(int ldd = 0;ldd<=1;ldd++)
                for(int rud = 0;rud<=1;rud++)
                    for(int rdd = 0;rdd<=1;rdd++){
                        if (u >= lud+rud and u <= lud+rud+n-2 and d >= ldd+rdd and d <= ldd+rdd +n-2 and l >= lud+ldd and l <= lud+ldd+n-2 and r >= rud+rdd and r <= rud+rdd+n-2)
                            flag = 1;
                    }
        if (flag){
            puts("YES");
        }
        else
            puts("NO");
    }
    return 0;
}
