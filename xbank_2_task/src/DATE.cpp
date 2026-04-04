#include "../include/DATE.h"
#include <vector>


DATE::DATE(int64_t day_, int64_t month_, int64_t year_) {
  if (year_ <= 0) {
    throw DATE_Exception();
  }
  if (month_ < 1 || month_ > 12) {
    throw DATE_Exception();
  }
  std::vector<int64_t> days_in_month;
  days_in_month.push_back(31);
  if ((year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0)) {
    days_in_month.push_back(29);
  } else {
    days_in_month.push_back(28);
  }
  days_in_month.push_back(31);
  days_in_month.push_back(30);
  days_in_month.push_back(31);
  days_in_month.push_back(30);
  days_in_month.push_back(31);
  days_in_month.push_back(31);
  days_in_month.push_back(30);
  days_in_month.push_back(31);
  days_in_month.push_back(30);
  days_in_month.push_back(31);
  if (day_ < 1 || days_in_month[month_ - 1] < day_) {
    throw DATE_Exception();
  }
  day=day_;
  month=month_;
  year=year_;
}

void DATE::Log(std::ostream& out) const {
  out << "DATE: " << day << "." << month << "." << year;
}
