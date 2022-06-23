#include <iostream>

class Shape
{
    int color;

public:
    Shape( int c ) : color( c ) { }

    int get_color() const
    {
        return color;
    }

    virtual double get_area() const = 0;

    virtual ~Shape() { } 
};

void print( Shape* p )
{
    std::cout << p->get_color() << ' ' << p->get_area() << std::endl;
}

class Circle : public Shape
{
    double rad;

public:
    Circle( int c, double r ): Shape( c ), rad( r ) { }

    virtual ~Circle() { }

    virtual double get_area() const
    {
        return rad * rad * 3.14;
    }

    int get_color() const
    {
        return -1;
    }
};

class Rectangle: public Shape
{
    int width, height;
public:
    Rectangle( int c, double x, double y ): Shape( c ), height( y ), width( x ) { }

    virtual double get_area() const
    {
        return width * height;
    }
};

int main()
{
    Shape* p = new Circle(6, 5.1);
    std::cout << p->get_area() << std::endl;
    print( p );
    Circle c(6, 5.1);
    std::cout << c.get_color() << std::endl;
    delete p;
    p = new Rectangle( 5, 4, 7.5 );
    print( p );
    delete p;
}