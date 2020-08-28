#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX=1e6+5;
int n,k;
char dna[MAX],mi[]={'A','T','C','G'};
int DNA[MAX][2];
inline int id(char a)
{
	if(a=='A')
		return 0;
	if(a=='T')
		return 1;
	if(a=='C')
		return 2;
	return 3;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",dna);
		for(int i=0;i<n;++i)
			DNA[i][0]=id(dna[i]);
		int tem,cnt=0;
		while(k)
		{
			int y=(k&(-k));
			k-=y;
			for(int i=0;i<n;i++)
			{
				tem=i+y;
				tem%=n;
				DNA[i][cnt^1]=DNA[tem][cnt]^DNA[i][cnt];
			}
			cnt^=1;
		}
		for(int i=0;i<n;++i)
			putchar(mi[DNA[i][cnt]]);
		putchar('\n');
	}
	return 0;
}
