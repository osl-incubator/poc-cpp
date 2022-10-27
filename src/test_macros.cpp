#include <cassert>
#include <memory>

#include "expr.h"

// based on: https://www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
#define IS_EXPR_PTR(ptr)                                        \
  ({                                                            \
    bool result = false;                                        \
    result = (dynamic_cast<const BaseExpr*>(ptr) != nullptr); \
    result;                                                     \
  })

void test_macros_template() {
  auto expr_1 = std::make_unique<IntExpr>(1);
  auto expr_2 = std::make_unique<FloatExpr>(1.5);
  auto expr_3 = IntExpr(2);
  auto expr_4 = FloatExpr(2.5);

  assert((IS_EXPR_PTR(expr_1.get()) == true));
  assert((IS_EXPR_PTR(expr_2.get()) == true));
  // assert((IS_EXPR_PTR(expr_1) == false));
  // assert((IS_EXPR_PTR(expr_2) == false));
}

void test_macros() {
  test_macros_template();
}
