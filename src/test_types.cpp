#include <cassert>
#include <iostream>
#include <memory>

#include "expr.h"
#include "utils.h"

class A {
public:
  int value;
  A(int value) {
    this->value = value;
  }
};

void test_use_typedef() {
    typedef A TypeA;
    TypeA type_a = A(1);
    std::cout << type_a.value << std::endl;
}

void test_types() {
  print_test_header("test_types");

  test_use_typedef();

  print_test_footer("test_types");
}
