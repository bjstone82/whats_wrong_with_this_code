#include <iostream>
using namespace std;

class Vehical
{
  public:
    virtual string name() const
    {return "Vehical!";}
};

class Car : public Vehical
{
  public:
    string name() const override
    {return "Car!";}
};

class Bike : public Vehical
{
  public:
    string name() const override
    {return "Bike!";}
};

void foo(Vehical& vehical) { cout << "Vehical" << endl; }
void foo(Vehical* vehical) { cout << "Vehical" << endl; }
void foo(Car* car)         { cout << "Car"     << endl; }
void foo(Bike* bike)       { cout << "Bike"    << endl; }

void bar(Vehical& vehical) { cout << vehical.name()  << endl; }
void bar(Vehical* vehical) { cout << vehical->name() << endl; }
void bar(Car* vehical)     { cout << vehical->name() << endl; }
void bar(Bike* vehical)    { cout << vehical->name() << endl; }

void example6()
{
  Vehical* someVehical = new Car;
  Vehical* someOtherVehical = new Bike;
  Car car;
  Bike bike;

  foo(someVehical);
  foo(*someVehical);
  foo(someOtherVehical);
  foo(*someOtherVehical);
  foo(car);
  foo(&bike);

  bar(someVehical);
  bar(*someVehical);
  bar(someOtherVehical);
  bar(*someOtherVehical);
  bar(car);
  bar(&bike);
}
