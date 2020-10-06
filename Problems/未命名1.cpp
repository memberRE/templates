#include<bits/stdc++.h>
using namespace std;
vector<string> test;
string str = "";
class Myclass {
	public:
		string a
		void Myclass (){
			a = "123";
		}
};
int main()
{
	Myclass a = Myclass(1,2);
	Myclass b = Myclass(0,0);
	b = a;
	a.a = 777;
	cout<<b.a;
	return 0;
	
	
	
	str = "1234567890";
	//str.push_back('1');
	for(int i=1;i<=1;i++)
		str.push_back('1');
	for(int i=1;i<=1000000;i++)
	{
		//str.pop_back();
		//str.push_back('1');
		test.push_back(str);
		//test[test.size() - 1].push_back('a'+ (i%20));
	}
	for(int i=1;i<=1000000;i++)
		test[test.size() - 1].push_back('a'+ (i%20)),test[test.size() - 1].pop_back();
	//test[1].push_back('2');
//	str.clear();
//	str.push_back('9');
//	test.push_back(str);
//	for(auto u : test)
//		cout<<u<<endl;
	cout<<test[0]<<endl<<test[1]<<endl<<test[2];
	return 0;
}
