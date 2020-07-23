#include "enor.h"

Enor::Enor(const std::string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}

std::pair<std::string, int> Enor::next()
{
    read();
    std::pair<std::string, int> out = { _dx.item, _dx.amount*_dx.price };
    _end = (abnorm ==_sx);
    return out;
}

void Enor::read()
{
    _x >> _dx.id >> _dx.item >> _dx.orderTime >> _dx.amount >> _dx.price;
    _sx = _x.fail() ? abnorm : norm;
}
