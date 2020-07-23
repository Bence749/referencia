#ifndef RECIPE_H_INCLUDED
#define RECIPE_H_INCLUDED

#include <string>
#include <fstream>
#include <sstream>

enum Status { abnorm, norm };

struct Recipe
{
    std::string name;
    std::string currentName;
    std::string ingredient;
    double amount;
    std::string unit;
    int counter = 0;
};

class RecipeEnor
{
    private:
        std::ifstream _f;
        Recipe _cur;
        bool _end;
        Status _sf;
        void read();
    public:
        enum FileError { MISSINGINPUTFILE };
        RecipeEnor (const std::string &str) throw (FileError);
        void first() { read(); next(); };
        void next();
        Recipe current() const { return _cur; };
        bool end() const { return _end; };
};

#endif // RECIPE_H_INCLUDED
