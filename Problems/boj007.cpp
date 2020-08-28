#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int num;
	while(cin>>num)
	{
		int a=num/100;
		num%=100;
		int b=num/10;
		num%=10;
		bool biao=0;
		int c=num;
		if(c)
		{
			cout<<c;
			biao=1;
			}	
		if(biao)
			cout<<b;
		else
		{
			if(b)
				cout<<b;
		}
		cout<<a<<endl;
	}	
	return 0;
}
