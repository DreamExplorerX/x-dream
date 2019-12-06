#include <iostream>

using std::cout;
using std::endl;

int main() {
  int sum = 0;
  for (int i = 50; i <= 100; ++i) {
    sum += i;
  }
  cout << "Sum of number between 50 and 100 is: " << sum << endl;
  return 0;
}
