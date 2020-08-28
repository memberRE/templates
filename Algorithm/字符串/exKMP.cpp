#include <cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 1e6 + 20;
char A[MAX], B[MAX];
int nex[MAX], extends[MAX];
void getnext()
{
	nex[0] = strlen(B);
	int noww = 0;
	int p = 1;
	while(B[noww]==B[noww+1] and noww+1<nex[0])
		noww++;
	nex[1] = noww;
	for (int i = 2; i < nex[0]; i++)
	{
		if (i + nex[i - p] < nex[p] + p)
			nex[i] = nex[i - p];
		else
		{
			noww =max(nex[p]+p-i,0) ;
			while(B[noww]==B[noww+i] and noww+i<nex[0])
				noww++;
			nex[i] = noww;
			p = i;
		}
	}
}
void exKMP()
{
	int lenA = strlen(A);
	int noww = 0;
	int p = 0;
	while (B[noww] == A[noww] and noww < min(lenA, nex[0]))
		noww++;
	extends[0] = noww;
	for (int i = 1; i < lenA; i++)
	{
		if (i + nex[i - p] < extends[p] + p)
			extends[i] = nex[i - p];
		else
		{
			noww = max(extends[p] + p - i, 0);
			while (B[noww] == A[noww + i] and noww < nex[0] and noww + i < lenA)
				noww++;
			extends[i] = noww;
			p = i;
		}
	}
}
int main()
{
	scanf("%s%s",A,B);
	getnext();
	exKMP();
	for (int i = 0; i < nex[0];i++)
		printf("%d ", nex[i]);
	putchar('\n');
	int lenA = strlen(A);
	for (int i = 0; i < lenA;i++)
		printf("%d ", extends[i]);
	return 0;
}
