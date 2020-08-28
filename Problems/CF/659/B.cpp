#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1e5 + 20;
struct ppp{
    int ori, tar;
    bool operator < (const ppp &a) const {
        if (ori == tar)
            return false;
        if (ori != a.ori)
            return ori < a.ori;
        return tar < a.tar;
    }
}pic[MAX],pic2[MAX];
char s[MAX],T[MAX];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        scanf("%s", s);
        scanf("%s", T);
        int flag = 0;
        for (int i = 1; i <= n;i++)
        {
            pic[i].ori = s[i - 1];
            pic[i].tar = T[i - 1];
            if(s[i-1] > T[i-1])
                flag = 1;
        }
        if(flag)
        {
            cout << -1 << endl;
            continue;
        }
        int N = 1;
        sort(pic + 1, pic + 1 + n);
        for (int i = 1; i <= n;i++)
        {
            if (pic[i].tar != pic[i-1].tar || pic[i].ori != pic[i].tar)
            {
                if (pic[i].tar == pic[i].ori)
                    continue;
                pic2[N++] = pic[i];
            }
        }
        N--;
        ppp tem = (ppp){0, 0};
        int ans = N;
        for (int i = 1; i <= N;i++)
        {
            if (pic[i].tar == pic[i].ori)
                break;
            if (tem.ori != pic[i].ori || tem.tar != pic[i].tar)
            {
                tem = pic[i];
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}