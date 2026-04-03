#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include "ID.h"
#include "STR.h"
#include "TYPE_TRANS.h"


class Category {
public:
  Category(const Category& category_);
  Category(const ID& id_, std::string name_);
  Category(int64_t id_, std::string name_);
  Category(const ID& id_, STR name_);
  void set_type(int64_t dif_balance_);
  void log(std::ostream& out = std::cout) const;
private:
  ID id;
  TYPE_TRANS type;
  STR name;
};
