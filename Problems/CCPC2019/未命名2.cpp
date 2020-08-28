#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#define ll long long
#define RI register int
#define A printf("A")
#define C printf(" ")
#define inf 2147483647
#define PI 3.1415926535898
using namespace std;
const int N=4e6+2;
//template <typename _Tp> inline _Tp max(const _Tp&x,const _Tp&y){return x>y?x:y;}
//template <typename _Tp> inline _Tp min(const _Tp&x,const _Tp&y){return x<y?x:y;}
template <typename _Tp> inline void IN(_Tp&x)
{
	char ch;
	bool flag=0;
	x=0;
	while(ch=getchar(),!isdigit(ch))if(ch=='-')flag=1;
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	if(flag)x=-x;
}
int n,m,a[N],ans,MX;
/*----------------------------------Splay-------------------------------------*/
int f[N],c[N],s[N],v[N],ch[N][2],rt[N],tot;
inline int chk(int x)
{
	return ch[f[x]][1]==x;
};
inline void Splay_del_node(int x)
{
	f[x]=s[x]=c[x]=v[x]=ch[x][0]=ch[x][1]=0;
};
inline void Splay_pushup(int x)
{
	s[x]=(ch[x][0]?s[ch[x][0]]:0)+(ch[x][1]?s[ch[x][1]]:0)+c[x];
};
inline void Splay_rotate(int x)
{
	int y=f[x],z=f[y],k=chk(x),v=ch[x][k^1];
	ch[y][k]=v;
	if(v)f[v]=y;
	f[x]=z;
	if(z)ch[z][chk(y)]=x;
	f[y]=x,ch[x][k^1]=y;
	Splay_pushup(y),Splay_pushup(x);
};
inline void Splay(int i,int x,int top=0)
{
	while(f[x]!=top)
	{
		int y=f[x],z=f[y];
		if(z!=top)Splay_rotate((ch[z][0]==y)==(ch[y][0]==x)?y:x);
		Splay_rotate(x);
	}
	if(!top)rt[i]=x;
};
inline void Splay_Insert(int i,int x)
{
	int pos=rt[i];
	if(!rt[i])
	{
		rt[i]=pos=++tot;
		v[pos]=x;
		s[pos]=c[pos]=1;
		f[pos]=ch[pos][0]=ch[pos][1]=0;
		return;
	}
	int last=0;
	while(1)
	{
		if(v[pos]==x)
		{
			++c[pos];
			Splay_pushup(last);
			break;
		}
		last=pos;
		pos=ch[pos][x>v[pos]];
		if(!pos)
		{
			pos=++tot;
			v[pos]=x;
			s[pos]=c[pos]=1;
			ch[last][x>v[last]]=pos;
			f[pos]=last;
			ch[pos][0]=ch[pos][1]=0;
			Splay_pushup(last);
			break;
		}
	}
	Splay(i,pos);
	return;
};
inline int Splay_rank(int i,int k)
{
	int x=rt[i],cal=0;
	while(x)
	{
		if(v[x]==k)return cal+((ch[x][0])?s[ch[x][0]]:0);
		else if(v[x]<k)
		{
			cal+=((ch[x][0])?s[ch[x][0]]:0)+c[x];
			x=ch[x][1];
		}
		else x=ch[x][0];
	}
	return cal;
};
inline int Splay_find(int i,int x)
{
	int pos=rt[i];
	while(x)
	{
		if(v[pos]==x)
		{
			Splay(i,pos);
			return pos;
		};
		pos=ch[pos][x>v[pos]];
	}
	return 0;
};
inline int Splay_pre(int i)
{
	int x=ch[rt[i]][0];
	while(ch[x][1])x=ch[x][1];
	return x;
}
inline int Splay_suc(int i)
{
	int x=ch[rt[i]][1];
	while(ch[x][0])x=ch[x][0];
	return x;
}
inline int Splay_Get_pre(int i,int x)
{
	int pos=rt[i];
	while(pos)
	{
		if(v[pos]<x)
		{
			if(ans<v[pos])ans=v[pos];
			pos=ch[pos][1];
		}
		else pos=ch[pos][0];
	}
	return ans;
};
inline int Splay_Get_suc(int i,int x)
{
	int pos=rt[i];
	while(pos)
	{
		if(v[pos]>x)
		{
			if(ans>v[pos])ans=v[pos];
			pos=ch[pos][0];
		}
		else pos=ch[pos][1];
	}
	return ans;
};
inline void Splay_Delete(int i,int key)
{
	int x=Splay_find(i,key);
	if(c[x]>1)
	{
		--c[x];
		Splay_pushup(x);
		return;
	}
	if(!ch[x][0]&&!ch[x][1])
	{
		Splay_del_node(rt[i]);
		rt[i]=0;
		return;
	}
	if(!ch[x][0])
	{
		int y=ch[x][1];
		rt[i]=y;
		f[y]=0;
		return;
	}
	if(!ch[x][1])
	{
		int y=ch[x][0];
		rt[i]=y;
		f[y]=0;
		return;
	}
	int p=Splay_pre(i);
	int lastrt=rt[i];
	Splay(i,p,0);
	ch[rt[i]][1]=ch[lastrt][1];
	f[ch[lastrt][1]]=rt[i];
	Splay_del_node(lastrt);
	Splay_pushup(rt[i]);
};
/*------------------------------Seg_Tree--------------------------------------*/
#define lc ((x)<<1)
#define rc ((x)<<1|1)
#define mid ((l+r)>>1)
inline void Seg_Insert(int x,int l,int r,int pos,int val)
{
	Splay_Insert(x,val);
	if(l==r)return;
	if(pos<=mid)Seg_Insert(lc,l,mid,pos,val);
	else Seg_Insert(rc,mid+1,r,pos,val);
};
inline void Seg_rank(int x,int l,int r,int L,int R,int Kth)
{
	if(l==L&&r==R)
	{
		ans+=Splay_rank(x,Kth);
		return;
	}
	if(R<=mid)Seg_rank(lc,l,mid,L,R,Kth);
	else if(L>mid)Seg_rank(rc,mid+1,r,L,R,Kth);
	else Seg_rank(lc,l,mid,L,mid,Kth),Seg_rank(rc,mid+1,r,mid+1,R,Kth);
};
inline void Seg_change(int x,int l,int r,int pos,int val)
{
//    printf("QvQ:: %d %d %d %d %d\n",x,l,r,pos,val);
	Splay_Delete(x,a[pos]);
	Splay_Insert(x,val);
	if(l==r)
	{
		a[pos]=val;
		return;
	};
	if(pos<=mid)Seg_change(lc,l,mid,pos,val);
	else Seg_change(rc,mid+1,r,pos,val);
};
inline void Seg_pre(int x,int l,int r,int L,int R,int val)
{
	if(l==L&&r==R)
	{
		ans=max(ans,Splay_Get_pre(x,val));
		return;
	}
	if(R<=mid)Seg_pre(lc,l,mid,L,R,val);
	else if(L>mid)Seg_pre(rc,mid+1,r,L,R,val);
	else Seg_pre(lc,l,mid,L,mid,val),Seg_pre(rc,mid+1,r,mid+1,R,val);
};
inline void Seg_suc(int x,int l,int r,int L,int R,int val)
{
	if(l==L&&r==R)
	{
		ans=min(ans,Splay_Get_suc(x,val));
		return;
	}
	if(R<=mid)Seg_suc(lc,l,mid,L,R,val);
	else if(L>mid)Seg_suc(rc,mid+1,r,L,R,val);
	else Seg_suc(lc,l,mid,L,mid,val),Seg_suc(rc,mid+1,r,mid+1,R,val);
};
/*---------------------------------ask----------------------------------------*/
inline int Get_Kth(int x,int y,int k)
{
	int L=0,R=MX+1,M;
	while(L<R)
	{
		M=(L+R)>>1;
		ans=0;
		Seg_rank(1,1,n,x,y,M);
		if(ans<k)L=M+1;
		else R=M;
	}
	return L-1;
};
/*-------------------------------main-------------------------------------*/
int main()
{
	IN(n),IN(m);
	for(RI i=1; i<=n; ++i)
	{
		IN(a[i]);
		Seg_Insert(1,1,n,i,a[i]);
		MX=max(MX,a[i]);
	}
	while(m--)
	{
		int op,x,y,v;
		IN(op),IN(x),IN(y);
		switch(op)
		{
			case 1:
			{
				IN(v);
				ans=0;
				Seg_rank(1,1,n,x,y,v);
				printf("%d\n",ans+1);
			}
			break;
			case 2:
			{
				IN(v);
				printf("%d\n",Get_Kth(x,y,v));
			}
			break;
			case 3:
			{
				Seg_change(1,1,n,x,y);
			}
			break;
			case 4:
			{
				IN(v);
				ans=-inf;
				Seg_pre(1,1,n,x,y,v);
				printf("%d\n",ans);
			}
			break;
			case 5:
			{
				IN(v);
				ans=inf;
				Seg_suc(1,1,n,x,y,v);
				printf("%d\n",ans);
			}
			break;
		}
	}
	return 0;
}
