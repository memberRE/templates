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
	ios::sync_with_stdio(0);
	cout<<900000000<<" "<<1000000<<endl;
	for(int i=1;i<=1000000;i++)
	{
		int opt=rand()%2;
		cout<<opt<<' '<<(int)rand()*rand()<<endl;
	}
		
	fclose(stdout);
	return 0;
}
