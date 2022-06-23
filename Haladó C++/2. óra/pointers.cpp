#include <iostream>

int main()
{
    int i = 23;
    const int n = 7;

    int * ip = &i;
    std::cout << ip << std::endl;
    *ip = 15;
    std::cout << i << std::endl;
    ip = 0;

    const int* cip = &i;
    std::cout << *cip << std::endl;
    cip = &n;
    std::cout << *cip << std::endl;

    int* const icp = &i;
    *icp = 4;
    std::cout << i << std::endl;

    const int* const cicp = &i;
    std::cout << cicp << std::endl;
    std::cout << *cicp << std::endl;
}