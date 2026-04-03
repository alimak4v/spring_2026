#pragma once
#include "exceptions.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
#include "TRANSACTION.h"


class TRANS_LIST {
public:
  TRANS_LIST() {}
  void ADD_FROM(const TRANSACTION& transaction_);
  void ADD_TO(const TRANSACTION& transaction_);
  void log(std::ostream& out = std::cout) const;
private:
  std::vector<TRANSACTION> transactions;
};
