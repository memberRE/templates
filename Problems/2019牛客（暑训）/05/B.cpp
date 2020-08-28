#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;
struct mat{
	ll m[3][3];
}a,e;
char n[1000030],er[4000009];
int start[1000030],ans[1000030],res[1000030];
int endd=1;;
//ll base[4]={1,1,1,1};
ll x0,x1,A,B,len;
mat mul(mat x,mat y)
{
	mat c;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			c.m[i][j]=0;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
				c.m[i][j]=(c.m[i][j]%MOD+x.m[i][k]*y.m[k][j]%MOD)%MOD;
	return c;
}
mat  qpower(mat x)
{
	 mat ns=e;
	 while(res[0]>=endd)
	 {
	 	if(res[endd]==1)
	 		ns=mul(ns,x);
	 	x=mul(x,x);
	 	endd++;
	 }
	 return ns;
}
void change()
{
	int y,i,j;
	while(start[0]>=1)
	{
		y=0;
        i=1;
        ans[0]=start[0];
        while(i <= start[0])
        {
            y = y * 10 + start[i];
            ans[i++] = y/2;
            y %= 2; 
        }
        res[++res[0]] = y;
        i = 1;
        while((i<=ans[0]) && (ans[i]==0)) i++;
        memset(start,0,sizeof(start));
        for(j = i;j <= ans[0];j++)
            start[++start[0]] = ans[j]; 
        memset(ans,0,sizeof(ans));
	}
}
int main()
{
	for(int i=1;i<=2;i++)
		e.m[i][i]=1;
	scanf("%lld%lld%lld%lld\n",&x0,&x1,&A,&B);
	scanf("%s %lld",n,&MOD);
	a.m[1][1]=A;a.m[1][2]=B;a.m[2][1]=1;
	len=strlen(n);
	start[0]=len;
	for(int i=0;i<len;i++)
		start[i+1]=n[i]-'0';
	change();
	if(len==1 and n[0]=='1')
		printf("%lld\n",x1);
	else
	{
		for(int i=1;i<=res[0];i++)
		{
			if(res[i]==1)
			{
				res[i]=0;
				if(i==res[0])
					res[0]--;
				break;
			}
			else
				res[i]=1;
		}
		mat ns=qpower(a);
		printf("%lld\n",(ns.m[1][1]*x1%MOD+ns.m[1][2]*x0%MOD)%MOD);
	}
	return 0;
}
