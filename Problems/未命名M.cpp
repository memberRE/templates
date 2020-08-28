#include<cstdio>
using namespace std;
int main()
{
	int n,i,h,tmp;
	while(scanf("%d",&n)!=EOF)
	{
		tmp=0;
		for(i=1;i<=2*n-1;i++)
		{
			scanf("%d",&h);
			tmp^=h;
		}
		printf("%d\n",tmp);
	}
	return 0;
}
