#include <memory>
using namespace std;

//Example 3
//Copy constructor, assigment pperator and other functions are not implemented
//in this example. Assume that everythin that is not implemented is valid!
class Resource { };
//class ReasourceManager
//{
//  private:
//    Resource * m_ptr1;
//    Resource * m_ptr2;

//  public:
//    ReasourceManager() {
//      m_ptr1 = new Resource();
//      m_ptr2 = new Resource();
//    }

//    ~ReasourceManager() {
//      delete m_ptr1;
//      delete m_ptr2;
//    }
//};

//============================Solution==========================================
class ReasourceManager
{
  private:
    //Resource * m_ptr1;
    //Resource * m_ptr2;
    shared_ptr<Resource> m_ptr1;
    shared_ptr<Resource> m_ptr2;

  public:
    ReasourceManager() {
      m_ptr1 = make_shared<Resource>(Resource());
      m_ptr2 = make_shared<Resource>(Resource()); //-> if this line thorws an exception and
      // m_ptr1 is no smart pointer, than there is a memory leak because the allocated
      // memory for m_ptr1 will not be freed. The destructor is never called because a
      // exception is throwen in the construcotr. The destructor is only called for objects
      // which are fully constructed (the } from the constructor is reached). For all
      // fully constructed member variable the destructors are called.
      //=============================C++ 11/14======================================
      //The functins make_shared and make_unique(C++14) have certain advantages over the new keyword
    }

    //No need for a destructor
    //~Resource() {
    //  delete m_ptr1;
    //  delete m_ptr2;
    //}
};

void example3()
{
  ReasourceManager();
}

//Source: Stephan T. Lavavej - Don't help the compiler (GoingNative 2013)
//        https://www.youtube.com/watch?v=AKtHxKJRwp4
