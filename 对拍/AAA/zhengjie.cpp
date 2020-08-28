#include<stdio.h>
#include<string.h>
int ans,x[55];
int f[2][110][5015];
int max(int p,int q)
{
	return p>q?p:q;
}
int main()
{
	int i,j,k,t,n,a,b;
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		f[0][50][2500]=1;
		int p=0;
		scanf("%d%d%d",&n,&a,&b);
		for(i=1; i<=n; i++)scanf("%d",&x[i]),x[i]-=a;
		for(i=1; i<=n; i++)
		{
			p^=1;
			for(j=50-i; j<=50+i; j++) //50+ a的个数 
			{
				for(k=0; k<=5000; k++) //2500+ b-a累加 
				{
					f[p][j][k]=f[p^1][j][k];
					if(k-x[i]>=0&&j-1>=0&&f[p^1][j-1][k-x[i]])
						f[p][j][k]=max(f[p][j][k],f[p^1][j-1][k-x[i]]+1);
					if(k+x[i]<=5000&&j-1>=0&&f[p^1][j+1][k+x[i]])
						f[p][j][k]=max(f[p][j][k],f[p^1][j+1][k+x[i]]+1);
				}
			}
		}
		int ans=f[p][50][2500];
		for(i=0; i<=100; i++)
		{
			if(a*(i-50)+2500<0)continue;
			if(a*(i-50)+2500>5000)break;
			ans=max(ans,f[p][i][-a*(i-50)+2500]);
		}
		printf("%d\n",n-(ans-1));
	}
	return 0;
}
