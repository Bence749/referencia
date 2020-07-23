#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED

#include <iostream>
#include <vector>

class Pol {
private:
    std::vector<double> vals;
public:
    void addEl(double x) {vals.push_back(x);}
    void addVec(std::vector<double> x) {for(double i : x) addEl(i);}
    std::vector<double> getVals();
    Pol* sum(Pol* x);
    Pol* mult(Pol* x);
    double calc(double x);
    void out();
};

#endif // POLINOM_H_INCLUDED
