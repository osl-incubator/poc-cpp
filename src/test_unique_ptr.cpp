#include <cassert>
#include <iostream>
#include <memory>

#include "expr.h"
#include "utils.h"

// https://www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

template <typename T>
bool is_expr_ptr(T* ptr) {
    return std::is_base_of<BaseExpr, T>::value;
}

template <typename T>
bool is_expr_ptr(std::unique_ptr<T> const& ptr) {
    return false;
}


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

  print_ref(*expr_int2);
  print_ref(*expr_float2);

  print_ptr(expr_all->expr_int.get());
  print_ptr(expr_all->expr_float.get());

  print_ref(*(expr_all->expr_int));
  print_ref(*(expr_all->expr_float));

  print_ptr(expr_all.get());
  print_ref(*expr_all);
}


void test_if_is_unique_ptr(){
  auto expr_1 = std::make_unique<IntExpr>(1);
  auto expr_2 = std::make_unique<FloatExpr>(1.5);
  auto expr_3 = new IntExpr(2);
  auto expr_4 = new FloatExpr(2.5);
  auto expr_5 = expr_1.get();
  auto expr_6 = expr_2.get();
  delete expr_3;
  delete expr_4;

  assert((is_expr_ptr(expr_1) == false));
  assert((is_expr_ptr(expr_2) == false));
  assert((is_expr_ptr(expr_5)));
  assert((is_expr_ptr(expr_6)));
}

void test_unique_ptr() {
  print_test_header("test_unique_ptr");
  test_unique_ptr_dispatch();
  test_if_is_unique_ptr();
  print_test_footer("test_unique_ptr");
}
