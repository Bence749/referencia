#ifndef WEATHER_H_INCLUDED
#define WEATHER_H_INCLUDED

#include <string>
#include "land.h"

class Weather
{
public:
    virtual void change( Land* &land, int *hum, Simulation *p ) = 0;
    virtual std::string getW() = 0;
    virtual ~Weather() {}
};

class Sunny : public Weather
{
    public:
        static Sunny* instance();
        static void destroy();
        std::string getW() override { return "Sunny"; }
        void change( Land* &land, int *hum, Simulation* p ) override
        {
            land = land->change(this, p);
            switch( land->getType() )
            {
            case 'D':
                *hum += 3; break;
            case 'G':
                *hum += 7; break;
            case 'L':
                *hum = 10; break;
            }
        }
    private:
        Sunny(){}
        static Sunny* _instance;
};

class Cloudy : public Weather
{
    public:
        static Cloudy* instance();
        static void destroy();
        std::string getW() override { return "Cloudy"; }
        void change( Land* &land, int *hum, Simulation* p ) override
        {
            land = land->change(this, p);
            switch( land->getType() )
            {
            case 'D':
                *hum +=  3; break;
            case 'G':
                *hum += 7; break;
            case 'L':
                *hum = 10; break;
            }
        }
    private:
        Cloudy(){}
        static Cloudy* _instance;
};

class Rainy : public Weather
{
    public:
        static Rainy* instance();
        static void destroy();
        std::string getW() override { return "Rainy"; }
        void change( Land* &land, int *hum, Simulation* p ) override
        {
            land = land->change(this, p);
            *hum = 30;
        }
    private:
        Rainy(){}
        static Rainy* _instance;
};

#endif // WEATHER_H_INCLUDED
