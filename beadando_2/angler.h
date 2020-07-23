//Author: Beregi Bence Zsolt
//Date: 2020.04.05.
//Title: Anglers

#ifndef ANGLER_H_INCLUDED
#define ANGLER_H_INCLUDED

#include "contest.h"

struct Angler
{
    std::string id;
    bool atleastTwo = false;
};

class AnglerEnor
{
    private:
        ContestEnor _tt;
        Angler _cur;
        bool _end;
    public:
        AnglerEnor(const std::string &str): _tt(str) { };
        void first() {_tt.first(); next();};
        void next();
        Angler current() const {return _cur;};
        bool end() const { return _end; };
};

#endif // ANGLER_H_INCLUDED
