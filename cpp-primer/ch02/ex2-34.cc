#include <iostream>

int main() {
  int  i = 0, &r = i;
  auto a = r;

  const int ci = i, &cr = ci;
  auto      b = ci;
  auto      c = cr;
  auto      d = &i;
  auto      e = &ci;

  auto &g = ci;

  std::cout << "a: before: " << a << std::endl;
  a = 42;
  std::cout << "a: after: " << a << std::endl;

  std::cout << "b: before: " << a << std::endl;
  b = 42;
  std::cout << "b: after: " << a << std::endl;

  std::cout << "c: before: " << a << std::endl;
  c = 42;
  std::cout << "c: after: " << a << std::endl;

  std::cout << "d: before: " << a << std::endl;
  d = 42;
  std::cout << "d: after: " << a << std::endl;

  std::cout << "e: before: " << a << std::endl;
  e = 42;
  std::cout << "e: after: " << a << std::endl;

  std::cout << "g: before: " << a << std::endl;
  g = 42;
  std::cout << "g: after: " << a << std::endl;

  return 0;
}
