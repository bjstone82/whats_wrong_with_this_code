#include <string>
using namespace std;

//Example 1
static void foo(string){}
static void bar(string){}
//void example1()
//{
//  string str = "Test1";
//  char * ptr = "Test2";
//  foo(string(str) + string(" + ") + string(ptr));
//  bar(string(ptr) + string(" + ") + string(str));
//}

//============================Solution==========================================
void example1()
{
  string str = "Test1";

  //char * ptr = "Test2";
    // ISO C++ forbids converting a string constant to ‘char*’ (most compilers
    // dispay a warning - it will be deprecated in the future)
  const char * ptr = "Test2"; // C++11/C++14

  //foo(string(str) + string(" + ") + string(ptr));
    // string(" + ") and string(ptr) redundant. An operator+(string, const char*) exists.
    // Operator+ is in C++ left associated. 5x Constructors (5x memory is allocated)
  foo(str + " + " + ptr); // C++98/C++11/C++14 only 2 Constructor calls

  //bar(string(ptr) + string(" + ") + string(str));
    // string(ptr) or string(" + ") ist needed because oeprator+ tries to add ptr and " + "
    // Such an operator does not exists. Operators for build-in types can not be overloaded
  bar(string(ptr) + " + " + str); //C++98/C++11 3x Constructor calls
  bar(ptr + " + "s + str); //C++14 3 nicer
}

//Source: Stephan T. Lavavej - Don't help the compiler (GoingNative 2013)
//        https://www.youtube.com/watch?v=AKtHxKJRwp4
