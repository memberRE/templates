#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pic[256],n,op,ans=0,tem[256];
void swap(int *a,int *b)
{
	int c=*a;
	*a=(*b);
	*b=c;
}
int cam(const void *a,const void *b)
{
	return *((int*)a)-*((int*)b);
}
void  bubbleSort(int k[ ])
{
	int i, j, flag=1;
	int temp;
	for(i=n-1; i>0 && flag==1; i--)
	{
		flag=0;                
		for(j=0; j<i; j++)
		{
			if(k[j]>k[j+1])
			{
				temp=k[j];
				k[j]=k[j+1];
				k[j+1]=temp;
				flag=1;              
			}
			ans++;
		}
			
	}
}
/*void adjust(int k[ ],int i,int N)
{
	int j,temp;
	temp=k[i];
	j=2*i+1;
	while(j<N)
	{
		if(j<N-1 && k[j]<k[j+1])
			j++;
		ans++;
		if(temp>=k[j])
			break;
		k[(j-1)/2]=k[j];
		j=2*j+1;
	}
	k[(j-1)/2]=temp;
}*/
void adjust(int k[],int i,int n)
{
	int j,temp;
	temp=k[i];
	j=2*i+1;
	while(j<n)
	{
		if(j<n-1 && k[j]<k[j+1])
			j++;
		ans++;
		if(temp>=k[j])
			break;
		k[(j-1)/2]=k[j];
		j=2*j+1;
	}
	k[(j-1)/2]=temp;
}
void heapSort(int k[])
{
	int i;
	int temp;
	for(i=n/2-1; i>=0; i--)
		adjust(k,i,n);
	for(i=n-1; i>=1; i--)
	{
		temp=k[i];
		k[i]=k[0];
		k[0]=temp;
		adjust(k,0,i);
	}
}
void merge(int x[ ],int tmp[ ],int left,int leftend,int rightend)
{
	int i=left, j=leftend+1, q=left;
	while(i<=leftend && j<=rightend)
	{
		ans++;
		if(x[i]<=x[j])
			tmp[q++]=x[i++];
		else
			tmp[q++]=x[j++];
	}
	while(i<=leftend)
		tmp[q++]=x[i++];
	while(j<=rightend)
		tmp[q++]=x[j++];
	for(i=left; i<=rightend; i++)
		x[i]=tmp[i];
}
void mSort(int k[], int tmp[], int left, int right)
{
	int center;
	if(left < right)
	{
		center = (left+right)/2;
		mSort(k, tmp, left, center);
		mSort(k, tmp, center+1, right);
		merge(k, tmp, left,center, right);
	}
}
void quickSort(int k[ ],int left,int right)
{
	int i, last;
	if(left<right)
	{
		last=left;
		for(i=left+1; i<=right; i++)
		{
			ans++;
			if(k[i]<k[left])
			{
				last++;
				swap(&k[last],&k[i]);
			}
		}

		swap(&k[left],&k[last]);
		quickSort(k,left,last-1);
		quickSort(k,last+1,right);
	}
}
int main()
{
	scanf("%d%d",&n,&op);
	int i;
	for(i=1; i<=n; i++)
		scanf("%d",&pic[i]);
	if(op==1)
	{
		qsort(pic+1,n,sizeof(int),cam);
		ans=(n*(n-1))>>1;
	}
	else if (op==2)
	{
//		int j;
//		for (i=1; i<=n-1; i++)
//		{
//			int flag=0;
//			for (j=1; j<=n-1-i; j++)
//			{
//				if (pic[j]>pic[j+1])
//				{
//					//swap(pic[j],pic[j+1]);
//					int k=pic[j];
//					pic[j]=pic[j+1];
//					pic[j+1]=k;
//					flag=1;
//				}
//				ans++;
//			}
//			if(flag)	break;
//		}
		bubbleSort(pic+1);
	}
	else if (op==3)
	{
		int temp;
		for(i=n/2-1; i>=0; i--)
			adjust(pic+1,i,n);
		for(i=n-1; i>=1; i--)
		{
			temp=(pic+1)[i];
			(pic+1)[i]=(pic+1)[0];
			(pic+1)[0]=temp;
			adjust((pic+1),0,i);
		}
	}
	else if (op==4)
	{
		mSort(pic,tem,1,n);
	}
	else if (op==5)
	{
		quickSort(pic,1,n);
	}
	for(i=1; i<=n; i++)
		printf("%d ",pic[i]);
	printf("\n%d",ans);
	return 0;
}
