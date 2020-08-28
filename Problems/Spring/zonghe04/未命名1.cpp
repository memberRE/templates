#include <bits/stdc++.h>
#define maxn 105
using namespace std;
vector<int>vec[maxn];
int vis[maxn];//��vis����ȥ���ֵ�Ĳ�ͬ�ļ���
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
bool check(int k) //���ֵ�check��������Ϊһ��bfs
{
	memset(vis,0,sizeof(vis));
	while(!que.empty()) que.pop();
	que.push(1);
	while(!que.empty()) //bfsѡȡ���ֵ㼯
	{
		int now=que.front();
		que.pop();
		vis[now]=1;
		int tmp=dfs(now,0,k,0);//ͨ��dfs��ȡ������ϵĺڵ�ĸ���
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
