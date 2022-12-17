#include <string>

class Result {
 public:
  std::string result_name;

  void set_value(std::string result_name);

  Result(std::string result_name) {
    this->result_name = "ResultValue: " + result_name;
  }

  std::string get_name() {
    return this->result_name;
  }
};

class ResultValue : public Result {
 public:
  ResultValue(std::string result_name)
      : Result("ResultValue: " + result_name) {}

  void set_value(std::string result_name) {
    this->result_name = "ResultValue: " + result_name;
  }
};

class ResultFunction : public Result {
 public:
  ResultFunction(std::string result_name)
      : Result("ResultFunction: " + result_name) {}

  void set_value(std::string result_name) {
    this->result_name = "ResultFunction: " + result_name;
  }
};
