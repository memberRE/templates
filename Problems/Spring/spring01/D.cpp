#include<bits/stdc++.h>
using namespace std;
const int MAX=1009;
const int SIGN=100000000;
int pic[MAX][MAX];
struct ppp{
	int val,id;
}heap[1000005];
int noww[MAX];
int K,cnt;
void update(int k)
{
	while(k>1)
	{
		if(heap[k].val<heap[k>>1].val)
			swap(heap[k].val,heap[k>>1].val);
		k>>=1;
	}
}
void insert(int k,int id)
{
	cnt++;
	heap[cnt].val=k;
	heap[cnt].id=id;
	update(cnt);
}
void down(int k)
{
	while((k<<1)<=cnt)
	{
		int son=k<<1;
		if(son+1<=cnt and heap[son+1].val<heap[son].val)	son++;
		if(heap[k].val>heap[son].val)	swap(heap[k],heap[son]);
		else break;
		k=son;
	}
}
void del()
{
	if(cnt==0)	return ;
	heap[1]=heap[cnt];
	cnt--;
	if(cnt==0)	return ;
	down(1);
}
int main()
{
	scanf("%d",&K);
	for(int i=1;i<=K;i++)
	{
		for(int j=1;j<=K;j++)
			scanf("%d",&pic[i][j]);
		sort(pic[i]+1,pic[i]+1+K);
		noww[i]=1;
	}
	int ans=0;
	for(int i=1;i<=K;i++)
	{
		ans+=pic[i][1];
		if(K>=2)
			insert(pic[i][2]-pic[i][1],i);
	}
	printf("%d ",ans);
	for(int i=2;i<=K;i++)
	{
		ppp tem=heap[1];
		int id=tem.id;
		ans+=tem.val;
		printf("%d ",ans);
		del();
		if(noww[id]<K)
		{
			noww[id]++;
			insert(pic[noww[id]]-pic[noww[id]-1],id);
		}
	}
	return 0;
}

