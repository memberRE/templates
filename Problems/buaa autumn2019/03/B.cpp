#include<bits/stdc++.h>
using namespace std;
char pic[100500];
char stk[100500];
int top;
int main()
{
	scanf("%s",pic);
	int cnt=0;
	int flag=0;
	for(int i=0;pic[i];i++)
		if(pic[i]=='1')
			cnt++;
	for(int i=0;pic[i];i++)
	{
		if(pic[i]=='0')
			putchar('0');
		else if(pic[i]=='2')
		{
			if(!flag)
			{
				for(int j=1;j<=cnt;j++)
					putchar('1');
				flag=1;
			}
			putchar('2');
		} 	
	}
	if(!flag)
	{
		for(int j=1;j<=cnt;j++)
			putchar('1');
		flag=1;
	}
	return 0;
}
