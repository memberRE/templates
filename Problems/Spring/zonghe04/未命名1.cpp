#include <bits/stdc++.h>
#define maxn 105
using namespace std;
vector<int>vec[maxn];
int vis[maxn];//用vis数组去区分点的不同的集合
int a[maxn];
queue<int>que;
int n,m;
int ans=0;
int dfs(int now,int fa,int all,int dis)
{
	int res=a[now];
	if(dis==all) return res;
	for(auto &it:vec[now])
	{
		if(!vis[it]||it==fa) continue;
		res+=dfs(it,now,all,dis+1);
	}
	return res;
}
bool check(int k) //二分的check，本质上为一个bfs
{
	memset(vis,0,sizeof(vis));
	while(!que.empty()) que.pop();
	que.push(1);
	while(!que.empty()) //bfs选取部分点集
	{
		int now=que.front();
		que.pop();
		vis[now]=1;
		int tmp=dfs(now,0,k,0);//通过dfs获取这个集合的黑点的个数
		if(tmp>=m) return 1;
		for(auto &it:vec[now])
		{
			if(vis[it]) continue;
			que.push(it);
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) 
		scanf("%d",&a[i]);
	for(int i=0; i<n-1; i++)
	{
		int from,to;
		scanf("%d%d",&from,&to);
		vec[from].push_back(to);
		vec[to].push_back(from);
	}
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
		//cout<<l<<" "<<r<<endl;
	}
	cout<<r<<endl;
}
