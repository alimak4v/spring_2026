#include "../include/BankAccount.h"
#include "../include/Transaction.h"


BankAccount::BankAccount(const ID& id_, const STR& name_, const RUB& balance_) {
  id = id_;
  name = name_;
  balance = balance_;
}

void BankAccount::UpdateName(const std::string& new_name_) {
  name = STR(new_name_);
}

void BankAccount::UpdateId(int64_t new_id_) {
  id = ID(new_id_);
}

RUB BankAccount::Balance() const {
  return balance;
}

void BankAccount::TopUpAccount(RUB sum_) {
  balance = balance + sum_;
}

void BankAccount::AddTrans(const Transaction& transaction_) {
  if (transaction_.From() == this) {
    list.AddFrom(transaction_);
    balance = balance - transaction_.Sum();
  } else if (transaction_.To() == this) {
    list.AddTo(transaction_);
    balance = balance + transaction_.Sum();
  } else {
    throw TRANS_Exception();
  }
}

STR BankAccount::GetName() const {
  return name;
}

void BankAccount::Log(std::ostream& out) const {
  out << "============================================================================================\n";
  out << "                                      BANK ACCOUNT\n";
  out << "--------------------------------------------------------------------------------------------\n   ";
  id.Log(out);
  out << "\n   NAME: ";
  name.Log(out);
  out << "\n   ";
  balance.Log(out);
  out << "\n   LIST OF TRANSACTIONS: ";
  list.Log(out);
  out << "============================================================================================\n";
}
