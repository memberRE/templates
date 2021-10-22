#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
using namespace std;
const int MAX = 2e5+20;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
int tem_fib[30];
set<int> Fib;
int head[MAX],nex[MAX<<1],to[MAX<<1],val[MAX<<1],total;
int n;
inline void add(int x,int y)
{
	val[total] = 1;
	to[total] = y;
	nex[total] = head[x];
	head[x] = total;
	total++; 
}
bool check(int root,int size)
{
	
}
int main()
{
	tem_fib[0] = 1;
	tem_fib[1] = 1;
	for(int i=2;i<=25;i++)
		tem_fib[i] = tem_fib[i-1]+tem_fib[i-2],Fib.insert(tem_fib[i]);
	n = read();
	for(int i=1;i<=n;i++)
	{
		int x = read(),y = read();
		add(x,y);
		add(y,x);
    }
	if (Fib.find(n) == Fib.end() or !check(1,n))
		puts("NO");
	else 
		puts("YES");
}
