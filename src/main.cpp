#include <iostream>

// forward declarations
void test_macros();
void test_casting();
void test_types();
void test_unique_ptr();
void test_template();

int main() {
  test_casting();
  test_macros();
  test_template();
  test_types();
  test_unique_ptr();

  std::cout << std::endl << "[II] Done!" << std::endl;
  return 0;
}
