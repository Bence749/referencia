#include <iostream>

int s = 4;

void f()
{
    int* p = &s;
    std::cout << s << ' ' << p << std::endl;

    delete p; // Ez hibát dob mivel a globális változók felszabadítása automatikusan történik
}

int main()
{
    f();
}