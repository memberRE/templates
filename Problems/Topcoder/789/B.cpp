#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
class StringsBetween
{
public:
    ll count(int L, string A, string B)
    {
        ll ans = 1;
        for (int i = 0; i < L;i++)
        {
            ll a, b;
            a = i < A.size() ? A.at(i) - 'a' : 0;
            b = i < B.size() ? B.at(i) - 'a':'z'+1 - 'a';
            ll tem = b - a + 1;
            ans *= tem;
        }
        return ans - 1;
    }
};
int main() {
    for(auto tem: (new string())->c(31, 38))
    {
        cout << tem << endl;
    }
}