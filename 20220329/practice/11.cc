#include <iostream>

class Stack
{
    public:
    Stack()
    :_stack(new int[10])
    ,_topidx(0)
    {
        std::cout << "构造函数已调用" << std::endl;
    }

    ~Stack()
    {
        std::cout << "析构函数已调用" << std::endl;
        delete _stack;
    }

    void push(int elem)
    {
       if(_topidx < 10)
       {
           _stack[_topidx++] = elem;
       }
       else
       {
           std::cout << "栈满，不能继续入栈。" << std::endl;
       }
    }

    void pop()
    {
        if(_topidx > 0)
        {
            std::cout << "出栈元素为：" << _stack[--_topidx] << std::endl;
            _stack[_topidx] = 0;
        }
        else
        {
           std::cout << "栈空，不能继续出栈。" << std::endl;
        }
    }

    int top()
    {
        if(_topidx > 0)
        {
            std::cout << "栈顶元素为：" << _stack[_topidx] << std::endl;
            return _stack[_topidx];
        }
        else
        {
           std::cout << "栈空。" << std::endl;
           return -1;
        }
    }   

    bool empty()
    {
        if(_topidx < 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    } 

    bool full()
    {
        if(_topidx > 9)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    private:
    
    int *_stack;
    int _topidx;
};

void test1()
{
    Stack test;
    if(test.empty())
    {
        std::cout << "It is empty." << std::endl;
    }
    for(int i = 0; i < 10; ++i)
    {
        test.push(i);
    }
    if(test.full())
    {
        std::cout << "It is full." << std::endl;
    }
    for(int i = 0; i < 10; ++i)
    {
        test.pop();
    }
    test.top();
}
int main()
{
    test1();
    return 0;
};