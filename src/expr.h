#include <iostream>
#include <memory>

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

class AllExpr : public BaseExpr {
 public:
  std::unique_ptr<IntExpr> expr_int;
  std::unique_ptr<FloatExpr> expr_float;
  std::unique_ptr<BaseExpr> expr_generic;

  AllExpr(
      std::unique_ptr<IntExpr> expr_int,
      std::unique_ptr<FloatExpr> expr_float,
      std::unique_ptr<BaseExpr> expr_generic) {
    this->kind = ExprKind::AllKind;
    this->expr_int = std::move(expr_int);
    this->expr_float = std::move(expr_float);
    this->expr_generic = std::move(expr_generic);
  }
};

void print_ptr(IntExpr* expr);
void print_ptr(FloatExpr* expr);
void print_ptr(AllExpr* expr);
void print_ref(std::unique_ptr<IntExpr>& expr);
void print_ref(std::unique_ptr<FloatExpr>& expr);
void print_ref(std::unique_ptr<AllExpr>& expr);
