#include <iostream>
#include "customer.h"
#include "station.h"
#include "cashregister.h"

void Customer::tankol( int statId, int amount, int cashId )
{
    _gasstation->tolt(statId, amount);
    _gasstation->pay(cashId, statId);

}
