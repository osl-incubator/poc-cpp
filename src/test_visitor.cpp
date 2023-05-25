#include <memory>
#include <string>

#include "expr-visitor.h"
#include "result.h"
#include "utils.h"

class PrintVisitor {
public:
  std::unique_ptr<ResultFunction> result_function;
  std::unique_ptr<ResultValue> result_value;

  auto visit(BaseExprV* expr) -> void;
  auto visit(IntExprV* expr) -> void;
  auto visit(FloatExprV* expr) -> void;
};

auto PrintVisitor::visit(BaseExprV* expr) -> void {
  this->result_function = std::make_unique<ResultFunction>("Base");
}

auto PrintVisitor::visit(IntExprV* expr) -> void {
  this->result_value = std::make_unique<ResultValue>("Int");
}

auto PrintVisitor::visit(FloatExprV* expr) -> void {
  this->result_value = std::make_unique<ResultValue>("Float");
}

void test_visitor_expr() {
  auto visitor = new PrintVisitor();
  auto f_expr = new FloatExprV(1.2);
  auto result_function = new ResultFunction("res1");
  auto resval1 = new ResultValue("resval1");
  auto resval12 = new ResultValue("resval2");

  f_expr->accept(visitor);

  delete visitor;
  delete f_expr;
  delete result_function;
  delete resval1;
  delete resval12;
}

void test_visitor() {
  print_test_header("test_types");

  test_visitor_expr();

  print_test_footer("test_types");
}
