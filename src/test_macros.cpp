#include <cassert>
#include <memory>

#include "expr.h"
#include "utils.h"

// based on: https://www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
#define IS_EXPR_PTR(ptr) (dynamic_cast<const BaseExpr*>(ptr) != nullptr)

#define MACRO_WITH_TERNARY_IF(expr)                             \
  ({                                                            \
    expr->kind == ExprKind::IntKind     ? (IntExpr*) (expr) :   \
      expr->kind == ExprKind::FloatKind ? (FloatExpr*) (expr) : \
                                          nullptr               \
  })

#define MACRO_WITH_TERNARY_IF_AND_FUNCTION(expr)                             \
  ({                                                            \
    expr->kind == ExprKind::IntKind     ? (IntExpr*) (expr) :   \
      expr->kind == ExprKind::FloatKind ? (FloatExpr*) (expr) : \
                                          nullptr               \
  })

void test_macro_oneline() {
  auto expr_1 = std::make_unique<IntExpr>(1);
  auto expr_2 = std::make_unique<FloatExpr>(1.5);

  assert((IS_EXPR_PTR(expr_1.get()) == true));
  assert((IS_EXPR_PTR(expr_2.get()) == true));
  // note: compile error:
  // assert((IS_EXPR_PTR(expr_1) == false));
  // assert((IS_EXPR_PTR(expr_2) == false));
}

void test_macro_with_switch() {
  auto expr_1 = std::make_unique<IntExpr>(1);
  auto expr_2 = std::make_unique<FloatExpr>(1.5);

  print_ptr(MACRO_WITH_TERNARY_IF(expr_1.get()));
  MACRO_WITH_TERNARY_IF_AND_FUNCTION(expr.get(), print_ptr);
}

void test_macros() {
  test_macro_oneline();
  void test_macro_with_switch();
}
