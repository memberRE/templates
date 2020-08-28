#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[200009];
int main()
{
    scanf("%s", s);
    long long tem = 0;
    for (int i = 0; s[i];i++)
        tem += s[i] - '0';
    if (tem % 9 == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}