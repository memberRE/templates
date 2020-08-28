#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<string>
using namespace std;
struct ppp{
	string name;
	int score;
//	ppp(string name,int score):name(name),score(score) {}
	bool operator < (const ppp& a)	const{
		return score>a.score or (score==a.score and name>a.name);
	}
	
};
set<ppp>s;
set<ppp>::iterator it;
int main()
{
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int kkk;
		scanf("%d",&kkk);
		if(kkk==1)
		{
///			string ss;
			ppp lin;
			scanf("%s",&lin.name);
//			int k;
			scanf("%d",&lin.score);
			for(it=s.begin();it!=s.end();it++)
				if((*it).name==/*ss*/lin.name)
				{
					s.erase(it);
					break;
				}
//			ppp kl(ss,k);
//			kl.name=ss;
//			kl.score=k;
			s.insert(lin);//这里出错了 
		}
		else
		{
			int ran;
			scanf("%d",&ran);
			int cnt=0;
			for(it=s.begin();;it++)
			{
				cnt++;
				if(cnt==ran)
				{
					cout<<(*it).name<<" "<<(*it).score<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
