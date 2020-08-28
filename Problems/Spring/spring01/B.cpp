#include<bits/stdc++.h>
using namespace std;
const int MAX =1e6+5;
int pic[MAX];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m*n;++i)
		scanf("%d",&pic[i]);
	sort(pic+1,pic+n*m+1);
	int num=unique(pic+1,pic+1+n*m)-pic-1;
	printf("%d",num); 
}
