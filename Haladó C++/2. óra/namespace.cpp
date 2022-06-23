#include <iostream>

namespace A
{
    void f()
    {
        std::cout << "Hello from Namespace A!" << std::endl;       
    }
}

namespace B
{
    void f()
    {
        std::cout << "Hello from Namespace B!" << std::endl;
    }
}

namespace X
{
    namespace Y
    {
        void f()
        {
            std::cout << "Hello from Namespace Y in Namespace X!" << std::endl;
        }
    }
}

int main()
{
    A::f();
    B::f();
    X::Y::f();
}