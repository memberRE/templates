#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long seed;
int pic[55][55];
int main()
{
	freopen("in.txt","w",stdout);
	seed=time(0);
	srand(seed);
	int t=26;//32768
	cout<<t/2<<endl;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=t;j++)
			if(i==j)
				pic[i][j]=0;
			else
				pic[i][j]=rand()%100;
	}
	for(int i=1;i<=t;i++)
		for(int j=1;j<=t;j++)
			pic[i][j]=pic[j][i];
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=t;j++)
			cout<<pic[i][j]<<' ';
		cout<<endl;
	}
	fclose(stdout);
	return 0;
}
