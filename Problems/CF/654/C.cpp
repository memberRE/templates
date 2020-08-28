#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll c, v, fir, sec;
        cin >> v >> c >> fir >> sec;
        if(v+c<fir+sec)
        {
            cout << "No" << endl;
            continue;
        }
        if(v != c)
        {
            ll cha = abs(v - c);
            if (cha >= fir)
            {
                if(v > c)
                {
                    v -= fir;
                    fir = 0;
                }
                else
                {
                    c -= fir;
                    fir = 0;
                }
            }
            else
            {
                v = c = min(v, c);
                fir -= cha;
            }
        }
        if (fir + sec == 0)
        {
            if(v + c != 0)
            {
                cout << "No" << endl;
                continue;
            }
            else
            {
                cout << "Yes" << endl;
                continue;
            }
        }
        if (v != c)
        {
            if(min(v,c) >= sec)
            {
                cout << "Yes" << endl;
                continue;
            }
            else
            {
                cout << "No" << endl;
                continue;
            }
        }
        else
        {
            ll tem = min(fir, sec);
            v -= tem;
            c -= tem;
            fir -= tem;
            sec -= tem;
            if (fir == 0)
            {
                if(v >= sec)
                {
                    cout << "Yes" << endl;
                    continue;
                }
                else
                {
                    cout << "No" << endl;
                    continue;
                }
            }
            else
            {
                cout << "Yes" << endl;
                continue;
            }
        }
    }
    return 0;
}