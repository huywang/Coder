#include <string>
#include <vector>

namespace Coder{
  enum Type;

  class FileParser {
  public:
    FileParser(const std::wstring& path);
    virtual ~FileParser(){}

    bool Parse();
  private:
    typedef std::vector<std::string> StringVector;
    typedef std::vector<Type> TypeVector;

    bool GetTypes(std::vector<Type>& types);
    bool ParseRow(const std::vector<Type>& types, const std::string& row);
    std::wstring file_path_;
  };
}