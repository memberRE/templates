#include<stdio.h>
#include<string.h>
int ans[205];
int main()
{
	char str[200],temp[200];
	int n,hjkl=0;
	scanf("%d\n",&n);
	scanf("%s",str);
	memset(ans,0,sizeof(ans));
	memset(temp,0,sizeof(temp));
	for(int i=0;i<=n;i++)
	{
		strcpy(temp,str);
		if(temp[i]=='V')
		{
			temp[i]='K';
		}
		else if(temp[i]=='K')
		{
			temp[i]='V';
		}
		for(int j=0;j<n;j++)
		{
			if(temp[j]=='V'&&temp[j+1]=='K')
			{
				ans[i]++;
			}	
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(ans[i]>hjkl)
		{
			hjkl=ans[i];
		}
	}
	
	printf("%d",hjkl);
	return 0;
}
