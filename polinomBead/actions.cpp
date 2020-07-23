#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "actions.h"
#include "polinom.h"

void polKi(std::vector<Pol*> x)
{
    for(int i = 0; i < (int)x.size(); i++)
    {
        std::cout << i+1 << ": ";
        x[i]->out();
    }
}

int checker(int x, std::string select)
{
    if(select == "min")
    {
        int out = -1;
        do
        {
            try
            {
                std::string x;
                getline(std::cin, x);
                out = stoi(x);
            }
            catch(...){std::cout << "Rossz ertek! Probald ujra: ";}
            if(out < x)
                std::cout << "Rossz ertek! Probald ujra: ";
        } while(out < x);
        return out;
    } else
    {
        int out = x + 1 ;
        do
        {
            try
            {
                std::string x;
                getline(std::cin, x);
                out = stoi(x);
            }
            catch(...){std::cout << "Rossz ertek! Probald ujra: ";}
            if(out > x)
                std::cout << "Rossz ertek! Probald ujra: ";
        } while(out > x);
        return out;
    }
}

int checker(int x, int y)
{
    int out = std::min(x, y) - 1;
    bool didCatch = false;
    do
    {
        try
        {
            std::string x;
            getline(std::cin, x);
            out = stoi(x);
        }
        catch(...){std::cout << "Rossz ertek! Probald ujra: "; didCatch = true;}
        if((out > std::max(x, y) || out < std::min(x, y)) && !didCatch)
            std::cout << "Rossz ertek! Probald ujra: ";
        didCatch = false;
    } while(out > std::max(x, y) || out < std::min(x, y));
    return out;
}

std::string splitter(int *start, std::string str, char delimetter, bool *x)
{
    *start += str.find(delimetter) + 1;
    *x = str.find(delimetter) == std::string::npos;
    str = str.substr(0, str.find(delimetter));
    return str;
}

void whatNext(bool* x, bool* y)
{
    std::cout << "Szeretne folytatni (1) vagy uj polinomokat megadni (2) vagy befejezni (3)?: ";
            int nextStep = checker(1, 3);
            if(nextStep == 2)
                *x = false;
            else if(nextStep == 3)
            {
                *y = false;
                *x = false;
            }
}

std::vector<double> be(int x, std::vector<Pol*> y)
{
    std::vector<double> out;
    bool retry = true;
    while(retry)
    {
        int start = 0;
        bool isLast = false;
        std::string input;
        getline(std::cin, input);
        try
        {
            retry = false;
            int tp;
            while(isLast == false)
            {
                tp = stod(splitter(&start, input.substr(start), ' ', &isLast));
                if(tp < 1 || tp > x)
                    throw std::out_of_range("oor");
                out.push_back(tp);
            }
        }
        catch(...)
        {
            std::cout << "Hibas bemenet. Elerheto polinomok:\n";
            polKi(y);
            std::cout << "Probald ujra: ";
            retry = true;
        }
    }
    return out;
}

double beX()
{
    double out;
    std::string input;
    bool success = false;
    do
    {
        try
        {
            getline(std::cin, input);
            out = stod(input);
            success = true;
        }
        catch(...)
        {
            std::cout << "Helytelen ertek! Probald ujra: ";
            success = false;
        }
    } while(!success);
    return out;
}
