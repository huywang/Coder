#include <string>
using namespace std;

template<typename T>
class BaseParser
{
public:
  BaseParser();
  ~BaseParser();

  virtual T Parse(const string& sourceString) = 0;
};
