#include <cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 1e6 + 20;
struct _LIST {
    int val;
    int next;
}list[MAX];
int tot=1;
int listHeadA,listHeadB,listHeadAbB,listHeadAjB,listHeadAcB;
void creat(int &head) {
    while(1)
    {
        int tem;
        scanf("%d", &tem);
        if(tem == -1)
            break;
        list[tot].val = tem;
        list[tot].next = head;
        head = tot;
        tot++;
    }
}
void creatBin()
{
    for (int i = listHeadA; i;i = list[i].next) // copy listA
    {
        list[tot] = list[i];
        list[tot].next = listHeadAbB;
        listHeadAbB = tot;
        tot++;
    }
    for (int i = listHeadB; i;i = list[i].next) 
    {
        int flag = 0;
        for (int j = listHeadAbB; j;j = list[j].next)
        {
            if (list[j].val == list[i].val)
            {
                flag = 1;
                break;
            }
        } 
        if (!flag) 
        {
            list[tot] = list[i];
            list[tot].next = listHeadAbB;
            listHeadAbB = tot;
            tot++;
        }
    }
}
void creatJiao() 
{
    for (int i = listHeadA; i;i = list[i].next)
    {
        int flag = 0;
        for (int j = listHeadB; j;j = list[j].next)
        {
            if (list[j].val == list[i].val)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            list[tot] = list[i];
            list[tot].next = listHeadAjB;
            listHeadAjB = tot;
            tot++;
        }
    }
}
void creatCha()
{
    for (int i = listHeadA; i;i = list[i].next)
    {
        int flag = 0;
        for (int j = listHeadAjB; j;j = list[j].next)
        {
            if (list[j].val == list[i].val)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            list[tot] = list[i];
            list[tot].next = listHeadAcB;
            listHeadAcB = tot;
            tot++;
        }
    }
}
void print(int head)
{
    for (int i = head; i;i=list[i].next)
    {
        printf("%d ", list[i].val);
    }
    printf("-1\n");
}
int main()
{
    creat(listHeadA);
    creat(listHeadB);
    creatBin();
    creatJiao();
    creatCha();
    print(listHeadAjB);
    print(listHeadAbB);
    print(listHeadAcB);
    return 0;
}
