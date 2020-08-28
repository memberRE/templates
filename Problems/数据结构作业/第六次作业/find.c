#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NHASH  3001
#define MULT  37
unsigned int hash(char *str)
{
	unsigned int h=0;
	char *p;
	for(p=str; *p!='\0'; p++)
		h = MULT*h + *p;
	return h % NHASH;
}
char dir[3555][25];
int sy[30],tot=0;
int head[3001],nex[3555];
void find1(char *w)
{
	int i=0,num=0;
	for(i=0;i<tot;i++)
	{
		int k=strcmp(dir[i],w);
		num++;
		if(k==0)
		{
			printf("1 %d",num);
			putchar('\n');
			return ;
		}
		if(k>0)
		{
			printf("0 %d",num);
			putchar('\n');
			return ;
		}
	}
	printf("0 %d",num);
	putchar('\n');
	return ;
}
void find2(char *w)
{
	int l=0,r=tot-2;
	int num=0;
	while(l<=r)
	{
	//	printf("%d %d\n",l,r);
		int mid=(l+r)>>1;
		num++;
		int k=strcmp(dir[mid],w);
		if(k==0)
		{
			printf("1 %d",num);
			putchar('\n');
			return ;
		}
		if(k>0)
			r=mid-1;
		else
			l=mid+1;
	}
	printf("0 %d",num);
	putchar('\n');
	return ;
}
void find3(char *w)
{
	int l=sy[w[0]-'a'],r=sy[w[0]+1-'a']-1;
	int num=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
	//	printf("%d %d\n",l,r);
		num++;
		int k=strcmp(dir[mid],w);
		if(k==0)
		{
			printf("1 %d",num);
			putchar('\n');
			return ;
		}
		if(k>0)
			r=mid-1;
		else
			l=mid+1;
	}
	printf("0 %d",num);
	putchar('\n');
	return ;
}
void find4(char *w)
{
	unsigned int k=hash(w);
	int i,num=0;
	for(i=head[k];i!=-1;i=nex[i])
	{
		num++;
		int jkl=strcmp(dir[i],w);
		if(jkl==0)
		{
			printf("1 %d",num);
			putchar('\n');
			return ;
		}
		if(jkl>0)
		{
			printf("0 %d",num);
			putchar('\n');
			return ;
		}
	}
	printf("0 %d",num);
	putchar('\n');
	return ;
}
int main()
{
	FILE *in=fopen("dictionary3000.txt","r");
	while(fscanf(in,"%s",dir[tot++])!=EOF);
	memset(head,-1,sizeof(head));
	int i;
	for(i=0;i<tot;i++)
	{
		if(dir[i][0]!='a' && sy[dir[i][0]-'a']==0)
			sy[dir[i][0]-'a']=i;
	}
	for(i='z'-'a';i>=0;i--)
		if(sy[i]==0)
			sy[i]=sy[i+1];
	sy['z'-'a'+1]=tot-1;
	for(i=tot-1;i>=0;i--)
	{
		unsigned int h=hash(dir[i]);
		nex[i]=head[h];
		head[h]=i;
	}
	char tem[25];
	int op;
//	while(scanf("%s %d",tem,&op)!=EOF)
//	{
		scanf("%s %d",tem,&op);
		if(op==1)
			find1(tem);
		if(op==2)
			find2(tem);
		if(op==3)
			find3(tem);
		if(op==4)
			find4(tem);
//	}
	return 0;
}
