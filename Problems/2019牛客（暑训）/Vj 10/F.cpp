#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+20;
int pic[MAX],dp1[MAX],dp2[MAX];//1ÏÂ½µ£¬£¬£¬2ÉÏÉý 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&pic[i]);
			dp1[i]=dp2[i]=1;
			if(i==1)
				continue;
			if(pic[i-1]>=pic[i])
				dp1[i]=dp1[i-1]+1;
			if(pic[i-1]<=pic[i])
				dp2[i]=dp2[i-1]+1;
			if(i==2)
				continue;
			else
			{
				if(pic[i-2]>=pic[i])
					dp1[i]=max(dp1[i],dp1[i-2]+1);
				if(pic[i-2]<=pic[i])
					dp2[i]=max(dp2[i],dp2[i-2]+1);
			}
		}
		if(n<=3 or dp1[n]>=n-1 or dp1[n-1]>=n-1 or dp2[n]>=n-1 or dp2[n-1]>=n-1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
