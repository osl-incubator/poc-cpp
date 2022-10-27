#include <iostream>

using std::cout;

// signatures
void test_unique_ptr();
void test_casting();
void test_types();


int main() {
    test_unique_ptr();
    test_casting();
    test_types();
    cout << std::endl << "[II] Done!" << std::endl;
    return 0;
}
