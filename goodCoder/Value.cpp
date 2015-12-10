#include "stdafx.h"
#include "Value.h"
#include "Util.h"

namespace Coder {

  IntergerValue::IntergerValue(const std::string& input_value)
    : Value(input_value, TypeInteger), parser_value_(0) {
  }

  bool IntergerValue::GetAsInteger() {
    parser_value_ = std::stoi(input_value_);
    return true;
  }

  FloatValue::FloatValue(const std::string& input_value)
    : Value(input_value, TypeFloat), parser_value_(0) {

  }

  bool FloatValue::GetAsFloat() {
    parser_value_ = std::stof(input_value_);
    return true;
  }

  BooleanValue::BooleanValue(const std::string& input_value)
    : Value(input_value, TypeBoolen), parser_value_(false) {
  }

  bool BooleanValue::GetAsBoolean() {
    bool ret = true;
    if (input_value_ == Util::kTrue)
      parser_value_ = true;
    else if (input_value_ == Util::kFalse)
      parser_value_ = false;
    else
      ret = false;

    return ret;
  }

  StringValue::StringValue(const std::string& input_value)
    : Value(input_value, TypeString) {

  }

  bool StringValue::GetAsString() {
    parser_value_ = input_value_;
    return true;
  }

  ArraryValue::ArraryValue(const std::string& input_value)
    : Value(input_value, TypeArray) {

  }

  bool ArraryValue::GetAsArray() {
    Type type = GetValueType();

    StringVector vector;
    if (!ParseValue(vector))
      return false;

    Value* value = nullptr;
    StringVector::const_iterator it = vector.begin();
    for (; it != vector.end(); ++it) {
      Util::ParseValueByType(type, *it, &value);
      parser_value_.push_back(value);
    }
    return true;
  }

  Type ArraryValue::GetValueType() {
    size_t pos = input_value_.find(Util::kColon);
    if (pos != std::string::npos) {
      return Util::ParseType(input_value_.substr(0, pos));
    }

    return TypeUnkown;
  }

  std::string ArraryValue::GetStringValue() {
    size_t pos = input_value_.find(Util::kColon);
    if (pos != std::string::npos) {
      return input_value_.substr(pos + 1, input_value_.size() - pos);
    }
    return std::string();
  }

  bool ArraryValue::ParseValue(StringVector& string_vector) {
    return Util::SplitByToken(GetStringValue(), Util::kComma, string_vector);
  }

  UserDefineValue::UserDefineValue(const std::string& input_value)
    : Value(input_value, TypeUserDefine), user_id(-1) {
  }

  bool UserDefineValue::GetAsUserDefine() {
    return ParseValue();
  }

  bool UserDefineValue::ParseValue() {
    return true;
  }
}