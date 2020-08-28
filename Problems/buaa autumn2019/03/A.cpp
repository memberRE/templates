#include<bits/stdc++.h>
using namespace std;
int wal[1024],game[1024];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>game[i];
	for(int j=1;j<=m;j++)
		cin>>wal[j];
	int ans=0,mon=1;
	for(int i=1;i<=n;i++)
	{
		if(mon==m+1)
			break;
		if(game[i]<=wal[mon])
			ans++,mon++;
	}
	cout<<ans;
}
