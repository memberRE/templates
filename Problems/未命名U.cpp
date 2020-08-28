#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const long long MOD=10000000007;
struct ppp{
	long long v;
	int fa;
	vector <int> son;
}pic[100002];
void push(int node)
{
	pic[node].v+=pic[pic[node].fa].v;
	pic[node].v%=MOD;
	for( int i=0;i<pic[node].son.size();i++)
		push(pic[node].son[i]);
	return ;
}
long long sum(int node)
{
	if(node==1)	return pic[1].v;
	long long ans=pic[node].v;
	ans+=sum(pic[node].fa);
	ans%=MOD;
	return ans;
}
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		pic[i].fa=k;
		pic[k].son.push_back(i);
	}
	pic[1].fa=0;
	pic[0].v=0;
	for(int i=1;i<=n;i++)
		scanf("%lld",&pic[i].v);
	for(int i=1;i<=m;i++)
	{
		int jkl;
		scanf("%d",&jkl);
		if(jkl==1)
			push(1);
		else
		{
			int h;
			scanf("%d",&h);
			printf("%lld\n",sum(h));
		}
	}
	return 0;
}
