#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+20;
const long long INF=300;
typedef long long ll;

ll read()
{
	ll x=0,flag=1;
	char c=getchar();
	while((c>'9' || c<'0') && c!='-') c=getchar();
	if(c=='-') flag=0,c=getchar();
	while(c<='9' && c>='0') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return flag?x:-x;
}

struct ppp{
	ll size,rnd,num,numsum,val,valsum;
	int ch[2];
}treap[MAX];
struct TREE{
	ll num,cost,heigh;
}pic[MAX],stk[MAX];
int n,tot,root,top;
ll backvalsum[MAX]/*,backsumnum[MAX]*/,ans=9223372036854775800;
bool cam(TREE a,TREE b)
{
	return a.heigh<b.heigh;
}
inline int NEW(TREE A)
{
	tot++;
	int p=tot;
	treap[p].size=1;
	treap[p].ch[0]=treap[p].ch[1]=0;
	treap[p].rnd=rand();
	treap[p].num=treap[p].numsum=A.num;
	treap[p].valsum=treap[p].val=A.num*A.cost;
	return p;
}
void update(int p)
{
	treap[p].size=treap[treap[p].ch[0]].size+treap[treap[p].ch[1]].size+1;
	treap[p].valsum=treap[p].val*treap[p].num+treap[treap[p].ch[0]].valsum+treap[treap[p].ch[1]].valsum;
	treap[p].numsum=treap[p].num+treap[treap[p].ch[0]].numsum+treap[treap[p].ch[1]].numsum;
}
void _init()
{
	TREE A;
	A.cost=-INF;
	A.num=0;
	NEW(A);
	A.cost=INF;
	NEW(A);
	treap[1].ch[1]=2;
	root=1;
	update(1);
}
int merge(int x,int y)//Ð¡¸ù¶Ñ 
{
    if(x==0 or y==0)
        return x+y;
    if(treap[x].rnd<treap[y].rnd)
    {
        treap[x].ch[1]=merge(treap[x].ch[1],y);
        update(x);
        update(treap[x].ch[1]);
        return x;
    }
    else
    {
        treap[y].ch[0]=merge(x,treap[y].ch[0]);
        update(y);
        update(treap[y].ch[0]);
        return y;
    }
}
void split(int now,int &x,int &y,int rank)
{
    if(rank>=treap[now].size)
    {
        x=now,y=0;
        return ;
    }
    if(rank<=0)
    {
        y=now,x=0;
        return ;
    }
    if(rank<=treap[treap[now].ch[0]].size)
    {
        y=now;
        split(treap[now].ch[0],x,treap[now].ch[0],rank);
    }
    else
    {
        x=now;
        split(treap[now].ch[1],treap[now].ch[1],y,rank-treap[treap[now].ch[0]].size-1);
    }
    update(now);
}
void split_val(int now,int val,int &x,int &y)
{
	if(now==0)
	{
		x=0;y=0;
		return ;
	}
	if(treap[now].val<=val)
	{
		x=now;
		split_val(treap[now].ch[1],val,treap[x].ch[1],y);
	}
	else
	{
		y=now;
		split_val(treap[now].ch[0],val,x,treap[y].ch[0]);
	}
	update(now);
}
void insert(TREE A)
{
	int x=0,y=0;
	split_val(root,A.cost,x,y);
	int p=NEW(A);
	root=merge(x,merge(p,y));
}
bool judge(int p,ll k)
{
	int x=0,y=0;
	split(root,x,y,p);
	ll tem=treap[x].numsum;
	root=merge(x,y);
	if(tem<=k)
		return true;
	else
		return false;
}
ll solve(ll k)
{
	if(k<=0)	return 0;
	int l=1,r=treap[root].size-1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(judge(mid,k))
			l=mid+1;
		else
			r=mid;
	}
	int x=0,y=0,z=0;
	split(root,x,y,l);
	split(y,z,y,1);
	ll tem=treap[x].valsum+treap[z].val*k-treap[x].numsum;
	root=merge(x,merge(z,y));
	return tem;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		top=tot=0;
		ans=9223372036854775800;
		_init();
		backvalsum[n+1]=0;
		for(int i=1;i<=n;++i)
			scanf("%lld%lld%lld",&pic[i].heigh,&pic[i].cost,&pic[i].num);
		pic[n+1].heigh=-1;
		sort(pic+1,pic+1+n,cam);
		for(int i=n;i>=1;--i)
		{
			backvalsum[i]=backvalsum[i+1]+pic[i].cost*pic[i].num;
	//		backnumsum[i]=backnumsum[i+1]+pic[i].num;
		}
		if(n<=50000)
		{
			for(int i=1;i<=n+1;++i)
			{
				if(top==0)
					stk[top++]=pic[i];
				else if(pic[i].heigh==stk[top-1].heigh)
					stk[top++]=pic[i];
				else
				{
					ll numsum=0,temans=0;
					for(int j=0;j<top;j++)
						numsum+=stk[j].num;
					temans+=backvalsum[i];
					temans+=solve(treap[root].numsum-numsum+1);
					ans=min(ans,temans);
					while(top)
					{
						top--;
						insert(stk[top]);
					}
				}
			}
			printf("%lld\n",ans);
		}
		else
		{
			for(int i=1;i<=n/4;++i)
				insert(pic[i]);
			for(int i=n/4;i<=(n*3)/4;++i)
			{
				if(top==0)
					stk[top++]=pic[i];
				else if(pic[i].heigh==stk[top-1].heigh)
					stk[top++]=pic[i];
				else
				{
					ll numsum=0,temans=0;
					for(int j=0;j<top;j++)
						numsum+=stk[j].num;
					temans+=backvalsum[i];
					temans+=solve(treap[root].numsum-numsum+1);
					ans=min(ans,temans);
					while(top)
					{
						top--;
						insert(stk[top]);
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
}
