#include<bits/stdc++.h>
using namespace std;
const int MAX=4e4;
struct SEG{
	int x0,x1;
	double y0,y1;
};
struct TREE{
	int midseg;
	SEG seg; 
}tree[MAX<<2];
double get_k(SEG jkl)
{
	int x0=jkl.x0,x1=jkl.x1;
	double y0=jkl.y0,y1=jkl.y1;
	return (double)(y1-y0)/(1.0*x1-1.0*x0);
}
void add(int node,SEG segment,int id,int L,int R)
{
	if(L==R)  //´ËÊ±y0==y1 
	{
		if(tree[node].midseg==0 or tree[node].seg.y0<segment.y0)
		{
			tree[node].midseg=id;
			tree[node].seg=segment;
		}
		return ;
	}
	
	if(segment.x0==L and segment.x1==R)
		if(tree[node].midseg==0 or (tree[node].seg.y0<segment.y0 and tree[node].seg.y1<segment.y1))
		{
			tree[node].midseg=id;
			tree[node].seg=segment;
			return ;
		}
		else
		{
			if(tree[node].seg.y0>=segment.y0 and tree[node].seg.y1>=segment.y1)
				return ;
			
			double ymidold,ymidnew;
			int mid=(L+R)>>1;
			if(segment.x0==segment.x1)
				ymidnew=segment.y0;
			else
			{
				double k=get_k(segment);
				ymidnew=segment.y0+k*(mid*1.0-segment.x0*1.0);
			}
			if(tree[node].seg.x0==tree[node].seg.x1)
				ymidold=tree[node].seg.y0;
			else
			{
				double k=get_k(tree[node].seg);
				ymidnew=tree[node].seg.y0+k*(mid*1.0-tree[node].seg.x0*1.0);
			}
			
			if(ymidold<ymidnew)
			{
				tree[node].midseg=id;
				tree[node].seg=segment;
				
			}
		}
}
int n,tot;
int main()
{
	scanf("%d",&n);
	int lasans=0;
	for(int i=1;i<=n;i++)
	{
		int op,k;
		scanf("%d",&op);
		if(op==0)
		{
			scanf("%d",&k);
			k=(k+lastans-1)%39989+1;
			//-------- lose print
			// renew the lasans
		}
		else if(op==1)
		{
			int x0,y0,x1,y1;
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			x0=(x0+lastans-1)%39989+1;
			y0=(y0+lastans-1)%1e9+1;
			x1=(x1+lastans-1)%39989+1;
			y1=(y1+lastans-1)%1e9+1;
			if(x0>x1)
				swap(x0,x1),swap(y0,y1);
			SEG jkl=(SEG){x0,x1,y0,y1};
			add(1,jkl,++tot,1,n);
		}
	}
}
