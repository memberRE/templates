#include<bits/stdc++.h>
using namespace std;
const int MAX=105;
int pic[4][8];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int jkl;
		scanf("%d",&jkl);
		pic[0][jkl]++;
	}
	for(int i=1;i<=n;i++)
	{
		int jkl;
		scanf("%d",&jkl);
		pic[1][jkl]++;
	}
	for(int i=1;i<=5;i++)
		if(abs(pic[0][i]-pic[1][i])%2)
		{
			cout<<-1;
			return 0;
		}
	int jkl=0,ans=0;
	for(int i=1;i<=5;i++)
	{
		jkl+=(pic[0][i]-pic[1][i])/2;
		if(pic[0][i]-pic[1][i]>0)
			ans+=(pic[0][i]-pic[1][i])/2;
	}
	if(jkl!=0)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}
