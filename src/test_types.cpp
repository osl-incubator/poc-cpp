#include <cassert>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <typeinfo>

#include "expr.h"
#include "utils.h"

class A {
 public:
  int value;

  A(int value) {
    this->value = value;
  }
};

// https://stackoverflow.com/a/20170989
template <class T>
constexpr std::string_view type_name() {
  using namespace std;
#ifdef __clang__
  string_view p = __PRETTY_FUNCTION__;
  return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
  string_view p = __PRETTY_FUNCTION__;
#if __cplusplus < 201402
  return string_view(p.data() + 36, p.size() - 36 - 1);
#else
  return string_view(p.data() + 49, p.find(';', 49) - 49);
#endif
#elif defined(_MSC_VER)
  string_view p = __FUNCSIG__;
  return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}

// tests

void test_use_typedef() {
  typedef A TypeA;
  TypeA type_a = A(1);
  std::cout << type_a.value << std::endl;
}

void test_get_type_name() {
  const int ci = 0;
  std::cout << type_name<decltype(ci)>() << '\n';
}

void test_types() {
  print_test_header("test_types");

  test_use_typedef();
  test_get_type_name();

  print_test_footer("test_types");
}
