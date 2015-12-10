#include "Util.h"
#include "Value.h"

namespace Coder{
  namespace Util{
    bool SplitByToken(const std::string& input_string, char token, std::vector<std::string>& values) {
      unsigned int start = 0, end = 0;
      if ((start = input_string.find(token, start)) == std::string::npos)
        return false;
      start += 1;

      while ((end = input_string.find(token, start)) != std::string::npos) {
        values.push_back(input_string.substr(start, end - start));
        start = end + 1;
      }

      values.push_back(input_string.substr(start, input_string.size() - start));

      return true;
    }

    Type ParseType(const std::string& input) {
      if (input == kInteger)
        return TypeInteger;
      else if (input == kFloat)
        return TypeFloat;
      else if (input == kBoolean)
        return TypeBoolen;
      else if (input == kString)
        return TypeString;
      else if (input == kArray)
        return TypeArray;
      else if (input == kUserDefine)
        return TypeUserDefine;
      return TypeUnkown;
    }

    bool ParseValueByType(Type type, const std::string& input_value, Value** value) {
      bool ret = false;
      switch (type)
      {
      case Coder::TypeUnkown:
        break;
      case Coder::TypeBoolen:
        *value = new BooleanValue(input_value);
        ret = (*value)->GetAsBoolean();
        break;
      case Coder::TypeInteger:
        *value = new IntergerValue(input_value);
        ret = (*value)->GetAsInteger();
        break;
      case Coder::TypeFloat:
        *value = new FloatValue(input_value);
        ret = (*value)->GetAsFloat();
        break;
      case Coder::TypeString:
        *value = new StringValue(input_value);
        ret = (*value)->GetAsString();
        break;
      case Coder::TypeArray:
        *value = new ArraryValue(input_value);
        ret = (*value)->GetAsArray();
        break;
      case Coder::TypeUserDefine:
        *value = new UserDefineValue(input_value);
        ret = (*value)->GetAsUserDefine();
        break;
      default:
        break;
      }

      return ret;
    }
  }
}