#include<bits/stdc++.h>
using namespace std;
const int MAX=160000;
int pic[MAX];
int n;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&pic[i]);
		int mmin=99999999,ans=0;
		for(int i=n;i>=1;i--)
			if(pic[i]>mmin)
				ans++;
			else
				mmin=min(mmin,pic[i]);
		printf("%d\n",ans);
	}
}
