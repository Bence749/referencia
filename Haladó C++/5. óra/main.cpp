#include <iostream>

double sum( int, double (*)( int ));

double f( int i )
{
    std::cout << "f called " << i << std::endl;
    return 1. / (i + 1);
}

double g( int i )
{
    std::cout << "g called " << i << std::endl;
    return 1.7 * i;
}

int main()
{
    std::cout << sum( 8, f ) << std::endl;
    std::cout << sum( 8, g ) << std::endl;
}