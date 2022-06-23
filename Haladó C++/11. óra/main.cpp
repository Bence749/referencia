#include "base.hpp"
#include <iostream>

void g( Base* );

struct X: Base
{
    virtual void f() const
    {
        std::cout << "X::f()" << std::endl;
    }

    virtual ~X() { std::cout << "X dtor" << std::endl; }
};

int main()
{
    Base* p = 0;
    p = new Base();
    g( p );
    delete p;
    p = new X();
    g( p );
    delete p;
    Base b;
    b.f();
    Der d;
    d.f();
    X x;
    x.f();
}