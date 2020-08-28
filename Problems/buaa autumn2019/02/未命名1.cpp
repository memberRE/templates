#include<bits/stdc++.h>
using namespace std;
int pic[22][22],vztd[22][22];
int n,m,xb,yb,xe,ye,ans;
void dfs(int x,int y)
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(pic[i][j])
					cout<<'5'<<' ';
				else
					cout<<vztd[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	//	system("pause");
	if(x==xe and y==ye)
	{
		
		ans++;
		return ;
	}
	vztd[x][y]=1;
	if(!pic[x+1][y] and !vztd[x+1][y] and x+1<n)
		dfs(x+1,y);
	if(!pic[x][y+1] and !vztd[x][y+1] and y+1<m)
		dfs(x,y+1);
	if(!pic[x][y-1] and !vztd[x][y-1] and y-1>=0)
		dfs(x,y-1);
	if(!pic[x-1][y] and !vztd[x-1][y] and x-1>=0)
		dfs(x-1,y);
	vztd[x][y]=0;
	return;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>pic[i][j];
	cin>>xb>>yb>>xe>>ye;
	xe--;
	ye--;
	xb--;
	yb--;
	dfs(xb,yb);
	cout<<ans;
}
4
5
0
1
0
0
0
1
0
0
1
0
0
0
1
0
0
0
0
0
0
1
3
1
2
5

