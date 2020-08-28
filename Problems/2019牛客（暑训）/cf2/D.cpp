#include<bits/stdc++.h>
using namespace std;
int main()
{
	double h1,h2,t1,t2;
	scanf("%lf%lf%lf%lf",&h1,&t1,&h2,&t2);
	double ans=t2-((t1-t2)/(sqrt(h1/h2)-1.0));
	printf("%lf",fabs(ans));
	return 0;
}
