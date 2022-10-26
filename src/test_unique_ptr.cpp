#include <iostream>
#include <memory>

// classes

class ExprBase {};

class ExprInt {
public:
  int value;

  ExprInt(int value) { this->value = value; }
};

class ExprFloat {
public:
  float value;

  ExprFloat(float value) { this->value = value; }
};

class ExprAll {
public:
  std::unique_ptr<ExprInt> expr_int;
  std::unique_ptr<ExprFloat> expr_float;

  ExprAll(std::unique_ptr<ExprInt> expr_int,
          std::unique_ptr<ExprFloat> expr_float) {
    this->expr_int = std::move(expr_int);
    this->expr_float = std::move(expr_float);
  }
};

// forward declaration

void print_ptr(ExprInt *expr);
void print_ptr(ExprFloat *expr);
void print_ref(std::unique_ptr<ExprInt> &expr);
void print_ref(std::unique_ptr<ExprFloat> &expr);

void print_ptr(ExprAll *expr) {
  std::cout << "print_ptr ExprAll" << std::endl;
  std::cout << "  ";
  print_ptr(expr->expr_int.get());
  std::cout << "  ";
  print_ptr(expr->expr_float.get());
}

void print_ptr(ExprInt *expr) {
  std::cout << "print_ptr > Value: " << expr->value << std::endl;
}

void print_ptr(ExprFloat *expr) {
  std::cout << "print_ptr > Value: " << expr->value << std::endl;
}

void print_ref(std::unique_ptr<ExprAll> &expr) {
  std::cout << "print_ref ExprAll" << std::endl;
  std::cout << "  ";
  print_ref(expr->expr_int);
  std::cout << "  ";
  print_ref(expr->expr_float);
}

void print_ref(std::unique_ptr<ExprInt> &expr) {
  std::cout << "print_ref > Value: " << expr->value << std::endl;
}

void print_ref(std::unique_ptr<ExprFloat> &expr) {
  std::cout << "print_ref > Value: " << expr->value << std::endl;
}

void test_unique_ptr_dispatch() {
  auto expr_int1 = std::make_unique<ExprInt>(1);
  auto expr_float1 = std::make_unique<ExprFloat>(1.5);

  auto expr_int2 = std::make_unique<ExprInt>(2);
  auto expr_float2 = std::make_unique<ExprFloat>(2.5);

  auto expr_int_move = std::make_unique<ExprInt>(3);
  auto expr_float_move = std::make_unique<ExprFloat>(3.5);

  auto expr_all = std::make_unique<ExprAll>(std::move(expr_int_move),
                                            std::move(expr_float_move));

  print_ptr(expr_int1.get());
  print_ptr(expr_float1.get());

  print_ref(expr_int2);
  print_ref(expr_float2);

  print_ptr(expr_all->expr_int.get());
  print_ptr(expr_all->expr_float.get());

  print_ref(expr_all->expr_int);
  print_ref(expr_all->expr_float);

  // print_ptr(expr_all.get());
  // print_ref(expr_all);
}

void test_unique_ptr() { test_unique_ptr_dispatch(); }
