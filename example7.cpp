#include <iostream>
#include <vector>
using namespace std;

class SomeBigClass
{
  private:
    int m_bigData[10000];

  public:
    SomeBigClass(int firstNumber)
    { m_bigData[0] = firstNumber; }
};

vector<SomeBigClass>& vFillBigVector1(vector<SomeBigClass>& vec)
{
  for(int i = 0; i < 10; ++i)
    vec.emplace_back(i);

  return vec;
}

vector<SomeBigClass> vFillBigVector2()
{
  vector<SomeBigClass> vec;
  for(int i = 0; i < 10; ++i)
    vec.emplace_back(i);

  return vec;
}

void example7()
{
  {
    vector<SomeBigClass> vec1;
    vec1.reserve(10);
    vec1 = vFillBigVector1(vec1);
  }

  {
    vector<SomeBigClass> vec2 = vFillBigVector2();
  }

}
