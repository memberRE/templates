#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

typedef pair<double,double> P;
struct edge
{
    P a,b;
    int l;
    bool operator < (const edge &x) const {return this->l<x.l;}
    bool operator == (const edge &x) const {return this->l==x.l;}
};
int n;
double ans;

bool can(int a,int b,int c)
{
    if(a+b<=c) return 0;
    if(a+c<=b) return 0;
    if(b+c<=a) return 0;
    return 1;
}

P getPoint(P a,int l1,P b,int l2)
{
    double x1=a.first,x2=b.first,y1=a.second,y2=b.second;
    double A=(x1-x2)/(y2-y1);
    double B=(x2*x2-x1*x1+l1*l1-l2*l2)/2/(y2-y1)+(y1+y2)/2-y1;
    double AA=1+A*A,BB=2*A*B-2*x1,CC=x1*x1+B*B-l1*l1;
    double x=(-BB+sqrt(BB*BB-4*AA*CC))/2/AA,xx=x=(-BB-sqrt(BB*BB-4*AA*CC))/2/AA;
    double y=A*x+B+y1,yy=A*xx+B+y1;
    return y>yy?P(x,y):P(xx,yy);
}

void dfs(set<int> b,set<edge> s)
{
    cout<<"asd"<<endl;
	if(b.size()<=1)
    {

        return;
    }
    for(set<int>::iterator i=b.begin();i!=b.end();i++)
        for(set<int>::iterator j=i;j!=b.end();j++)
        {
            
			if(j==i) j++;
            int l1=*i,l2=*j;
            b.erase(l1),b.erase(l2);
            for(set<edge>::iterator it=s.begin();it!=s.end();it++)
            {
                int l=it->l;
                edge e=*it;
                if(can(l,l1,l2))
                {
                    P p=getPoint(it->a,l1,it->b,l2);
                    s.erase(e);
                    s.insert((edge){e.a,p,l1});
                    s.insert((edge){e.b,p,l2});
                    dfs(b,s);
                    s.erase((edge){e.a,p,l1});
                    s.erase((edge){e.b,p,l2});
                    p=getPoint(it->b,l1,it->a,l2);
                    s.insert((edge){e.b,p,l1});
                    s.insert((edge){e.a,p,l2});
                    dfs(b,s);
                    s.erase((edge){e.b,p,l1});
                    s.erase((edge){e.a,p,l2});
                    s.insert(e);
                }
            }
            b.insert(l1),b.insert(l2);
        }
}

int main()
{
    cin>>n;
    set<int> e;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        e.insert(x);
    }
    for(set<int>::iterator it=e.begin();it!=e.end();it++)
    {
        //cout<<'h';
        int l=*it;
        e.erase(l);
        set<edge> s;
        s.insert((edge){P(0,0),P(l,0),l});
        dfs(e,s);
        e.insert(l);
    }

	return 0;
}
