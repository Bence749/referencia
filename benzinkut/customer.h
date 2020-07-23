#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include "gasstation.h"

class Customer{
    public:
        Customer(Gasstation* x) : _gasstation(x) {}
        void tankol( int statId, int amount, int cashId );
        Gasstation* _gasstation;
};

#endif // CUSTOMER_H_INCLUDED
