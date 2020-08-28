#include<stdio.h>
int main()
{
	double ans;
	int n;
	
	scanf("%d",&n);
	
	ans=n*0.505;
	n-=150;
	
	if(n>0)
	{
		ans+=n*0.101;
		n-=250;
	}
	
	if(n>0)	
		ans+=n*0.101;
		
	printf("%.4lf",ans);
	
	return 0;
}
