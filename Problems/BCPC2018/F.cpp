#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const long long MOD=998244353;
const int MAX=1e7+5;
typedef long long ll;
using namespace std;
int prime[500],cnt;//prime 下标从0开始 
ll d[MAX];
ll sum[MAX];
bool vztd[MAX];//0 is prime ;
void is_prime()//欧拉筛 
{
	for(int i=2;i<MAX;i++)
	{
		if(!vztd[i] and cnt<=490)
			prime[cnt++]=i;
		for(int j=0;j<446 and i*prime[j]<MAX;++j)
		{
			vztd[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}
void work()
{
	for(int i=3;i<=MAX;++i)//update sum[i-1] and d[i],d[i-1]
	{
		d[i]=1;
		if(vztd[i]==0)
		{
			d[i]*=2;
			d[i]%=MOD;
			d[i-1]*=i;
			d[i-1]%=MOD;
			sum[i-1]=(d[i-1]+sum[i-2])%MOD;
			continue;
		}
		int k=i;
		ll temans=1,temansi2=1;
		int cnt=0;
		for(int j=0;j<=446;++j)
		{
			cnt=0;
			if(vztd[k]==0) cnt=1,k=0;
			else if(k%prime[j]==0)
			{
				while(k%prime[j]==0)
					k/=prime[j],cnt++;
			}
			if(cnt)
			{
				temans*=cnt+1;
				temansi2*=cnt*(i-1)+1;
				temans%=MOD;
				temansi2%=MOD;
			}
			if(k<=1)	break;
		}
		d[i]*=temans;
		d[i]%=MOD;
		d[i-1]*=temansi2;
		d[i-1]%=MOD;
		sum[i-1]=(d[i-1]+sum[i-2])%MOD;
	}
}
int main()
{
	d[1]=d[2]=2;
	sum[1]=2;
	is_prime();
	work();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",sum[n]);
	}
	return 0;
}
