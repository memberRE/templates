#include<unordered_map>
#include<map>
using namespace std;
typedef long long ll;
/*unordered_*/map <int,int> umap;
int main()
{
	for(int i = 1;i<=500*500*500;i++)
		umap[rand()] = rand();
	for(int i = 1;i<=500*500*500;i++)
		umap.find(rand());
}
