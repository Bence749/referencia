#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.1415

int main()
{
    /*int a, b;
    char nev[10];
    double doub[10];
    scanf("%s", &nev);
    scanf("%d %d", &a, &b);
    int size = sizeof(nev) / sizeof(nev[0]);
    printf("Size of nev array: %d\n", size);
    printf("Hello %s!\nAs a rectangle:\nCircumference of the rectangle: %d\nArea of the rectangle: %d", nev, a+b, a*b);
    printf("As a circle where 'a' is the diameter:\nCircumference of the circle: %f\nArea of the circle: %f", PI*a, (PI/4)*a*a);*/

    /*int years = 0, weeks = 0, days;
    scanf("%d", &days);
    printf("%d = ", days);
    if(days / 365 > 0)
    {
            years += days/365;
            days -= 365*(days/365);
    }
    if(days / 7 > 0)
    {
            weeks += days/7;
            days -= 7*(days/7);
    }
    printf("%d year(s) %d week(s) %d day(s)", years, weeks, days);*/

    /*char from;
    float temp;
    scanf("%s %f", &from, &temp);
    switch(from)
    {
        case 'c': printf("%.2f Celsius = %.2f Fahrenheit", temp, temp*1.8+32);
            break;
        case 'f': printf("%.2f Fahrenheit = %.2f Celsius", temp, (temp-32)/1.8);
            break;
        default: printf("Bad input!");
            break;
    }*/
    char input[10];
    scanf("%s", &input);
    while(strcmp(input, "quit.") != 0)
    {
        printf("Hello %s\n", input);
        scanf("%s", &input);
    }
    return 0;
}
