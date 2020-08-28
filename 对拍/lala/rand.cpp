#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define f 5//frequency of 1
int o[100000]={1};
int main(){
	srand(time(NULL));
	int i,j;
	int n=rand()%3+8;
	int a=rand()%n+1,b=rand()%n+1,c=rand()%n+1;//alue of n,a,b,c
	printf("%d %d %d %d\n",n,a,b,c);
	for(i=0;i<n;i++){
		for(j=0;j<a;j++)printf("%d ",o[rand()%f]);
		printf("\n");
	}
	for(i=0;i<n;i++){
		for(j=0;j<b;j++)printf("%d ",o[rand()%f]);
		printf("\n");
	}
	for(i=0;i<n;i++){
		for(j=0;j<c;j++)printf("%d ",o[rand()%f]);
		printf("\n");
	}
	return 0;
}

