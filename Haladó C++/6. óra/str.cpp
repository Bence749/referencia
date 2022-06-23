#include <string> //A string objektum dinamikus memória kezelést végez
#include <iostream>
#include <cstdlib>

void f()
{
    //std::string* str = new std::string( "Hello" );
    std::string* str = static_cast<std::string*>( std::malloc( sizeof( std::string ) ) );
    std::string h = "Hello";
    *str = h;
    str->push_back( '!' );
    str->push_back( '!' );
    str->push_back( '!' ); 

    std::cout << *str << std::endl;
    //delete str; //Igaz, hogy a string dinamikusan kezeli a memóriát azonban ha pointerként hozzuk létre,
                  //akkor már szükség van a felszabadításra! 

    std::free( str );
}

int main()
{
    f();
}