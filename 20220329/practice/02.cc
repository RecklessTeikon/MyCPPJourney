#include <iostream>

class nothing
{
    public:
    nothing()
    {
        std::cout << "1" << std::endl;
    }
    ~nothing()
    {
        std::cout << "2" << std::endl;
    }
};
int main()
{
    nothing A,B,C;
    return 0;
}