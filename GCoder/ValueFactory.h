#pragma once
#include <xmemory>
#include <string>

namespace Coder {
  enum Type;
  class Value;

  class ValueFactory {
  public:
    static Value* GetValueForType(Type type, const std::string& input_value);
    static ValueFactory* GetInstance();
  private:
    static ValueFactory* instance_;
  };
}

