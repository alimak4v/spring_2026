#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
#include "ID.h"
#include "RUB.h"
#include "DATE.h"
#include "STR.h"


class BankAccount;
class Category;
class Operation;

class Transaction {
public:
  Transaction(const ID& id_, BankAccount* from_, BankAccount* to_, RUB sum_, DATE date_, Category* category_);
  Transaction(const ID& id_, BankAccount* from_, BankAccount* to_, RUB sum_, DATE date_, STR descr_, Category* category_);
  void SetDescribtion(STR line);
  BankAccount* From() const;
  BankAccount* To() const;
  RUB Sum() const;
  void SecretRegister();
  void Register(std::vector<Operation>& operations_);
  void Log(std::ostream& out = std::cout) const;
private:
  ID id;
  BankAccount* from;
  BankAccount* to;
  RUB sum;
  DATE date;
  STR descr;
  Category* category;
};
