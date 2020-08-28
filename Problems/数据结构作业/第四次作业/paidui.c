#include<stdio.h>
#include<string.h>
#define MAX 1000000
typedef struct ppp{
	int que[MAX];
	int front,last;
}queue;
queue q;
int length()
{
	int len= q.last-q.front+1;
	if(len<0)	len+=MAX;
	return len;
}
int modify(int window)
{
	int len=length();
	if(len/window>=7) 
	{
		if(window<5)
			window++;
		if(len/window>=7 && window<5)
			window++;
	}
	else
	{
		if(window>3)
			window--;
	}
	
//	printf("     len: %d\n",len);
//	if(len<21)	window=3;
//	else if(len>=21 && len<28)	window=4;
//	else window=5;
//	printf("     win: %d\n",window);
//	system("pause");
	return window;
}
int main()
{
	int n,cnt=0,window=3;
	int i,tim=1;
	q.front=0;
	q.last=-1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		int j;
		for(j=1;j<=k;j++)
		{
			q.last++;
			q.last%=MAX;
			q.que[q.last]=tim;
		//	window=modify(window);
		}
		window=modify(window);
		for(j=1;j<=window;j++)
		{
			if(length()>0)
			{
				printf("%d : %d\n",++cnt,tim-q.que[q.front]);
				q.front++;
				q.front%=MAX;
			//	window=modify(window);
			}
		}
		tim++;
		window=modify(window);
	}
	while(length())
	{
		int i;
	//	system("pause");
	//	printf("        %d    \n",tim);
		for(i=1;i<=window;i++)
		{
			if(length()>0)
			{
				printf("%d : %d\n",++cnt,tim-q.que[q.front]);
				q.front++;
				q.front%=MAX;
			//	window=modify(window);
			}
		}
		tim++;
		//window=modify(window);
		if(length()/window<7 && window>3)
			window--;
	}
	return 0;
}
