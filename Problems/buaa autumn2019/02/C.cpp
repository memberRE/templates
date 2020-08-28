#include<bits/stdc++.h>
using namespace std;
const int MAX=256;
struct ppp{
	int x,y;
}tri[10],xie[10];
int pic[MAX][MAX];
bool cam1(ppp a,ppp b)
{
	if(a.y==b.y)
		return a.x<b.x;
	return a.y>b.y;
}
int main()
{
	int x,y;
	for(int i=1;i<=4;i++)
	{
		scanf("%d%d",&x,&y);
		tri[i].x=x+101;
		tri[i].y=y+101;
	}
	for(int i=1;i<=4;i++)
	{
		scanf("%d%d",&x,&y);
		xie[i].x=x+101;
		xie[i].y=y+101;
	}
	sort(xie+1,xie+5,cam1);
	for(int x=xie[1].x,y=xie[1].y;x<=xie[3].x;x++,y--)
	{
		int x0=x-(xie[1].x-xie[2].x),y0=y-(xie[1].y-xie[2].y);
		for(int x1=x,y1=y;x1>=x0;x1--,y1--)
			pic[x1][y1]=1;
		if(x!=xie[3].x)
			for(int x1=x,y1=y-1;x1>=x0+1;x1--,y1--)
				pic[x1][y1]=1;
	}
	sort(tri+1,tri+5,cam1);
	for(int x=tri[1].x;x<=tri[2].x;x++)
		for(int y=tri[3].y;y<=tri[1].y;y++)
			if(pic[x][y]==1)
			{
				cout<<"YES";
				return 0;
			}
	cout<<"NO";
}
