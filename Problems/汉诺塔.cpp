#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
void tow(int k,char a,char b,char c)
{
	if(k==1)
		{
			printf("%c to %c\n",a,b);
			printf("%c to %c\n",b,c);
		}
	else
	{ 
		tow(k-1,a,c,b);
		tow(k-1,b,a,c);
		printf("%c to %c\n",a,b);
		tow(k-1,c,a,b);
		tow(k-1,b,c,a);
		printf("%c to %c\n",b,c);
		tow(k-1,a,c,b);
		tow(k-1,b,a,c);
	}
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		tow(n,'A','B','C');
		cout<<endl;
	}
	return 0;
}
