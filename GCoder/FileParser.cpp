#include "FileParser.h"
#include "Util.h"

#include <fstream>

namespace Coder {
  FileParser::FileParser(const std::wstring& path)
    : file_path_(path){

  }

  bool FileParser::Parse() {
    std::ifstream in;
    in.open(file_path_, std::ios_base::in | std::ios_base::out);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
      lines.push_back(line);
    }

    std::vector<std::string> types_string;
    if (!lines.empty())
      Util::SplitByToken(lines[0], Util::kTab, types_string);

    std::vector<Type> types;
    std::vector<std::string>::const_iterator it_type = types_string.begin();
    for (; it_type != types_string.end(); ++it_type) {
      types.push_back(Util::ParseType(*it_type));
    }

    std::vector<std::string> rows;
    rows.assign(lines.begin() + 1, lines.end());

    std::vector<std::string>::iterator it_row = rows.begin();
    for (; it_row != rows.end(); ++it_row) {
      ParseRow(types, *it_row);
    }

    return true;
  }

  bool FileParser::ParseRow(const std::vector<Type>& types, const std::string& row) {
    StringVector values;
    Util::SplitByToken(row, Util::kTab, values);

    if (values.size() != types.size())
      return false;

    StringVector::const_iterator it_value = values.begin();
    TypeVector::const_iterator it_type = types.begin();
    Value* value = nullptr;
    for (; it_value != values.end() && it_type != types.end(); ++it_value, ++it_type) {
      Util::ParseValueByType(*it_type, *it_value, &value);
    }

    return true;
  }
}