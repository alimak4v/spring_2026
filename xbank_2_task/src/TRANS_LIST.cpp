#include "../include/TRANS_LIST.h"
#include "../include/RUB.h"
#include "../include/Transaction.h"
#include "../include/BankAccount.h"


void TRANS_LIST::AddFrom(const Transaction& transaction_) {
  RUB zero = RUB(0, 0);
  if (transaction_.From()->Balance() - transaction_.Sum() >= zero) {
    transactions.push_back(transaction_);
  } else {
    throw TRANS_Exception();
  }
}

void TRANS_LIST::AddTo(const Transaction& transaction_) {
  transactions.push_back(transaction_);
}

void TRANS_LIST::Log(std::ostream& out) const {
  size_t num = 1;
  for (const Transaction& t : transactions) {
    out << "\n";
    t.Log(out);
    if (num != transactions.size()) {
      out << "\n      ,";
    }
    ++num;
  }
  out << "\n";
}
