#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//32-126
typedef struct ppp{
	int sig,vztd;
	struct ppp *nex;
}node;
char miyue[130];
int vztd[130],mi[130];
node *root=NULL ,*endd=NULL;
char a[2009];
void creat()
{
	int i=0;
	for(i=0;i<=94;i++)
	{
		node* newnode;
		newnode=(node*)malloc(sizeof(node));
		newnode->sig=mi[i];
		newnode->vztd=0;
		newnode->nex=NULL;
		if(root==NULL)
			root=endd=newnode;
		else
		{
			endd->nex=newnode;
			endd=newnode;
		}
	}
	endd->nex=root;
}
int main()
{
	gets(miyue);
	int i=1,cnt=0;
	for(i=0;miyue[i];i++)
		if(!vztd[miyue[i]])
			mi[cnt++]=miyue[i],vztd[miyue[i]]=1;
	for(i=32;i<=126;++i)
		if(!vztd[i])
			mi[cnt++]=i,vztd[i]=1;
	creat();
	int fir=root->sig;
	node *noww=root;
	for(;cnt>=1;cnt--)
	{
		int num,k;
		num=k=noww->sig;
		noww->vztd=1;
		if(cnt==1)
		{
			mi[num]=fir;
			break;
		}
		for(;num>0;)
		{
			noww=noww->nex;
			if(noww->vztd==0)
				num--;
		}
			
		mi[k]=noww->sig;
	}
	FILE *in,*out;
	in=fopen("in.txt","r");
	out=fopen("in_crpyt.txt","w");
	while(fgets(a,2002,in)!=NULL)
	{
		int i;
		for(i=0;a[i];i++)
			if(a[i]>=32 && a[i]<=126)
				fputc(mi[a[i]],out);
			else
				fputc(a[i],out);
	}
	return 0;
}
