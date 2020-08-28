#include<bits/stdc++.h>
using namespace std;
vector<int> a[60];
set<int>pf;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=1e4;i++)
		pf.insert(i*i);
	int ans=1;
	for(;;ans++)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i].empty())
			{
				a[i].push_back(ans);
				break;
			}
			int k=a[i].back()+ans;
			if(pf.count(k))
			{
				a[i].push_back(ans);
				break;
			}
			if(i==n)
			{
				printf("%d\n",ans-1);
				for(int j=1;j<=n;j++)
				{
					vector<int>::iterator it=a[j].begin();
					for(;it!=a[j].end();it++)
						printf("%d ",*(it));
					putchar('\n');
				}
				return 0;
			}
		}
	}
	
	return 0;
}
