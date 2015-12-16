#pragma once
#include <string>
#include <vector>
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
  template<typename T>
  class Value {
  public:
    virtual bool Parse(const std::string& input_string) = 0;
    virtual T GetValue() = 0;
  };

  union BuildInUnion {
    int int_value_;
    float float_value_;
    bool value_bool_;
    char* value_char_;
  };

  class BuildInValue : public Value<BuildInUnion> {
  public:
    BuildInValue(Type& type) : type_(type) {}
    virtual BuildInUnion GetValue() { return value_; }
    virtual bool Parse(const std::string& input_string) override;
  private:
    bool parseInt(const std::string& input);
    bool parseFloat(const std::string& input);
    bool parseBool(const std::string& input);
    bool parseChar(const std::string& input);
    BuildInUnion value_;
    Type type_;
  };

  class ArrayValue : public Value < std::vector<BuildInUnion> > {
  public:
    virtual std::vector<BuildInUnion> GetValue() { return value_; }
    virtual bool Parse(const std::string& input_string) override;
  private:
    typedef std::vector<std::string> StringVector;
    bool ParseValue(StringVector& string_vector);
    Type GetValueType();
    std::vector<BuildInUnion> value_;
    Type type_;
  };
  /*class IntergerValue : public Value<int> {
  public:
    explicit IntergerValue();
    virtual ~IntergerValue(){}

    virtual int Parse(const std::string& input_string) override;

  private:
    int parser_value_;
  };

  class FloatValue : public BuildInValue<float> {
  public:
    explicit FloatValue();
    virtual ~FloatValue(){}

    virtual float Parse(const std::string& input_string) override;

  private:
    float parser_value_;
  };

  class BooleanValue : public BuildInValue<bool> {
  public:
    explicit BooleanValue();
    virtual ~BooleanValue(){}

    virtual bool Parse(const std::string& input_string) override;

  private:
    bool parser_value_;
  };

  class StringValue : public BuildInValue<std::string> {
  public:
    explicit StringValue();
    virtual ~StringValue(){}

    virtual std::string Parse(const std::string& input_string) override;

  private:
    std::string parser_value_;
  };

  class ArrayValue {
  public:
    explicit ArrayValue();
    virtual ~ArrayValue(){}

    bool Parse(const std::string& input_string);

  private:
    typedef std::vector<std::string> StringVector;
    Type GetValueType();
    
    std::string GetStringValue();
    bool ParseValue(StringVector& string_vector);
  };*/

  /*class UserDefineValue : public Value<UserDefineValue> {
  public:
    explicit UserDefineValue();
    virtual ~UserDefineValue(){}

    virtual bool Parse(const std::string& input_string) override;

  private:
    bool ParseValue();

  private:
    std::string user_name_;
    int user_id;
  };

  class User {
  public:

  };*/
}

