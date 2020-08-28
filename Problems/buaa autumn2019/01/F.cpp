//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
const double MAX = 5e9;
using namespace std;
struct ppp{
	double a,b;
}pic[55];
double dp[55][55][55];
int n;
bool cam(ppp a,ppp b)
{
	return a.a>b.a;
}
bool judeg(double x)
{
	for (int i = 0; i <= n+1;i++)
		for (int j = 0; j <= n+1;j++)
			for (int k = 0; k <= n+1;k++)
				dp[i][j][k] = MAX;
	dp[0][0][0] = 0;
	for (int i = 1; i <= n;i++)
		for (int j = 0; j <= i;j++)
			for (int k = 0; k <= i;k++)
			{
				if(pic[i].a<pic[i-1].a)
				{
					dp[i][j][0] = min(dp[i][j][0], j - k + 1 >= 0 ? dp[i - 1][j - k + 1][k] : MAX);
					dp[i][j][1] = min(dp[i][j][1], j - k >= 0 ? dp[i - 1][j - k][k] + pic[i].a - x * pic[i].b : MAX);
				}
				else
					dp[i][j][k] = min(dp[i - 1][j + 1][k], k - 1 >= 0 ? dp[i - 1][j][k - 1] + pic[i].a - x * pic[i].b : MAX);
			}
	for (int j = 0; j <= n;j++)
		for (int k = 0; k <= n-j;k++)
			if(dp[n][j][k]<=0)
				return true;
	return false;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &pic[i].a);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &pic[i].b);
    sort(pic + 1, pic + 1 + n, cam);
    pic[0].a=-1e8;    
	double l=0,r=5e9;
	for (int i = 1; i <= 101; i++)
	{
		double mid=(l+r)/2;
		if(judeg(mid))
			r=mid;
		else
			l=mid;
	}
	cout<<(long long)(ceil(l*1000));
}
