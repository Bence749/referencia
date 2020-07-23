#include <iostream>
#include "gasstation.h"
#include "customer.h"

using namespace std;

int main()
{
    Gasstation* gasstation = new Gasstation(6, 2);
    Customer* customer = new Customer(gasstation);

    customer->tankol(2/*Station Id*/, 12/*Amount*/, 1/*Cashregister Id*/);
    return 0;
}
