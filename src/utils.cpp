#include <string>
#include <iostream>


void print_test_header(std::string text) {
  std::cout << "==================================" << std::endl;
  std::cout << text << ": STARTING ... " << std::endl;
  std::cout << "----------------------------------" << std::endl;
}


void print_test_footer(std::string text) {
  std::cout << "----------------------------------" << std::endl;
  std::cout << text << ": DONE" << std::endl;
  std::cout << "==================================" << std::endl;
}
