#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
void tow(int k,char a/*from**/,char b,char c/*to*/)
{
	if(k==1)
		{
			if(a=='B' or c=='B')
			printf("%c -> %c\n",a,c);
			else
			{
				printf("%c -> %c\n",a,b);
				printf("%c -> %c\n",b,c);
			}
		}
	else
	{
		tow(k-1,a,b,c);
		printf("%c -> %c\n",a,b);
		tow(k-1,c,b,a);
		printf("%c -> %c\n",b,c);
		tow(k-1,a,b,c);
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
