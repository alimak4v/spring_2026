#include "../include/RUB_INT.h"


RUB_INT::RUB_INT(int64_t value) {
  if (value < MAX_INT && value >= 0) { // [0, MAX_INT.0)
    value_ = value;
  } else {
    throw RUB_Exception();
  }
}

int64_t RUB_INT::operator()() const {
  return value_;
}
