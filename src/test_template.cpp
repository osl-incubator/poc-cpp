#include <memory>
#include "expr.h"
#include "utils.h"

class Result {};

class ResultValue : public Result {};
class ResultFunction : public Result {};


template <typename T>
T codegen(std::unique_ptr<BaseExpr>& expr, T result) {
  return codegen(expr.get(), result);
}

template <typename T>
T codegen(BaseExpr* expr, T result) {
  switch (expr->kind) {
    case ExprKind::FloatKind:
      print_ptr((FloatExpr*) expr);
      break;
    case ExprKind::IntKind:
      print_ptr((IntExpr*) expr);
      break;
  }
  return result;
}

void test_template_function() {
  auto expr_float = new FloatExpr(1.1);
  auto expr_int = new IntExpr(1);

  auto result_function = new ResultFunction();
  auto result_value = new ResultValue();

  codegen(expr_float, result_function);
  codegen(expr_float, result_value);
  codegen(expr_int, result_function);
  codegen(expr_int, result_value);
}

void test_template() {
  print_test_header("test_template");

  test_template_function();

  print_test_footer("test_template");
}
