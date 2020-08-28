#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int a[555]={1,2,3,4,5,6,7,8,9,10,11,12,13};
int main()
{
	int b;
	b=lower_bound(a+3,a+12,6)-a;
	cout<<a[b];
	return 0;
}
