#include <iostream>

using std::cout;
using std::endl;

class Base
{ 
	int a1,a2;
public:
	Base(int x1 = 0, x2 = 0);//参数类型不能省
};

int main()
{
	Base data(2,3);
 	cout << data.a1 << endl;//私有成员数据不能直接访问
 	cout << data.a2 << endl;
    
    return 0;
}