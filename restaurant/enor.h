#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include <string>
#include <fstream>
#include <utility>

enum Status { abnorm, norm };

struct rendeles
{
    int id;
    std::string item;
    std::string orderTime;
    int amount;
    int price;
};

class Enor{
    public:
        enum Errors { FILEERROR };
        Enor(const std::string &str);
        std::pair<std::string, int> next();
        bool end() const { return _end; };
    private:
        std::ifstream _x;
        rendeles _dx;
        Status _sx;
        bool _end;
        void read();
};


#endif // ENOR_H_INCLUDED
