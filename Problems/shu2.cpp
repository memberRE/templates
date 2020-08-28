#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
struct ppp{
	string name;
	int score;
}pic[1002];
bool cam(ppp a,ppp b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else
	return a.name<b.name;
}
int num=0;
int main()
{
	ios::sync_with_stdio(false);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int k;
		cin>>k;
		if(k==1)
		{	
			string nam;
			int k;
			cin>>nam>>k;
			int j=1;
			for(;j<=num;j++)
				if(pic[j].name==nam)
				{
					pic[j].score=k;
					break;
				}
			if(j==num+1)
			{
				num++;
				pic[j].name=nam;
				pic[j].score=k;
			}
		}
		else
		{
			int jkl;
			cin>>jkl;
			sort(pic+1,pic+1+num,cam);
			cout<<pic[jkl].name<<" "<<pic[jkl].score<<endl;
		}
	}
	return 0;
}
