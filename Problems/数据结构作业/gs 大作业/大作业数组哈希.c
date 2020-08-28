#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct tt{
	int link;
}VHASH;
typedef struct nn{
	int id;
	int next;
}EHASH;
typedef struct jj{
	char word[52];
	int pos[2001],time,next;
}FHASH;
FHASH B[25001]={};
int top=-1,id=-1,top2=-1;
VHASH hash[450001]={},hash2[25001];
EHASH A[450001]={};
char table[450001][52]={};
unsigned int To_Hash(char *str);
void Read_Dictionary(FILE *fp);
void Check_Book(FILE *fin);
void quick(int left,int right);
void Write(FILE *fout);
int main()
{
	FILE *fp=NULL,*fin=NULL,*fout=NULL;
	if((fp=(fopen("dictionary.txt","r")))==NULL)
		printf("can not find such file");
	if((fin=(fopen("article.txt","r")))==NULL)
		printf("can not find such file");
	if((fout=(fopen("misspelling.txt","w")))==NULL)
		printf("can not find such file");
	Read_Dictionary(fp);
	int i=0;
	for(i=0;i<20;i++)
		printf("%s\n",table[i]);
//	Check_Book(fin);
//	quick(0,top2);
//	Write(fout);
	fclose(fin);
	fclose(fout);
	fclose(fp);
	return 0;
}
void Write(FILE *fout)
{
	int i=0,j=0;
	for(i=0;i<=top2;i++)
	{
		fprintf(fout,"%s %d",B[i].word,B[i].time);
		for(j=0;j<B[i].time;j++)
			fprintf(fout," %d",(B[i].pos)[j]);
		fputc('\n',fout);
	}
}
void quick(int left,int right)
{     
    int i=0, last=0;
    FHASH tem;
    if(left<right){
        last=left; 
        for(i=left+1;i<=right;i++)
        {
        	if(B[i].time>B[left].time)
            {
             	tem=B[i];
             	B[i]=B[left];
             	B[left]=tem;
			} 
			else if ((B[i].time==B[left].time)&&(strcmp(B[i].word,B[left].word)>0))
			{
				tem=B[i];
             	B[i]=B[left];
             	B[left]=tem;
			}
		}
		tem=B[left];
		B[left]=B[last];
		B[last]=tem;
        quick(left,last-1); 
        quick(last+1,right);   
    }
}
void Check_Book(FILE *fin)
{
	int test=20;///测试 
	int i=-1,t=0,j=0,sig=0,now=0,flag=0;
	unsigned int h=0,hh=0;
	char c='0',temp[52];
	while(!feof(fin))
	{
		++i;
		c=fgetc(fin);
		if(isalpha(c))
		{
			sig=1;
			j=-1;
			t=i;
			temp[++j]=tolower(c);
			while(isalpha(c=fgetc(fin)))
			{
				++i;
				temp[++j]=tolower(c);
			}
			++i;
			temp[j+1]='\0';
			h=To_Hash(temp);
			hh=h%450001;
			now=hash[hh].link;
			while(A[now].next!=0)
			{
				if(strcmp(temp,table[A[now].id])==0)
				{
					sig=0;
					break;
				}
				else now=A[now].next;
			}
			if(sig==1)
			{
				hh=h%25001;
				if(hash2[hh].link==0)
				{
					hash2[hh].link=++top2;
					strcpy(B[top2].word,temp);
					B[top2].time=1;
					(B[top2].pos)[0]=t; 
				}
				else
				{
					flag=1;
					now=hash2[hh].link;
					while(B[now].next!=0)
					{
						if(strcmp(B[now].word,temp)==0)
						{
							(B[now].pos)[B[now].time]=t;
							(B[now].time)++;
							flag=0;
						}
						else now=B[now].next;
					}
					if(flag==1)
					{
						B[now].next=++top2;
						strcpy(B[top2].word,temp);
						B[top2].time=1;
						(B[top2].pos)[0]=t;
					}
				}
				if(test>0)/////测试 
				{
					printf("1");
					test--;
				}
			}
		}
	}
}
void Read_Dictionary(FILE *fp)
{
	unsigned int h=0;
	int now=0;
	char temp[52];
	while(!feof(fp))
	{
		fscanf(fp,"%s",temp);
		h=To_Hash(temp)%450001;
		if(hash[h].link==0)
		{
			hash[h].link=++top;
			A[top].id=++id;
//			A[top].next=0;//看需不需要初始化 
			strcpy(table[id],temp);
		}
		else
		{
			now=hash[h].link;
			while(A[now].next!=0)
				now=A[now].next;
			A[now].next=++top;
			A[top].id=++id;
//			A[top].next=0;//看需不需要初始化 
			strcpy(table[id],temp);
		}
	}
	
}
unsigned int To_Hash(char *str)
{
	unsigned int h=0;
	while(*str!='\0')
	{
		h=(h<<5)+*str;
		//h=h<<7+h<<1+h+*str;
		str++;
	}
	return h;	
}
