#include <iostream>

int main()
{
    int i = 5;
    int* p = &i;
    *p = 8;
    std::cout << p << ' ' << *p << ' ' << i << std::endl;

    p = 0;
    //std::cout << p << ' ' << *p << std::endl; ==> Segmentation fault (nullptr)
    std::cerr << p << ' ';

    if( p )
        std::cout << *p << std::endl;

    std::cout << "Vegig fut!" << std::endl;
}