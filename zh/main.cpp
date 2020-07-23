#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/linsearch.hpp"
#include "library/counting.hpp"
#include "library/maxsearch.hpp"
#include "library/enumerator.hpp"

using namespace std;

struct dates
{
    string date;
    string success;
    friend istream& operator>>(istream &is, dates &d)
    {
        is >> d.date >> d.success;
        return is;
    }
};

struct line
{
    string name;
    string prio;
    int success;
};

class HabitSuccess : public Counting<dates>
{
    void first() override {}
    bool cond(const dates& e) const override { return e.success == "I"; }
};

istream& operator>>(istream &is, line &line)
{
    string str;
    getline(is, str);
    stringstream ss(str);
    ss >> line.name >> line.prio;
    HabitSuccess pr;
    StringStreamEnumerator<dates> enor(ss);
    pr.addEnumerator(&enor);
    pr.run();
    line.success = pr.result();
    return is;
}

class numberOfSuccess : public Counting<line>
{
private:
    string _name;
public:
    numberOfSuccess(const string &name) : _name(name) {}
protected:
    bool cond(const line& e) const override { return e.success; }
    bool whileCond(const line &e) const override { return e.name == _name; }
    void first() override {}
};

struct szokas
{
    string name;
    int numberOfSuccess;
};

class szokasEnum : public Enumerator<szokas>
{
private:
    SeqInFileEnumerator<line>* _f;
    szokas _szokas;
    bool _end;
public:
    szokasEnum(const string &fname) { _f = new SeqInFileEnumerator<line>(fname); }
    ~szokasEnum() { delete _f; }
    void first() override { _f->first(); next(); }
    void next() override;
    szokas current() const override { return _szokas; }
    bool end() const override { return _end; }
};

void szokasEnum::next()
{
    if( (_end = _f->end()) ) return;
    _szokas.name = _f->current().name;
    numberOfSuccess pr(_szokas.name);
    pr.addEnumerator(_f);
    pr.run();
    _szokas.numberOfSuccess = _f->current().success;
}

class rosszSzokas : public MaxSearch<szokas,int,Less<int>>
{
    virtual int func(const szokas& e) const override { return e.numberOfSuccess; }
};

int main()
{
    try
    {
        rosszSzokas pr;
        szokasEnum enor("test2.txt");
        pr.addEnumerator(&enor);
        pr.run();
        cout << "Legkevesbe megtartott szokas: "<< pr.optElem().name << endl;
    }
    catch (SeqInFileEnumerator<line>::Exceptions exc)
    {
        cout << "Fajl nem talalhato.\n";
    }
    return 0;
}
