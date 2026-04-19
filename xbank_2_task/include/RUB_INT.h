#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>


const int64_t MAX_INT = 10000000000000;

class RUB_INT {
public:
  RUB_INT(int64_t value = 0);
  int64_t operator()() const;
private:
  int64_t value_;
};
