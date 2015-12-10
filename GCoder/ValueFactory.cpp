#include "ValueFactory.h"
#include "Value.h"

namespace Coder {
  ValueFactory* ValueFactory::instance_;

  ValueFactory* ValueFactory::GetInstance() {
    if (NULL == instance_)
      instance_ = new ValueFactory();

    return instance_;
  }

  Value* ValueFactory::GetValueForType(Type type, const std::string& input_value) {
    Value* value = NULL;
    switch (type)
    {
    case Coder::TypeUnkown:
      break;
    case Coder::TypeBoolen:
      value = new BooleanValue(input_value);
      break;
    case Coder::TypeInteger:
      value = new IntergerValue(input_value);
      break;
    case Coder::TypeFloat:
      value = new FloatValue(input_value);
      break;
    case Coder::TypeString:
      value = new StringValue(input_value);
      break;
    case Coder::TypeArray:
      value = new ArraryValue(input_value);
      break;
    case Coder::TypeUserDefine:
      value = new UserDefineValue(input_value);
      break;
    default:
      break;
    }

    return value;
  }
}
