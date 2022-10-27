#include <iostream>
#include <memory>

#include "expr.h"
#include "utils.h"


// test functions

void test_unique_ptr_dispatch() {
  auto expr_int1 = std::make_unique<IntExpr>(1);
  auto expr_float1 = std::make_unique<FloatExpr>(1.5);

  auto expr_int2 = std::make_unique<IntExpr>(2);
  auto expr_float2 = std::make_unique<FloatExpr>(2.5);

  auto expr_int_move = std::make_unique<IntExpr>(3);
  auto expr_float_move = std::make_unique<FloatExpr>(3.5);
  auto expr_generic_move = std::make_unique<FloatExpr>(3.6);

  auto expr_all = std::make_unique<AllExpr>(
      std::move(expr_int_move),
      std::move(expr_float_move),
      std::move(expr_generic_move));

  print_ptr(expr_int1.get());
  print_ptr(expr_float1.get());

  print_ref(expr_int2);
  print_ref(expr_float2);

  print_ptr(expr_all->expr_int.get());
  print_ptr(expr_all->expr_float.get());

  print_ref(expr_all->expr_int);
  print_ref(expr_all->expr_float);

  print_ptr(expr_all.get());
  print_ref(expr_all);
}

void test_unique_ptr() {
  print_test_header("test_unique_ptr");
  test_unique_ptr_dispatch();
  print_test_footer("test_unique_ptr");
}
