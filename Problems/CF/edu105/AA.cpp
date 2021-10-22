#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
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
char S[1000];
int main()
{
    int t = read();
    while(t--){
        //int n = read();
        scanf("%s",S);
        int len = strlen(S);
        char lef = S[0];
        char rit = S[len-1];
        int stktop = 0;
        int flag = 0;
        if (lef == rit){
            puts("NO");
            continue;
        }
        for(int i = 0;i<len;i++) // lef
        {
            if (S[i] != rit) //
                stktop++;
            else
                stktop--;
            if (stktop < 0)
            {
                flag = -1;
                break;
            }
        }
        if (flag == -1 || stktop > 0)
        {
            flag = 0,stktop = 0;
            for(int i = 0;i<len;i++) // rit
            {
                if (S[i] != lef) //
                    stktop--;
                else
                    stktop++;
                if (stktop < 0)
                {
                    flag = -1;
                    break;
                }
            }
            if (flag == -1 || stktop > 0){
                puts("NO");
                continue;
            }
            else {
                puts("YES");
                continue;
            }
        }
        else {
            puts("YES");
            continue;
        }
    }
    return 0;
}
