#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	int A=a*100000,B=b*100000;
	int c=A%B;
	cout<<A<< "  "<<B<<endl;
	printf("%.4lf",(double)c/100000);
	return 0;
}
/*#include<stdio.h>
int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	int A=a*10000,B=b*10000;
	printf("%.4lf",(A%B)/10000.0);
	return 0;
}*/ 
