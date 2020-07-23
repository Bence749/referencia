#ifndef CASHREGISTER_H_INCLUDED
#define CASHREGISTER_H_INCLUDED
#include <iostream>
#include "station.h"

class Cashregister
{
    protected:
        int _id;
        int _toPay;
    public:
        Cashregister( int id ): _id(id), _toPay(0) {}
        void fizet( int n, Station* station )
        {
            _toPay = n * station->getAmount();
            std::cout << "Sikeresen fizetett: " << _toPay << "Ft-ot!" << std::endl;
            station->nullAmount();
        }
        int getCheck() { return _toPay; }
};

#endif // CASHREGISTER_H_INCLUDED
