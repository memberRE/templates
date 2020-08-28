#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int kkk=100;
long long pic[1001][1001];
int main()
{
	memset(pic,0,sizeof(pic));
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
		{
			for(int I=1;I<=i;I++)
				for(int J=1;J<=j;J++)
					pic[i][j]+=(i-I+1)*(j-J+1);
		}
/*	for(int i=1;i<=kkk;i++)
	{
		for(int j=1;j<=kkk;j++)
			cout<<pic[i][j]<<" ";
		cout<<endl;
	}*/
	for(int i=1;i<=55;i++)
	cout<<pic[i][i]<<endl;
	return 0;
}
