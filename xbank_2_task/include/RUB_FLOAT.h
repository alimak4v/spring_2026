#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>


class RUB_FLOAT {
public:
  RUB_FLOAT(int64_t value = 0);
  int64_t operator()() const;
private:
  int64_t value_;
};
