#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include "ID.h"
#include "RUB.h"
#include "STR.h"
#include "TRANS_LIST.h"


class Transaction;

class BankAccount {
public:
  BankAccount(const ID& id_, const STR& name_, const RUB& balance_);
  void UpdateName(const std::string& new_name_);
  void UpdateId(int64_t new_id_);
  RUB Balance() const;
  void TopUpAccount(RUB sum_);
  void AddTrans(const Transaction& transaction_);
  STR GetName() const;
  void Log(std::ostream& out = std::cout) const;
private:
  ID id;
  STR name;
  RUB balance;
  TRANS_LIST list;
};
