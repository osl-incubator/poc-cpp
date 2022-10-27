#include <iostream>
#include <memory>

// classes

enum class ExprKind { FloatKind = 0, IntKind = 1, AllKind = 2 };

class BaseExpr {
 public:
  ExprKind kind;
};

class IntExpr : public BaseExpr {
 public:
  int value;

  IntExpr(int value) {
    this->kind = ExprKind::IntKind;
    this->value = value;
  }
};

class FloatExpr : public BaseExpr {
 public:
  float value;

  FloatExpr(float value) {
    this->kind = ExprKind::FloatKind;
    this->value = value;
  }
};

class ExprAll : public BaseExpr {
 public:
  std::unique_ptr<IntExpr> expr_int;
  std::unique_ptr<FloatExpr> expr_float;
  std::unique_ptr<BaseExpr> expr_generic;

  ExprAll(
      std::unique_ptr<IntExpr> expr_int,
      std::unique_ptr<FloatExpr> expr_float,
      std::unique_ptr<BaseExpr> expr_generic) {
    this->kind = ExprKind::AllKind;
    this->expr_int = std::move(expr_int);
    this->expr_float = std::move(expr_float);
    this->expr_generic = std::move(expr_generic);
  }
};

// forward declaration

void print_ptr(IntExpr* expr);
void print_ptr(FloatExpr* expr);
void print_ref(std::unique_ptr<IntExpr>& expr);
void print_ref(std::unique_ptr<FloatExpr>& expr);

void print_ptr(ExprAll* expr) {
  std::cout << "print_ptr ExprAll" << std::endl;
  std::cout << "  ";
  print_ptr(expr->expr_int.get());
  std::cout << "  ";
  print_ptr(expr->expr_float.get());
  std::cout << "  ";
  switch (expr->expr_generic.get()->kind) {
    case ExprKind::IntKind: {
      print_ptr(static_cast<IntExpr*>(expr->expr_generic.get()));
    }
    case ExprKind::FloatKind: {
      print_ptr(static_cast<FloatExpr*>(expr->expr_generic.get()));
    }
  }
}

void print_ptr(IntExpr* expr) {
  std::cout << "print_ptr > Value: " << expr->value << std::endl;
}

void print_ptr(FloatExpr* expr) {
  std::cout << "print_ptr > Value: " << expr->value << std::endl;
}

void print_ref(std::unique_ptr<ExprAll>& expr) {
  std::cout << "print_ref ExprAll" << std::endl;
  std::cout << "  ";
  print_ref(expr->expr_int);
  std::cout << "  ";
  print_ref(expr->expr_float);
  switch (expr->expr_generic.get()->kind) {
    case ExprKind::IntKind: {
      /*
      print_ref(std::make_unique<IntExpr>(
          static_cast<IntExpr>(expr->expr_generic.release())));
      */
    }
    case ExprKind::FloatKind: {
      /*
      print_ref(std::make_unique<FloatExpr>(
          static_cast<FloatExpr>(expr->expr_generic.release())));
      */
    }
  }
}

void print_ref(std::unique_ptr<IntExpr>& expr) {
  std::cout << "print_ref > Value: " << expr->value << std::endl;
}

void print_ref(std::unique_ptr<FloatExpr>& expr) {
  std::cout << "print_ref > Value: " << expr->value << std::endl;
}

void test_unique_ptr_dispatch() {
  auto expr_int1 = std::make_unique<IntExpr>(1);
  auto expr_float1 = std::make_unique<FloatExpr>(1.5);

  auto expr_int2 = std::make_unique<IntExpr>(2);
  auto expr_float2 = std::make_unique<FloatExpr>(2.5);

  auto expr_int_move = std::make_unique<IntExpr>(3);
  auto expr_float_move = std::make_unique<FloatExpr>(3.5);
  auto expr_generic_move = std::make_unique<FloatExpr>(3.6);

  auto expr_all = std::make_unique<ExprAll>(
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
  test_unique_ptr_dispatch();
}
