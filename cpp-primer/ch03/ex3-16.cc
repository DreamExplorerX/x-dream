#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> v1;  // 0 空值
  cout << "\nv1:\n size: " << v1.size() << "\nvalue: ";
  if (!v1.empty()) {
    for (auto i : v1) {
      cout << i << " ";
    }
  }
  cout << endl;

  vector<int> v2(10);  // 10个0
  cout << "\nv2\n size: " << v2.size() << "\nvalue: ";
  if (!v2.empty()) {
    for (auto i : v2) {
      cout << i << " ";
    }
  }
  cout << endl;

  vector<int> v3(10, 42);  // 10个42
  cout << "\nv3:\n size: " << v3.size() << "\nvalue: ";
  if (!v3.empty()) {
    for (auto i : v3) {
      cout << i << " ";
    }
  }
  cout << endl;

  vector<int> v4{10};  // 1个10
  cout << "\nv4:\n size: " << v4.size() << "\nvalue: ";
  if (!v4.empty()) {
    for (auto i : v4) {
      cout << i << " ";
    }
  }
  cout << endl;

  vector<int> v5{10, 42};  // 2个值，分别是 10, 42
  cout << "\nv5:\n size: " << v5.size() << "\nvalue: ";
  if (!v5.empty()) {
    for (auto i : v5) {
      cout << i << " ";
    }
  }
  cout << endl;

  vector<string> v6{10};  // 10个空string
  cout << "\nv6:\n size: " << v6.size() << "\nvalue: ";
  if (!v6.empty()) {
    for (auto i : v6) {
      cout << i << " ";
    }
  }
  cout << endl;

  vector<string> v7{10, "hi"};  // 10 个 "hi"
  cout << "\nv7:\n size: " << v7.size() << "\nvalue: ";
  if (!v7.empty()) {
    for (auto i : v7) {
      cout << i << " ";
    }
  }
  cout << endl;
}
