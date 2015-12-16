#include "Value.h"

namespace Coder {
  bool BuildInValue::Parse(const std::string& input_string) {
    bool ret = true;
    switch (type_) {
    case Coder::TypeBoolen:
      value_.value_bool_ = true;
      break;
    case Coder::TypeInteger:
      value_.int_value_ = 0;
      break;
    case Coder::TypeFloat:
      value_.float_value_ = 0;
      break;
    case Coder::TypeString:
      value_.value_char_ = NULL;
      break;
    default:
      ret = false;
      break;
    }

    return ret;
  }

  bool ArrayValue::Parse(const std::string& input_string) {
    Type type = GetValueType();
    if (TypeUnkown == type)
      return false;

    StringVector vector;
    if (!ParseValue(vector))
      return false;

    Value* value = nullptr;
    StringVector::const_iterator it = vector.begin();
    for (; it != vector.end(); ++it) {
      BuildInValue value(type);
      if (!value.Parse(*it)) {
        return false;
      }
      value_.push_back(value.GetValue());
    }
    return true;
  }
}
