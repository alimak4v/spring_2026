#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>


class STR {
public:
  STR(std::string str_ = "");
  std::string operator()() const;
  void Log(std::ostream& out = std::cout) const;
private:
  std::string str;
};
