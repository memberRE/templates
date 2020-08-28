#include<bits/stdc++.h>
using namespace std;
const int MAX=3020;
int h[2][MAX],l[2][MAX],r[2][MAX],n,m,cur;
char pic[MAX][MAX];
int ans=0;
int main()
{
	scanf("%d%d",&n,&m);
	getchar();
//	for(int i=1;i<=n;++i)
//		for(int j=1;j<=m;++j)
//			scanf("%d",&pic[i][j]);
	for(int i=1;i<=n;i++)
		scanf("%s",pic[i]+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			if(pic[i][j]=='1')
				h[cur][j]=h[cur^1][j]+1;
			else
				h[cur][j]=0;
		for(int j=1;j<=m;++j)
		{
			l[cur][j]=j;
			while(l[cur][j]>1 and h[cur][j]<=h[cur][l[cur][j]-1])
				l[cur][j]=l[cur][l[cur][j]-1];
		}
		for(int j=m;j>=1;--j)
		{
			r[cur][j]=j;
			while(r[cur][j]<m and h[cur][j]<=h[cur][r[cur][j]+1])
				r[cur][j]=r[cur][r[cur][j]+1];
		}
		//int lash=0,lasl=0,lasr=0;
		for(int j=1;j<=m;++j)
		{
			if(h[cur][j]!=0)
			{
				if(/*h[cur][j]!=lash and*/ pic[i][r[cur][j]]>=0 or pic[i][l[cur][j]]>=0)
				{
					if(h[cur][j]==1)
					{
						ans++;
						if(pic[i][r[cur][j]]>0)	pic[i][r[cur][j]]*=-1;
						if(pic[i][l[cur][j]]>0)	pic[i][l[cur][j]]*=-1;
					}
					else if(l[cur][j]!=l[cur^1][j] or r[cur][j]!=r[cur^1][j])
					{
						ans++;
						if(pic[i][r[cur][j]]>0)	pic[i][r[cur][j]]*=-1;
						if(pic[i][l[cur][j]]>0)	pic[i][l[cur][j]]*=-1;
					}
				}
			}
		}
//		cout<<ans<<endl;
//		system("pause");
		cur^=1;
	}
	printf("%d",ans);
	return 0;
}

//5 4
//100100
//110110
//111111
//110110
//100100
//
//3 5
//11111
//00110
//01100
