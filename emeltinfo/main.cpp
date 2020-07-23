#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Weather
{
private:
    string _location;
    string _time;
    string _data;
    int _temp;
    bool _isSet = false;
public:
    Weather( string loc, string time, string data, int temp) : _location(loc), _time(time), _data(data), _temp(temp), _isSet(true) {}
    bool locChekc( string x ) { return _location == x; }
    string getTime() { return _time; }
    string getLoc() { return _location; }
    int getTemp() { return _temp; }
    string formatTime() { return _time.substr(0, 2) + ":" + _time.substr(2); }
    string getData() { return _data; }
    bool isSet() { return _isSet; }
};

int main()
{
    ifstream f("input.txt");
    vector<Weather*> inp;
    string l;
    while( f >> l )
    {
        string t, d;
        int te;
        f >> t >> d >> te;
        inp.push_back( new Weather(l, t, d , te) );
    }
    string line;
    cout << "2. feladat\nAdja meg a telepules kodjat! Telepules: ";
    getline(cin, line);
    Weather* second;
    Weather* min = inp[0];
    Weather* max = inp[0];
    vector<Weather*> fourth;
    list<string> cities;
    for( Weather* x : inp )
    {
        if(x->locChekc(line))
            second = x;
        if( min->getTemp() > x->getTemp() )
            min = x;
        if( max->getTemp() < x->getTemp() )
            max = x;
        if( x->getData() == "00000" )
            fourth.push_back(x);
        cities.push_back(x->getLoc());
    }

    cout << "Az utolso meresi adat a megadott telepulesrol " << second->formatTime() << "-kor erkezett!" << endl;
    cout << "3. feladat:\nA legalacsonyabb homerseklet: " << min->getLoc() << ' ' << min->formatTime() << ' ' << min->getTemp() << " fok" << endl;
    cout << "A legmagasabb homerseklet: " << max->getLoc() << ' ' << max->formatTime() << ' ' << max->getTemp() << " fok" << endl;
    if(fourth.size() == 0)
        cout << "4.feladat\nNem volt szelcsend a meresek idejen!" << endl;
    else for( Weather* x : fourth)
        cout << x->getLoc() << ' ' << x->formatTime() << endl;
    cities.sort();
    cities.unique();
    cout << "5. feladat" << endl;
    for(string x : cities)
    {
        ofstream w;
        w.open( x + ".txt" );
        w << x << endl;
        int temp = 0;
        int counter = 0;
        int mi, ma;
        bool first = true;
        list<string> times;
        for( Weather* y : inp )
        {
            if( y->getLoc() == x )
                {
                    if(y->getTime().substr(0, 2) == "01" || y->getTime().substr(0, 2) == "07" || y->getTime().substr(0, 2) == "13" || y->getTime().substr(0, 2) == "19" )
                    {
                        temp += y->getTemp();
                        counter++;
                        times.push_back( y->getTime().substr(0, 2) );
                    }
                    if(mi > y->getTemp() || first)
                        mi = y->getTemp();
                    if(ma < y->getTemp() || first)
                        ma = y->getTemp();
                    first = false;
                    w << y->formatTime() << ' ';
                    for( int i = 0; i < stoi(y->getData().substr(3, 2)); i++)
                        w << '#';
                    w << endl;
                }
        }
        times.unique();
        if( times.size() != 4 )
            cout << x << " NA ; Homerseklet-ingadozas: " << ma-mi << endl;
        else
            cout << x << " Kozephomerseklet: " << temp/counter << "; Homerseklet-ingadozas: " << ma-mi << endl;
    }
    cout << "Fajlok elkeszultek!" << endl;
    return 0;
}
