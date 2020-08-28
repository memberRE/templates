#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a,b,c;
int leve[101];
inline int exp(int k)
{
	return (k*a+b)%c;
}
bool check(int num)
{
	int k[101];
	memcpy(k,leve,sizeof(leve));
	sort(k+1,k+1+num);
	int sum=0;
	for(int i=1;i<=num-n;i++)
		sum+=k[i];
	if(sum<=m)
		return 1;
	else
		return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
		for(int i=1;i<=99;i++)
			leve[i]=exp(i);
		int l=1,r=100;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid))
				l=mid+1;
			else
				r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}
