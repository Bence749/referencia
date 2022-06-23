#include <iostream>

inline double fahr2cels(double x)
{
    return 5. / 9 * (x - 32);
}

int main()
{
    const int lower = 0;
    const int upper = 300;
    const int step = 20;

    for(int i = lower; i < upper; i += step)
    {
        std::cout << i << "Fahrenheit\t" << fahr2cels(i) << " Celsius" << std::endl;
    }
}