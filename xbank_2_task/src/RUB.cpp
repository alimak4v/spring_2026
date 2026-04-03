#include "../include/RUB.h"


RUB::RUB(int64_t integer_part, int64_t float_part) {
  int_part_ = RUB_INT(integer_part);
  float_part_ = RUB_FLOAT(float_part);
}

RUB::RUB(RUB_INT integer_part, RUB_FLOAT float_part) {
  int_part_ = integer_part;
  float_part_ = float_part;
}

int64_t RUB::to_kopek() const {
  return int_part_() * 100 + float_part_();
}

RUB RUB::from_kopek(int64_t kopek) {
  if (kopek < 0 || kopek >= MAX_INT * 100) throw RUB_Exception();
  return RUB(kopek / 100, kopek % 100);
}

RUB& RUB::operator=(const RUB& other) {
  if (this != &other) {
    int_part_ = other.int_part_;
    float_part_ = other.float_part_;
  }
  return *this;
}

RUB RUB::operator+(const RUB& other) const {
  return from_kopek(this->to_kopek() + other.to_kopek());
}

RUB RUB::operator-(const RUB& other) const {
  return from_kopek(this->to_kopek() - other.to_kopek());
}

bool RUB::operator==(const RUB& other) const {
  return this->to_kopek() == other.to_kopek();
}

bool RUB::operator!=(const RUB& other) const {
  return !(*this == other);
}

bool RUB::operator>(const RUB& other) const {
  return this->to_kopek() > other.to_kopek();
}

bool RUB::operator<(const RUB& other) const {
  return this->to_kopek() < other.to_kopek();
}

bool RUB::operator>=(const RUB& other) const {
  return *this == other || *this > other;
}

bool RUB::operator<=(const RUB& other) const {
  return *this == other || *this < other;
}

void RUB::log(std::ostream& out) const {
  out << "RUB: ";
  out << int_part_() << ".";
  if (float_part_() < 10) {
    out << "0";
  }
  out << float_part_();
}
