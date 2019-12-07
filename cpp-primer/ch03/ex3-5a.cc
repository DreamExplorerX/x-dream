#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main() {
  string sum, str;
  while (cin >> str) {
    sum += str;
  }
  cout << sum << endl;
  return 0;
}
