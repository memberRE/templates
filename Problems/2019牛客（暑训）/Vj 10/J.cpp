#include<bits/stdc++.h>
using namespace std;
const int MAX=1000400;
struct ppp{
	int son[2],sig;
}trie[MAX*32];
int n,pic[1024];
int tot,root=1;
int maxx=-1;
void creat_trie(int x,int sig)
{
	int noww=root;
	int x1=sig/10000,x2=sig%10000;//x1<x2
	for(int i=30;i>=0;i--)
	{
		int u=x&(1<<i);
		if(u!=0)	u=1;
		if(!trie[noww].son[u])
			trie[noww].son[u]=tot++;
		noww=trie[noww].son[u];
		if(trie[noww].sig==-1)
			continue;
		if(trie[noww].sig==0)
			trie[noww].sig=sig;
		else
		{
			int tem=trie[noww].sig/10000;
			int jkl=trie[noww].sig%10000;
			if(tem==x1 or tem==x2)
				trie[noww].sig=tem;
			else if(jkl==x1 or jkl==x2)
				trie[noww].sig=jkl;
			else
				trie[noww].sig=-1;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<=tot;i++)
			trie[i].sig=trie[i].son[0]=trie[i].son[1]=0;
		maxx=-1;
		root=1;
		tot=2;
		//memset(trie,0,sizeof(trie));
		for(int i=1;i<=n;i++)
			scanf("%d",&pic[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;++j)
				creat_trie(pic[i]+pic[j],i*10000+j);
		for(int j=1;j<=n;j++)
		{
			int noww=root,ans=0,x=pic[j];
			for(int i=30;i>=0;i--)
			{
				int k=x&(1<<i);
				if(k!=0)	k=1;
				k^=1;
				ans<<=1;
				if(trie[noww].son[k] and trie[trie[noww].son[k]].sig/10000!=j and trie[trie[noww].son[k]].sig%10000!=j)
				{
					noww=trie[noww].son[k];
					ans|=1;
				}
				else
					noww=trie[noww].son[k^1];
			}
			maxx=max(maxx,ans);
		}
		printf("%d\n",maxx);
	}
	
	return 0;
}
