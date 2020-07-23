//Author: Beregi Bence Zsolt
//Date: 2020.04.05.
//Title: Anglers

#ifndef CONTEST_H_INCLUDED
#define CONTEST_H_INCLUDED

#include <fstream>
#include <sstream>
#include <string>

struct Contest
{
    std::string angler;
    std::string contest;
    bool wasCarp = false;
    double weight = 1000;
};

class ContestEnor
{
    private:
        std::ifstream _f;
        Contest _cur;
        bool _end;
    public:
        enum FileError{ MISSINGINPUTFILE };
        ContestEnor( const std::string &str ) throw ( FileError );
        void first() { next(); };
        void next();
        Contest current() const { return _cur; };
        bool end() const { return _end; };
};

#endif // CONTEST_H_INCLUDED
