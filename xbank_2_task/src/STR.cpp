#include "../include/STR.h"


STR::STR(std::string str_) {
  for (char& c : str_) {
    if (c >= 'a' && c <= 'z') {
      continue;
    }
    if (c >= 'A' && c <= 'Z') {
      continue;
    }
    if (c == '_' || c == ' ') {
      continue;
    }
    if (c == '+' || c == '-') {
      continue;
    }
    if (c >= '0' && c <= '9') {
      continue;
    }
    throw STR_Exception();
  }
  str = str_;
}

std::string STR::operator()() const {
  return str;
}

void STR::log(std::ostream& out) const {
  out << str;
}
