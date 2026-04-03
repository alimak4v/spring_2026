#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>


class ID {
public:
  ID();
  ID(int64_t id_);
  ID& operator=(const ID& other);
  static ID GENERATE_UNIQUE();
  static bool IS_USED(int64_t id_);
  static void MARK_AS_USED(int64_t id_);

  int64_t operator()() const;
  void log(std::ostream& out = std::cout) const;
private:
  int64_t id;
  static std::map<int64_t, bool> WAS_USED;
};
