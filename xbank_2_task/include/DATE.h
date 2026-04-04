#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>


class DATE {
public:
  DATE(int64_t day_, int64_t month_, int64_t year_);
  void Log(std::ostream& out = std::cout) const;
private:
  int64_t day;
  int64_t month;
  int64_t year;
};
