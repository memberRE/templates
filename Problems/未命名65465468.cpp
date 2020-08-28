#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1000007];
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=n+1;i++)
		{
			int k;
			scanf("%d",&k);
			a[k]++;
		}
		for(int i=1;i<=n;i++)
			if(a[i]>1)
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
