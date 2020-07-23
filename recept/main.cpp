#include <iostream>
#include "recipe.h"

using namespace std;

int main()
{
    RecipeEnor t("input.txt");
    Recipe e;
    for( t.first(); !t.end(); t.next() )
        if( t.current().counter > e.counter )
            e = t.current();
    cout << "The following recipe needs the most ingredient(s): " << e.currentName << " with the total of: " << e.counter << " ingredient(s)";
    return 0;
}
