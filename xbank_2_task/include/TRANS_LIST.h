#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
#include "Transaction.h"


class TRANS_LIST {
public:
  TRANS_LIST() {}
  void ADD_FROM(const Transaction& transaction_);
  void ADD_TO(const Transaction& transaction_);
  void log(std::ostream& out = std::cout) const;
private:
  std::vector<Transaction> transactions;
};
