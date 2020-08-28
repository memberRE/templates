#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[1003];
int main()
{
	cin.getline(a,999999,'$');
	int len=strlen(a),ans=0;
	for(int i=0;i<len;i++)
		if(i<=len-3)
			if(a[i]=='t' and a[i+1]=='l' and a[i+2]=='s')
				ans++;
	for(int i=0;i<len;i++)
		if(i<=len-3)
			if(a[i]=='l' and a[i+1]=='l' and a[i+2]=='s')
				ans++;
	for(int i=0;i<len;i++)
		if(i<=len-3)
			if(a[i]=='l' and a[i+1]=='z' and a[i+2]=='y')
				ans++;
	if(ans!=1)
		cout<<"NO";
	else
		cout<<"YES";
	return 0;
}
