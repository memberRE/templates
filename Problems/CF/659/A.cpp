#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[128][128];
int pic[128];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++)
            cin >> pic[i];
        s[0][0] = 0;
        for (int i = 1; i <= pic[1];i++)
            s[0][i - 1] = 'a', s[0][i] = 0;
        if(pic[1] == 0)
            s[0][0] = 'a', s[0][1] = 0;
        for (int i = 1; i <= n;i++)
        {
            int len = strlen(s[i-1]);
            //strcpy(s[i], s[i - 1]);
            while (len < pic[i])
            {
                s[i - 1][len] = 'a';
                if (i - 2 >= 0 && s[i-2][len] == s[i-1][len])
                    s[i - 1][len]++;
                s[i - 1][len + 1] = 0;
                len++;
            }
            if (len > pic[i])
                strncpy(s[i], s[i - 1], pic[i]),s[i][pic[i]] = 0;
            else
                strcpy(s[i], s[i - 1]);
            if(strlen(s[i]) == 0)
                s[i][0] = (s[i - 1][0] + 1 > 'z') ? 'a' : s[i - 1][0] + 1,s[i][1] = 0;
            cout << s[i - 1] << endl;
        }
        cout << s[n] << endl;
    }
    return 0;
}