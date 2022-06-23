#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

void print(const int& i)
{
    std::cout << i << ' ';
}

int main()
{
    //std::vector<int> v; //1. módszer (vektor létrehozás)
    std::vector<int> v( //2. módszer (vektor létrehozása)
        (std::istream_iterator<int>( std::cin )), //std::cin.begin()
        std::istream_iterator<int>() );           //std::cin.end()
    int i;
    while( std::cin >> i )
    {
        v.push_back( i );
    }

    std::sort( v.begin(), v.end() ); //algorithm
    /*for(i = 0; i < v.size(); ++i )
    {
        std::cout << v[ i ] << ' ';  //1. módszer (kiírás)
    }*/
    //std::for_each(v.begin(), v.end(), print); //2. módszer (kiírás)
    std::copy( v.begin(), 
             v.end(), 
             std::ostream_iterator<int>( std::cout, " " ) ); //3. módszer (kiírás)
    std::endl( std::cout );
}