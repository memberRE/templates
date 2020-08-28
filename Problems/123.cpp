#include<iostream>
using namespace std;
static int tem = 1;
int main()
{
	int jkl=223;
	int *p=(int*)malloc(sizeof(int));
	cout<<&tem<<endl;
	cout<<&jkl<<endl;
	cout<<p<<endl;
	cout<<(int*)main<<endl;
}
