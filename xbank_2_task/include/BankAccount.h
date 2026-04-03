#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include "ID.h"
#include "RUB.h"
#include "STR.h"
#include "TRANS_LIST.h"


class TRANSACTION;

class BankAccount {
public:
  BankAccount(const ID& id_, const STR& name_, const RUB& balance_);
  void UPDATE_NAME(const std::string& new_name_);
  void UPDATE_ID(int64_t new_id_);
  RUB balance_() const;
  void TOP_UP_ACCOUNT(RUB sum_);
  void ADD_TRANS(const TRANSACTION& transaction_);
  STR get_name() const;
  void log(std::ostream& out = std::cout) const;
private:
  ID id;
  STR name;
  RUB balance;
  TRANS_LIST list;
};
