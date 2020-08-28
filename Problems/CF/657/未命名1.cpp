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
                    flag = 1;
                else
                    break;
            }
            if(T[j] == '\0')
            {
                ans[flag]++;
                if(flag == 1)
                    stk[top++] = i;
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
            if(ans[1] == 0)
            {
                cout << "No" << endl;
                continue;
            }
            int tem = -1;
            for (int i = 0; i < top;i++)
            {
                memcpy(SS, s, 55);
                for (int j = stk[i]; T[j - stk[i]];j++)
                    if(SS[j] == '?')
                        SS[j] = T[j - stk[i]];
                int fflag = 0;
                for (int k = 0;  k < n;k++)
                {
                    int j = k;
                    for (; T[j - k];j++)
                        if(SS[j] != T[j-k])
                            break;
                    if(!T[j-k])
                    {
                    	fflag = 1;
						break;
					}
                }
                if(!fflag)
                {
                	tem = stk[i];
				}
                if(tem != -1)
                    break;
            }
            if(tem == -1)
            {
                cout << "No" << endl;
                continue;
            }
            cout << "Yes" << endl;
            for (int i = tem; i < n && T[i - tem];i++)
                if(s[i] == '?')
                    s[i] = T[i - tem];
            for (int i = 0; i < n;i++)
                cout << ((s[i] == '?') ? 'z' : s[i]);
            cout << endl;
        }
    }
    return 0;
}
