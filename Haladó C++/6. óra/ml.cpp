#include <iostream>

void f()
{
    int i = 7;
    double d = 3.54;
    ++d;
    int* p = &i;
    std::cout << p << std::endl;
    p = new int[ i ];
    std::cout << p << std::endl;
    delete [] p; //Enélkül valgrinddel futtatva hibát fedezhetünk fel, ami alapból észre se vehető!
    int* q = static_cast<int*>( std::malloc( i * sizeof( int ) ) );
    std::cout << q << std::endl;
    q[ 0 ] = 23;
    std::free( q ); //Itt ha delete-t használnánk akkor fordításnál és futtatásnál nem láttnánk a hibát
                    //azonban valgrinddel futtatva szólna h missmatched free/delete    
}

int main()
{
    f();
}