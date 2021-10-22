#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
using namespace std;
const int MAX = 2e5+20;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
int ZA[MAX],ZB[MAX],FA[MAX],FB[MAX];
int cntZA,cntFA,cntZB,cntFB;
int summZ[MAX],summF[MAX];
int flagZ[MAX],flagF[MAX];
int lengthZ[MAX],lengthF[MAX];
int main()
{
    int t = read();
    while(t--)
    {
        int n = read(),m = read();
        cntFA = 0,cntZA = 0;
        cntZB = 0,cntFB = 0;
        for(int i= 1;i<=n;i++){
            int tem = read();
            if (tem > 0)
                ZA[++cntZA] = tem;
            else
                FA[++cntFA] = -tem;
        }
        for(int i= 1;i<=m;i++){
            int tem = read();
            if (tem > 0)
                ZB[++cntZB] = tem;
            else
                FB[++cntFB] = -tem;
        }
        //label:temm_label;
        sort(ZA+1,ZA+1+cntZA);
        sort(ZB+1,ZB+1+cntZB);
        int pot_ZA = 1;
        for(int i = 1;i<=cntZB;i++)
            lengthZ[i] = summZ[i] = flagZ[i] = 0;
        for(int i = 1;i<=cntZB and pot_ZA<=cntZA;i++)
        {
            while(ZA[pot_ZA]<ZB[i] and pot_ZA<cntZA)
                pot_ZA++;
            if (ZA[pot_ZA] == ZB[i])
                flagZ[i] = 1;
            lengthZ[i] = pot_ZA; // 有几个
            if (ZA[pot_ZA] > ZB[i])
                lengthZ[i]--;
        }
        for(int i = cntZB-1;i>=1;i--)
            summZ[i] = summZ[i+1] + flagZ[i];
        int ans = 0;
        for(int i = 1;i<=cntZB;i++){
            int len = lengthZ[i];
            if (len == 0 || len == 1) {
                ans = max(ans,summZ[i+1]+len);
            }
            int goal = ZB[i] - len;//小于等于goal的最后一个数字
            int l = 0,r = i;
            while(l<r){ //ans = l-1 or r
                int mid = (l+r)>>1;
                if (ZB[mid]>goal)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            int index = r;
            if (i == 3)
                printf("    %d    \n",len);
            ans = max(ans,summZ[i+1]+(i-r));
        }

        sort(FA+1,FA+1+cntFA);
        sort(FB+1,FB+1+cntFB);
        int pot_FA = 1;
        for(int i = 1;i<=cntFB;i++)
            lengthF[i] = summF[i] = flagF[i] = 0;
        for(int i = 1;i<=cntFB and pot_FA<=cntFA;i++)
        {
            while(FA[pot_FA]<FB[i] and pot_FA<cntFA)
                pot_FA++;
            if (FA[pot_FA] == FB[i])
                flagF[i] = 1;
            lengthF[i] = pot_FA - (1-flagF[i]); // 有几个
        }
        for(int i = cntFB-1;i>=1;i--)
            summF[i] = summF[i+1] + flagF[i];
        int ansF = 0;
        for(int i = 1;i<=cntFB;i++){
            int len = lengthF[i];
            if (len == 0 || len == 1) {
                ansF = max(ansF,summF[i+1]+len);
            }
            int goal = FB[i] - len;//小于等于goal的最后一个数字
            int l = 0,r = i;
            while(l<r){ //ans = l-1 or r
                int mid = (l+r)>>1;
                if (FB[mid]>goal)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            int index = r;
            ansF = max(ansF,summF[i+1]+(i-r));
        }
        int realans = ans + ansF;
        printf("%d\n",realans);
    }
    return 0;
}
