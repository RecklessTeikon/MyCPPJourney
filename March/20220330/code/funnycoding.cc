#include <iostream>
using namespace std;

class NullPointCall
{
public:
static void test1();
void test2();
void test3(int test);
void test4();
private:
static int _static;
int _test;
};
int NullPointCall::_static = 0;
void NullPointCall::test1()
{
cout << "_static = " << _static << endl;
}
void NullPointCall::test2()
{
cout << "coding is very cool!" << endl;
}
void NullPointCall::test3(int test)
{
cout << "test = " << test << endl;
}
void NullPointCall::test4()
{
cout << "_test = " << _test << endl;
}
int main(void)
{
NullPointCall * pNull = nullptr;
pNull->test1();
pNull->test2();
pNull->test3(10);
pNull->test4();
return 0;
}