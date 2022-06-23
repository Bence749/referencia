#include <iostream>

int main()
{
    const int n = 14;
    int *p = const_cast<int*>(&n); //Mivel a fordító nem engedi: int *p = &n
    *p = 9;
    std::cout << p << std::endl;
    std::cout << &n << std::endl;
    std::cout << *p << " " << n << std::endl; //Azonos memória cím, különböző érték, mivel a fordító futási időben
                                              //a 'const' jelző miatt behelyeteíti az n értékére a 14-et ezáltal
                                              //futtatáskor nem a memóriából olvassa ki az értékét.
}