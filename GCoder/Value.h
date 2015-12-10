#include <string>
#include <vector>

using namespace std;
namespace Coder {
  enum Type {
    TypeUnkown = 0,
    TypeBoolen,
    TypeInteger,
    TypeFloat,
    TypeString,
    TypeArray,
    TypeUserDefine
  };

  class Value {
  public:
    virtual bool GetAsBoolean() { return false; }
    virtual bool GetAsInteger() { return false; }
    virtual bool GetAsFloat() { return false; }
    virtual bool GetAsString() { return false; }
    virtual bool GetAsArray() { return false; }
    virtual bool GetAsUserDefine() { return false; }
    Type GetType();
    std::string GetInputValue();

    explicit Value(const std::string& input_value, Type type) : input_value_(input_value), type_(type){};
    virtual ~Value(){};
  protected:
    std::string input_value_;
  private:
    Type type_;
  };

  class IntergerValue : public Value {
  public:
    explicit IntergerValue(const std::string& input_value);
    virtual ~IntergerValue(){}

    virtual bool GetAsInteger() override;

  private:
    int parser_value_;
  };

  class FloatValue : public Value {
  public:
    explicit FloatValue(const std::string& input_value);
    virtual ~FloatValue(){}

    virtual bool GetAsFloat() override;

  private:
    float parser_value_;
  };

  class BooleanValue : public Value {
  public:
    explicit BooleanValue(const std::string& boolen_value);
    virtual ~BooleanValue(){}

    virtual bool GetAsBoolean() override;

  private:
    bool parser_value_;
  };

  class StringValue : public Value {
  public:
    explicit StringValue(const std::string& input_value);
    virtual ~StringValue(){}

    virtual bool GetAsString() override;

  private:
    std::string parser_value_;
  };

  class ArraryValue : public Value {
  public:
    explicit ArraryValue(const std::string& input_value);
    virtual ~ArraryValue(){}

    virtual bool GetAsArray() override;

  private:
    typedef std::vector<std::string> StringVector;
    Type GetValueType();
    std::string GetStringValue();
    bool ParseValue(StringVector& string_vector);

  private:
    std::vector<Value*> parser_value_;
  };

  class UserDefineValue : public Value {
  public:
    explicit UserDefineValue(const std::string& input_value);
    virtual ~UserDefineValue(){}

    virtual bool GetAsUserDefine() override;

  private:
    bool ParseValue();

  private:
    std::string user_name_;
    int user_id;
  };
}