#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100003];
int n;
void quick_sort(int l,int r)
{
	if(l>=r)	return ;
	int i=l,j=r;
	ll key=a[i];
	while(i<j)
	{
		while (i<j and a[j]>=key)
			j--;
		while (i<j and a[i]>key);
		//	swap(a[i++],a[mid]);
	}
	quick_sort(l,mid-1);
	quick_sort(mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a[i]);
	quick_sort(1,n);
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]);
	return 0;
}
