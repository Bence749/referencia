#ifndef TROPHY_H_INCLUDED
#define TROPHY_H_INCLUDED
#include <string>
#include "animal.h"

class Trophy
{
    protected:
        Animal* _animal;
        std::string _place;
    public:
        Trophy( Animal* animal ,std::string place) : _animal(animal), _place(place){}
        Animal* getAnimal() { return _animal; }
        std::string getPlace() { return _place; }
};

#endif // TROPHY_H_INCLUDED
