#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> svec;
  string         str;
  while (cin >> str) {
    for (auto& c : str) {
      c = toupper(c);
    }
    svec.push_back(str);
  }

  for (auto& s : svec) {
    cout << s << endl;
  }
  return 0;
}
