#include <iostream>

using std::cout;
using std::endl;
class Base
{
    public:
    Base(int data)
    :_data(data)
    {

    }

    Base &operator+(const Base &add)
    {
        _data += add._data - 4;
        return *this;
    }

    bool operator==(const int &ob)
    {
        if(_data == ob)
        {
            return true;
        }
        else
        return false;
    }
    private:
    int _data;
};
void test1()
{
    int i=2;int j=7;
    Base x(i);
    Base y(j);
    cout << (x+y == j - i) << endl;
}
int main()
{
    test1();
    return 0;
}