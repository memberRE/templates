#include<bits/stdc++.h>
#define P(x) ((ll)phi[x-1]*1000000ll+(ll)phi[x]+(ll)phi[x-2]*1000000000000ll)
//#define P(x) (phi[x-1]*100000+phi[x])
using namespace std;
typedef long long ll;
const int MAX=6e5+20;
int phi[622222]; 
struct ppp{
	int x,y,z;
	ll phi;
	bool operator < (ppp a) const {
	return phi<a.phi;
	}
};
set<ppp>S;
void euler(int n)
{
    for (int i=1;i<=n;i++) phi[i]=i;
    for (int i=2;i<=n;i++)
    {
        if (phi[i]==i)//这代表i是质数
        {
            for (int j=i;j<=n;j+=i)
            {
                phi[j]=phi[j]/i*(i-1);//把i的倍数更新掉
            }
        }
    }
}
int main()
{
	euler(MAX+10000);
	S.insert((ppp){1,2,3,P(3)});
	for(int i=4;i<=MAX;i++)
	{
		ppp a=(ppp){i-2,i-1,i,P(i)};
		if(S.count(a))
		{
			//set<ppp>::iterator it=S.lower_bound(a);
			//cout<<(*it).x<<' '<<(*it).y<<endl;
			//cout<<phi[(*it).x]<<' '<<phi[(*it).y]<<endl;
			//cout<<a.x<<' '<<a.y<<endl;
			cout<<phi[i-1]<<' '<<phi[i];
			return 0;
		}
		else
			S.insert(a);
	}
	return 0;
}
 
