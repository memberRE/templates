#include<iostream>
#include<unistd.h>
using namespace std;
int tem = 0;
int main()
{
	pid_t fpid;
	fpid = fork();
	if(fpid == 0)
	{
		cout<<"Son:   "<<tem<<endl;
	}
	else
	{
		tem++;
		cout<<"FA:   "<<tem<<endl;
	}
}

