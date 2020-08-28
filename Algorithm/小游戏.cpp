#include<bits/stdc++.h>
using namespace std;
const int MAXI=21,MAXJ=51;
char pic[MAXI+5][MAXJ+5];
bool vztd[55][105],quit=0;
int difcult=5;//�Ѷ�Ĭ��Ϊ5 
int diri=1,dirj=1;//���ﵱǰλ�� 
void clear_screen(int k)//���� 
{
	for(int i=1;i<=k;i++)
		printf("\n");
}
void run_pic(int flag,int k)	//flag:1(i),2(j) k  //�����ͼ 
{
	clear_screen(50);
	for(int i=1;i<=MAXI;i++)
	{
		if(flag==1 and i==k)
		{
			for(int j=1;j<=MAXJ;j++)
				if(i==diri and j==dirj)
					putchar('@');
				else
				putchar('*');
		} 
		else
			for(int j=1;j<=MAXJ;j++)
			{
				if(i==diri and j==dirj)
					putchar('@');
				else
				if(flag==2 and j==k)
					putchar('*');
				else
				putchar(pic[i][j]);
			}
		putchar('\n'); 
	}
}
void _init()//��ʼ�� 
{
	for(int i=1;i<=MAXI;i++)
		for(int j=1;j<=MAXJ;j++)
			pic[i][j]='.';
	pic[(MAXI+1)>>1][(MAXJ+1)>>1]='+';
	run_pic(0,0);
}
void grow()
{
	for(int i=1;i<=MAXI;i++)
		for(int j=1;j<=MAXJ;j++)
			if(pic[i][j]=='+')
			{
				vztd[i+1][j]=1;
				vztd[i-1][j]=1;
				vztd[i][j-1]=1;
				vztd[i][j+1]=1;
			}
	int k=0;
	for(int j=1;j<=MAXJ;j++)
		if(pic[1][j]=='+' or pic[MAXI][j]=='+')
			k=1;
	for(int i=1;i<=MAXI;i++)
		if(pic[i][1]=='+' or pic[i][MAXJ]=='+')
			k=1;
	if(k==1)
	{
		cout<<endl<<"\tYOU LOST !!!"<<endl<<endl;
		quit=1;
		return ;
	}
	for(int i=1;i<=MAXI;i++)
		for(int j=1;j<=MAXJ;j++)
			if(vztd[i][j])
				pic[i][j]='+';
	memset(vztd,0,sizeof(vztd));
}
bool check()
{
	for(int i=1;i<=MAXI;i++)
		for(int j=1;j<=MAXJ;j++)
			if(pic[i][j]=='+')
				return false;
	return true;
}
int main()
{
	printf("��Ϸ����XXXXX\n���ߣ�\n\n");
	printf("��Ϸ˵����\n\tw,a,s,d��������'@'���������ƶ�\n\t����i�������\n\t����j�������\n\n");
	printf("��ʤĿ�꣺\n\t�������С����'+'\n\n") ;
	printf("ע�⣺\n\tС����ÿx�غϻᱩ��һȦ������С����ռ����ͼ֮ǰ����ȫ������\n");
	system("pause");
	clear_screen(100);
	printf("��������Ϸ�Ѷȣ�������������Ĭ��Ϊ5��\n");
	clear_screen(20);
	scanf("%d%*c",&difcult);
	clear_screen(50);
	if(difcult<=0)
	{
		printf("�ú��Ӳ����ң������������˲���������(�s���n��)�s");
		clear_screen(10); 
		return 0; 
	}
	cout<<"\t\t\t\t\t    GOOD LUCK!"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t  START!";
	clear_screen(10);
	system("pause"); 
//	getchar();
	//------------------------------------------------------------------------------------
	_init();
	int huihe=0;
	for(;;)
	{
		huihe++;
		if(huihe==difcult)
		{
			grow();
			if(quit)
			return 0;
			huihe%=difcult;
		}
		//run_pic(0,0);
		printf("�����������ж�(w,a,s,d,i,j),Ȼ��س�:\n\n");
		char x;
		x=getchar();
		scanf("%*c");
		//------------------------------------------------------
		if(x=='w')
		{
			diri--;
			if(diri==0)
			{
				printf("\n���Ѿ�����ս����Χ��\n\n�ӱ��ǿɳܵģ�������");
				printf("\n\n��Ϸ������");
				return 0; 
			}
			run_pic(0,0);
		}
		if(x=='a')
		{
			dirj--;
			if(dirj==0)
			{
				printf("\n���Ѿ�����ս����Χ��\n\n�ӱ��ǿɳܵģ�������");
				printf("\n\n��Ϸ������");
				return 0; 
			}
			run_pic(0,0);
		}
		if(x=='s')
		{
			diri++;
			if(diri>MAXI)
			{
				printf("\n���Ѿ�����ս����Χ��\n\n�ӱ��ǿɳܵģ�������");
				printf("\n\n��Ϸ������");
				return 0; 
			}
			run_pic(0,0);
		}
		if(x=='d')
		{
			dirj++;
			if(dirj>MAXJ)
			{
				printf("\n���Ѿ�����ս����Χ��\n\n�ӱ��ǿɳܵģ�������");
				printf("\n\n��Ϸ������");
				return 0; 
			}
			run_pic(0,0);
		}
		//----------------------------------------------------------------------
		if(x=='i')
		{
			for(int j=1;j<=MAXJ;j++)
				pic[diri][j]='.';
			run_pic(1,diri);
		}
		if(x=='j')
		{
			for(int i=1;i<=MAXI;i++)
				pic[i][dirj]='.';
			run_pic(2,dirj);
		}
		if(check())
		{
			for(int op=1;op<=3;op++)
				printf("\n\nYOU WIN!!!!\n\n");
			return 0;
		}
	}
	return 0;
}
