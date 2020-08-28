#include <iostream>
int main()
{
    int sum = 0, value = 0;
    while (std::cin >> value)
       {
     	 	 sum += value;
     	   std::cout << "The sum of the numbers you give is " << sum <<std::endl;
	   } 
        return 0;
    }

