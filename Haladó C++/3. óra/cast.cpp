#include <iostream>

int find( int );
int* find_pointer( int );

int main()
{
    long s = (long) find( 6 ); //Lefordul C-s castolással
    std::cout << s << std::endl;

    long t = static_cast<long>(find( 6 )); //És lefordul C++-os static_cast-al is
    std::cout << t << std::endl;

    long r = reinterpret_cast<long>(find_pointer( 6 )); //Ilyen esetben, hogy ha a függvény
    std::cout << r << std::endl;                        //visszatérési értéke int* onnantól reinterpret_cast

}