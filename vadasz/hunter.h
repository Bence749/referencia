#ifndef HUNTER_H_INCLUDED
#define HUNTER_H_INCLUDED
#include "trophy.h"
#include <string>
#include <vector>

class Hunter
{
    protected:
        std::string _name;
        int _age;
        std::vector<Trophy*> _trophies;
    public:
        Hunter( std::string name, int age, int n ) : _name(name), _age(age) {}
        void earn( Trophy* trophy ) { _trophies.push_back(trophy); };
        int howManyMaleLions()
        {
            int counter = 0;
            //std::cout << "Faj: " << t->getAnimal()->getType() << "Speciál: " << t->getAnimal()->getSpecial();
            for(Trophy* t : _trophies)
                if(t->getAnimal()->getType() == "Lion" && (t->getAnimal()->getSpecial() == "Male" || t->getAnimal()->getSpecial() == "male"))
                    counter++;
            return counter;
        }
};

#endif // HUNTER_H_INCLUDED
