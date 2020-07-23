//Author: Beregi Bence Zsolt
//Date: 2020.04.05.
//Title: Anglers

#include "angler.h"

void AnglerEnor::next()
{
    if( !(_end = _tt.end()) )
    {
        _cur.id = _tt.current().angler;
        int counter = 0;
        for( ; !_tt.end() && _tt.current().angler == _cur.id; _tt.next() )
            if(_tt.current().wasCarp) counter++;
        if(counter >= 2)
            _cur.atleastTwo = true;
        else
            _cur.atleastTwo = false;
    }
}
