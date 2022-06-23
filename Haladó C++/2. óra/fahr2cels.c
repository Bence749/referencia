#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
#define FAHR2CELS(x) (5./9*((x)-32))

int main()
{
    /*int lower = 0;
    int upper = 300; Preprocessorban deklarálva
    int step = 20;*/ 
    
    int i = LOWER;

    for( ; i <= UPPER; i += STEP)
    {
        printf("%d Fahrenheit\t%f Celsius\n",
        i,
        /*5. / 9 * (i - 32) =(preprocessorban definiált képlet)=>*/ FAHR2CELS(i));
    }
    
    return 0;
}