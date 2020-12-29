#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long seed;
int pic[11100];
int main()
{
	freopen("A.in","w",stdout);
	seed=time(0);
	srand(seed);
	ios::sync_with_stdio(0);
	int n = 100; //rand()%10000;
	n = max(n,20);
	int i = 1;
	while(i <= n)
	{
		int jkl = rand()%n+1;
		int len = rand()%4+1;
		while(len--)
		{
			if (i >= n + 1)
				break;
			pic[i++] = jkl;
		}
	}
	int lim = rand()%20;
	for(int i = 1;i<=lim;i++)
	{
		int l = rand()%(n - 1) + 1;
		int r = rand()%(n - 1) + 1;
		swap(pic[l],pic[r]);
	}
//	for(int i = 1;i<=n;i++)
//		pic[i] = (rand()%n)+1;
	cout<<n<<endl;
	for(int i = 1;i<=n;i++)
		cout<<pic[i]<<endl;
	fclose(stdout);
	return 0;
}
