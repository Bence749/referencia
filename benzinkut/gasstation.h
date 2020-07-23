#ifndef GASSTATION_H_INCLUDED
#define GASSTATION_H_INCLUDED
#include "cashregister.h"
#include "station.h"
#include <vector>
#include <iostream>

class Gasstation{
    protected:
        int _numberOfStations;
        int _numberOfCashregisters;
        int _price = 285;
        std::vector<Cashregister*> _cashregisters;
        std::vector<Station*> _stations;
    public:
        enum OutOfRange{ OUTOFRANGE };
        Gasstation( int n, int k );
        int getPrice() { return _price; }
        Station* getStation( int n ) throw ( OutOfRange );
        Cashregister* getCashregister( int k ) throw ( OutOfRange );
        void tolt( int id, int amount)
        {
            getStation(id)->tolt(amount);
        }
        void pay( int id, int statId)
        {
            getCashregister(id)->fizet( _price, getStation(statId) );
        }
};

#endif // GASSTATION_H_INCLUDED
