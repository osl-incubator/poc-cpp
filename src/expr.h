#include <iostream>
#include <memory>

enum class ExprKind { FloatKind = 0, IntKind = 1, AllKind = 2 };

class BaseExpr {
 public:
  ExprKind kind;

  virtual ~BaseExpr() = default;
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
    std::unique_ptr<BaseExpr> expr_generic
  ) :
    expr_int(std::move(expr_int)),
    expr_float(std::move(expr_float)),
    expr_generic(std::move(expr_generic))
  {
    this->kind = ExprKind::AllKind;
  }

  AllExpr(const AllExpr&) = delete;
  AllExpr& operator=(const AllExpr&) = delete;

};

void print_ptr(IntExpr* expr);
void print_ptr(FloatExpr* expr);
void print_ptr(AllExpr* expr);
void print_ref(IntExpr& expr);
void print_ref(FloatExpr& expr);
void print_ref(AllExpr& expr);
