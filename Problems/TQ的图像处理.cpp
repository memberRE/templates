#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int pic[103][103],n,m;
bool vztd[103][103];
int main()
{
//	ios::sync_with_stdio(false); 
	int t;
	cin>>t;
	for(int K=1;K<=t;K++)
	{
		memset(pic,0,sizeof(pic));;
		memset(vztd,0,sizeof(vztd));
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>pic[i][j];//j--x;i--y
		for(int nnn=1;nnn<=m;nnn++)
		{
			string s;
			cin>>s;
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			if(y1>y2 or x1>x2)
			{
				swap(x1,x2);
				swap(y1,y2);
			}
			if(s[0]=='g')
			{
				for(int i=x1;i<=x2;i++)
					for(int j=y1;j<=y2;j++)
							if(!vztd[i][j])
							{
								pic[i][j]=(pic[i][j]*pic[i][j]+233)%1773;
								vztd[i][j]=1;
							}
			}
			else if(s[0]=='n')
			{
				for(int i=x1;i<=x2;i++)
					for(int j=y1;j<=y2;j++)
						if(vztd[i][j])
						{
							if(pic[i][j]!=0)
							pic[i][j]=1;
							else
							pic[i][j]=0;
						}
			}
			else if(s[0]=='d')
			{
				for(int i=x1;i<=x2;i++)
					
					{
						for(int j=y1;j<=y2;j++)
							printf("#%06X  ",pic[i][j]);
						cout<<endl;
					}
			}
		}
		for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					printf("%04d  ",pic[i][j]);
				cout<<endl;
			}
	}
	return 0;
}
