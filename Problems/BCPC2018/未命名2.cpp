#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAX=1e5+5;
int p[MAX],n;
vector<int> a[MAX];
int pic[MAX];
int ans=0;
inline int find(int x)
{
	if(p[x]==x)
		return x;
	else
	{
		p[x]=find(p[x]);
		return p[x];
	}
}
inline int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(pic,0,sizeof(pic));
		for(int i=0;i<=100000;i++)
			vector<int>().swap(a[i]);
		ans=0;
		int r=-1;
		for(int i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			pic[i]=k;
			r=max(r,k);//maxxÎªgcdÉÏ½ç
			a[k].push_back(i);
		}
		for(int i=1;i<=n;i++)
			p[i]=i;
		int cnt=0;
			for(int i=r;i>=1;--i) //i=gcd
			{
				for(int k=1;k<=n;k++)
				{
					if(pic[k]%i==0)
					{
						for(int j=1;i*j<=r;++j)
						{
							int hjk=a[i*j].size();
							if(hjk>0)
							{
								for(int h=0;h<hjk;h++)
								{
									int aa=find(k),bb=find(a[i*j][h]);
									if(aa!=bb)
									{
										ans+=i;
										p[aa]=bb;
										cnt++;
										if(cnt==n-1)
											break;
									}
								}
							}
						}
					}
				}
			//	if(i==1)	break;
			}
		while(cnt<n-1)
		{
			ans++;
			cnt++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
