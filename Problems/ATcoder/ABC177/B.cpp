#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
char S[1024], T[1024];
int main()
{
    cin >> S >> T;
    int anss = 0x3f3f3f3f;
    for (int i = 0; S[i];i++)
    {
        int ans = 0;
        int flag = 0;
        int pos = i;
        for (int j = 0; T[j];j++)
        {
            if (!S[pos+j])
            {
                flag = 1;
                break;
            }
            if (S[pos + j] != T[j])
                ans++;
        }
        if (!flag)
            anss = min(anss, ans);
    }
    cout << anss << endl;
}