#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int x1,x2,x3,y1,y2,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	if(x1*y1<x2*y2)
	{
		swap(x1,x2);
		swap(y1,y2);
	}
	if(x1*y1<x3*y3)
	{
		swap(x1,x3);
		swap(y1,y3);
	}
	if((x2+x3<=x1 and y3<=y1 and y2<=y1) or (y2+y3<=y1 and x2<=x1 and x3<=x1))
	{
		cout<<"SIXSIXSIX!"<<endl;
		return 0;
	}
	swap(x2,y2);
	if((x2+x3<=x1 and y3<=y1 and y2<=y1) or (y2+y3<=y1 and x2<=x1 and x3<=x1))
	{
		cout<<"SIXSIXSIX!"<<endl;
		return 0;
	}
	swap(x3,y3);
	if((x2+x3<=x1 and y3<=y1 and y2<=y1) or (y2+y3<=y1 and x2<=x1 and x3<=x1))
	{
		cout<<"SIXSIXSIX!"<<endl;
		return 0;
	}
	swap(x2,y2);
	if((x2+x3<=x1 and y3<=y1 and y2<=y1) or (y2+y3<=y1 and x2<=x1 and x3<=x1))
	{
		cout<<"SIXSIXSIX!"<<endl;
		return 0;
	}
	cout<<"GG!"<<endl;
	return 0;
}
