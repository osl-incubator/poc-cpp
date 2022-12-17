#include <memory>
#include <string>

#include "expr-visitor.h"
#include "result.h"
#include "utils.h"

class PrintVisitor {
public:
  template <typename T>
  T* visit(BaseExprV* expr, T* output);

  template <typename T>
  T* visit(IntExprV* expr, T* output);

  template <typename T>
  T* visit(FloatExprV* expr, T* output);
};

template <typename T>
T* PrintVisitor::visit(BaseExprV* expr, T* output) {
  return output;
}

template <typename T>
T* PrintVisitor::visit(IntExprV* expr, T* output) {
  return output;
}

template <typename T>
T* PrintVisitor::visit(FloatExprV* expr, T* output) {
  return output;
}

void test_visitor_expr() {
  auto visitor = new PrintVisitor();
  auto f_expr = new FloatExprV(1.2);
  auto result_function = new ResultFunction("res1");
  auto result_value = new ResultValue("res2");

  f_expr->visit(visitor, result_function);
  f_expr->visit(visitor, result_value);
}

void test_visitor() {
  print_test_header("test_types");

  test_visitor_expr();

  print_test_footer("test_types");
}
