#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+20;
int n,m,rd[MAX],ans[MAX];
vector<int> pic[MAX];
priority_queue<int>que;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		pic[b].push_back(a);
		rd[a]++;
	}
	for(int i=1;i<=n;++i)
		if(!rd[i])
			que.push(i);
	int cnt=n;
	while(!que.empty())
	{
		int x=que.top();
		que.pop();
		ans[cnt]=x;
		cnt--;
		for(int i=0;i<pic[x].size();++i)
		{
			rd[pic[x][i]]--;
			if(!rd[pic[x][i]])
				que.push(pic[x][i]);
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}
