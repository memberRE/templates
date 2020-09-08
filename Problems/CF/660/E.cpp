#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
const int MAX = 2020;
int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while ((c > '9' || c < '0') && c != '-')
        c = getchar();
    if (c == '-')
        flag = 0, c = getchar();
    while (c <= '9' && c >= '0')
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return flag ? x : -x;
}
struct SEG
{
    double xl, xr, y;
    SEG(double xl, double xr, double y) : xl(xl), xr(xr), y(y) {}
    SEG() : xl(0), xr(0), y(0) {}
};
SEG seg[MAX];
vector<SEG> temm;
set<double> y_set;
vector<pair<double, double>> tem_vec;
vector<double> xielv;

template <typename Cmp_1, typename Cmp_2>
struct Convex_hull_trick
{
    int top;
    vector<pair<double, double>> pts;
    vector<double> X;
    pair<double, double> stk[3000];
    Cmp_1 cmp_1;
    Cmp_2 cmp_2;
    double cross(pair<double, double> A, pair<double, double> B)
    {
        return (A.first - B.first) / (B.second - A.second);
    }
    Convex_hull_trick(vector<SEG> &seg) : cmp_1(Cmp_1()), cmp_2(Cmp_2())
    {
        for (auto s : seg)
        {
            pts.emplace_back(s.xl, s.y);
            pts.emplace_back(s.xr, s.y);
        }
        sort(pts.begin(), pts.end(), [this](const pair<double, double> &A, const pair<double, double> &B) {
            if (abs(A.second - B.second) < 1e-8)
                return this->cmp_1(A.first, B.first);
            return this->cmp_2(A.second, B.second);
        });
        int i = 0;
        top = 0;
        stk[top++] = pts[0];
        while (i < pts.size() and abs(pts[i].second - pts[0].second) < 1e-8)
            i++;
        if (i == pts.size())
        {
            X.push_back(-0x3f3f3f3f3f3f3f3f);
            return;
        }
        stk[top++] = pts[i++];
        while (i < pts.size())
        {
            int j = i;
            while (j < pts.size() and abs(pts[j].second - pts[i].second) < 1e-8)
                j++;
            if (j == pts.size())
                break;
            auto cur = pts[j];
            while (top >= 2)
            {
                double cross_x = cross(stk[top - 1], stk[top - 2]);
                double cross_cur = cross(cur, stk[top - 2]);
                if (cross_cur < cross_x)
                    top--;
                else
                    break;
            }
            stk[top++] = cur;
            i = j + 1;
        }
        X.push_back(-0x3f3f3f3f3f3f3f3f);
        for (int i = 1; i < top; i++)
            X.push_back(cross(stk[i - 1], stk[i]));
    }
    double query(double a)
    {
        int idx = lower_bound(X.begin(), X.end(), a) - X.begin();
        idx--;
        return stk[idx].first + stk[idx].second * a;
    }
};
struct Less
{
    bool operator()(double A, double B)
    {
        return A < B;
    }
};
struct Great
{
    bool operator()(double A, double B)
    {
        return A > B;
    }
};
int main()
{
    int n = read();
    double maxx, mmin;
    for (int i = 1; i <= n; i++)
    {
        double xl, xr, y;
        cin >> xl >> xr >> y;
        seg[i] = SEG(xl, xr, y);
        temm.push_back(seg[i]);
        y_set.insert(y);
        if (i == 1)
            maxx = xr, mmin = xl;
        else
            maxx = max(maxx, xr), mmin = min(mmin, xl);
    }
    if (y_set.size() == 1)
    {
        cout << maxx - mmin << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (seg[i].y == seg[j].y)
                continue;
            auto s1 = seg[i];
            auto s2 = seg[j];
            if (s1.y > s2.y)
                swap(s1, s2);
            double beta1 = (s1.xr - s2.xl) / (s2.y - s1.y);
            double beta2 = (s1.xl - s2.xr) / (s2.y - s1.y);
            tem_vec.emplace_back(beta2, beta1);
        }

    sort(tem_vec.begin(), tem_vec.end());
    // 筛选出合法的方向向量（即保证不会存在重叠的投影）
    double cur = -0x3f3f3f3f3f3f3f3f;
    for (auto x : tem_vec)
    {
        if (x.first >= cur)
        {
            xielv.push_back(x.first);
            if (cur > -0x3f3f3f3f3f3f3f3f)
                xielv.push_back(cur);
        }
        cur = max(cur, x.second);
    }
    xielv.push_back(cur);
    //-------------------------------------------
    Convex_hull_trick<Less, Great> left(temm);
    Convex_hull_trick<Great, Less> right(temm);
    double ans = 0x3f3f3f3f3f3f3f3f;
    for(auto x : xielv) {
        double l = left.query(x);
        double r = right.query(x);
        ans = min(ans, r-l);
    }
    printf("%.10f\n", ans);
}