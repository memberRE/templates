#include<bits/stdc++.h>
using namespace std;
int pic[12][12],jynum[10009];
int ans=0;
inline int getjy(int x)
{
	int a=x/1000;
	x%=1000;
	int b=x/100;
	x%=100;
	int c=x/10,d=x%10;
	return pic[pic[pic[pic[0][a]][b]][c]][d];
}
int main()
{
	for(int i=0;i<=9;++i)
		for(int j=0;j<=9;++j)
			scanf("%d",&pic[i][j]);
	for(int i=0;i<=9999;i++)
	{
		int e=getjy(i);
		jynum[i]=e;
	}
	for(int i=0;i<=9999;i++)
	{
		int flag=0;
		for(int j=0;j<=9;j++)
			if(j==jynum[i])
				continue;
			else if(!pic[jynum[i]][j])
			{
				ans++;
				flag=1;
				break;
			}
		if(flag)	continue;
		//-----------adjacent
		int x=i;
		int a=x/1000;
		x%=1000;
		int b=x/100;
		x%=100;
		int c=x/10,d=x%10;
		if(!pic[pic[pic[pic[pic[0][b]][a]][c]][d]][jynum[i]])
		{
			if((b*1000+a*100+c*10+d)!=i)
			{
				ans++;
				continue;
			}
		}
		if(!pic[pic[pic[pic[pic[0][a]][c]][b]][d]][jynum[i]])
		{
			if((a*1000+c*100+b*10+d)!=i)
			{
				ans++;
				continue;
			}
		}
		if(!pic[pic[pic[pic[pic[0][a]][b]][d]][c]][jynum[i]])
		{
			if((a*1000+b*100+d*10+c)!=i)
			{
				ans++;
				continue;
			}
		}
		if(!pic[pic[pic[pic[pic[0][a]][b]][c]][jynum[i]]][d])
		{
			if((a*1000+b*100+c*10+jynum[i])!=i or d!=jynum[i])
			{
				ans++;
				continue;
			}
		}
		//------------------------------
		int A=a,B=b,C=c,D=d;
		for(int j=0;j<=9;j++)
		{
			if(j==A)
				continue;
			a=j;
			if(!pic[pic[pic[pic[pic[0][a]][b]][c]][d]][jynum[i]])
			{
				ans++;
				flag=1;
				break;
			}
		}
		if(flag)	continue;
		a=A;
		for(int j=0;j<=9;j++)
		{
			if(j==B)
				continue;
			b=j;
			if(!pic[pic[pic[pic[pic[0][a]][b]][c]][d]][jynum[i]])
			{
				ans++;
				flag=1;
				break;
			}
		}
		if(flag)	continue;
		b=B;
		for(int j=0;j<=9;j++)
		{
			if(j==C)
				continue;
			c=j;
			if(!pic[pic[pic[pic[pic[0][a]][b]][c]][d]][jynum[i]])
			{
				ans++;
				flag=1;
				break;
			}
		}
		if(flag)	continue;
		c=C;
		for(int j=0;j<=9;j++)
		{
			if(j==D)
				continue;
			d=j;
			if(!pic[pic[pic[pic[pic[0][a]][b]][c]][d]][jynum[i]])
			{
				ans++;
				flag=1;
				break;
			}
		}
		if(flag)	continue;
		d=D;
	}
	cout<<ans;
	return 0;
}
