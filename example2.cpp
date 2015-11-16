#include <vector>
#include <string>
using namespace std;

//Example 2
string getStringFromFile(const string&){return "";}
//void example2()
//{
//  string bigStrA = getStringFromFile("FileA.txt"); // Memory allocation
//  string bigStrB = getStringFromFile("FileB.txt"); // Memory allocation
//  const char* tinyPtr = "Test";
//  vector<string> v;
//  v.push_back(tinyPtr);
//  v.push_back(bigStrA);        // Memory allocation
//  bigStrB = bigStrB + tinyPtr; // Memory allocation
//  v.push_back(bigStrB);        // Memory allocation
//}

//============================Solution==========================================
void example2()
{
//  //=============================C++ 98=========================================
//  string bigStrA = getStringFromFile("FileA.txt"); // Memory allocation
//  string bigStrB = getStringFromFile("FileB.txt"); // Memory allocation
//  const char* tinyPtr = "Test";
//  vector<string> v;
//  v.push_back(tinyPtr);
//  v.push_back(bigStrA);        // Memory allocation
//
//  //bigStrB = bigStrB + tinyPtr;
//    // bigStrB is 2x copied. First in operator+ than in operator=
//  bigStrB += tinyPtr; //better solution because no copies are made
//
//  v.push_back(bigStrB); // Memory allocation
//
//
//  //=============================C++ 11/14======================================
  // In the C++98 solution bigStrA and bigStrB are 4x created/copied
  // When those strings are large, it can be a preformance problem. In C++11/C++14 there
  // is a better solution with only 2 memory allocations
  string bigStrB = getStringFromFile("FileB.txt"); // Memory allocation
  const char* tinyPtr = "Test";
  vector<string> v;
  v.push_back(tinyPtr);
  v.emplace_back( getStringFromFile("FileA.txt") ); // Memory allocation
  bigStrB += tinyPtr;
  v.push_back( std::move(bigStrB) );

  //Explanation:
  // -> v.emplace_back() uses "perfect forwarding". The Argument will be created
  //    in place. It only makes sense when a temporary variable is passed.
  //    There is no copy constructor or move constuctor call
  // -> v.push_back( std::move(bigStrB) ). std::move enables the call to the move
  //    constructor in C++11. In this case no new copy is made. Just pointers
  //    are moved. The new element of the vector has the memory of bigStrB
  //    Move should be used when variables are not needed any more. The variable
  //    which is moved is in a valid state, which means that the variable can be
  //    destroyed and a new value can be assigned to the variable. After the move,
  //    the value of the variable is not defined. Calls to the member functions
  //    bigStrB.len() or bigStrB.c_str() would cause undefined behavior
}
