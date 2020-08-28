#include<iostream>
#include<string>
using namespace std;
int main()

{
	string s;
	cin>>s;
	s.push_back('#');
	for(int i=0;i<=s.length()+1;i++)
		cout<<(short)s[i]<<" ";
	return 0;
}
