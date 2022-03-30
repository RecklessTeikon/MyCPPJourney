#include <iostream>
#define ELEMTYPE int

class Queue
{
    public:

    Queue()
    :_queue(new ELEMTYPE[10])
    ,_frontidx(0)
    ,_rearidx(0)
    {
        std::cout << "构造函数已被调用" << std::endl;
    }

    ~Queue()
    {
        std::cout << "析构函数已被调用" << std::endl;
        delete [] _queue;
    }

    void push(ELEMTYPE elem)
    {
        if((_rearidx + 1) % 10 == _frontidx)
        {
            std::cout << "队满，入队失败" << std::endl;
        }
        else
        {
            _queue[_rearidx] = elem;
            _rearidx = (_rearidx + 1) % 10;
        }
    }

    void pop()
    {
        if(_rearidx == _frontidx)
        {
            std::cout << "队空，出队失败" << std::endl;
        }
        else
        {
            std::cout << "出队元素为：" << _queue[_frontidx] << std::endl;
            _frontidx = (_frontidx + 1) % 10;
        }
    }

    int front()
    {
        if(_rearidx == _frontidx)
        {
            std::cout << "队空，读取失败" << std::endl;
            return -1;
        }
        else
        {
            return _queue[_frontidx];
        }
    }

    int rear()
    {
        if(_rearidx == _frontidx)
        {
            std::cout << "队空，读取失败" << std::endl;
            return -1;
        }
        else
        {
            int target = (_rearidx == 0? 9: _rearidx - 1);
            return _queue[target];
        }
    }
    private:

    ELEMTYPE *_queue;
    int _frontidx;
    int _rearidx;
};

void test1()
{
    Queue test;
    for(int i = 0; i < 11; ++i)
    {
        test.push(i);
    }
    std::cout << "front:" << test.front() << std::endl
    << "rear" << test.rear() << std::endl;
    for(int i = 0; i < 11; ++i)
    {
        test.pop();
    } 
}
int main()
{
    test1();
    return 0;
}