#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[100002];
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=q;i++)
	{
		int e;
		scanf("%d",&e);
		int* d=lower_bound(a+1,a+1+n,e);
		if(*d!=e or d-a>n or d-a<1)
			printf("tan90\n");
		else
			printf("%d\n",d-a);
	}
	return 0;
}
