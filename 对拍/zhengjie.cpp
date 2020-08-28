#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

#define gc getchar()
int read()
{
    char ch;
    while((ch=gc)<'0');
    int x=ch-'0';
    while((ch=gc)>='0')x=x*10+ch-'0';
    return x;
}

typedef
__gnu_pbds::
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> 
Tree;

const int N=500005;
Tree T[N];

int n;

void add(int x,int y)
{
    T[x].insert(y);
}
void del(int x,int y)
{
    T[x].erase(y);
}
int qiu(int x,int y)
{
    return T[x].order_of_key(y);
}

int a[N],mx[N*4];
int dy[N];
#define mid (l+r>>1)
#define cl (k*2)
#define cr (cl+1)
int L[N*4],R[N*4];
int Count(int x,int l,int r)
{
    if(r-l<=20)
    {
        int ans=0;
        for(;l<=r;++l)
        if(a[l]==x)++ans;
        return ans;
    }
    return qiu(x,r+1)-qiu(x,l);
}
void up(int k)
{
    int l=L[k],r=R[k];
    if(mx[cl])
    if(Count(mx[cl],l,r)*2>r-l+1) {mx[k]=mx[cl];return ;}
    if(mx[cr])
    if(Count(mx[cr],l,r)*2>r-l+1) {mx[k]=mx[cr];return ;}
    mx[k]=0;
}
void init(int k,int l,int r)
{
    L[k]=l;R[k]=r;
    if(l==r) 
    { 
      dy[l]=k; 
      add(mx[k]=a[l]=read(),l); 
      return ;
    }
    init(cl,l,mid);init(cr,mid+1,r);
    up(k);
}

int ql,qr,ans;
void modify()
{
    int x=read();
    if(a[x]==ans)return ;
    del(a[x],x);add(a[x]=ans,x);
    int k=dy[x];
    mx[k]=ans;
    while(k>>=1)up(k);
}
bool qiu(int k,int l,int r)
{
    if(ql<=l&&qr>=r)
    {
        if(mx[k])
        {
            if(Count(mx[k],ql,qr)*2>qr-ql+1) {ans=mx[k];return 1;}
        }
        return 0;
    }
    if(ql<=mid)if(qiu(cl,l,mid))return 1;
    if(qr>mid)if(qiu(cr,mid+1,r))return 1;
    return 0;
}

int main()
{
	freopen("date.in","r",stdin);
	freopen("zhengjie.out","w",stdout);
    n=read();int m=read();
    init(1,1,n);

    while(m--)
    {
        ql=read();qr=read();

        if(!qiu(1,1,n))ans=read();
        else read();
        printf("%d\n",ans);

        int k=read();
        while(k--) modify();
    }

    if(mx[1]) printf("%d\n",mx[1]);
    else puts("-1");
    fclose(stdin);
    fclose(stdout);
}
