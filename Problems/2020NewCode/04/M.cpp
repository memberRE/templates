#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 2e5 + 20;
int prime[MAX],cnt;
int vztd[MAX],is_prime[MAX];
int A[MAX], B[MAX], top;
int stk[MAX], stktop;
void get_prime()//欧拉筛 
{
	for(int i=2;i<MAX;i++)
	{
		if(!is_prime[i])
			prime[cnt++]=i;
		for(int j=0;i*prime[j]<MAX;++j)
		{
			is_prime[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}
void init()
{
    top = 0;
    memset(vztd, 0, sizeof(vztd));
}
int main()
{
    int t;
    cin >> t;
    get_prime();
    while(t--)
    {
        init();
        int n;
        scanf("%d", &n);
        int max_pri = upper_bound(prime, prime + cnt, n) - prime;
        for (int i = max_pri - 1; i > 0;i--)
        {
            int ppcnt = n / prime[i] - 1;
            if (ppcnt <= 0)
                continue;
            ppcnt++;
            stktop = 0;
            int even_ = -1;
            for (int j = 1,tem; (tem = j * prime[i]) <= n;j++)
            {
                if (vztd[tem] != 1)
                {
                    stk[stktop++] = tem;
                    if(!(tem & 1) && even_ == -1)
                        even_ = tem;
                }
            }
            if(stktop & 1)
            {
                for (int j = 0; j < stktop;j+=2)
                {
                    if(stk[j] == even_)
                    {
                        j--;
                        continue;
                    }
                    if(stk[j + 1] == even_)
                    {
                        vztd[stk[j]] = 1;
                        vztd[stk[j + 2]] = 1;
                        A[top] = stk[j];
                        B[top] = stk[j + 2];
                        top++;
                        j++;
                        continue;
                    }
                    vztd[stk[j]] = 1;
                    vztd[stk[j + 1]] = 1;
                    A[top] = stk[j];
                    B[top] = stk[j + 1];
                    top++;
                }
            }
            else
            {
                for (int j = 0; j < stktop;j+=2)
                {
                    vztd[stk[j]] = 1;
                    vztd[stk[j + 1]] = 1;
                    A[top] = stk[j];
                    B[top] = stk[j + 1];
                    top++;
                }
            }
        }
        int las = -1;
        for (int i = 2; i <= n;i+=2)
        {
            if(vztd[i])
                continue;
            if(las == -1)
                las = i;
            else
            {
                A[top] = las;
                B[top] = i;
                las = -1;
                top++;
            }
        }
        printf("%d\n", top);
        for (int i = 0; i < top;i++)
        {
            printf("%d %d\n", A[i], B[i]);
        }
    }
    return 0;
}
