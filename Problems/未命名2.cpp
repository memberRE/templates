#include <cstdio>
#include <list>
#include <iterator>
#include <unordered_map>
#include "pageReplace.h"
#define MAX_PHY_PAGE 64
#define MAX_PAGE 12
#define get_Page(x) (x >> MAX_PAGE)
using namespace std;
list<pair<int, int>> cache;
unordered_map <int, list<pair<int, int>>::iterator> page_map;

void pageReplace(long *physic_memery, long nwAdd)
{
	static int cnt = 0;
	int k = (nwAdd >> MAX_PAGE);
	auto iter = page_map.find(k);
	if (iter == page_map.end())
	{
		if (cache.size() == MAX_PHY_PAGE)
		{
			auto lst = cache.back();
			physic_memery[lst.second] = k;
			page_map.erase(lst.first);
			cache.pop_back();
			lst.first = k;
			cache.push_front(lst);
			page_map[k] = cache.begin();
		}
		else
		{
			cache.push_front({k,cnt});
			physic_memery[cnt] = k;
			cnt++;
			page_map[k] = cache.begin();
		}
	}
	else
	{
		int id = iter->second->second;
		cache.erase(iter->second);
		cache.push_front({k,id});
		page_map[k] = cache.begin();
	}
}
int main()
{
	long pages[4] = {0, 0, 0, 0};
	int x;
	while (~scanf("%d",&x))
	{
		pageReplace(pages, x);
		printf("%d\n",get_Page(x));
		for (int i=0; i<4; i++)
		{
			printf("%ld ", pages[i]);
		}
		printf("\n");
	}
	return 0;
}
