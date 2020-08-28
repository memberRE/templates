#include <cstdio>
#include <stdio.h>
//#include "pageReplace.h"
#define MAX_PHY_PAGE 4/*64*/
#define MAX_PAGE 12
#define get_Page(x) (x >> MAX_PAGE)
#define __list struct LIST_myPage 
using namespace std;
struct LIST_myPage {
    int pageMap;   // page in physic_memery
    int pageId; 
    int last;
    int next;
    int listType; // 1 is fir; 2 is sec
};
static __list List[128];
/*static int firHead = -1;
static int secHead = -1;
static int firTail = -1;
static int secTail = -1;*/
static int Head[3] = {-1, -1, -1};
static int Tail[3] = {-1, -1, -1};
static int cnt = 0;
static int mapp[MAX_PHY_PAGE];
void List_Remove(int index) {
    int type = List[index].listType;
    if (List[index].last == -1) {   //head
        Head[type] = List[index].next;
        if (List[index].next != -1) {   //删除之后队列不为空
            List[List[index].next].last = -1;
        }
        else {
            Tail[type] = -1;
        }
    }
    else {
        List[List[index].last].next = List[index].next;
        if (List[index].next != -1) {
            List[List[index].next].last = List[index].last;
        }
        else {
            Tail[type] = List[index].last;
        }
    }
}
void List_insert_head(int type, int index) {
    List[index].next = Head[type];
    List[index].last = -1;
    if (Head[type] != -1) {
        List[Head[type]].last = index;
    }
    else {
        Tail[type] = index;
    }
    Head[type] = index;
}
int List_empty(int head) {
    if (head == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
void pageReplace(long *physic_memery, long nwAdd)
{
    int k = (nwAdd >> MAX_PAGE);
    for (int i = 0; i < MAX_PHY_PAGE; i++)
    {
        if ( k == physic_memery[i])
        {
            List_Remove(mapp[i]);
            List_insert_head(2, mapp[i]);
            return;
        }
        if (physic_memery[i] == 0)
        {
            physic_memery[i] = k;
            List[cnt].listType = 1;
            List[cnt].last = -1;
            List[cnt].next = -1;
            List[cnt].pageId = k;
            List[cnt].pageMap = i;
            mapp[i] = cnt;
            cnt++;
            List_insert_head(1, cnt);
            return;
        }
    }
    int tem;
    if (List_empty(Head[2]) == 0) { //如果队列不为空格去除第二次访问最远的那个
        tem = Tail[2];
    }
    else {
        tem = Tail[1];
    }
    List_Remove(tem);
    physic_memery[List[tem].pageMap] = k;
    List[tem].listType = 1;
    List[tem].pageId = k;
    List[tem].last = List[tem].next = -1;
    List_insert_head(1, tem);
}
int main() {
    long pages[4] = {0, 0, 0, 0};
    int x;
    while (~scanf("%d",&x)) {
        pageReplace(pages, x);
        printf("%d\n",get_Page(x));
        for (int i=0; i<4; i++) {
            printf("%ld ", pages[i]);
        }
        printf("\n");
    }
    return 0;
}
