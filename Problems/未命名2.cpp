#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a = "111\0\0";
	string b = to_string(111);
	for(char t:a)
		if (!isdigit(t))
			cout<<"@@@"<<endl;
	cout<<a<<b;
}
