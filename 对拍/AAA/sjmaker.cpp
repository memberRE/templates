#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long seed;
int main()
{
	freopen("A.in","w",stdout);
	seed=time(0);
	srand(seed);
	int t=50;//32768
	cout<<t<<endl;
	for(int i=1;i<=t;i++)
	{
		int n=rand()%50;
		if(!n)
			n+=5;
		int a=rand(),b=rand();
		if(a>b)
			swap(a,b);
		b+=50;
		cout<<n<<' '<<a<<' '<<b<<endl;
		for(int j=1;j<=n;j++)
		{
			int k=rand();
			k%=(b-a);
			k+=a;
			cout<<k<<' ';
		}
		cout<<endl;
	}
		
	fclose(stdout);
	return 0;
}
