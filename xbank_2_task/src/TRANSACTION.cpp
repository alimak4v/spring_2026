#include "../include/Transaction.h"
#include "../include/BankAccount.h"
#include "../include/Category.h"
#include "../include/Operation.h"


Transaction::Transaction(const ID& id_, BankAccount* from_, BankAccount* to_, RUB sum_, DATE date_, Category* category_) : date(date_) {
  id = id_;
  from = from_;
  to = to_;
  sum = sum_;
  descr = STR("NO DESCRIBTION");
  category = category_;

  if (to_ == nullptr || from_ == nullptr) {
    throw TRANS_Exception();
  }
}

Transaction::Transaction(const ID& id_, BankAccount* from_, BankAccount* to_, RUB sum_, DATE date_, STR descr_, Category* category_) : date(date_) {
  id = id_;
  from = from_;
  to = to_;
  sum = sum_;
  descr = descr_;
  category = category_;

  if (to_ == nullptr || from_ == nullptr) {
    throw TRANS_Exception();
  }
}

void Transaction::SetDescribtion(STR line) {
  descr = line;
}

BankAccount* Transaction::From() const {
  return from;
}

BankAccount* Transaction::To() const {
  return to;
}

RUB Transaction::Sum() const {
  return sum;
}

void Transaction::SecretRegister() {
  Category* category_from = new Category(*category);
  Category* category_to = new Category(*category);
  category_from -> SetType(-1);
  category_to -> SetType(1);
  category = category_from;
  from->AddTrans(*this);
  category = category_to;
  to->AddTrans(*this);
}

void Transaction::Register(std::vector<Operation>& operations_) {
  Category* category_from = new Category(*category);
  Category* category_to = new Category(*category);
  category_from -> SetType(-1);
  category_to -> SetType(1);
  category = category_from;
  from->AddTrans(*this);
  category = category_to;
  to->AddTrans(*this);
  operations_.push_back(Operation(id, TYPE_TRANS(-1), from, sum, date, descr, category_from));
  operations_.push_back(Operation(id, TYPE_TRANS(1), to, sum, date, descr, category_to));
}

void Transaction::Log(std::ostream& out) const {
  out << "--------------------------------------------------------------------------------------------\n      ";
  id.Log(out);
  out << "\n      FROM: ";
  from->GetName().Log(out);
  out << "\n      TO: ";
  to->GetName().Log(out);
  out << "\n      ";
  sum.Log(out);
  out << "\n      ";
  date.Log(out);
  out << "\n      ";
  category->Log(out);
  out << "\n--------------------------------------------------------------------------------------------";
}
