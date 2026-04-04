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
  void AddFrom(const Transaction& transaction_);
  void AddTo(const Transaction& transaction_);
  void Log(std::ostream& out = std::cout) const;
private:
  std::vector<Transaction> transactions;
};
