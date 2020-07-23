#include "weather.h"

Sunny* Sunny::_instance = nullptr;
Sunny* Sunny::instance()
{
    if( _instance == nullptr )
        _instance = new Sunny();
    return _instance;
}
void Sunny::destroy() { if ( nullptr!=_instance ) delete _instance; }

Cloudy* Cloudy::_instance = nullptr;
Cloudy* Cloudy::instance()
{
    if( _instance == nullptr )
        _instance = new Cloudy();
    return _instance;
}
void Cloudy::destroy() { if ( nullptr!=_instance ) delete _instance; }

Rainy* Rainy::_instance = nullptr;
Rainy* Rainy::instance()
{
    if( _instance == nullptr )
        _instance = new Rainy();
    return _instance;
}
void Rainy::destroy() { if ( nullptr!=_instance ) delete _instance; }
