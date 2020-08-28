#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define chl k<<1
#define chr k<<1|1
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
const int MAX=3e5+100;
const int maxn=3e5+5;
const int TYPE=26;
typedef bitset<26> B;
int cnt[MAX],fail[MAX],len[MAX],las,tot=1,ch[MAX][26],loca[MAX];
char s[MAX];
LL ans;

B tree[maxn<<2];
int n;
void push_up(int k) {tree[k]=tree[chl]|tree[chr];}
void build(int k,int l,int r)
{
    if(l>r) return;
    if(l==r)
    {
        tree[k][s[l]-'a']=1;
        return;
    }
    build(chl,l,mid);
    build(chr,mid+1,r);
    push_up(k);
}
B query(int k,int l,int r,int ll,int rr)
{
    if(l>rr || ll>r) return 0;
    if(l>=ll && r<=rr) return tree[k];
    return query(chl,l,mid,ll,rr)|query(chr,mid+1,r,ll,rr);
}

//int main()
//{
//    //freopen("input.txt","r",stdin);
//    scanf("%s",s+1);
//    
//    int l,r;
//    while(~scanf("%d %d",&l,&r)) cout<<query(1,1,n,l,r).count()<<endl;
//
//	return 0;
//}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
    build(1,1,n);
	s[0]='#';
	len[1]=-1;
	fail[0]=1;
	las=0;
	for(int i=1;s[i];++i)
	{
		while(s[i-len[las]-1]!=s[i])
			las=fail[las];
		if(!ch[las][s[i]-'a'])
		{
			tot++;
			loca[tot]=i;  // new insert
			len[tot]=len[las]+2;
			int j=fail[las];
			while(s[i-len[j]-1]!=s[i])
				j=fail[j];
			fail[tot]=ch[j][s[i]-'a'];
			ch[las][s[i]-'a']=tot;
		}
		las=ch[las][s[i]-'a'];
		cnt[las]++;
	}
//	for(int i=tot;i;--i)
//	{
//		cnt[fail[i]]+=cnt[i];
//		int l=loca[i],r;
//		if(len[i]&1)
//		{
//			int jkl=len[i]>>1;
//			l=loca[i]-jkl;
//			r=loca[i]+jkl;
//		}
//		else
//		{
//			
//		}
//		ans+=(LL)cnt[i]*()
//	}
	for(int i=0;i<=tot;i++)
		cout<<loca[i]<<' ';
	cout<<ans;
	return 0;
}
