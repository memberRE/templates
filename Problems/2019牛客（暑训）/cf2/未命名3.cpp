#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int MAX=1e5+5;
const ll MOD=256;
ll maxx[270],dp[270][MAX];
int a[MAX],n;
int get(char c,char d)
{
    if(isalpha(c)) c=c-'A'+10;
    else c=c-'0';
    if(isalpha(d)) d=d-'A'+10;
    else d=d-'0';
    return c*16+d;
}
int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;++i)
	{
		char C=getchar();
		char D=getchar();
		a[i]=get(C,D);
		getchar();
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=0;i<256;++i)
		{
			int tem=((j/256)*256+i);
			if(tem>j)
				tem-=256;
			if(tem<0)
				continue;
			int nex=(i-1+256)%256;
			dp[i][j]=ll(tem^a[j])+maxx[nex];
		}
		for(int i=0;i<256;++i)
			maxx[i]=max(maxx[i],dp[i][j]);
	}
	ll ans=0;
	for(int i=0;i<=255;i++)
		ans=max(ans,maxx[i]);
	printf("%lld",ans);
	return 0;
}
