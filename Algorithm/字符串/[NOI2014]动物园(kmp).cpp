#include<bits/stdc++.h>
using namespace std;
const long long MAX=1e6+3 ,MOD=1000000007;
char s[MAX];
long long next[MAX],sum[MAX];
void getnext(char* t)
{
	memset(sum,0,sizeof(sum));
	memset(next,0,sizeof(next));
	sum[1]=1;
	int j=0;
	for(int i=1;t[i];i++)
	{
		while(j and t[i]!=t[j])	j=next[j];
		if(t[i]==t[j])	j++;
		next[i+1]=j;
		sum[i+1]=sum[j]+1;//�˴���1�о������ǲ��øüӵģ����ǣ����ﲻ�ӣ�����ҲҪ�ӣ����Ǽӵ�ǰ����ˣ��ӵ��Ǹ�1���������� 
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int len=strlen(s);
		getnext(s);
		long long cnt=1,j=0;
		for(int i=1;i<len;i++)
		{
			while(j and s[i]!=s[j])	j=next[j];
			if(s[i]==s[j])	j++;
			while((j<<1)>i+1)	j=next[j];
			
			cnt*=(sum[j]+1);
			cnt%=MOD;
		//	cout<<j<<' '<<cnt<<endl;
		}
		printf("%lld\n",cnt);
	}
}
