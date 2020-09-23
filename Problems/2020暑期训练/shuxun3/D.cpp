#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <math.h>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
const int MAX = 1e4 + 20;
const double eps = 1e-10;
pair<double, double> pic[MAX],tem_pic[MAX];
double dis;
int n, b;
double ans = 0x3f3f3f3f3f3f3f3f;
inline double get_vy(double x,double l)
{
    return l / (2.0 * x);
}
inline double get_highest(double x,double y,double d)
{
    double tem = d / 2.0;
    return -((tem * tem)/ (2 * x * x)) + (y * tem / x);
}
inline void  get_xy(double x,double y,double l,double & xx,double& yy)
{
    double tem = ((-x * x / 2.0) + (l / 2.0) * x) / y;
    xx = sqrt(fabs(tem));
    yy = get_vy(xx, l);
}
inline double get_a(double x, double h, double d){
	return h/ (d*d-x*x);
}
int main()
{
    scanf("%lf%d%d", &dis, &n, &b);
    for (int i = 1; i <= n;i++)
    {
        scanf("%lf%lf", &pic[i].first, &pic[i].second);
    }
    for (int i = 0; i <= b;i++)
    {
        double L = (dis / (double)(i + 1));
        double hightest = 0;
        double hia = -1;
        double fin_vx, fin_vy;
        for (int i = 1; i <= n;i++)
        {
            double vx, vy, xx, yy;
            xx = pic[i].first;
            yy = pic[i].second;
            while(xx > L)
                xx -= L;
            if (fabs(xx) < eps or fabs(xx - L) < eps)
                continue;
            get_xy(xx, yy, L, vx, vy);
            double temheig = get_highest(vx, vy, L);
            hia = max(get_a(fabs(L/2 - xx), yy, L/2), hia);
            if (temheig > hightest)
            {
                hightest = temheig;
                fin_vx = vx;
                fin_vy = vy;
            }
        }
        
        if(hia > 0){
        	//ans = sqrt(hia*L*L/2+ 0.5/hia);
		}
        if (hightest > 0)
        {
            double temans = sqrt(fin_vx * fin_vx + fin_vy * fin_vy);
            ans = min(ans, temans);
        }
    }
    printf("%.8lf", ans);
    return 0;
}
