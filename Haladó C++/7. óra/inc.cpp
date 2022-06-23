#include <iostream>

void inc( int& r )
{
    ++r;
}

int main()
{
    int x = 3;
    inc( x );
    std::cout << x << std::endl;
}