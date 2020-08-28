#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	float pi=4.0;
	for(int i=2;i<=10000000;i++)
	{
		float li;
		int k=(i*2)-1;
		if(i%2==0)
			li=-(4.0/k);
		else
			li=4.0/k;
		pi+=li;
	}
	printf("%.4f",pi);
	return 0;
}
