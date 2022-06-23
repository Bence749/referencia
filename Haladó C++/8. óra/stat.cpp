#include <set>
#include <iterator>
#include <iostream>

double rate( int cnt, int all )
{
    return 100. * cnt / all;
}

int main()
{
    std::multiset<char> stat(
        (std::istream_iterator<char>( std::cin )),
        std::istream_iterator<char>()
    );

    for( std::multiset<char>::iterator i = stat.begin(); i != stat.end(); )
    {
        int n = stat.count( *i );
        std::cout << *i << ':' << n << " (" << rate( n, stat.size()) << "%)" <<std::endl;
        i = stat.upper_bound( *i );
    }
}