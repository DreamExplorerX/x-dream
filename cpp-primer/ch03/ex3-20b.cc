#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  vector<int> ivec;
  int         num;
  while (cin >> num) {
    ivec.push_back(num);
  }

  auto mid = (ivec.size() + 1) / 2;
  for (decltype(ivec.size()) i = 0; i < mid; ++i) {
    cout << ivec[ i ] + ivec[ ivec.size() - i - 1 ] << " ";
  }
  cout << endl;

  return 0;
}
