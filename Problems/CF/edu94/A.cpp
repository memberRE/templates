#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
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
int main()
{
    int t = read();
    while (t--)
    {
        int n = read();
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
            printf("%c", s[i * 2]);
        putchar('\n');
    }
    return 0;
}