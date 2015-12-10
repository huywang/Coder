#ifndef GOOD_CODER_UTIL_H
#define GOOD_CODER_UTIL_H

#include "Value.h"
#include <string>
#include <vector>

namespace Coder {
  namespace Util {
    static const char kTrue[] = "true";
    static const char kFalse[] = "false";
    static const char kColon[] = ":";
    static const char kComma = ',';
    static const char kTab = '\t';
    static const char kInteger[] = "int";
    static const char kFloat[] = "float";
    static const char kBoolean[] = "bool";
    static const char kString[] = "string";
    static const char kArray[] = "array";
    static const char kUserDefine[] = "user";

    bool SplitByToken(const std::string& input_string, char token, std::vector<std::string>& values);

    Type ParseType(const std::string& input);

    bool ParseValueByType(Type type, const std::string& input_value, Value** value);
  }
}

#endif