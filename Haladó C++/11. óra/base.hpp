#include <iostream>

class Base
{
public:
    virtual void f() const
    {
        std::cout << "Base::f()" << std::endl;
    }
    
    virtual ~Base() { std::cout << "Base dtor" << std::endl; }
};

class Der: public Base
{
public:
    virtual void f() const
    {
        std::cout << "Der::f()" << std::endl;
    }

    virtual ~Der() { std::cout << "Der dtor" << std::endl; }
};