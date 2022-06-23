#include <iostream>

int main()
{
    int i = 3;
    int* p = &i;
    *p = 6;
    std::cout << i << std::endl;
    int& r = i;
    std::cout << r << std::endl;
    r = 8;
    std::cout << i << std::endl;
    int k  = 5;
    r = k; // i = k;
    std::cout << i << std::endl;
    ++r;
    std::cout << i << std::endl;
    const int& cr = i;
    std::cout << cr << std::endl;
    p = 0;
}