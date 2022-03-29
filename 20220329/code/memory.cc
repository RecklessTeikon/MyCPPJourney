#include <iostream>

static int staticglobalint = -1;
int globalint = 0;
void test1()
{
    int stackint = 1;
    static int staticint = 2;
    int *heapintp = new int(3);
    const char *stringp = "helloworld";
    char string[] = "helloworld";
    printf("global addr: %p\n", &globalint);
    printf("static global addr: %p\n", &staticglobalint);
    printf("stack addr: %p\n", &stackint);
    printf("static int addr: %p\n", &staticint);
    printf("heap addr: %p\n", heapintp);
    printf("read only addr: %p\n", stringp);
    printf("character array addr: %p\n", string);
    printf("code addr: %p\n", &test1);

    delete heapintp;
}
int main()
{
    test1();
    return 0;
}