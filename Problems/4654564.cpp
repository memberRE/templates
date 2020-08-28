#include "pageReplace.h"
#include<unordered_map>
//#include <stdio.h>
#define MAX_PHY_PAGE 64
#define MAX_PAGE 12
#define get_Page(x) (x >> MAX_PAGE)
#define __list struct LIST_myPage 
#pragma GCC optimize(2)
using namespace std;
struct LIST_myPage {
    int pageId; 
    int last;
    int next;
    int listType; // 1 is fir; 2 is sec
};
unordered_map<int,int> page_map;
static LIST_myPage List[128];
static int Head[2] = {-1, -1};
static int Tail[2] = {-1, -1};
void List_Remove(int index) {
    int type = List[index].listType;
    if (List[index].last == -1) {   //head
        Head[type] = List[index].next;
        if (List[index].next != -1) {
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
	static int cnt = 0;
	int k = (nwAdd >> MAX_PAGE);
	int index = -1;
	unordered_map<int, int>::iterator iter = page_map.find(k);
	if (iter == page_map.end())
	{
		if (cnt == MAX_PHY_PAGE)
		{
			int rm = Tail[0];
			page_map.erase(page_map.find(List[rm].pageId));
			page_map.insert(make_pair(k,rm));
			physic_memery[rm] = k;
			List_Remove(rm);
			List[rm].pageId = k;
			List[rm].last = -1;
            List[rm].next = -1;
			List_insert_head(0,rm);
			
		}
		else
		{
			List[cnt].pageId = k;
			List[cnt].next = List[cnt].last = -1;
			List[cnt].listType = 0;
			List_insert_head(0,cnt);
			physic_memery[cnt] = k;
			page_map.insert(make_pair(k,cnt));
			cnt++;
		}
	}
	else
	{
		index = iter->second;
		List_Remove(index);
		List_insert_head(0,index);
	}
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
