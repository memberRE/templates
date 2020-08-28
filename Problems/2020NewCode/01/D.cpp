#include<iostream>
#include <cstdio>
#include <algorithm>
#include<cstring>
using namespace std;
const long long MOD = 998244353;
typedef long long ll;
ll n,var,equ,pic[256][256],x[256];
ll ans[256];
int gcd(ll X,ll Y)
{
    return Y ? gcd(Y, X % Y) : X;
}
void extgcd(ll a,ll b,ll& d,ll& X,ll& Y){
	if(!b)
    {
        d = a;
        X = 1;
        Y = 0;
    }
    else
    {
		extgcd(b,a%b,d,Y,X);
        Y -= X * (a / b);
    }
}
ll mod_inv(ll a,ll modp) {
	ll d,X,Y;
    while (a < 0)
        a += MOD;
    extgcd(a, modp, d, X, Y);
    return d == 1 ? (X + modp) % modp : -1;
}
void Gauss()
{
    ll i,j,k,col,max_r;
    for (k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        max_r = k;
        for (i = k + 1; i < equ; i++)
            if (abs(pic[i][col]) > abs(pic[max_r][col]))
                max_r = i;
        if (k != max_r)
        {
            for (j = col; j < var; j++)
                swap(pic[k][j],pic[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k] *= mod_inv(pic[k][col], MOD);
        x[k] %= MOD;
        for (j = col + 1; j < var; j++)
            pic[k][j] = (pic[k][j]%MOD * mod_inv(pic[k][col],MOD))%MOD;
        pic[k][col]=1;
        for (i = 0; i < equ; i++)
        {
            if (i != k)
            {
                x[i] -= x[k] * pic[i][col];
                x[i] %= MOD;
                for (j = col + 1; j < var; j++)
                {
                    pic[i][j] -= pic[k][j] * pic[i][col];
                    pic[i][j] %= MOD;
                }
                pic[i][col] = 0;
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        var = equ = n;
        for (int i = 0; i < n;i++)
            for (int j = 0; j < n;j++)
                scanf("%lld", &pic[i][j]);
        for (int i = 0; i < n;i++)
        {
            scanf("%lld", &x[i]);
            ans[i] = x[i];
        }
        Gauss();
        ll jkl = 0;
        for (int i = 0; i < n;i++)
        {
            jkl += (ans[i] * x[i]) % MOD;
            jkl %= MOD;
        }
        cout << (jkl >= 0 ? jkl : jkl + MOD) << endl;
    }
    return 0;
}