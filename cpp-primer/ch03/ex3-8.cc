#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main() {
  string str;
  while (cin >> str) {
    decltype(str.size()) i = 0;
    while (i < str.size()) {
      str[ i++ ] = 'X';
    }
    cout << str << endl;

    for (i = 0; i < str.size(); ++i) {
      str[ i ] = 'X';
    }
    cout << str << endl;
  }
  return 0;
}
