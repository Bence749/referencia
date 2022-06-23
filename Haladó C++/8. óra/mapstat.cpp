#include <iostream>
#include <map>
#include <algorithm>

double rate( int cnt, int all )
{
    return 100. * cnt / all;
}

struct Print
{
    int all;

    Print( int i ) { all = i; }

    void operator()( const std::pair<char, int>& p )
    {
        std::cout << p.first << ':' << p.second << " (" << rate(p.second, all) << "%)" << std::endl;
    }
};

int main()
{
    int all = 0;
    std::map<char, int> stat;
    char ch;
    while( std::cin >> ch )
    {
        ++stat[ ch ];
        ++all;
    }

    std::for_each( stat.begin(), stat.end(), Print( all ) );
}