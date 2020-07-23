//Author: Beregi Bence Zsolt
//Date: 2020.04.05.
//Title: Anglers

#include "contest.h"

ContestEnor::ContestEnor(const std::string &str) throw (FileError)
{
    _f.open( str );
    if( _f.fail() ) throw MISSINGINPUTFILE;
}

void ContestEnor::next()
{
    std::string line;
    getline( _f, line );
    if(!( _end = _f.fail()))
    {
        std::istringstream is(line);
        is >> _cur.angler >> _cur.contest;
        std::string fish;
        double curWeight;
        _cur.wasCarp = false;
        for(is >> fish >> curWeight; !(is.fail()); is >> fish >> curWeight)
            if(fish == "carp")
            {
                if(curWeight < _cur.weight)
                    _cur.weight = curWeight;
                _cur.wasCarp = true;
            }
    }
}
