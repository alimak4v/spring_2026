#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include "ID.h"
#include "TYPE_TRANS.h"
#include "RUB.h"
#include "DATE.h"
#include "STR.h"


class BankAccount;
class Category;

class Operation {
public:
  Operation(const ID& id_, TYPE_TRANS type_, BankAccount* bank_account_, RUB sum_, DATE date_, STR descr_, Category* category_);
  void Log(std::ostream& out = std::cout) const;
private:
  ID id;
  TYPE_TRANS type;
  BankAccount* bank_account;
  RUB sum;
  DATE date;
  STR descr;
  Category* category;
};
