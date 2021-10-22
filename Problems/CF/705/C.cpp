#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
const int MAX = 1e5+20;
char S[MAX];
int cnt[30];
int main()
{
    int t = read();
    while(t--)
    {
        int n = read(),k = read();
        for(int i = 0;i<=29;i++)
            cnt[i] = 0;
        scanf("%s",S);
        if (n%k != 0){
            printf("-1\n");
            continue;
        }

        for(int i = 0;i<n;i++)
        {
            cnt[S[i] - 'a']++;
        }
        int flag = 1;
        for(int i = 0;i<26;i++){
            if (cnt[i]%k!=0)
                flag = 0;
        }
        if (flag == 1)
        {
            puts(S);
            continue;
        }
        flag = 0;
        for(int i = n-1;i>=0;i--){
        	if (flag == 1)
        		break;
            cnt[S[i]-'a']--;
            if (S[i] == 'z')
                continue;
            for(int jjj = 1;jjj<26;jjj++)
            {
            	int temp = S[i]-'a'+jjj;
            	if (temp > 'z' - 'a')
            		break;
	            cnt[temp]++;
	            int total = 0;
	            for(int j=0;j<26;j++)
	                total += (k-(cnt[j]%k))%k;
	            if (total <= n-i-1)
	            {
	                //success
	                flag = 1;
	                for(int j = 0;j<i;j++)
	                    putchar(S[j]);
	                putchar(temp+'a');
	                for(int j = 1;j<=n-i-1-total;j++)
	                    putchar('a');
	                for(int j=0;j<26;j++){
	                    int summ = (k-(cnt[j]%k))%k;
	                    for(int kk = 1;kk<=summ;++kk)
	                        putchar(j+'a');
	                }
	                putchar('\n');
	                break;
	            }
	            cnt[temp]--;
			}
	            
        }
        if (flag == 0)
            puts("-1");
    }
    return 0;
}

