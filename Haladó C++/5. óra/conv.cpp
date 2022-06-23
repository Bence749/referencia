#include <iostream>

//T -> d
//a -> F
//i -> E

struct Pair
{
    char from;
    char to;

    Pair( char f, char t )
    {
        from = f;
        to = t;
    }
};

char conv( char ch )
{
    /*switch ( ch )
    {
        case 'T': return 'd'; break;
        case 'a': return 'F'; break; ==> Amatőr megoldás
        case 'i': return 'E'; break;
        default: return ch; break;
    }*/

    static const Pair conv[] = { Pair( 'T', 'd' ), Pair( 'a', 'F' ), Pair( 'i', 'E' ) };

    for( int i = 0; i < sizeof( conv )/sizeof( conv[0] ); i++ )
        if( conv[ i ].from == ch )
            return conv[ i ].to;

    return ch;
}