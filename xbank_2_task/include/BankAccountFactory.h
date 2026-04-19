#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include "BankAccount.h"


class BankAccountFactory {
public:
  static BankAccount Create(int64_t id_, std::string name_);
  static BankAccount Create(const ID &id_, std::string name_);
};
