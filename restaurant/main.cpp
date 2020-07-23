#include <iostream>
#include <map>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("input.txt");
    map<std::string, int> orderPrices;
    for(pair<std::string, int> i = t.next(); !t.end(); i = t.next())
        if(!(orderPrices.insert(i).second))
            (orderPrices.find(i.first))->second += i.second;

    std::string maxName = orderPrices.begin()->first;
    int maxVal = orderPrices.begin()->second;
    map<std::string, int>::iterator it;
    for(it = orderPrices.begin(); it != orderPrices.end(); it++)
        if(it->second > maxVal)
        {
            maxName = it->first;
            maxVal = it->second;
        }
    cout << "A legtobb bevetelt hozo etel: " << maxName;
    return 0;
}
