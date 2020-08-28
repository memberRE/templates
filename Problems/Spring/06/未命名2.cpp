#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define MAX 1000000002
using namespace std;
bool prime[1000000020];
void isprime()
{
	prime[0]=prime[1]=0;prime[2]=1;
	for(int i=3;i<MAX;i++)
		prime[i]=i%2==0?0:1;
	int t=(int)sqrt(MAX*1.0);
	for(int i=3;i<t;i++)
		if(prime[i])
			for(int j=i*i;j<MAX;j+=(i<<1))
				prime[j]=0;
}
int main()
{
	isprime();
	int las=2,ans=0;
	int ans1,ans2; 
	for(int i=3;i<=MAX;++i)
	{
		if(prime[i])
		{
			if(i-las>ans)
			{
				ans=i-las;
				ans1=las;ans2=i;
			}
			las=i;
		}
	}
	cout<<ans<<endl<<ans1<<endl<<ans2;
	return 0;
}
