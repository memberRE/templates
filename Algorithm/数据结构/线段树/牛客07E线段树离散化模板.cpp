#include<bits/stdc++.h>
#define ls (node<<1)
#define rs ((node<<1)|1)
#define mid ((L+R)>>1)
using namespace std;
typedef long long ll;
const int MAX=4e5+20;
struct ppp{
    int l,r,lazy;
    ll sum;
}tree[MAX<<3];
struct SEG{
    int l,r;
}segment[MAX];
int tem[MAX<<1];
int n,a1,a2,b1,b2,c1,c2,x1,x2,y2,m1,m2,N,Y1;
void discrete()
{
    sort(tem+1,tem+1+n*2);
    N=unique(tem+1,tem+1+n*2)-tem-1;???加一还是加二？？？
}
void build(int node,int L,int R)
{
    tree[node].l=L;
    tree[node].r=R;
    tree[node].sum=0;
    tree[node].lazy=0;
    if(L+1==R)  return ;
    build(ls,L,mid);
    build(rs,mid,R);    对于离散化之后建线段树，由于不能有单独的点，所以此处mid不加一，区间是左开右闭区间
}
void pushdown(int node)
{
    if(tree[node].l+1==tree[node].r)    return ;
    tree[ls].sum+=(ll)(tem[tree[ls].r]-tem[tree[ls].l])*(ll)tree[node].lazy;//开区间，此处不+1；
    tree[rs].sum+=(ll)(tem[tree[rs].r]-tem[tree[rs].l])*(ll)tree[node].lazy;
    tree[ls].lazy+=tree[node].lazy;
    tree[rs].lazy+=tree[node].lazy;
    tree[node].lazy=0;
}
void _insert(int node,int l,int r,int L,int R)
{
    tree[node].sum+=(ll)(tem[r]-tem[l]);
    if(tree[node].lazy) pushdown(node);
    if(tree[node].l==l and tree[node].r==r)
    {
        tree[node].lazy++;
        return ;
    }
    if(r<=tree[ls].r)
        _insert(ls,l,r,L,mid);
    else if(l>=tree[rs].l)
        _insert(rs,l,r,mid,R);
    else
        _insert(ls,l,mid,L,mid),_insert(rs,mid,r,mid,R);
}
void query(int node,ll rank)
{
    if(tree[node].l+1==tree[node].r)
    {
        ll tmp=tree[node].sum/(tem[tree[node].r]-tem[tree[node].l]);
        printf("%lld\n",tem[tree[node].l]+(rank-1)/tmp);
        return ;
    }
    if(tree[node].lazy) pushdown(node);
    if(tree[ls].sum<rank)
        query(rs,rank-tree[ls].sum);
    else query(ls,rank);
}
int main()
{
    scanf("%d",&n);
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&x1,&x2,&a1,&b1,&c1,&m1,&Y1,&y2,&a2,&b2,&c2,&m2);
    for(int i=1;i<=n;i++)
    {
        if(i==1)
            segment[i].l=min(x1,Y1)+1,segment[i].r=max(x1,Y1)+1;
        else if(i==2)
            segment[i].l=min(x2,y2)+1,segment[i].r=max(x2,y2)+1;
        else
        {
            x1=(1ll*a1*x2+1ll*b1*x1+c1)%m1;
            Y1=(1ll*a2*y2+1ll*b2*Y1+c2)%m2;
            swap(x1,x2);
            swap(Y1,y2);
            segment[i].l=min(x2,y2)+1,segment[i].r=max(x2,y2)+1;
        }
        tem[i<<1]=segment[i].l;
        tem[(i<<1)-1]=segment[i].r+1;右边换成开区间
    }
    discrete();
    build(1,1,N);
    for(int i=1;i<=n;i++)
    {
        int L=lower_bound(tem+1,tem+1+N,segment[i].l)-tem;
        int R=lower_bound(tem+1,tem+1+N,segment[i].r+1)-tem;
        _insert(1,L,R,1,N);
        query(1,(tree[1].sum+1)>>1);
    }
    return 0;
}
