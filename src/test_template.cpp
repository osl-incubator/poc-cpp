#include <memory>
#include "expr.h"
#include "result.h"
#include "utils.h"


template <typename T>
T codegen(FloatExpr* expr, T result) {
  result->set_value("float");
  return result;
}

template <typename T>
T codegen(IntExpr* expr, T result) {
  result->set_value("integer");
  return result;
}

template <typename T>
T codegen(std::unique_ptr<BaseExpr>& expr, T result) {
  return codegen(expr.get(), result);
}

template <typename T>
T codegen(BaseExpr* expr, T result) {
  switch (expr->kind) {
    case ExprKind::FloatKind:
      codegen((FloatExpr*) expr, result);
      break;
    case ExprKind::IntKind:
      codegen((IntExpr*) expr, result);
      break;
  }
  return result;
}

void test_template_function() {
  auto expr_float = new FloatExpr(1.1);
  auto expr_int = new IntExpr(1);

  auto result_function = new ResultFunction("res1");
  auto result_value = new ResultValue("res2");

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
