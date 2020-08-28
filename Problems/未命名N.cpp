#include<cstdio>
#include<iostream>
#include<cstring>//dirx[]={1,0,-1,0},diry[]={0,-1,0,1}
using namespace std;
int pic[25][25];
int main()
{
	int n,dir[]={1,0,-1,0};
	cin>>n;
	int x=1,y=n,nx=0,ny=1;
	memset(pic,-1,sizeof(pic));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			pic[i][j]=0;
	for(int i=1;i<=(n*n);i++)
	{
		pic[x][y]=i;
		if(pic[x+dir[nx]][y+dir[ny]]!=0)
		{
			nx++;
			ny++;
			nx%=4;
			ny%=4;
		}
		x+=dir[nx];
		y+=dir[ny];
	}
	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<pic[i][j]<<' ';
			cout<<endl;
		}
	return 0;
}
