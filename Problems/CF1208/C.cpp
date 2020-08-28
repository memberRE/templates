#include<bits/stdc++.h>
using namespace std;
const int MAX=1009;
int n;
int pic[MAX][MAX];
int main()
{
	//cin>>n;
	for(n=4;n<=1000;n+=4)
	{
		int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			pic[i][j]=cnt++;
	//for(int i=1;i<=n;i++) 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i%4==0 && abs(i-j)%4 == 0)
				for(int k=0;k<4;k++)
					pic[i+k][j+k] = abs( n*n-1 - pic[i+k][j+k] );
			else if (i%4==3 && (i+j)%4 == 3)
				for(int k=0;k<4;k++)
					pic[i-k][j+k] = abs( n*n-1 - pic[i-k][j+k] );
		}
	int ans=0;
	for(int i=0;i<n;i++)
		ans^=pic[i][0];
	for(int i=0;i<n;i++)
	{
		int tem=0;
		for(int j=0;j<n;j++)
			tem^=pic[i][j];
		if(tem!=ans)
		{
			cout<<n<<endl;system("pause");break;
		//	return 0;
		}
	}
	for(int j=0;j<n;j++)
	{
		int tem=0;
		for(int i=0;i<n;i++)
			tem^=pic[i][j];
		if(tem!=ans)
		{
			cout<<n<<endl;system("pause");break;
			//return 0;
		}
	}
	//cout<<"ac"<<endl;
	
	}
	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//			printf("%d ",pic[i][j]);
//		putchar('\n');
//	}
	return 0;
}
