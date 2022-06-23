#include <iostream>
#include <string>

int i = 3;

int main()
{
    std::string s = "Hello";
    std::cout << s << std::endl;
    std::cout << &s << std::endl;
    double* p = reinterpret_cast<double*>( &s );
    std::cout << *p << std::endl;

    double d = 12.34;                                       //
    std::string* q = reinterpret_cast<std::string*>( &d );  //
    //std::cout << *q << std::endl;                         //==> Szegmentálási hiba

    std::cout << &i << std::endl;
    long x = reinterpret_cast<long>(&i);
    std::cout << x << std::endl;
}