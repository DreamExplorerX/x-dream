#include <iostream>
#include "Sales_data.h"

int main() {
  Sales_data book;
  double price;
  std::cin >> book.bookNo >> book.units_sold >> price;
  book.revenue = book.units_sold * price;
  std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue
            << " " << price;

  return 0;
}
