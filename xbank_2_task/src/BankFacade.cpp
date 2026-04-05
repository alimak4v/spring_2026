#include "../include/BankFacade.h"


std::vector<Operation> BankFacade::ops;

void BankFacade::Register(Transaction& trans_) {
  trans_.Register(ops);
}

void BankFacade::SecretRegister(Transaction& trans_) {
  trans_.SecretRegister();
}

void BankFacade::Register(BankAccount* from_, BankAccount* to_, RUB sum_, DATE date_, Category* category_, ID id_) {
  Transaction t(id_, from_, to_, sum_, date_, category_);
  t.Register(ops);
}

void BankFacade::SecretRegister(BankAccount* from_, BankAccount* to_, RUB sum_, DATE date_, Category* category_, ID id_) {
  Transaction t(id_, from_, to_, sum_, date_, category_);
  t.SecretRegister();
}

void BankFacade::Log(std::ostream& out) {
  out << "\n\n\nOPERATION LIST:\n";
  for (const auto& o : ops) {
    o.Log();
    out << "\n";
  }
}

void BankFacade::AddOperation(const Operation& op) {
  ops.push_back(op);
}
