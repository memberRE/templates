#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
long long seed;
int main()
{
	freopen("merge.in","w",stdout);
	seed=time(0);
	srand(seed);
	int n=20;//rand();//32768
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
		cout<<rand()<<' ';
	fclose(stdout);
	return 0;
}
