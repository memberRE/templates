#include<stdio.h>
#include<string.h>
#define MAX 512
typedef struct ppp{
	int stk[MAX],top;
} stack;
int empty(stack * iop)
{
	if(iop->top==0)
		return 1;
	else if(iop->top>0)
		return 0;
	printf("error\n");
	return -1;
}
void pop(stack * iop)
{	
	if(empty(iop)==1)
		printf("error\n");
	iop->top--;
}
void push(stack * iop,int k)
{
	iop->stk[iop->top]=k;
	iop->top++;
}
int topp(stack * iop)
{
	if(iop->top>0)
		return iop->stk[iop->top-1];
	else
		printf("error\n");
	return 0;
}
stack ssign,scal,sans,caltree;
int node[MAX],ls[MAX],rs[MAX],tot;
int yx[50];
int main()
{
	int k=-1;
	yx['+']=1;yx['-']=1;yx['*']=2;yx['/']=2;yx['%']=2;yx['(']=0;
	ssign.top=scal.top=0;
	while(1)
	{
		char tem=getchar();
		if(tem=='=')
		{
			if(k!=-1)
				push(&scal,k);
			while(!empty(&ssign))
			{
				push(&scal,0-topp(&ssign));
				pop(&ssign);
			}
			break;
		}
		if(tem>='0' && tem<='9')
		{
			if(k==-1)
				k=0;
			k*=10;
			k+=tem-'0';
			continue;
		}
		if(tem=='+' || tem=='-' || tem=='*' || tem=='/' ||tem=='%' || tem=='(' ||tem==')')
		{
			if(k!=-1)
			{
				push(&scal,k);
				k=-1;
			}
			if(tem=='(')
				push(&ssign,'(');
			else if(tem==')')
			{
				while(topp(&ssign)!='(')
				{
					push(&scal,0-topp(&ssign));
					pop(&ssign);
				}
				pop(&ssign);
			}
			else
			{
				while(!empty(&ssign) && yx[tem]<=yx[topp(&ssign)])
				{
					push(&scal,0-topp(&ssign));
					pop(&ssign);
				}
				push(&ssign,tem);
			}
		}
	}
	int i;
	for(i=0;i<scal.top;i++)
	{
		int tem=scal.stk[i];
		if(tem>=0)//caozuoshu
			push(&sans,tem);
		else
		{
			int k1=topp(&sans);
			pop(&sans);
			int k2=topp(&sans);
			pop(&sans);
			tem*=-1;
			int anss=0;
			if(tem=='+')
				anss=k2+k1;
			else if(tem=='-')
				anss=k2-k1;
			else if(tem=='*')
				anss=k2*k1;
			else if(tem=='/')
				anss=k2/k1;
			else if(tem=='%')
				anss=k2%k1;
			push(&sans,anss);
		}
	}
	for(i=0;i<scal.top;i++)
	{
		int tem=scal.stk[i];
		if(tem>=0)
		{
			tot++;
			node[tot]=tem;
			push(&caltree,tot);
		}
		else
		{
			tot++;
			node[tot]=tem;
			int k1=topp(&caltree);
			pop(&caltree);
			int k2=topp(&caltree);
			pop(&caltree);
			ls[tot]=k2;
			rs[tot]=k1;
			push(&caltree,tot);
		}
	}
	int root=topp(&caltree);
	if(node[root]<0)
		printf("%c",-node[root]);
	else 
		printf("%d",node[root]);
	if(ls[root]>0)
	{
		if(node[ls[root]]<0)
			printf(" %c",-node[ls[root]]);
		else 
			printf(" %d",node[ls[root]]);
	}
	if(rs[root]>0)
	{
		if(node[rs[root]]<0)
			printf(" %c",-node[rs[root]]);
		else 
			printf(" %d",node[rs[root]]);
	}
	putchar('\n');
	printf("%d",topp(&sans));
	return 0;
}
