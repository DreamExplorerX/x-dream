#include <iostream>
#include "file.h"

int main() {
  extern const int a = 10;
  std::cout << a << std::endl;
  printA();
}
