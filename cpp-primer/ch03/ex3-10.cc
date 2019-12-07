#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;

using std::string;

int main() {
  string str;
  getline(cin, str);
  for (auto c : str) {
    if (!ispunct(c)) {
      cout << c;
    }
  }
  return 0;
}

