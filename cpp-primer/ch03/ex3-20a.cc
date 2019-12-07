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

  for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; ++i) {
    cout << ivec[ i ] + ivec[ i + 1 ] << " ";
  }
  cout << endl;

  return 0;
}
