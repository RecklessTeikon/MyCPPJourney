#include <iostream>

class Foo
{
    public:
    int operator()(int a, int b)
    {
        return a + b;
    }
    int add(int a, int b)
    {
        return a + b;
    }
};
int add(int a, int b)
{
    return a + b;
}
//typedef int (Foo::*Funcpointer)(int ,int);
void test1()
{
    int (Foo::*fp)(int ,int ) = &Foo::add;
    //auto (Foo::*fp) = &Foo::add;
    Foo foo;
    
}