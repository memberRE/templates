#include<cstdio>
const int MOD=1e9+7;
long long a[100005]={1,1},noww=1;
int main()
{
	int t,n,maxx=-1;
	scanf("%d",&t);
	for(int i=2;i<=100001;i++)
	{
		noww*=i;
		noww%=MOD;
		a[i]=(a[i-1]+noww)%MOD;
	}
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",a[n]);
	}
	return 0;
}

