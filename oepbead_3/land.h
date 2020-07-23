#ifndef LAND_H_INCLUDED
#define LAND_H_INCLUDED

#include <string>

class Simulation;
class Sunny;
class Cloudy;
class Rainy;

class Land
{
public:
    virtual char getType() = 0;
	virtual Land* change(Sunny* k, Simulation* p) = 0;
	virtual Land* change(Cloudy* k, Simulation* p) = 0;
	virtual Land* change(Rainy* k, Simulation* p) = 0;
	virtual ~Land() {};
};

class Desert : public Land
{
public:
	static Desert* instance();
	Land* change(Sunny* k, Simulation* p) override;
	Land* change(Cloudy* k, Simulation* p) override;
	Land* change(Rainy* k, Simulation* p) override;
	static void destroy();
	char getType() override { return 'D'; }
private:
    Desert(){}
	static Desert* _instance;
};

class Green : public Land
{
public:
	static Green* instance();
	Land* change(Sunny* k, Simulation* p) override;
	Land* change(Cloudy* k, Simulation* p) override;
	Land* change(Rainy* k, Simulation* p) override;
	static void destroy();
	char getType() override { return 'G'; }

private:
    Green(){}
	static Green* _instance;
};

class Lake : public Land
{
public:
	static Lake* instance();
	Land* change(Sunny* k, Simulation* p) override;
	Land* change(Cloudy* k, Simulation* p) override;
	Land* change(Rainy* k, Simulation* p) override;
	static void destroy();
	char getType() override { return 'L'; }
private:
    Lake(){}
	static Lake* _instance;
};
#endif // LAND_H_INCLUDED
