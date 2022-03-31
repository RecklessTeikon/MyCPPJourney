#include <iostream>
#include <string>
#include <string.h>

void test1()
{
    //C风格的字符串
    char string[] = "hello, world";
    const char *stringp = "hello, universe";

    //获取长度
    printf("%s\n",string);
    printf("strlen = %ld\n",strlen(string));
    printf("sizeof = %ld\n",sizeof(string));

    printf("%s\n",stringp);
    printf("strlen = %ld\n",strlen(stringp));
    printf("sizeof = %ld\n",sizeof(stringp));//输出为8，因为指针的sizeof是8

    //字符串的拼接
    char longstring[50] = {0};
    strcat(longstring,string);
    printf("%s\n",longstring);
    strcat(longstring,stringp);
    printf("%s\n",longstring);

    //逐字符打印
    for(int i = 0; longstring[i] != 0; ++i)
    {
        putchar(longstring[i]);
        putchar(' ');
    }

}
void test2()
{
    //C++风格的字符串
    std::string stringcpp = "hello, cppworld";

    //获取长度

    printf("cppstring length: %ld.\n",stringcpp.length());
    printf("cppstring size: %ld.\n", stringcpp.size());

    //字符串的拼接

    std::string appendstringcpp = "hello, cppuniverse";
    stringcpp = stringcpp + appendstringcpp;
    std::cout << stringcpp << std::endl;

    stringcpp.append("peaceful world.");
    std::cout << stringcpp << std::endl;

    //逐字符打印

    for(size_t i = 0; i < stringcpp.size(); ++i)
    {
        std::cout << stringcpp[i] << " ";
    }

    //转换成C语言风格字符串
    const char *pcstring = stringcpp.c_str();
    printf("%s\n", pcstring);
}
int main()
{
    //test1();
    test2();
    return 0;
}