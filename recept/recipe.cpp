#include "recipe.h"

RecipeEnor::RecipeEnor(const std::string &str) throw (FileError)
{
    _f.open( str );
    if( _f.fail() ) throw MISSINGINPUTFILE;
}

void RecipeEnor::read()
{
    _f >> _cur.name >> _cur.ingredient >> _cur.amount >> _cur.unit;
    _sf = _f.fail() ? abnorm : norm;
}

void RecipeEnor::next()
{
    if( !(_end = ( abnorm == _sf )))
    {
        _cur.counter = 0;
        std::string name = _cur.name;
        for( ; _sf == norm && _cur.name == name ; read() )
            _cur.counter++;
        _cur.currentName = name;
    }
}
