# BUAA Autumn Training 4

### F. Compute Power

​	https://codeforces.com/gym/257489/problem/F?mobile=false

**01分数规划+DP**

​		裸的01分数规划是选取k个$(a_i,b_i)$使得$\sum a_i / \sum b_i$的最小，做法是$令x=max{(\sum a_i / \sum b_i})$于是有$\sum a_i - x\sum b_i<=0$(注意这个式子没有max，代表任意的选取方案都比max小)，所以二分x，更新$a_i-xb_i$然后对其排序，取最小的k个检验是否$<=0$，复杂度为$O{(n(logn)^2)}$.

​		但是在这题，选择方式有一些变化，要求全部选择，但是每台机器可以允许运行第二个程序，第二个程序不对x做贡献，只要第一个程序消耗的“算力”要严格大于第二个即可。所以我们二分答案之后的检验需要用dp来进行。$dp[i][j][k]$表示，第i个程序（算力从大到小排序，保证后面的程序可以成为前面计算机的的第二个程序），还可以放j个程序作为第二个程序，有k个和$a_i$一样的程序作为了第一个程序，的最小值，转移很好推，每一个程序要么作为第一个程序要么作为第二个。

代码：

```cpp
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

```

----

