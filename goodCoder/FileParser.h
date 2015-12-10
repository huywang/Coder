//#ifndef GOOD_CODER_FILE_PARSER_H
//#define GOOD_CODER_FILE_PARSER_H

#include "Value.h"

#include <string>
#include <vector>

namespace Coder{
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
//#endif
