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
  static ID GenerateUnique();
  static bool IsUsed(int64_t id_);
  static void MarkAsUsed(int64_t id_);
  int64_t operator()() const;
  void Log(std::ostream& out = std::cout) const;
  static bool importing;
private:
  int64_t id;
  static std::map<int64_t, bool> WAS_USED;
};
