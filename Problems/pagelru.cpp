#include "pageReplace.h"
//#include <stdio.h>
#define MAX_PHY_PAGE 64
#define MAX_PAGE 12
#define get_Page(x) (x >> MAX_PAGE)
#define __list struct LIST_myPage
using namespace std;
struct LIST_myPage
{
	int pageId;
	int last;
	int next;
	int listType; // 1 is fir; 2 is sec
};
static LIST_myPage List[64];
static int Head[2] = {-1, -1};
static int Tail[2] = {-1, -1};
/*void List_Remove(int index) {
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
}*/
void pageReplace(long *physic_memery, long nwAdd)
{
	static int cnt = 0;
	int k = (nwAdd >> MAX_PAGE);
	int index = -1;
	int index2 = -1;
	/*for(int i = Head[0],j=Tail[0]; i!=-1 && j!=-1 ; i=List[i].next,j=List[j].last)
	{
		if(List[i].pageId == k)
		{
			index = i;
			break;
		}
		if(List[j].pageId == k)
		{
			index = j;
			break;
		}
		if(List[i].next == j || i==j)
			break;
	}*/
	for(int i=0; i+8<MAX_PHY_PAGE; i+=8)
	{
		if(List[i].pageId==k)
			index = i;
		if(List[i+1].pageId==k)
			index2 = i+1;
		if(List[i+2].pageId==k)
			index = i+2;
		if(List[i+3].pageId==k)
			index2 = i+3;
		if(List[i+4].pageId==k)
			index = i+4;
		if(List[i+5].pageId==k)
			index2 = i+5;
		if(List[i+6].pageId==k)
			index = i+6;
		if(List[i+7].pageId==k)
			index2 = i+7;
		if(index != -1 || List[i+7].pageId==0 || index2 != -1)
			break;
	}
	if (index == -1)
		index = index2;
	
	if (index == -1)
	{
		if (cnt == MAX_PHY_PAGE)
		{
			int rm = Tail[0];
			physic_memery[rm] = k;
			//List_Remove(rm);
			index = rm;
			int type = List[index].listType;
			if (List[index].last == -1)     //head
			{
				Head[type] = List[index].next;
				if (List[index].next != -1)
				{
					List[List[index].next].last = -1;
				}
				else
				{
					Tail[type] = -1;
				}
			}
			else
			{
				List[List[index].last].next = List[index].next;
				if (List[index].next != -1)
				{
					List[List[index].next].last = List[index].last;
				}
				else
				{
					Tail[type] = List[index].last;
				}
			}


			List[rm].pageId = k;
			List[rm].last = -1;
			List[rm].next = -1;
			//List_insert_head(0,rm);


			List[rm].next = Head[type];
			List[rm].last = -1;
			if (Head[type] != -1)
			{
				List[Head[type]].last = rm;
			}
			else
			{
				Tail[type] = rm;
			}
			Head[type] = rm;
		}
		else
		{
			List[cnt].pageId = k;
			List[cnt].next = List[cnt].last = -1;
			List[cnt].listType = 0;
			//List_insert_head(0,cnt);
			index = cnt;
			List[index].next = Head[0];
			List[index].last = -1;
			if (Head[0] != -1)
			{
				List[Head[0]].last = index;
			}
			else
			{
				Tail[0] = index;
			}
			Head[0] = index;

			physic_memery[cnt] = k;
			cnt++;
		}
	}
	else
	{
		//List_Remove(index);
		int type = List[index].listType;
		if (List[index].last == -1)     //head
		{
			Head[type] = List[index].next;
			if (List[index].next != -1)
			{
				List[List[index].next].last = -1;
			}
			else
			{
				Tail[type] = -1;
			}
		}
		else
		{
			List[List[index].last].next = List[index].next;
			if (List[index].next != -1)
			{
				List[List[index].next].last = List[index].last;
			}
			else
			{
				Tail[type] = List[index].last;
			}
		}

		//List_insert_head(0,index);
		List[index].next = Head[0];
		List[index].last = -1;
		if (Head[0] != -1)
		{
			List[Head[0]].last = index;
		}
		else
		{
			Tail[0] = index;
		}
		Head[0] = index;
	}
}
/*int main() {
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
}*/
