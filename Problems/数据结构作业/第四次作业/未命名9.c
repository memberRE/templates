#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 200
#define MINSVR 3
#define MAXSVR 5
#define NUMBER 7

typedef struct
{
    int id;
    int wtime;
}CustType;

CustType queue[MAXSIZE];
int front=0,real=-1,num=0;
int Worknum=MINSVR;

int isEmpty();
int isFull();
void enQueue(CustType q);
CustType deQueue();
void updatetime();
void arriveCust();
void service();

int main(void)
{
    int clock,sumClock;
    scanf("%d",&sumClock);
    clock=1;
    while(1)
    {
        if(!isEmpty())
            updatetime();
        if(clock<=sumClock)
            arriveCust();
        service();
        if(num==0 && clock>sumClock)
            break;
        clock++;
    }
    return 0;
}

int isEmpty()
{
    return num==0;
}
int isFull()
{
    return num==MAXSIZE;
}
void enQueue(CustType q)
{

    if(isFull())
        exit(-1);
    else
    {
        real=(real+1)%MAXSIZE;
        queue[real]=q;
        num++;
    }
    return;
}
CustType deQueue()
{
    CustType q;
    if(isEmpty())
        exit(-1);
    else
    {
        q=queue[front];
        front=(front+1)%MAXSIZE;
        num--;
    }
    return q;
}
void updatetime()
{
    int i;
    for(i=0;i<num;i++)
        queue[(front+i)%MAXSIZE].wtime++;
    return;
}
void arriveCust()
{
    static int count=1;
    int i,n;
    CustType q;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        q.id=count++;
        q.wtime=0;
        enQueue(q);
    }
    while((num/Worknum)>=NUMBER && Worknum<MAXSVR)
        Worknum++;
    return;
}
void service()
{
    int i;
    CustType q;
    for(i=0;i<Worknum;i++)
        if(isEmpty())
            return;
        else
        {
            q=deQueue();
            printf("%d : %d\n",q.id,q.wtime);
        }
    while((num/Worknum)<NUMBER && Worknum>MINSVR)
        Worknum--;
    return;
}
