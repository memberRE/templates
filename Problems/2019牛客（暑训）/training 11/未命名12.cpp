#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4200;
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
}node,node2;
char s1[MAX],s2[MAX];
set<ppp> SET;
int main()
{
	scanf("%s",s1);
	getchar();
	scanf("%s",s2);
	int len1=strlen(s1),len2=strlen(s2);
	for(int i=min(len1,len2);i>=1;--i)
	{
		for(int j=0;j<28;++j)
			node.A[j]=0;
		for(int j=0;j<i;++j)
			node.A[s1[j]-'a']++;
		SET.insert(node);
		for(int j=1;j+i-1<len1;j++)
		{
			node.A[s1[j-1]-'a']--;
			node.A[s1[j+i-1]-'a']++;
				SET.insert(node);
		}
		
		for(int j=0;j<28;++j)
			node2.A[j]=0;
		for(int j=0;j<i;++j)
			node2.A[s2[j]-'a']++;
		if(SET.count(node2))
		{
			printf("%d",i);
			return 0;
		}
		for(int j=1;j+i-1<len2;j++)
		{
			node2.A[s2[j-1]-'a']--;
			node2.A[s2[j+i-1]-'a']++;
			if(SET.count(node2))
			{
				printf("%d",i);
				return 0;
			}
		}
		SET.clear();
	}
	printf("0");
	return 0;
}
