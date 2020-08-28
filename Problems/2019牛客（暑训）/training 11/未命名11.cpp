#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4200;
const ll MOD=1e9+7;
const ll BASE=19260817;
ll base[30];
struct ppp{
	int A[28];
	bool operator < (ppp a) const {
	for(int i=0;i<=27;i++)
		if(A[i]==a.A[i])
			continue;
		else
			return A[i]<a.A[i];
	return A[27]<a.A[27];
	}
}node;
char s1[MAX],s2[MAX];
set<ppp> SET[4001];
int main()
{
	scanf("%s",s1);
	getchar();
	scanf("%s",s2);
	int len1=strlen(s1),len2=strlen(s2);
	for(int i=4;i<=len1;++i)
	{
		for(int j=0;j<28;++j)
			node.A[j]=0;
		for(int j=0;j<i;++j)
			node.A[s1[j]-'a']++;
		SET[i].insert(node);
//		cout<<tem<<' '<<i<<' ' << '0' << endl;
		for(int j=1;j+i-1<len1;j++)
		{
			node.A[s1[j-1]-'a']--;
			node.A[s1[j+i-1]-'a']++;
			//if(!SET[i].count(tem))
				SET[i].insert(node);
//			cout<<tem<<' '<<i<<' '<<j<<endl;
		}	
	}
//	cout<<endl;
	for(int i=len2;i>=1;--i)
	{
		for(int j=0;j<28;++j)
			node.A[j]=0;
		for(int j=0;j<i;++j)
			node.A[s2[j]-'a']++;
//		cout<<tem<<' '<<i<<' '<< '0' <<endl;
		if(SET[i].count(node))
		{
			printf("%d",i);
			return 0;
		}
		for(int j=1;j+i-1<len2;j++)
		{
			node.A[s2[j-1]-'a']--;
			node.A[s2[j+i-1]-'a']++;
//			cout<<tem<<' '<<i<<' '<<j<<endl;
			if(SET[i].count(node))
			{
				printf("%d",i);
				return 0;
			}
		}
	}
	printf("0");
	return 0;
}
