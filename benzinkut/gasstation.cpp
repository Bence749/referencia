#include "gasstation.h"
#include "cashregister.h"
#include "station.h"

Gasstation::Gasstation( int n, int k )
{
    _stations.resize(n);
    _cashregisters.resize(k);
    _numberOfStations = n;
    _numberOfCashregisters = k;
    for( int i = 0; i < n; i++ ) { _stations[i] = new Station(i+1); };
    for( int i = 0; i < k; i++ ) { _cashregisters[i] = new Cashregister(i+1); };
}

Station* Gasstation::getStation( int n ) throw ( OutOfRange )
{
    if( n > _numberOfStations )
        throw OUTOFRANGE;
    else
        return _stations[n-1];
}

Cashregister* Gasstation::getCashregister( int k ) throw ( OutOfRange )
{
    if( k > _numberOfCashregisters )
        throw OUTOFRANGE;
    else
        return _cashregisters[k-1];
}
