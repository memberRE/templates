#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);
#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> P;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
 
const int maxn=1e5+5,inf=1e9;
char s[maxn];
int a[maxn],n,ans;
 
int cmp(int l1,int r1,int l2,int r2)
{
    int flag=0;
    if(r1>n || r2>n || l1>r1 || l2>r2) return inf;
    if(a[l1]==0 || a[l2]==0) return inf;
    if(abs((r1-l1)-(r2-l2))>1) return inf;
    if(abs((r1-l1)-(r2-l2))==1)
    {
        if(r1-l1<r2-l2) swap(l1,l2),swap(r1,r2),flag=1;
        if(a[l1]!=1) return inf;
        if(a[r1]>=a[r2]) return inf;
        for(int i=l1+1;i<r1;i++) if(a[i]!=0) return inf;
        for(int i=l2;i<r2;i++) if(a[i]!=9) return inf;
        int ret=a[r1]+10-a[r2];
        return flag?-ret:ret;
    }
    else    // len>=2
    {
        int k=1;
        while(k<=r1-l1+1 && a[l1+k-1]==a[l2+k-1]) k++;
        if(k>r1-l1+1) return 0;
        if(k==r1-l1+1)
        {
            return a[r1]-a[r2];
        }
        int dif=abs(a[l1+k-1]-a[l2+k-1]);
        if(dif>1 && dif<9) return inf;
        if(dif==1)
        {
            if(a[l1+k-1]<a[l2+k-1]) swap(l1,l2),swap(r1,r2),flag=1;
        }
        else if(dif==9 && a[l1+k-1]==9) swap(l1,l2),swap(r1,r2),flag=1;
        for(int i=l1+k;i<r1;i++) if(a[i]!=0) return inf;
        for(int i=l2+k;i<r2;i++) if(a[i]!=9) return inf;
        int ret=a[r1]+10-a[r2];
        return flag?-ret:ret;
    }
}
 
void solve(int len)
{
    int l1=1,r1=len,l2=1,r2=len;
    int update=0;
    VI L,R;
    //L.pb(l1); R.pb(r1);
    while(r1+len-1<=n)
    {
        if(len==1 && r1+len>n) break;
        int minx=10,r;
        if(r1+len+1<=n && (r=abs(cmp(l1,r1,r1+1,r1+len+1)))<minx) minx=r,l2=r1+1,r2=r1+len+1;
        if(r1+len<=n && (r=abs(cmp(l1,r1,r1+1,r1+len)))<minx) minx=r,l2=r1+1,r2=r1+len;
        if(len>1 && r1+len-1<=n && (r=abs(cmp(l1,r1,r1+1,r1+len-1)))<minx) minx=r,l2=r1+1,r2=r1+len-1;
        if(minx>=ans) return;
        update=max(update,minx);
        l1=l2; r1=r2;
        L.pb(l1); R.pb(r1);
    }
    if(r1<n)
    {
        l2=r1+1,r2=n;
        update=max(update,abs(cmp(l1,r1,l2,r2)));
        L.pb(l2); R.pb(r2);
    }
    if(update>=ans) return;
 
    int minL=1,minR=len,maxL=1,maxR=len;
    for(int i=0;i<L.size();i++)
    {
        int l=L[i],r=R[i],re;
        if((re=cmp(l,r,minL,minR))<0) minL=l,minR=r;
        if(re>=ans) return;
        if((re=cmp(l,r,maxL,maxR))>0) maxL=l,maxR=r;
        if(re>=ans) return;
    }
    //cout<<minL<<' '<<minR<<endl<<maxL<<' '<<maxR<<endl;
    update=max(update,abs(cmp(minL,minR,maxL,maxR)));
    ans=min(ans,update);
}
 
void solve1()
{
    int maxx=0,minx=100;
    for(int i=1;i<=n;i++)
    {
        int x;
        if(a[i]==1 && i<n) x=a[i]*10+a[++i];
        else x=a[i];
        maxx=max(maxx,x);
        minx=min(minx,x);
    }
    ans=min(ans,maxx-minx);
}
 
int main()
{
    int T=read();
    while(T--)
    {
        //n=read();
        int maxx=0,minx=10;
        scanf("%s",s+1);
        n = strlen(s+1);
        REP(i,1,n)
        {
            a[i]=s[i]-'0';
            maxx=max(maxx,a[i]);
            minx=min(minx,a[i]);
        }
        ans=maxx-minx;
        if(!ans || a[1]==0) {printf("%d\n",ans); continue;}
 
        int maxl=0,len=0;
        REP(i,1,n)
        {
            if(a[i]==0) len++;
            else maxl=max(maxl,len),len=0;
        }
        maxl=max(maxl,len);
 
        solve1();
        if(!ans) {printf("%d\n",ans); continue;}
 
        for(int i=max(maxl,1);i<=(n+1)/2;i++)
        {
            solve(i);
            if(!ans) {break;}
        }
        //printf("hhh:   %d\n",cmp(1,3,4,5));
        printf("%d\n",ans);
    }
 
    return 0;
}
