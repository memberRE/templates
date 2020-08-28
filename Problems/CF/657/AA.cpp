#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
using namespace std;
char s[512],SS[512];
int stk[512];
char T[512] = "abacaba\0";
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cin >> s;
        strcpy(SS, s);
        //cout << s << "%%$%$%$%$%" << endl;
        int ans[2] = {0,0};
        int top = 0;
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            int flag = 0;
            for (; T[j];j++)
            {
                if(T[j] == s[i+j])
                    continue;
                if(s[i+j] == '?')
                {
                    flag = 1;
                }
                else
                    break;
            }
            if(T[j] == '\0')
            {
                int tem = -1;
                for (j = 0; T[j];j++)
                {
                    if(T[j] == s[i+j])
                        continue;
                    if(s[i+j] == '?')
                    {
                        flag = 1;
                        if(SS[i+j] == '?')
                            SS[i + j] = T[j];
                        else if(SS[i+j] == T[j])
                            SS[i + j] = 'z',tem = 1;
                    }
                    else
                        break;
                }
                ans[flag]++;
                if(flag == 1 && tem != -1)
                    ans[flag] -= 2;
            }
                
        }
        if(ans[0]  > 1)
        {
            cout << "No" << endl;
        }
        else if(ans[0] == 1)
        {
            cout << "Yes" << endl;
            for (int i = 0; i < n;i++)
                cout << ((s[i] == '?') ? 'z' : s[i]);
            cout << endl;
        }
        else
        {
            if(ans[1] <= 0)
            {
                cout << "No" << endl;
                continue;
            }
            cout << "Yes" << endl;
            for (int i = 0; i < n;i++)
                cout << ((SS[i] == '?') ? 'z' : SS[i]);
            cout << endl;
        }
    }
    return 0;
}