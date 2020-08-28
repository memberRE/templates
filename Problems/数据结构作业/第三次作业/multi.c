#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ppp{
	int xi,zhi;
	struct ppp *nex;
}node;
node *p1,*p2;
node * creat()
{
	int x,y;
	node * root=NULL;
	node * endd=NULL;
	while(scanf("%d%d",&x,&y))
	{
		node* tem=malloc(sizeof(node));
		tem->xi=x;
		tem->zhi=y;
		tem->nex=NULL;
		if(root==NULL)
			root=endd=tem;
		else
		{
			endd->nex=tem;
			endd=tem;
		}
		char c=getchar();
		if(c=='\n')	break;
	}
	return root;
}
int main()
{
	p1=creat();
	p2=creat();
	node * nowp1=p1;
	node * nowp2=p2;
	node * root=NULL;
	node * endd=NULL;
	for(;nowp1!=NULL;nowp1=nowp1->nex)
	{
		for(nowp2=p2;nowp2!=NULL;nowp2=nowp2->nex)
		{
			int xi=nowp1->xi*nowp2->xi;
			int zhi=nowp1->zhi+nowp2->zhi;
			node * newnode=malloc(sizeof(node));
			newnode->xi=xi;
			newnode->zhi=zhi;
			newnode->nex=NULL;
			if(root==NULL)
				root=endd=newnode;
			else
			{
				if(endd->zhi>newnode->zhi)
				{
					endd->nex=newnode;
					endd=endd->nex;
				}
				else if(root->zhi<newnode->zhi)
				{
					newnode->nex=root;
					root=newnode;
				}
				else
				{
					node * las=root,*noww=root;
					for(;noww!=NULL;noww=noww->nex)
					{
						if(noww->zhi==newnode->zhi)
						{
							noww->xi+=newnode->xi;
							break;
						}
						if(noww->zhi<newnode->zhi)
						{
							las->nex=newnode;
							newnode->nex=noww;
							break;
						}
						las=noww;
					}
				}
			}

		}
	}
	node * noww=root;
	for(noww=root;noww!=NULL;noww=noww->nex)
		printf("%d %d ",noww->xi,noww->zhi);
	return 0;
}
