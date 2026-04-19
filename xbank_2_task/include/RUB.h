#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include "RUB_INT.h"
#include "RUB_FLOAT.h"


class RUB {
public:
  RUB(int64_t integer_part = 0, int64_t float_part = 0);
  RUB(RUB_INT integer_part, RUB_FLOAT float_part);
  int64_t ToKopek() const;
  static RUB FromKopek(int64_t kopek);
  RUB& operator=(const RUB& other);
  RUB operator+(const RUB& other) const;
  RUB operator-(const RUB& other) const;
  bool operator==(const RUB& other) const;
  bool operator!=(const RUB& other) const;
  bool operator>(const RUB& other) const;
  bool operator<(const RUB& other) const;
  bool operator>=(const RUB& other) const;
  bool operator<=(const RUB& other) const;
  void Log(std::ostream& out = std::cout) const;
private:
  RUB_INT int_part_;
  RUB_FLOAT float_part_;
};
