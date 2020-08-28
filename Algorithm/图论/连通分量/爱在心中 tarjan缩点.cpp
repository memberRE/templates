#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
vector<int> pic[1003],scc[1003],sccmem[1003],ans;
int sccno[1003],dfn[1003],low[1003],id=1,cnt,sccsize[1003],n,m,num;
stack<int> s;
void tarjan(int u)
{
	dfn[u]=low[u]=++id;
	s.push(u);
	for(int i=0;i<pic[u].size();i++)
	{
		int v=pic[u][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
		if(!sccno[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		cnt++;
		num++;
		int kl=0;
		for(;;kl++)
		{
			int x=s.top();
			s.pop();
			sccsize[cnt]++;
			sccmem[cnt].push_back(x);
			sccno[x]=cnt;
			if(x==u)
			break;
		}
		if(kl<=0)
		num--;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		pic[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	cout<<num<<endl;
	for(int i=1;i<=n;i++)
		for(int j=0;j<pic[i].size();j++)
		{
			int v=pic[i][j];
			if(sccno[i]!=sccno[v])
			scc[sccno[i]].push_back(sccno[v]);
		}
	bool biao=1,kll=0;
	for(int i=1;i<=cnt;i++)
	{
		if(!scc[i].size() and sccsize[i]>1)
		{
			if(kll)
			{
				cout<<-1<<endl;
				return 0;
			}
			biao=0;
			sort(sccmem[i].begin(),sccmem[i].end());
			for(int j=0;j<sccmem[i].size();j++)
				ans.push_back(sccmem[i][j]);
			kll=1;
		}
	}
	if(biao) {
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}