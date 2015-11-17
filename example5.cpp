#include <algorithm>
using namespace std;
//Example 5
//A "bug free" copy constructor is implemented. Assume that everything that is not implemented is valid!
//class Resource
//{
//  private:
//    size_t m_sizeOfData;
//    unsigned char * m_data;
//
//    static const size_t m_additionalByts = 8;
//
//  public:
//    Resource(size_t sizeOfData)
//    : m_sizeOfData(sizeOfData + Resource::m_additionalByts), m_data(new unsigned char[m_sizeOfData]) {}
//
//    Resource& operator=(const Resource& other)
//    {
//      delete[] m_data;                           //delete old data
//      m_sizeOfData = other.m_sizeOfData;
//      m_data = new unsigned char(m_sizeOfData); //allocate memory for new data
//      std::copy(other.m_data, other.m_data + m_sizeOfData, m_data); //copy data from other to this
//      return *this;
//    }
//
//    ~Resource() { delete[] m_data;}
//};

//===========================Solution===========================================
//There are several levels of exception safety
//    1. No-throw guarantee, also known as failure transparency: Operations are guaranteed to succeed and satisfy all requirements even in exceptional situations. If an exception occurs, it will be handled internally and not observed by clients.
//    2. Strong exception safety, also known as commit or rollback semantics: Operations can fail, but failed operations are guaranteed to have no side effects, so all data retain their original values.[4]
//    3. Basic exception safety, also known as a no-leak guarantee: Partial execution of failed operations can cause side effects, but all invariants are preserved and no resources are leaked. Any stored data will contain valid values, even if they differ from what they were before the exception.
//    4. No exception safety: No guarantees are made.
//
//===================OK Solution - basic exception guarantee====================
//class Resource
//{
//  private:
//    size_t m_sizeOfData;
//    unsigned char * m_data;
//
//    static const size_t m_additionalByts = 8;
//
//  public:
//    Resource(size_t sizeOfData)
//    : m_sizeOfData(sizeOfData + Resource::m_additionalByts), m_data(new unsigned char[m_sizeOfData]) {}
//
//    Resource& operator=(const Resource& other)
//    {
//      // test for selfassigment. If the object is assigned to itself do nothing.
//      // If no such check, than m_data will be deleted!
//      if(this != &other)
//      {
//        delete[] m_data;
//        m_data = nullptr;  // if an exception happens while allocating the new memory, the
//        // old memory will not again be destroyed after the destructor is called. If
//        // m_data is not set to NULL, it will be 2x deleted (segmentation fault)
//        m_sizeOfData = other.m_sizeOfData;
//        m_data = new unsigned char[m_sizeOfData];
//        std::copy(other.m_data, other.m_data + m_sizeOfData, m_data);
//      }
//      return *this;
//    }
//
//    ~Resource() { delete[] m_data;}
//};

//================better Solution - strong exception guarantee==================
//class Resource
//{
//  private:
//    size_t m_sizeOfData;
//    unsigned char * m_data;
//
//    static const size_t m_additionalByts = 8;
//
//  public:
//    Resource(size_t sizeOfData)
//    : m_sizeOfData(sizeOfData + Resource::m_additionalByts), m_data(new unsigned char[m_sizeOfData]) {}
//
//    Resource& operator=(const Resource& other)
//    {
//      if(this != &other)
//      {
//        m_sizeOfData = other.m_sizeOfData;
//        unsigned char * tempData = new unsigned char[m_sizeOfData];
//        // first the memory is allocated. After this no exception can be thrown. This
//        // means that the data won't change if an exception is thrown - Strong exception guarantee
//        std::copy(other.m_data, other.m_data + m_sizeOfData, tempData);
//        delete[] m_data;
//        m_data = tempData;
//      }
//      return *this;
//    }
//
//    ~Resource() { delete[] m_data;}
//};

//==============The right Solution - strong exception guarantee=================
class Resource
{
  private:
    size_t m_sizeOfData;
    unsigned char * m_data;

    static const size_t m_additionalByts = 8;

  public:
    Resource(size_t sizeOfData)
    : m_sizeOfData(sizeOfData + Resource::m_additionalByts), m_data(new unsigned char[m_sizeOfData]) {}

    // No selfassigment check needed. No new needed. No delete needed. Strong exception guarantee.
    // No code duplication. The copy constructor does all the work.
    Resource& operator=(Resource other)
    {
      swap(this->m_sizeOfData, other.m_sizeOfData);
      swap(this->m_data, other.m_data);
      return *this;
    }

    ~Resource() { delete[] m_data;}
};

void example5()
{
  Resource(10);
}

//Source: What is the copy and swap idiom
//        https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
