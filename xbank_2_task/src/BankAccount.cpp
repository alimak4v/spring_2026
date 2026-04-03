#include "../include/BankAccount.h"
#include "../include/Transaction.h"


BankAccount::BankAccount(const ID& id_, const STR& name_, const RUB& balance_) {
  id = id_;
  name = name_;
  balance = balance_;
}

void BankAccount::UPDATE_NAME(const std::string& new_name_) {
  name = STR(new_name_);
}

void BankAccount::UPDATE_ID(int64_t new_id_) {
  id = ID(new_id_);
}

RUB BankAccount::balance_() const {
  return balance;
}

void BankAccount::TOP_UP_ACCOUNT(RUB sum_) {
  balance = balance + sum_;
}

void BankAccount::ADD_TRANS(const Transaction& transaction_) {
  if (transaction_._from() == this) {
    list.ADD_FROM(transaction_);
    balance = balance - transaction_._sum();
  } else if (transaction_._to() == this) {
    list.ADD_TO(transaction_);
    balance = balance + transaction_._sum();
  } else {
    throw TRANS_Exception();
  }
}

STR BankAccount::get_name() const {
  return name;
}

void BankAccount::log(std::ostream& out) const {
  out << "============================================================================================\n";
  out << "                                      BANK ACCOUNT\n";
  out << "--------------------------------------------------------------------------------------------\n   ";
  id.log(out);
  out << "\n   NAME: ";
  name.log(out);
  out << "\n   ";
  balance.log(out);
  out << "\n   LIST OF TRANSACTIONS: ";
  list.log(out);
  out << "============================================================================================\n";
}
