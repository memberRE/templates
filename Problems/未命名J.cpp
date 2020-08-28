#include<iostream>
#include<cmath>
using namespace std;
double x1,x2,x3,y2,y3,x4,y4;
 int main()
{
	double y1;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	x4=((x1*x1*(y2-y3)+x2*x2*(y3-y1)+x3*x3*(y1-y2))-(y1-y2)*(y2-y3)*(y3-y1))/(2*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
	y4=(-(y1*y1*(x2-x3)+y2*y2*(x3-x1)+y3*y3*(x1-x2))+(x1-x2)*(x2-x3)*(x3-x1))/(2*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
	if(-x4<1e-5 and x4<=0 )
	x4=0;
	if(y4<1e-5 and y4<=0)
	y4=0;
	printf("(%.2lf,%.2lf)\n",x4,y4);
}
