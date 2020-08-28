#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAX = 3e5 + 7;
char s[MAX];
int l[32], r[32];
int k;
int sum[MAX][30], vztd[30];
int nex[MAX][30];
char ans[MAX];
bool check(int loca,int len)
{
    int maxlen = 0,leastlen = 0;
    for (int i = 0; i < 26; i++)
    {
        leastlen += (l[i] - vztd[i]) < 0 ? 0 : (l[i] - vztd[i]);
        maxlen += vztd[i] + min(sum[loca][i], r[i] - vztd[i]);
        if (vztd[i] + sum[loca][i] < l[i])
            return false;
    }
    if(maxlen < k or leastlen + len > k)
        return false;
    return true;
}
void init()
{
    memset(vztd,0,sizeof(vztd));
    memset(sum,0,sizeof(sum));
    memset(nex,-1,sizeof(nex));
}
int main()
{
    while (scanf("%s%d", s, &k) != EOF)
    {
        for (int i = 0; i < 26; i++)
            scanf("%d%d", &l[i], &r[i]);
        int len = strlen(s);
        for (int i = len - 1; i >= 0; i--)
        {
            for(int j=0;j<26;j++)
            {
                sum[i][j]=sum[i+1][j];
                nex[i][j]=nex[i+1][j];
            }
            sum[i][s[i] - 'a']++;
            nex[i][s[i] - 'a'] = i;
        }
        int top = 0;
        for (int i = 0; i < len && top < k;)
        {
            bool flag = false;
            for (int p = 0; p < 26; p++)
            {
                if (nex[i][p] != -1 && vztd[p] < r[p])
                {
                    vztd[p]++;
                    if (check(nex[i][p] + 1, top + 1))
                    {
                        ans[top++] = p + 'a';
                        i = nex[i][p] + 1;
                        flag = true;
                        break;
                    }
                    vztd[p]--;
                }
            }
            if (!flag)
            {
                printf("-1\n");
                top = 0;
                break;
            }
        }
        ans[top]='\0';
        if(top) 
            printf("%s\n",ans);
	}
	return 0;
}
