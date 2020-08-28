#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
	char word[50];
	int count;
	struct node *left,*right;
}Node;
int Getword(FILE *fin,char tem[]);
Node *Read_From_File(FILE *fin);
void Print_Word(Node *first);
int main()
{
	FILE *fin;
	if((fin=fopen("article.txt","r"))==NULL)
		printf("Can not find such file");
	Node *first=Read_From_File(fin);
	Print_Word(first);
	fclose(fin);
}

int Getword(FILE*fin,char tem[])
{
	int i=0;
	char c;
	while(fscanf(fin,"%c",&c)!=EOF)
	{
		if(isalpha(c))
		{
			tem[i]=tolower(c);
			i++;
		}
		else if((!isalpha(c))&&i>0)
		{
			tem[i]='\0';
			break;
		}	
		else if(c==EOF)
			return -1;
	}
}

Node *Read_From_File(FILE *fin)
{
	Node *first=NULL,*p=NULL,*q=NULL;
	p=(Node*)malloc(sizeof(Node));
	if(p==NULL)			
		printf("Malloc fail");
	else
	{
		memset(p,0,sizeof(Node));
		Getword(fin,p->word);
		p->count=1;
		first=p;
	}
	q=(Node*)malloc(sizeof(Node));
	memset(q,0,sizeof(Node));
	q->count=-1;
	strcpy(q->word,"{");
	q->left=p;
	p->right=q;
	q=(Node*)malloc(sizeof(Node));
	memset(q,0,sizeof(Node));
	q->count=-1;
	strcpy(q->word,"0");
	first=q;
	q->right=p;
	p->left=q;
	while(1)
	{
		q=(Node*)malloc(sizeof(Node));
		if(q==NULL)	printf("Malloc fail");
		else
		{
			memset(q,0,sizeof(Node));
			if(Getword(fin,q->word)<0)
			{
				break;
			}
			q->count=1;
		}
		p=first;
		for(;p!=NULL;p=p->right)
		{
			if(strcmp(p->word,q->word)==0)
			{
				(p->count)++;
				break;
			}
			else if(strcmp(p->word,q->word)>0)
			{
					p->left->right=q;
					q->left=p->left;
					p->left=q;
					q->right=p;
					break;
			}
			else if(strcmp(p->word,q->word)<0)
					continue;
		}
	}
	return first;
}
void Print_Word(Node *first)
{
	Node *p=NULL;
	p=first;
	p=p->right;
	while(p->count>0)
	{
		printf("%s %d\n",p->word,p->count);
		p=p->right;
	}
	p=NULL,first=NULL;
}







