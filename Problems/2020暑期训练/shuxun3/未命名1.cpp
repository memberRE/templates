
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
#include<float.h>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
const int N = 1e4 + 20;
double eps = 1e-9;
double d;
int n, b;
double p[N], h[N];
double delx[N];
double dmod(double x, double fac)
{
	int t = x / fac;
	return x - t * fac;
}

double min(double x, double y)
{
	if(x < y)return x;
	else return y;
}

double sqr(double x)
{
	return x * x;
}

int main()
{
	scanf("%lf%d%d", &d, &n, &b);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf%lf", &p[i], &h[i]);
	}
	double ans = LDBL_MAX;
	double g = 1.0;
	for(int i = b; i >= 0; i--)
	{
		double len = d / (i + 1);
		double sm_vx2 = LDBL_MAX;

		for(int j = 0; j < n; j++)
		{
			delx[j] = dmod(p[j], len);
			double tmp2 = (len * g * delx[j] - g * sqr(delx[j])) * 0.5 / h[j];
			sm_vx2 = min(sm_vx2, tmp2);
		}
		double line = len * g / 2.0;
		if(sm_vx2 > line + eps)
			sm_vx2 = line;
		double res = sqrt(sqr(len * g) * 0.25 / sm_vx2 + sm_vx2);
		ans = min(ans, res);
	}
	printf("%.5lf", ans);
	return 0;
}

