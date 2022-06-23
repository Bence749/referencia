#include <iostream>

int* f( int i )
{
    int* p = new int[ i ];
    p[ 0 ] = 34;
    return p;
}

int main()
{
    int* q = f( 9 );
    std::cout << q[ 0 ] << std::endl;
    delete [] q;
}