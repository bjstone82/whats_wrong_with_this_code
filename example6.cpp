#include <iostream>
using namespace std;

class Vehicle
{
  public:
    virtual string name() const
    {return "Vehicle!";}
};

class Car : public Vehicle
{
  public:
    string name() const override
    {return "Car!";}
};

class Bike : public Vehicle
{
  public:
    string name() const override
    {return "Bike!";}
};

void foo(Vehicle& /*vehicle*/) { cout << "Vehicle" << endl; }
void foo(Vehicle* /*vehicle*/) { cout << "Vehicle" << endl; }
void foo(Car* /*car*/)         { cout << "Car"     << endl; }
void foo(Bike* /*bike*/)       { cout << "Bike"    << endl; }

void bar(Vehicle& vehicle) { cout << vehicle.name()  << endl; }
void bar(Vehicle* vehicle) { cout << vehicle->name() << endl; }
void bar(Car* vehicle)     { cout << vehicle->name() << endl; }
void bar(Bike* vehicle)    { cout << vehicle->name() << endl; }

void example6()
{
  Vehicle* someVehicle = new Car;
  Vehicle* someOtherVehicle = new Bike;
  Car car;
  Bike bike;

  // which foo is called is evaluated with the overloading resolution. This
  // happens in C++ at compile time. The compiler knows that someVehicle and
  // someOtherVehicle are pointers to a Vehicle object and calls the foo(vehicle)
  // function
  foo(someVehicle);       // Vehicle
  foo(*someVehicle);      // Vehicle
  foo(someOtherVehicle);  // Vehicle
  foo(*someOtherVehicle); // Vehicle

  // The compiler chooses which function is the right one depending on Koening Lookup
  // (oversimplified: The function for which less implicit casts are needed is called).
  // In this example foo(Vehicle&) is the only function with can be called (1 cast is needed)
  foo(car);               // Vehicle -> upcasting

  foo(&bike);             // Bike

  // same as above happens: the functions bar(Vehicle) are called. Because of Polymophism
  // (which happens at runtime) the right name() function is called.
  bar(someVehicle);       // Car!
  bar(*someVehicle);      // Car!
  bar(someOtherVehicle);  // Bike!
  bar(*someOtherVehicle); // Bike!
  bar(car);               // Car!

  bar(&bike);             // Bike!
}
