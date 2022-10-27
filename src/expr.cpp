#include <iostream>
#include <memory>

#include "expr.h"

void print_ptr(AllExpr* expr) {
  std::cout << "print_ptr AllExpr" << std::endl;
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

void print_ref(std::unique_ptr<AllExpr>& expr) {
  std::cout << "print_ref AllExpr" << std::endl;
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
