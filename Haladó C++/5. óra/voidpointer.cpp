#include <iostream>

int main()
{
    int i = 7;
    double d = 12.34;
    char str[] = "blabla";
    void* p = &i; //VoidPointer ==> Memória címek tárolására alkalmazható
    std::cout << p << std::endl;
    p = &d;
    std::cout << p << std::endl;
    p = &str;
    std::cout << p << std::endl;
}