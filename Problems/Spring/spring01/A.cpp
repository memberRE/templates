#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
const long long MOD=12345678910;
typedef long long ll;
ll stk[MAX<<1];//-1(,,,,,,,,,0)
int pic[MAX];//0(,,,,,,,,,,,,1)
int top=0,n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&pic[i]);
	for(int i=1;i<=n;i++)
	{
		if(pic[i]==0)
			stk[top++]=pic[i]-1;
		else
		{
			if(top==0)	while(1);//si xun huan tle
			if(stk[top-1]==-1)
				stk[top-1]=1;
			else
			{
				ll ans=0;
				while(top)
				{
					if(stk[top-1]==-1)
						break;
					else
					{
						ans+=stk[top-1];
						ans%=MOD;
						top--;
					}
				}
				stk[top-1]=(ans<<1)%MOD;
			}
		}
	}
	ll ans=0;
	while(top)
	{
		ans+=stk[top-1];
		ans%=MOD;
		top--;
	}
	printf("%lld",ans);
}
