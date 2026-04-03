#include "../include/TRANS_LIST.h"
#include "../include/RUB.h"
#include "../include/TRANSACTION.h"
#include "../include/BankAccount.h"


void TRANS_LIST::ADD_FROM(const TRANSACTION& transaction_) {
  RUB zero = RUB(0, 0);
  if (transaction_._from()->balance_() - transaction_._sum() >= zero) {
    transactions.push_back(transaction_);
  } else {
    throw TRANS_Exception();
  }
}

void TRANS_LIST::ADD_TO(const TRANSACTION& transaction_) {
  transactions.push_back(transaction_);
}

void TRANS_LIST::log(std::ostream& out) const {
  size_t num = 1;
  for (const TRANSACTION& t : transactions) {
    out << "\n";
    t.log(out);
    if (num != transactions.size()) {
      out << "\n      ,";
    }
    ++num;
  }
  out << "\n";
}
