#include<stdio.h>
#include<string.h>
int pic[22][22];
int checkhang(int i,int j)// 向右扫描，因为从左向右，i如果不行，i+1更不行 
{
	int cnt=1,sign=pic[i][j],k;
	for(k=j+1;k<=19;k++)
		if(pic[i][k]==sign)
			cnt++;
		else
			break;
	if(cnt!=4)
		return 0;
	if(pic[i][j-1]==0 || pic[i][k]==0)
		return 1;
	return 0;
}
int checklie(int i,int j)
{
	int cnt=1,sign=pic[i][j],k;
	for( k=i+1;k<=19;k++)
		if(pic[k][j]==sign)
			cnt++;
		else
			break;
	if(cnt!=4)
		return 0;
	if(pic[i-1][j]==0 || pic[k][j]==0)
		return 1;
	return 0;
}
int checkyouxia(int i,int j)
{
	int cnt=1,sign=pic[i][j],ii,jj;
	for(ii=i+1,jj=j+1;ii<=19 && jj<=19;++ii,++jj)
		if(pic[ii][jj]==sign)
			cnt++;
		else
			break;
	if(cnt!=4)
		return 0;
	if(pic[i-1][j-1]==0 || pic[ii][jj]==0)
		return 1;
	return 0;
}
int checkzuoxia(int i,int j)
{
	int cnt=1,sign=pic[i][j],ii,jj;
	for(ii=i+1,jj=j-1;ii<=19 && jj<=19 &&jj>=1;++ii,--jj)
		if(pic[ii][jj]==sign)
			cnt++;
		else
			break;
	if(cnt!=4)
		return 0;
	if(pic[i-1][j+1]==0 || pic[ii][jj]==0)
		return 1;
	return 0;
}
int main()
{
	int i,j;
	memset(pic,-1,sizeof(pic));
	for(i=1;i<=19;i++)
		for(j=1;j<=19;j++)
			scanf("%d",&pic[i][j]);
	for(i=1;i<=19;i++)
		for(j=1;j<=19;j++)
			if(pic[i][j]!=0)
				if(checkhang(i,j) || checklie(i,j) || checkyouxia(i,j) || checkzuoxia(i,j))
				{
					printf("%d:%d,%d\n",pic[i][j],i,j);
					return 0;
				}
	printf("No\n");
	return 0;
}
