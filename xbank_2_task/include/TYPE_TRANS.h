#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include "STR.h"


class TYPE_TRANS {
public:
  TYPE_TRANS(int8_t diff_balance_ = 0);
  TYPE_TRANS(std::string diff_balance_);
  void Log(std::ostream& out = std::cout) const;
private:
  STR type;
};
