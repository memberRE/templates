#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int recursive(int n)
{
    if (n==1)
        return 0;
    if (n==2)
        return 1;
    return (n-1)*(recursive(n-2)+recursive(n-1));
}
int main()
{
	for(int i=1;i<=9;i++)
	cout<<recursive(i)<<endl;
	return 0;
}
