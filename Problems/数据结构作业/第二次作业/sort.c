#include<stdio.h>
#include<string.h>
typedef struct ppp{
	char name[30];
	long long num;
	int cnt,r,l;
}pp;
pp pic[120];
char nam[30];
int tot=0,root=1;
inline int add()
{
	tot++;
	scanf("%s %lld",pic[tot].name,&pic[tot].num);
	pic[tot].l=pic[tot].r=pic[tot].cnt=0;
	return tot;
}
int main()
{
	int n;
	scanf("%d\n",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		int p=add();
		int now=root;
		int flag=0;
		while(p!=root && now)
		{
			int k=strcmp(pic[now].name,pic[p].name);
			if(k>0)
			{
				pic[p].r=now;
				pic[p].l=pic[now].l;
				pic[pic[p].l].r=p;
				pic[now].l=p;
				pic[p].cnt=flag;
				if(pic[p].r==root)
					root=p;
				break;
			}
			else if(k==0)
			{
				if(pic[now].num==pic[p].num)
					break;
				flag++;
			}
			if(!pic[now].r)
			{
				pic[now].r=p;
				pic[p].l=now;
				pic[p].cnt=flag;
				break;
			}
			now=pic[now].r;
		}
	}
	for(i=root;i;i=pic[i].r)
	{
		printf("%s",pic[i].name);
		if(pic[i].cnt!=0)
		{
			putchar('_');
			printf("%d",pic[i].cnt);
		}
		putchar(' ');
		printf("%lld\n",pic[i].num);
	}
	return 0;
}
