#ifndef STATION_H_INCLUDED
#define STATION_H_INCLUDED
#include <iostream>

class Station
{
    protected:
        int _id;
        int _amount;
    public:
        Station( int id ): _id(id), _amount(0) {}
        void tolt( int amount ) { _amount = amount; std::cout << "Sikeresen tankolt " << amount << "l benzint" << std::endl; };
        int getId() { return _id; }
        int getAmount() { return _amount; }
        void nullAmount() { _amount = 0; }
};



#endif // STATION_H_INCLUDED
