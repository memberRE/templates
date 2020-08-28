#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long MAXP=1e5+3;
typedef long long ll;
struct ppp{
	ll xi,zhi;
}pic[66536];
ll aj[MAXP],p[12];//lucas
ll v[20],n,m,k,cnt;//main
ll B[20];//crt
bool cam(ppp a,ppp b)
{
	return a.zhi<b.zhi;
}
void work()
{
	int tot=1;
	pic[tot].xi=-1;
	pic[tot++].zhi=v[1]+1;
	pic[tot].xi=1;
	pic[tot++].zhi=0;
	for(int i=2;i<=n;i++)
	{
		int K=tot-1;
		for(int j=1;j<=K;j++)
		{
			pic[tot].xi=pic[j].xi*(-1);
			pic[tot++].zhi=pic[j].zhi+v[i]+1;
			if(pic[tot-1].zhi>m)
				tot--;
		}
	}
	tot--;
	sort(pic+1,pic+tot+1,cam);
	//合并同类项
	ll laszhi=pic[1].zhi;
	cnt=1;
	for(int i=2;i<=tot;i++) 
	{
		if(pic[i].zhi>m)	break;
		if(pic[i].zhi==laszhi)
			pic[cnt].xi+=pic[i].xi;
		else
		{
			cnt++;
			laszhi=pic[i].zhi;
			pic[cnt].zhi=laszhi;
			pic[cnt].xi=pic[i].xi;
		}
	}
}
ll qmulti(ll M, ll N, ll P)//快速乘法 
{
    ll ans = 0;//注意初始化是0，不是1 
    while (N)
    {
        if (N & 1)
            ans += M;
        M = (M + M) % P;//和快速幂一样，只不过这里是加 
        M %= P;//取模，不要超出范围 
        ans %= P;
        N >>= 1;
    }
    return ans;
}
ll qpow(ll y,ll z,ll P)//快速幂
{
	y%=P;
	ll ans=1;
	for(int i=z;i;i>>=1,y=y*y%P)
		if(i&1)	ans=ans*y%P;
	return ans;
}
ll cm(ll N,ll M,ll P)
{
	if(M>N)	return 0;
	return (aj[N]*qpow(aj[M],P-2,P))%P*qpow(aj[N-M],P-2,P)%P;
}
ll lucas(ll N,ll M,ll P)
{
	if(M==0)	return 1;
	return cm(N%P,M%P,P)*lucas(N/P,M/P,P)%P;	
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ll gcd=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-(a/b)*y;
	return gcd;
}
ll china()//W->P,B->B,k->k
{
	ll x,y,a=0,M,N=1;
	for(int i=1;i<=k;i++)
		N*=p[i];
	for(int i=1;i<=k;i++)
	{
		M=N/p[i];
		exgcd(p[i],M,x,y);
	//	a=(a+((y*M)%N)*B[i])%N;
		ll jkl=qmulti(y,M,N);
		a=(a+qmulti(jkl,B[i],N))%N;;
	}
	if(a>0)
		return a;
	else
		return a+N;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		memset(pic,0,sizeof(pic));
		for(int i=1;i<=n;i++)
			scanf("%lld",&v[i]);
		for(int i=1;i<=k;i++)
			scanf("%lld",&p[i]);
		work();//多项式乘积，最终有cnt项 
		
		for(int i=1;i<=k;++i)
		{
			ll tem=0;
			memset(aj,0,sizeof(aj));
			aj[0]=1;
			for(int j=1;j<=p[i];j++)
				aj[j]=(aj[j-1]*j)%p[i];
			for(int j=1;j<=cnt;++j)
			{
				ll zhi=pic[j].zhi;
				ll  xi=pic[j].xi;
				if(xi==0)	continue;
				if(zhi>m)	continue;
				if(n-1+m-zhi>=0)
				{
					tem+=xi*lucas(n-1+m-zhi,n-1,p[i]);
					tem%=p[i];
				}
			}
			while(tem<0)
				tem+=p[i];
			B[i]=tem;
		}
		printf("%lld\n",china());
	}
}
