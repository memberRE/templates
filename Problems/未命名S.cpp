#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
map<char,int> pic;
map<string,int> ans;
int main()
{
	pic['A']=2;pic['B']=2;pic['C']=2;
	pic['D']=3;pic['E']=3;pic['F']=3;
	pic['G']=4;pic['H']=4;pic['I']=4;
	pic['J']=5;pic['K']=5;pic['L']=5;
	pic['M']=6;pic['N']=6;pic['O']=6;
	pic['P']=7;pic['R']=7;pic['S']=7;
	pic['T']=8;pic['U']=8;pic['V']=8;
	pic['W']=9;pic['X']=9;pic['Y']=9;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s,tmp;
		int cnt=0;
		cin>>s;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]>='0' and s[j]<='9')
			{
				tmp.push_back(s[j]);
				cnt++;
			}
			else	if(s[j]>='A' and s[j]<='Z')
			{
				tmp.push_back(pic[s[j]]+48);
				cnt++;
			}
			if(cnt==3)
			tmp.push_back('-'),cnt++;
		}
//		tmp.push_back('\0');
		ans[tmp]++;
	}
	int num=0;
	map<string,int>::iterator it;
	for(it=ans.begin();it!=ans.end();it++)
	{
	//	cout<<(*it).first<<' '<<(*it).second<<"    TEST   !!!";
		if((*it).second>=2)
		{
			if(num!=0)
				cout<<endl;
			cout<<(*it).first<<' '<<(*it).second;
			num++;
		}
	}
	if(num==0)
	cout<<"No duplicates.";
	return 0;
}
