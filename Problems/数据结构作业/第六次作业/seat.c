#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ppp{
	int stunum;
	char name[25];
	int seat;
}STU;
STU pic[128];
int n,map[250],map2[250];
int num_b,b[250];
int cam(const void *a,const void *b)
{
	STU A=*((STU*)a),B=*((STU*)b);
	if(A.seat==B.seat)
		return A.stunum-B.stunum;
	return A.seat-B.seat;
}
int ccam(const void *a,const void *b)
{
	STU A=*((STU*)a),B=*((STU*)b);
		return A.stunum-B.stunum;
}
int main()
{
	FILE *in=fopen("in.txt","r");
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		fscanf(in,"%d%s%d",&pic[i].stunum,pic[i].name,&pic[i].seat);
		map2[pic[i].seat]=1;
		
		b[pic[i].seat]++;
		if(b[pic[i].seat]==2){
			num_b++;
		}
	}
	qsort(pic+1,n,sizeof(STU),cam);
	int m=pic[n].seat,r=n;
	if(m>n)	m=n;
/*	for(i=1;i<=n;i++)
	{
		if(!map2[i])
			pic[r--].seat=i;
	}*/
	int top=n; 
	for(i=1;i<=n-num_b;i++){
		if(b[i]==0){
			b[pic[top].seat]--;
			pic[top].seat=i;
			b[i]++;
			qsort(pic+1,n,sizeof(STU),cam);
		}
	}
	qsort(pic+1,n,sizeof(STU),cam);
	m=pic[n].seat+1;
	for(i=1;i<=n;i++)
	{
		if(!map[pic[i].seat])
			map[pic[i].seat]=1;
		else
		{
			pic[i].seat=m++;
		//	map[pic[i].seat]=1;
		}
	}
	qsort(pic+1,n,sizeof(STU),ccam);
	FILE *out=fopen("out.txt","w");
	for(i=1;i<=n;i++)
		fprintf(out,"%d %s %d\n",pic[i].stunum,pic[i].name,pic[i].seat);
	fclose(out);
	return 0;
}
