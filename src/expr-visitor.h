#include <iostream>
#include <memory>

enum class ExprKindV { FloatKind = 0, IntKind = 1, AllKind = 2 };

class BaseExprV {
 public:
  ExprKindV kind;

  template <typename V>
  auto accept(V* visitor) -> void {
    visitor->visit(this);
  }
};

class IntExprV : public BaseExprV {
 public:
  int value;

  IntExprV(int value) {
    this->kind = ExprKindV::IntKind;
    this->value = value;
  }

};

class FloatExprV : public BaseExprV {
 public:
  float value;

  FloatExprV(float value) {
    this->kind = ExprKindV::FloatKind;
    this->value = value;
  }

};
