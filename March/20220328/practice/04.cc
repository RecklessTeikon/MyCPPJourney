#include <iostream>

int main(int argc, char** argv)
{
    int x;
    std::cin >> x;
    if(x++ > 5)
	{
		std::cout << x << std::endl;
	}      
    else
	{
		std::cout << x-- << std::endl;
	}
    
    return 0;
}