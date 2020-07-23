#include "land.h"
#include "weather.h"
#include "simulation.h"

#include <iostream>

//Desert
Desert* Desert::_instance = nullptr;
Desert* Desert::instance()
{
    if( _instance == nullptr )
        _instance = new Desert();
    return _instance;
}

Land* Desert::change( Sunny *k, Simulation* p )
{
    p->changeWater(-3);
    if( p->getWater() < 0) p->nullWater();
    return this;
}
Land* Desert::change( Cloudy *k, Simulation* p )
{
    p->changeWater(1);
    if( p->getWater() < 0) p->nullWater();
    return this;
}
Land* Desert::change( Rainy *k, Simulation* p )
{
    p->changeWater(5);
    if( p->getWater() < 0) p->nullWater();
    if( p->getWater() > 15 )
    {
        return Green::instance();
    }
    return this;
}

void Desert::destroy() { if ( nullptr!=_instance ) delete _instance; }

//Green
Green* Green::_instance = nullptr;
Green* Green::instance()
{
    if( _instance == nullptr )
        _instance = new Green();
    return _instance;
}

Land* Green::change( Sunny *k, Simulation* p )
{
    p->changeWater(-6);
    if( p->getWater() < 0) p->nullWater();
    if( p->getWater() < 15)
    {
        return Desert::instance();
    }
    return this;
}
Land* Green::change( Cloudy *k, Simulation* p )
{
    p->changeWater(2);
    if(p->getWater() < 0) p->nullWater();
    if( p->getWater() < 16)
    {
        return Desert::instance();
    }
    return this;
}
Land* Green::change( Rainy *k, Simulation* p )
{
    p->changeWater(10);
    if( p->getWater() < 0) p->nullWater();
    if( p->getWater() > 50)
    {
        return Lake::instance();
    }
    return this;
}

void Green::destroy() { if ( nullptr!=_instance ) delete _instance; }

//Lake
Lake* Lake::_instance = nullptr;
Lake* Lake::instance()
{
    if( _instance == nullptr )
        _instance = new Lake();
    return _instance;
}

Land* Lake::change( Sunny *k, Simulation* p )
{
    p->changeWater(-10);
    if( p->getWater() < 0) p->nullWater();
    if( p->getWater() < 51)
    {
        return Green::instance();
    }
    return this;
}
Land* Lake::change( Cloudy *k, Simulation* p )
{
    p->changeWater(3);
    if( p->getWater() < 0) p->nullWater();
    if( p->getWater() < 51)
    {
        return Green::instance();
    }
    return this;
}
Land* Lake::change( Rainy *k, Simulation* p )
{
    p->changeWater(15);
    if( p->getWater() < 0) p->nullWater();
    return this;
}

void Lake::destroy() { if ( nullptr!=_instance ) delete _instance; }
