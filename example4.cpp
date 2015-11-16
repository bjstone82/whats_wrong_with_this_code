#include <cstdlib>
using namespace std;

//Example 4
//A "bug free" copy constructor is implemented. Assume that everything that is not implemented is valid!
//class Resource
//{
//  private:
//    unsigned char * m_data;
//    size_t m_sizeOfData;
//
//    static const size_t m_additionalByts = 8;
//
//  public:
//    Resource(size_t sizeOfData)
//    : m_sizeOfData(sizeOfData + Resource::m_additionalByts), m_data(new unsigned char[m_sizeOfData]) {}
//
//    ~Resource() { delete[] m_data;}
//
//};

//============================Solution==========================================
class Resource
{
  private:
    size_t m_sizeOfData;
    unsigned char * m_data;
    //size_t m_sizeOfData;
      // The Bug is that m_data is initialized bevor m_sizeOfData. For m_data an udefined number of
      // bytes will be allocated. Member variables are initialized in the order of definition in the
      // class declaration. All good compilers will warn you about this behavior.

    static const size_t m_additionalByts = 8;

  public:
    Resource(size_t sizeOfData)
    : m_sizeOfData(sizeOfData + Resource::m_additionalByts), m_data(new unsigned char[m_sizeOfData]) {}

    ~Resource() { delete[] m_data;}
};

void example4()
{
  Resource(10);
}

