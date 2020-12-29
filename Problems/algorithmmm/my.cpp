#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
const int MAX = 1e5 + 20;
const int MAXN = 32768 + 1000;
int n, pic[MAX],dp[MAX];
int prevv[MAX];
int flag[MAX];
int w[MAX];
int las[MAXN];
int lower[MAXN];
//int firs[32768 + 1000];
set<int> sett;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
int main()
{
    //freopen("A.in","r",stdin);
	//n = read();
	cin>>n;
    int ans_index = 0;
    for (int i = 1; i <= n;i++)
    {
        //pic[i] = read();
        cin>>pic[i];
        sett.insert(pic[i]);
        //cout<<pic[i]<<endl;
        if (las[pic[i]] != 0)
            prevv[i] = las[pic[i]];
        las[pic[i]] = i;
    }
    int las_num = 0;
    for(int num:sett)
    {
    	lower[num] = las_num;
    	las_num = num;
	}
        
    for (int i = 1; i <= n;i++)
    {
        dp[i] = 1;
        //int flggg = 0;
        int j = las[lower[pic[i]]];
        if (prevv[i] != 0)
        {
            dp[i] = dp[prevv[i]], w[i] = prevv[i];
            goto enddd;
        }
        if (j != 0 and j < i)
        	if (dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1, w[i] = j;
        enddd:
        if (dp[i] >= dp[ans_index])
            ans_index = i;
    }
    cout<<sett.size() - dp[ans_index];
	// sett.clear();
	// int t = ans_index;
    // while(t)
    // {
    //     flag[t] = 1;
    //     t = w[t];
    // }
    // sett.clear();
    // for (int i = 1; i <= n;i++)
    //     if (flag[i] == 0)
    //     {
    //     	if (pic[i] == 0)
    //     		cout<<"@@@@@   "<<i<<endl;
	// 		sett.insert(pic[i]);
	// 	}
    // for(int num:sett)
    // 	cout<<num<<endl;
    // cout << sett.size() << endl;
}
