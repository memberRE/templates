#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[201],B[201],n;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&A[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&B[i]);
		int ans=0,las=0;
		for(int i=1;i<=n;i++)
		{
			int k=las+B[i];
			if(k<=A[i])
			{
				ans+=(i-1)*(A[i]-k);
				k=A[i];
			}
			ans+=k;
			las=k;
		}
		printf("%d\n",ans);
	}
	return 0;
}
