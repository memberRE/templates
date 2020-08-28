#include<bits/stdc++.h>
using namespace std;
int pic[22];
int ans[22];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&pic[i]);
	for(int i=1;i<=m;i++)
	{
		int jkl;
		scanf("%d",&jkl);
		ans[jkl]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[pic[i]])	
			printf("%d ",pic[i]);
	}
	return 0;
}
