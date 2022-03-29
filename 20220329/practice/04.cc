#include <iostream>

class nothing1
{
    public:
    ~nothing1()
    {
        printf("1 Destructor called\n");
    }
};
class nothing2
{
    public:
    ~nothing2()
    {
        printf("2 Destructor called\n");
    }
};
class nothing3
{
    public:
    ~nothing3()
    {
        printf("3 Destructor called\n");
    }
};
class nothing4
{
    public:
    ~nothing4()
    {
        printf("4 Destructor called\n");
    }
};
nothing3 c;
int main()
{
    nothing1 *pa = new nothing1;
    nothing2 b;
    static nothing4 d;
    delete pa;
    return 0;
}