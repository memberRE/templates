#include<bits/stdc++.h>
using namespace std;
void solve(int b,int p,int f,int h,int c)
{
	if(p*2>b)
		printf("%d\n",(b>>1)*h);
	else 
	{
		int ans=p*h;
		b-=(p<<1);
		if(f*2>b)
			ans+=(b>>1)*c;
		else
			ans+=f*c;
		printf("%d\n",ans);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int b,p,f,h,c;
		scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
		if(h>c)
			solve(b,p,f,h,c);
		else
			solve(b,f,p,c,h);
	}
	return 0;
}
