#include<stdio.h>
#include<math.h>
const double eps=1e-8;
int main()
{
	double a,b,c;
	int d;
	scanf("%lf%lf%lf%d",&a,&b,&c,&d);
	for(int i=0;i<=d;i++)
	{
		double k=a*i+b*(d-i);
		if(fabs(k-c)<=eps)
		{
			printf("%d %d",i,d-i);
			return 0;
		}
	}
	printf("Jenny has a bad memory!");
	return 0;
}
