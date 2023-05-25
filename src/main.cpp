#include <iostream>

// forward declarations
auto test_macros() -> void;
auto test_casting() -> void;
auto test_types() -> void;
auto test_unique_ptr() -> void;
auto test_template() -> void;
auto test_visitor() -> void;
auto test_memory_leak() -> void;

int main() {
  test_casting();
  test_macros();
  test_template();
  test_types();
  test_unique_ptr();
  test_memory_leak();

  std::cout << std::endl << "[II] Done!" << std::endl;
  return 0;
}
