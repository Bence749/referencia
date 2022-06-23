#include <vector>
#include <string>
#include <iostream>

class safe_string : public std::string
{
    //std::string s; unalmas ezért inkább származtatjuk
public:
    safe_string( const char* p ): std::string( p ? p: "") { }

    /*int size() const
    {
        return s.size();
    }
                                //==>Nincs szükség ezekre a származtatás miatt mivel ezeket megkapja a szülőtöl
    void push_back( char ch )
    {
        s.push_back( ch );
    }*/
};

int main()
{
    std::vector<char> v( 7 );
    std::cout << v.size() << std::endl;
    //std::string s( 0 ); //Ugye a sima string nullptr esetén segmentációs hibát dob

    safe_string s( 0 );
    s.push_back( 'a' );
    std::cout << s.size() << std::endl;
    const safe_string t("Hello");
    std::cout << t.size() << std::endl;
}