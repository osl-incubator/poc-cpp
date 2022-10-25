#include <memory>
#include <iostream>

class ExprBase {};

class ExprInt {
public:
  int value = 0;

  ExprInt(int value) {
    this->value = value;
  }
};

class ExprFloat {
public:
  float value = 0;

  ExprFloat(float value) {
    this->value = value;
  }
};

void print_ptr(ExprInt * expr) {
  std::cout << "print_ptr > Value: " << expr->value << std::endl;
}

void print_ptr(ExprFloat * expr) {
  std::cout << "print_ptr > Value: " << expr->value << std::endl;
}

void print_ref(std::unique_ptr<ExprInt> & expr) {
  std::cout << "print_ref > Value: " << expr->value << std::endl;
}

void print_ref(std::unique_ptr<ExprFloat> & expr) {
  std::cout << "print_ref > Value: " << expr->value << std::endl;
}


void test_unique_ptr_dispatch() {
  auto expr_int1 = std::make_unique<ExprInt>(1);
  auto expr_float1 = std::make_unique<ExprFloat>(1.5);

  auto expr_int2 = std::make_unique<ExprInt>(2);
  auto expr_float2 = std::make_unique<ExprFloat>(2.5);

  print_ptr(expr_int1.get());
  print_ptr(expr_float1.get());

  print_ref(expr_int2);
  print_ref(expr_float2);
}


void test_unique_ptr() {
  test_unique_ptr_dispatch();
}
