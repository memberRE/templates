#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
struct ppp{
	string name;
	int score;
	int size;
	int cnt;
}pic[1003];
int ls[1003],rs[1003],num=0;
bool Find(string s,int k)
{
	for(int i=1;i<=num;i++)
		if(pic[i].name==s and pic[i].cnt!=0)
			pic[i].cnt=0; 
}
void add(int node,string k,int sec)
{
	if(ls[0]==0)
	{
		pic[1].name=k;
		pic[1].score=sec;
		pic[1].size=1;
		ls[0]=1;
		return ;
	}
	
}
int main()
{
	memset(ls,0,sizeof(ls));
	memset(rs,0,sizeof(ls));
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int k;
		cin>>k;
		if(k==1)
		{
			string s;
			int jkl;
			cin>>s>>jkl;
			
			add(1,s,jkl);
			num++;
		}
		else
		{
			int jkl;
			cin>>jkl;
			check(jkl);
		}
	}
	return 0;
}
