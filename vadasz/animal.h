#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED
#include <string>

class Animal{
    protected:
        std::string _name;
        std::string _date;
        int _weight;
    public:
        Animal( std::string name, std::string date, int weight ) : _name(name), _date(date), _weight(weight) {}
        std::string getName() { return _name; };
        std::string getDate() { return _date; };
        int getweight() { return _weight; };
        virtual std::string getType() = 0;
        virtual std::string getSpecial() = 0;
};

class Elephant : public Animal
{
    protected:
        std::pair<int, int> _special;
    public:
        Elephant( std::string name, std::string date, int weight, std::pair<int, int> special ) : Animal(name, date, weight), _special(special) {}
        std::string getSpecial() override { return std::to_string(_special.first) + std::to_string(_special.second); };
        std::string getType() override { return "Elephant"; };
};

class Rhino : public Animal
{
    protected:
        int _special;
    public:
        Rhino( std::string name, std::string date, int weight, int special ) : Animal(name, date, weight), _special(special) {}
        std::string getSpecial() override { return std::to_string(_special); };
        std::string getType() override { return "Rhino"; };
};

class Lion : public Animal
{
    protected:
        std::string _special;
    public:
        Lion( std::string name, std::string date, int weight, std::string special ) : Animal(name, date, weight), _special(special) {}
        std::string getSpecial() override { return _special; };
        std::string getType() override { return "Lion"; };
};

#endif // ANIMAL_H_INCLUDED
