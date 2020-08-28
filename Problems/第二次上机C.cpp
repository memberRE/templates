#include<stdio.h>
#include<math.h>
int main()
{
	long long a[4];
	scanf("%lld%lld%lld%lld",&a[0],&a[1],&a[2],&a[3]);
	for(int i=0;i<=3;i++)
		if(a[i]&(a[i]-1))
			printf("No\n");
		else
			printf("Yes\n");
	return 0;
}
