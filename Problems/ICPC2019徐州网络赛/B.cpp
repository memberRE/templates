#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int MAX=2e6+500;
struct ppp{
	int l,r;
	bool operator < (ppp a) const {
		return l<a.l;
	}
};
int read()
{
    int x=0,flag=1;
    char c=getchar ();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
char sjkui[100];
void print(int n)
{
    int t=0;
    while(n) sjkui[t++]=n%10+'0',n/=10;
    while(t--) putchar(sjkui[t]);
    //putchar(' ');
}
set<ppp> SET;
set<ppp>::iterator it;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	SET.insert((ppp){1,n});
	for(int i=1;i<=q;i++)
	{
		int opt,x;
		//scanf("%d%d",&opt,&x);
		opt=read();
		x=read();
		if(opt==1)
		{
			if(SET.end()==SET.begin())
				continue;
			it=SET.lower_bound((ppp){x,x});
			if(it==SET.end())
			{
				it--;
				if((*it).r<x)
					continue;
			}
			else if(it==SET.begin())
			{
					if((*it).l>x)
						continue;
			}
			else
			{
				if((*it).l!=x)
					it--;
				if((*it).r<x)
					continue;
			}
			ppp a=*it;
			SET.erase(it);
			if(x==a.l and x==a.r)
				continue;
			else if(x==a.l)
				SET.insert((ppp){a.l+1,a.r});
			else if(x==a.r)
				SET.insert((ppp){a.l,a.r-1});
			else
			{
				SET.insert((ppp){a.l,x-1});
				SET.insert((ppp){x+1,a.r});
			}
		}
		else
		{
			if(SET.end()==SET.begin())
			{
				putchar('-');putchar('1');putchar('\n');
				continue;
			}
			it=SET.lower_bound((ppp){x,x});
			if(it==SET.end())
			{
				it--;
				if((*it).r<x)
				{
					putchar('-');putchar('1');putchar('\n');
					continue;
				}
				else
				{
					print(x);putchar('\n');
					continue;
				}
			}
			else if(it==SET.begin())
			{
			//	printf("%d\n",(*it).l);
				print((*it).l);putchar('\n');
				continue;
			}
			else
			{
				if((*it).l>x)
				{
					it--;
					if((*it).r<x)
					{
						it++;
					//	printf("%d\n",(*it).l);
						print((*it).l);putchar('\n');
						continue;
					}
					else
					{
					//	printf("%d\n",x);
						print(x);putchar('\n');
						continue;
					}
				}
				else
				{
				//	printf("%d\n",x);
					print(x);putchar('\n');
					continue;
				}
			}
		}
	}
	return 0;
}
