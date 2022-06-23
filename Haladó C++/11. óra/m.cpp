#include <iostream>

class Base
{
public:
    virtual void f() const
    {
        std::cout << "Base::f()" << std::endl;
    }
    
    virtual ~Base() { }
};

class Der: public Base
{
public:
    virtual void f() const
    {
        std::cout << "Der::f()" << std::endl;
    }

    virtual ~Der() { }
};

int main()
{
    std::cout << sizeof(Base) << std::endl;
    Base* p = 0;
    p = new Base();
    p->f();
    delete p;

    p = new Der();
    p->f();
    delete p;
}