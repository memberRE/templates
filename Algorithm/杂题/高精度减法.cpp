#include<iostream>
#include<cstring>
using namespace std;
const int L=500;
string mins(string a,string b)
{
	string ans;
	int na[L]={0},nb[L]={0},la,lb;
	la=a.size();
	lb=b.size();
	for(int i=0;i<la;i++)	na[la-1-i]=a[i]-'0';
	for(int i=0;i<lb;i++)	nb[lb-1-i]=b[i]-'0';
	int maxx=la>lb?la:lb;
	for(int i=0;i<maxx;i++)
	{
		na[i]-=nb[i];
		if(na[i]<0)
		{
			na[i]+=10;
			na[i+1]--;
		}
	}
	while(!na[--maxx] and maxx>0) ;
	maxx++;
	for(int i=maxx-1;i>=0;i--)
		ans+=na[i]+'0';
	return ans;
}
int main()
{
	string a,b;
	cin>>a>>b;
	if(a.size()<b.size())	swap(a,b),cout<<'-';
	cout<<mins(a,b)<<endl;
	return 0;
}
