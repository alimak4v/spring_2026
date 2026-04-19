#include "../include/RUB_FLOAT.h"


RUB_FLOAT::RUB_FLOAT(int64_t value) {
  if (value < 100 && value >= 0) { // [0.0; 0.99]
    value_ = value;
  } else {
    throw RUB_Exception();
  }
}

int64_t RUB_FLOAT::operator()() const {
  return value_;
}
