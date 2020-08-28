#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct pppp{
	int x1,x2,y1,y2;
}pic[102];
vector <int> m[102];
bool vztd[103];
int ans=0;
bool cha(int a,int b)
{
	int x=pic[b].x1,y=pic[b].y2;
	//cout<<x<<" "<<y<<endl;
	if(x>=pic[a].x1 and x<=pic[a].x2 and y>=pic[a].y1 and y<=pic[a].y2)
		return true;
	return false;
}
void dfs(int node)
{
	ans++;
	vztd[node]=1;
	for(int i=0;i<m[node].size();i++)
	{
		if(!vztd[m[node][i]])
		dfs(m[node][i]);
	}
}
int main()
{
	int n,x1,y1,x2,y2,x,y;
	cin>>n;
	memset(vztd,0,sizeof(vztd));
	for(int i=1;i<=n;i++)
	{
		cin>>pic[i].x1>>pic[i].y1>>pic[i].x2>>pic[i].y2;
		for(int j=1;j<i;j++)
			if(cha(i,j))
			{
				m[j].push_back(i);
			//	cout<<"sadas"<<endl;
				}
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
