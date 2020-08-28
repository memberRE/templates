#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,j=0,o=0;
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		if(k%2==0)
			o++;
		else
			j++;
	}
	cout<<min(o,j);
}
