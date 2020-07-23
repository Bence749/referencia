#include <iostream>
#include <vector>
#include <math.h>
#include "polinom.h"

std::vector<double> Pol::getVals()
{
    return vals;
}

void Pol::out()
{
    for(int i = 0; i < (int)vals.size(); i++)
    {
        if(vals.at(i) != 0)
            i != (int)(vals.size() - 1) ? std::cout << vals.at(i) << "(x^" << vals.size() - i - 1 << ")" : std::cout << vals.at(i);
        if(i != (int)vals.size() - 1 && vals.at(i + 1) != 0)
            std::cout << '+';
    }
    std::cout << std::endl;
}

Pol* Pol::sum(Pol* x)
{
    if(vals.size() == 0)
    {
        std::vector<double> a(x->getVals().size(), 0);
        addVec(a);
    }
    std::vector<double> z(std::max(vals.size(), x->getVals().size()), 0);
    int sizeOfSmaller = std::min(vals.size(), x->getVals().size());
    bool isThisTheSmaller = sizeOfSmaller == (int)vals.size();
    for(int i = std::max(vals.size(), x->getVals().size()) - 1; i >= 0; --i)
    {
        if(sizeOfSmaller > 0)
        {
            if(!isThisTheSmaller)
                z.at(i) = (vals.at(i) + x->getVals().at(sizeOfSmaller - 1));
            else
                z.at(i) = (vals.at(sizeOfSmaller - 1) + x->getVals().at(i));
            sizeOfSmaller--;
        }
        else
            if(isThisTheSmaller)
                z.at(i) = x->getVals().at(i);
            else
                z.at(i) = vals.at(i);
    }
    Pol* out = new Pol();
    out->addVec(z);
    return out;
}

Pol* Pol::mult(Pol* x)
{
    if(vals.size() == 0)
    {
        std::vector<double> a(x->getVals().size(), 0);
        addVec(a);
    }
    std::vector<double> z(vals.size() + x->getVals().size(), 0);
    for(int i = 0; i < (int)vals.size(); i++)
        for(int j = 0; j < (int)x->getVals().size(); j++)
            z.at(i+j) += vals.at(vals.size() - i - 1) * x->getVals().at(x->getVals().size() - j - 1);
    int start = vals.size() + x->getVals().size() - 1;
    while(start >= 0 && z.at(start) == 0) start--;
    Pol* out = new Pol();
    if(start >= 0)
        for(int i = start; i >= 0; i--)
            out->addEl(z.at(i));
    return out;
}

double Pol::calc(double x)
{
    float out = 0;
    for(int i = vals.size() - 1; i >= 0; i--)
        out += vals.at(i) * pow(x, vals.size() - i - 1);
    return out;
}
