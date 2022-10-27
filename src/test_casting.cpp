#include <cassert>
#include <iostream>
#include <memory>

#include "expr.h"
#include "utils.h"

#define DOWNCASTING_PTR_EXPR(expr, func)                   \
  ({                                                       \
    switch (expr->kind) {                                  \
      case ExprKind::IntKind: {                            \
        func((IntExpr*) (expr));                           \
        break;                                             \
      }                                                    \
      case ExprKind::FloatKind: {                          \
        func((FloatExpr*) (expr));                         \
        break;                                             \
      }                                                    \
      default: {                                           \
        std::cout << "[WW] DOWNCASTING_EXPR MATCH FAILED"; \
        break;                                             \
      }                                                    \
    };                                                     \
  })

void test_downcasting_manually() {
  // upcasting
  BaseExpr* base_expr = new FloatExpr(1.1);

  // downcasting
  FloatExpr* expr = static_cast<FloatExpr*>(base_expr);

  assert((expr->kind == ExprKind::FloatKind));
}

void test_downcasting_macro() {
  // upcasting
  BaseExpr* base_expr = new FloatExpr(1.1);

  // downcasting
  DOWNCASTING_PTR_EXPR(base_expr, print_ptr);
}

void test_casting() {
  print_test_header("test_casting");

  test_downcasting_manually();
  test_downcasting_macro();

  print_test_footer("test_casting");
}
