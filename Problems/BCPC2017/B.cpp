#include<bits/stdc++.h>
using namespace std;
const int MAX=5e6;
char s[MAX];
int bit[30]={1};
int dp,len;
bool pic[MAX];
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=30;i++)
		bit[i]=(1<<i);
	while(t--)
	{
		memset(pic,0,sizeof(pic));dp=0;
		scanf("%s",s);
		int k=1;
		len=strlen(s);
		for(;(1<<k)+k-1<=len;k++);
		int ans=k,cnt=0;
		k--;
		//---------------------------------�����õ�һ������ѡ�񳤶�Ϊk-1���Ӵ� 
		for(int i=0;i<k;i++)//�Ѵ�0��ʼ�ĵ�һ���Ӵ�Ū�� 
		{
			int num=s[i]-'0';
			dp+=num*bit[i];
		}
		pic[dp]=1;
		cnt++;
		for(int i=1;i<=len-k;i++)//Ū֮����Ӵ�
		{
			dp>>=1;
			dp+=((s[i+k-1]-'0')<<(k-1));
			if(!pic[dp])
				pic[dp]=1,cnt++;
		} 
		if(cnt!=(1<<k))
			ans--;
		k--;
		//--------------------------------------------��֤k��k+1 --> k 
		for(;k>=1;k--)
		{
			cnt=0;
			for(int i=0;i<=(1<<(k+1))-1;i++)
			{
				if(pic[i])
				{
					int ch=i&((1<<k)-1);
					pic[i]=0;
					if(!pic[ch])
						pic[ch]=1,cnt++;
				}
			}
			//���������Ǹ�
			int q=0;
			for(int i=len-k;i<len;i++)
				q+=(s[i]-'0')<<(i-len+k);
			if(!pic[q])
				pic[q]=1,cnt++;
			if(cnt!=(1<<k))
				ans=k;
		}
		printf("%d\n",ans);
	}
	return 0;
}
