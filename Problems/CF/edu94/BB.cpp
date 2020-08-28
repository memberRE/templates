#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p, f, cnts, cntw, s, w;
        scanf("%d%d%d%d%d%d", &p, &f, &cnts, &cntw, &s, &w);
        int ans = 0;
        for (int i = 0; i <= cnts; ++i)
        {
            if (s * i > p)
                break;
            int j = min(cntw, (p - s * i) / w);
            int cs = cnts - i;
            int cw = cntw - j;
            int tot = i + j;
            if (s > w)
            {
                j = min(cw, f / w);
                tot += j + min(cs, (f - j * w) / s);
            }

            else
            {
                j = min(cs, f / s);
                tot += j + min(cw, (f - j * s) / w);
            }
            ans = max(ans, tot);
        }
        cout << ans << endl;
    }
}