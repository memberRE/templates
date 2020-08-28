#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4200;
const ll MOD=1e9+7;
const ll BASE=19260817;
ll base[30];
struct ppp{
	ll x,y;
	bool operator < (ppp a) const {
	if(x==a.x)
		return x<a.x;
	else
		return y<a.y;
	}
};
ppp Hash(int * a)
{
	ppp tem;
	tem.x=tem.y=0;
	for(int i=0;i<28;i++)
		tem.x+=(a[i]*base[i])%MOD,tem.y+=(a[27-i]*base[i])%MOD;
	tem.x%=MOD;
	tem.y%=MOD;
	return tem;
}
char s1[MAX],s2[MAX];
set<ppp> SET[4001];
int main()
{
	base[0]=1;
	for(int i=1;i<28;i++)
		base[i]=(base[i-1]*BASE)%MOD;
	int A[30];
	memset(A,0,sizeof(A));
	scanf("%s",s1);
	getchar();
	scanf("%s",s2);
	int len1=strlen(s1),len2=strlen(s2);
	for(int i=0;i<=len1;++i)
	{
		for(int j=0;j<28;++j)
			A[j]=0;
		for(int j=0;j<i;++j)
			A[s1[j]-'a']++;
		ppp tem=Hash(A);
		SET[i].insert(tem);
//		cout<<tem<<' '<<i<<' ' << '0' << endl;
		for(int j=1;j+i-1<len1;j++)
		{
			tem.x-=base[s1[j-1]-'a'];
			tem.x+=base[s1[j+i-1]-'a'];
			tem.x%=MOD;
			tem.y-=base[27-s1[j-1]+'a'];
			tem.y+=base[27-s1[j+i-1]+'a'];
			tem.y%=MOD;
			if(tem.x<0)	tem.x+=MOD;
			if(tem.y<0)	tem.y+=MOD;
			if(!SET[i].count(tem))
				SET[i].insert(tem);
//			cout<<tem<<' '<<i<<' '<<j<<endl;
		}	
	}
//	cout<<endl;
	for(int i=len2;i>=1;--i)
	{
		for(int j=0;j<28;++j)
			A[j]=0;
		for(int j=0;j<i;++j)
			A[s2[j]-'a']++;
		ppp tem=Hash(A);
//		cout<<tem<<' '<<i<<' '<< '0' <<endl;
		if(SET[i].count(tem))
		{
			printf("%d",i);
			return 0;
		}
		for(int j=1;j+i-1<len2;j++)
		{
			tem.x-=base[s2[j-1]-'a'];
			tem.x+=base[s2[j+i-1]-'a'];
			tem.x%=MOD;
			tem.y-=base[27-s2[j-1]+'a'];
			tem.y+=base[27-s2[j+i-1]+'a'];
			tem.y%=MOD;
			if(tem.x<0)	tem.x+=MOD;
			if(tem.y<0)	tem.y+=MOD;
//			cout<<tem<<' '<<i<<' '<<j<<endl;
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
