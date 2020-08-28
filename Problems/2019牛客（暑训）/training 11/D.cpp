#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4200;
const ll MOD=1e9+7;
const ll BASE=4001;
ll base[30];
ll Hash(int * a)
{
	ll tem=0;
	for(int i=0;i<28;i++)
	{
		tem+=(a[i]*base[i])%MOD;
		tem%=MOD;
	}	
	return tem%MOD;
}
char s1[MAX],s2[MAX];
set<ll> SET[4001];
int main()
{
	base[0]=1;
	for(int i=1;i<28;i++)
		base[i]=(base[i-1]*BASE)%MOD;
	int A[30];
	scanf("%s",s1);
	getchar();
	scanf("%s",s2);
	int len1=strlen(s1),len2=strlen(s2);
	for(int i=1;i<=len1;++i)
	{
		for(int j=0;j<28;++j)
			A[j]=0;
		for(int j=0;j<i;++j)
			A[s1[j]-'a']++;
		ll tem=Hash(A);
		SET[i].insert(tem);
		for(int j=1;j+i-1<len1;j++)
		{
			tem-=base[s1[j-1]-'a'];
			tem+=base[s1[j+i-1]-'a'];
			tem%=MOD;
			if(tem<0)	tem+=MOD;
			if(!SET[i].count(tem))
				SET[i].insert(tem);
		}	
	}
	for(int i=min(len1,len2);i>=1;--i)
	{
		for(int j=0;j<28;++j)
			A[j]=0;
		for(int j=0;j<i;++j)
			A[s2[j]-'a']++;
		ll tem=Hash(A);
		if(SET[i].count(tem))
		{
			printf("%d",i);
			return 0;
		}
		for(int j=1;j+i-1<len2;j++)
		{
			tem-=base[s2[j-1]-'a'];
			tem+=base[s2[j+i-1]-'a'];
			tem%=MOD;
			if(tem<0)	tem+=MOD;
			if(SET[i].count(tem))
			{
				printf("%d",i);
				return 0;
			}
		}
	}
	printf("0");
	return 0;
}
