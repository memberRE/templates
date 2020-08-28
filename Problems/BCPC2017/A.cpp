#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		n%=72;
		if(n)
			cout<<32<<endl;
		else
			cout<<7<<endl;
	}
	return 0;
}
