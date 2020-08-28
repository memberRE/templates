#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct queue{
	int id;
	struct queue *pre,*next;
}QUEUE;
int num=1;
QUEUE *number[100005];
QUEUE *front=NULL;
void Initial_Queue();
void Enter_Queue();
void Leave_Queue();
int main()
{
	int n=0,m;
//	freopen("123.txt","r",stdin);
	scanf("%d",&n);
	n--;
	Initial_Queue();
	while(n--)
		Enter_Queue();
	scanf("%d",&m);
	while(m--)
		Leave_Queue();
	front=front->next;
	while(front->next!=NULL)
	{
		printf("%d ",front->id);
		front=front->next;	
	}	
	return 0;	
}
void Leave_Queue()
{
	int id=0;
	scanf("%d",&id);
	if(number[id]!=NULL)
	{
		number[id]->pre->next=number[id]->next;
		number[id]->next->pre=number[id]->pre;
		free(number[id]);
		number[id]=NULL;
	}
	return ;
}
void Enter_Queue()
{
	int k=0,pos=0;
	num++;
	scanf("%d%d",&k,&pos);
	if((number[num]=(QUEUE *)malloc(sizeof(QUEUE)))==NULL)
	{
		printf("Malloc Fail");
		exit(-1);
	}
	memset(number[num],0,sizeof(QUEUE));
	number[num]->id=num;//????
	if(pos==0)
	{
		number[k]->pre->next=number[num];
		number[num]->pre=number[k]->pre;
		number[num]->next=number[k];
		number[k]->pre=number[num];
	}
	else if(pos==1)
	{
		number[k]->next->pre=number[num];
		number[num]->next=number[k]->next;
		number[num]->pre=number[k];
		number[k]->next=number[num];
	}
}
void Initial_Queue()//1???????????,???? 
{
	if((number[1]=(QUEUE*)malloc(sizeof(QUEUE)))==NULL)
	{
		printf("Malloc Fail");
		exit(-1);
	}
	memset(number[1],0,sizeof(QUEUE));
	number[1]->id=1;
	if((number[0]=(QUEUE*)malloc(sizeof(QUEUE)))==NULL)
	{
		printf("Malloc Fail");
		exit(-1);
	}
	memset(number[0],0,sizeof(QUEUE));
	number[0]->id=0;
	front=number[0];
	if((number[100004]=(QUEUE*)malloc(sizeof(QUEUE)))==NULL)
	{
		printf("Malloc Fail");
		exit(-1);
	}
	memset(number[100004],0,sizeof(QUEUE));
	number[100004]->id=-2;
	number[0]->next=number[1];
	number[1]->pre=number[0];
	number[0]->pre=NULL;
	number[1]->next=number[100004];
	number[100004]->pre=number[1];
	number[100004]->next=NULL;
}                               
