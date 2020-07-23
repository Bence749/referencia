#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED
#include "land.h"
#include <iostream>
#include <vector>

class Desert;
class Green;
class Lake;

class World
{
    public:
        int humidity;
        std::vector<Land*> lands;
        void weather( int x );
        bool allTheSame();
};
#endif // WORLD_H_INCLUDED
