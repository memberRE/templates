#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<int,char> pic,ans;
typedef unsigned long long lld;
int main()
{
	string a,b,c;
	cin>>a>>b;
	for(int i='a';i<='z';i++)
	{
		pic[i]=i-'a';
	//	cout<<(char)i<<" "<<i-'a'<<endl;
		ans[i-'a']=i;
		}	
	for(int i=0;i<=9;i++)
	{
		pic[i+'0']=i+26;
		ans[i+26]=i+'0';
		}
	int j=0;	
	for(int i=0;i<a.length();i++)
	{
		int k=pic[a[i]]+pic[b[j]];
		if(k>35)
		k%=36;
		j++;
		j%=b.length();
		c.push_back(k);
	}
	for(int i=0;i<c.length();i++)
		cout<<ans[c[i]];
	return 0;
}
