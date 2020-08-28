#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<time.h>
using namespace std;
const int MAX = 1e5 + 40;
int n;
char s[MAX];
int b_suf[MAX],a_len[MAX],ans[MAX];
int sa[MAX],rk[MAX],num[MAX],sec[MAX];
struct ppp{
    int a, d, id;
} pic[MAX];
void binsort(int N,int M)
{
	for(int i=0;i<=M;i++)	num[i]=0;
	for(int i=1;i<=N;i++)	num[rk[i]]++;
	for(int i=1;i<=M;i++)	num[i]+=num[i-1];
	for(int i=N;i>=1;i--)	sa[num[rk[sec[i]]]--]=sec[i];
}
void suffix_array(int N,int M)
{
	//M='z';
	for(int i=1;i<=N;i++)	rk[i]=b_suf[i] + 1,sec[i]=i;
	binsort(N,M);
	for(int w=1,p=0;p<N;w<<=1,M=p)
	{
		p=0;
		for(int i=1;i<=w;i++)	sec[++p]=N-w+i;
		for(int i=1;i<=N;i++)	if(sa[i]>w)	sec[++p]=sa[i]-w;
		binsort(N,M);
		swap(rk,sec);
        rk[sa[1]] = p = 1;
        for(int i=2;i<=N;i++)//重排rk 
			rk[sa[i]]=(sec[sa[i-1]]==sec[sa[i]] and sec[sa[i-1]+w]==sec[sa[i]+w]) ? p : ++p;
	}
}
bool cam(ppp a,ppp b)
{
    if (a.a != b.a)
        return a.a < b.a;
    else
        return a.d < b.d;
}
int main()
{
    clock_t sta = clock();
    while (scanf("%d", &n) != EOF)
    {
        scanf("%s", s + 1);
        for (int i = 2,j = 1;;i++)
        {
            if(!s[i])
            {
                for (; j < i;j++)
                    a_len[j] = i - j;
                break;
            }
            if(s[i] != s[j])
            {
                for (; j < i;j++)
                    a_len[j] = i - j + 1;
            }
        }
        int a = 0, b = 0;
        for (int i = 1; s[i];i++)
        {
            int *tem = (s[i] == 'a') ? &a : &b;
            if(*tem == 0)
                b_suf[i] = 0;
            else
                b_suf[i] = i - *tem;
            *tem = i;
        }
        
        suffix_array(n, n);
        
        for (int i = 1; i <= n;i++)
            pic[i].a = a_len[i], pic[i].d = rk[i + a_len[i]], pic[i].id = i;
        sort(pic + 1, pic + 1 + n, cam);
        for (int i = 1; i <= n;i++)
            printf("%d ", pic[i].id);
        putchar('\n');
    }
    clock_t endd = clock();
    cout<<"####   :"<<endd - sta<<endl;
    return 0;
}
