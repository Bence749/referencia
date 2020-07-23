#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

#include "land.h"
#include "weather.h"

class Simulation
{
protected:
    int _water;
    std::string _name;
public:
    Simulation ( std::string &name, int water ) : _water(water), _name(name) {}
    int getWater() { return _water; }
    std::string getName() { return _name; }
    void nullWater() { _water = 0; }
    void changeWater( int x ) { _water += x; }
    void change( Land* &land, Weather* weather, int *hum )
    {
        weather->change(land, hum, this);
    }
    ~Simulation() {}
};

#endif // SIMULATION_H_INCLUDED
