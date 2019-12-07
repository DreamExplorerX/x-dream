#include <iostream>
#include <vector>

using std::cin;
using std::vector;

int main() {
  vector<int> ivec;
  int         num;
  while (cin >> num) {
    ivec.push_back(num);
  }
  return 0;
}
