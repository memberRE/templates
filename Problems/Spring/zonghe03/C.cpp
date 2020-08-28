#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int pic[200050];
int n,k;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&pic[i]);
		int ans,maxx=0x4fffffff;
		for(int i=1;i<=n-k;i++)
		{
			if(((pic[i+k]-pic[i]+1)>>1)<maxx)
			{
				maxx=(pic[i+k]-pic[i]+1)>>1;
				ans=(pic[i]+pic[i+k])>>1;
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
