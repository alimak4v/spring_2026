#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
#include "Operation.h"
#include "Transaction.h"

class BankFacade {
public:
  BankFacade() = delete;
  static void Register(Transaction& trans_);
  static void Register(BankAccount* from_, BankAccount* to_, RUB sum_, DATE date_, Category* category_, ID id_ = ID());
  static void SecretRegister(Transaction& trans_);
  static void SecretRegister(BankAccount* from_, BankAccount* to_, RUB sum_, DATE date_, Category* category_, ID id_ = ID());
  static void Log(std::ostream& out = std::cout);
private:
  static std::vector<Operation> ops;
};