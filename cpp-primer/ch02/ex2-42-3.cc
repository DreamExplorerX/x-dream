#include <iostream>
#include "Sales_data.h"

int main() {
  Sales_data total;
  double total_price;
  if (std::cin >> total.bookNo >> total.units_sold >> total_price) {
    total.revenue = total.units_sold * total_price;
    Sales_data trans;
    double price;
    while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;

      if (total.bookNo == trans.bookNo) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        std::cout << total.bookNo << " " << total.units_sold << " "
                  << total.revenue << " ";
        if (total.units_sold != 0) {
          std::cout << total.revenue / total.units_sold << std::endl;
        } else {
          std::cout << "No Sales!" << std::endl;
        }

        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue;
      }
    }

    std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue
              << " ";
    if (total.units_sold != 0) {
      std::cout << total.revenue / total.units_sold << std::endl;
    } else {
      std::cout << "No Sales!" << std::endl;
    }
  } else {
    std::cout << "No data?" << std::endl;
  }
  return 0;
}
