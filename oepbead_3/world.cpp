#include "world.h"
#include <cstdlib>

void World::weather( int x )
{
    int switcher = humidity > 70 ? 2 : ( humidity < 40 ? 0 : (x < (humidity - 40)*3.3) ? 2 : 1 );
    std::cout << "|---" << (switcher == 0 ? "Sunny" : (switcher == 2 ? "Rainy" : (x < (humidity - 40)*3.3 ? "Rainy" : "Cloudy"))) << "---|" << std::endl;
    for(unsigned int i = 0; i < lands.size(); i++)
    {
        std::cout << "Kezdet: " << lands[i]->getName() << " adatai: " << lands[i]->getWater() << "km3; " << lands[i]->type() << std::endl;
        switch( switcher )
        {
            case 0:
            {
                char newType = lands[i]->changes('S', &humidity);
                if( newType != lands[i]->type() )
                    lands[i] = lands[i]->change(newType, lands[i]->getName(), lands[i]->getWater() );
                break;
            }
            case 1:
            {
                char newType = lands[i]->changes('C', &humidity);
                if (newType != lands[i]->type())
                    lands[i] = lands[i]->change(newType, lands[i]->getName(), lands[i]->getWater() );
                break;
            }
            case 2:
            {
                char newType = lands[i]->changes('R', &humidity);
                if (newType != lands[i]->type())
                    lands[i] = lands[i]->change(newType, lands[i]->getName(), lands[i]->getWater() );
                break;
            }
        }
        std::cout << "Veg: " << lands[i]->getName() << " adatai: " << lands[i]->getWater() << "km3; " << lands[i]->type() << std::endl;
    }
    std::cout << "Humidity " << humidity << std::endl;
}

bool World::allTheSame()
{
    bool out = true;
    for(unsigned int i = 0; out && i < lands.size(); i++)
        out = (lands[0]->type() == lands[i]->type());
    return out;
}
