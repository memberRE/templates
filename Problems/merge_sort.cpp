#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1000007],n,lin[1000007];
unsigned long long ans=0;
void marge(int l,int m,int r)
{
	int i=l,j=m+1,k=l;
	while(i<=m and j<=r)
	{
		if(a[i]>a[j])
		{
			lin[k]=a[j];
			k++;j++;
			ans+=(m-i+1);
		}
		else		
		{
			lin[k]=a[i];
			k++;i++;
		}
	}
	while(i<=m) lin[k++]=a[i++];
	while(j<=r) lin[k++]=a[j++];
	for(i=l;i<=r;i++)
		a[i]=lin[i];
}
void marge_sort(int l,int r)
{
	
	if(l<r)
	{
		int mid=(l+r)>>1;
		marge_sort(l,mid);
		marge_sort(mid+1,r);
		marge(l,mid,r);
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans=0;
		marge_sort(1,n);
		cout<<ans<<endl;
	}
	return 0;
}
