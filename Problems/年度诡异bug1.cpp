#include<stdio.h>
char str[100],sum;
int num,arr[100];
int main()
{
	int i,n,j,k=1,m;



	scanf("%d",&n);

	for(j=1; j<=n; j++)

	{ 

		scanf("%d",&m);

		for(i=1; i<=m; m++)

		{

			str[i]=getchar();

		}

		sum=str[1];

		for(i=1; i<=m-2; i+=2)

		{

			if(str[i+1]=='+')

			{

				sum+=str[i+2]-'0';

			}

			else if(str[i+1]=='-')

			{

				sum-=str[i+2]-'0';

				if(sum<'0')

				{

					num++;

					arr[k]=j;

					k++;

					break;

				}

			}

		}



	}

	printf("%d\n",num);

	for(i=1; i<=num; i++)

	{

		printf("%d\n",arr[i]);

	}

	return 0;

}

