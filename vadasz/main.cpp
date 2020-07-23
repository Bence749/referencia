#include <iostream>
#include <utility>

#include "hunter.h"
#include "elephant.h"

using namespace std;

int main()
{
    Hunter* Sanyi = new Hunter("Sanyi", 42, 6);
    Sanyi->earn(new Trophy(new Elephant("elefant", "2012.06.26.", 820, {32, 34}), "Nig�ria"));
    Sanyi->earn(new Trophy(new Lion("lion", "2012.07.26.", 560, "Male"), "Rom�nia"));
    Sanyi->earn(new Trophy(new Lion("lion", "2012.07.26.", 560, "female"), "Magyarorsz�g"));
    cout << Sanyi->howManyMaleLions();
    return 0;
}
