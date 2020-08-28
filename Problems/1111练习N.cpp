#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
int tpow[20]={1,2,4,8,16,32,64,128,256};
int mfs(int num,int mon)
{
	if(num<tpow[mon])
		return num==0;
	if(num==tpow[mon])
		return 1;
	int ans=0;
	for(int i=0;num-tpow[mon]*i>=0;i++)
		ans+=mfs(num-tpow[mon]*i,mon+1);
	
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",mfs(n,0));
	return 0;
}
