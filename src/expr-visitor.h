#include <iostream>
#include <memory>

enum class ExprKindV { FloatKind = 0, IntKind = 1, AllKind = 2 };

class BaseExprV {
 public:
  ExprKindV kind;

  template <typename V, typename T>
  T* visit(V* visitor, T* output) {
    return visitor->visit(this, output);
  }
};

class IntExprV : public BaseExprV {
 public:
  int value;

  IntExprV(int value) {
    this->kind = ExprKindV::IntKind;
    this->value = value;
  }

  template <typename V, typename T>
  T* visit(V* visitor, T* output) {
    return visitor->visit(this, output);
  }

};

class FloatExprV : public BaseExprV {
 public:
  float value;

  FloatExprV(float value) {
    this->kind = ExprKindV::FloatKind;
    this->value = value;
  }

  template <typename V, typename T>
  T* visit(V* visitor, T* output) {
    return visitor->visit(this, output);
  }

};
