#include <iostream>
#include <string>
#include <vector>

using namespace std;

class szemely
{
    public:
        string name;
        string location;
        string birthLoc;
        string birthDate;
        string id;
        szemely(string name, string location, string birthLoc, string birthDate, string id)
        {
            this->name = name;
            this->location = location;
            this->birthLoc = birthLoc;
            this->birthDate = birthDate;
            this->id = id;
        }
};

int main()
{
    vector<szemely> a;
    a.push_back(szemely("Kis J�nos","Szeged","Budapest","2000.05.06.","1234ABCD"));
    a.push_back(szemely("Nagy Lajos","�zd","�zd","1973.06.01.","4321ABCD"));
    a.push_back(szemely("N�methy K�roly","Tatab�nya","�zd","2005.01.28.","1234DCBA"));
    a.push_back(szemely("Lengyel-T�th �bel","Majosh�za","Budapest","1934.12.24.","110353VQ"));

    for(unsigned i = 0; i < a.size(); i++) if(a.at(i).id == "110353VQ") {cout << a.at(i).name; break;}
    return 0;
}
