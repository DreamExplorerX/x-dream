#include <iostream>
#include "Sales_data.h"

int main() {
  Sales_data sd1, sd2;
  double price1, price2;
  std::cin >> sd1.bookNo >> sd1.units_sold >> price1;
  std::cin >> sd2.bookNo >> sd2.units_sold >> price2;
  sd1.revenue = sd1.units_sold * price1;
  sd2.revenue = sd2.units_sold * price2;

  if (sd1.bookNo == sd2.bookNo) {
    unsigned int total_sold = sd1.units_sold + sd2.units_sold;
    double total_revenue = sd1.revenue + sd2.revenue;
    std::cout << sd1.bookNo << " " << total_sold << " " << total_revenue;
    if (total_sold != 0) {
      std::cout << " " << total_revenue / total_sold << std::endl;
    } else {
      std::cout << "No Sales" << std::endl;
    }
  } else {
    std::cout << "These books' bookNo are different" << std::endl;
  }
  return 0;
}
