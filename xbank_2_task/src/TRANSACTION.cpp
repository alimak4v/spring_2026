#include "../include/TRANSACTION.h"
#include "../include/BankAccount.h"
#include "../include/Category.h"
#include "../include/Operation.h"


TRANSACTION::TRANSACTION(const ID& id_, BankAccount* from_, BankAccount* to_, RUB sum_, DATE date_, Category* category_) : date(date_) {
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

TRANSACTION::TRANSACTION(const ID& id_, BankAccount* from_, BankAccount* to_, RUB sum_, DATE date_, STR descr_, Category* category_) : date(date_) {
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

void TRANSACTION::set_describtion(STR line) {
  descr = line;
}

BankAccount* TRANSACTION::_from() const {
  return from;
}

BankAccount* TRANSACTION::_to() const {
  return to;
}

RUB TRANSACTION::_sum() const {
  return sum;
}

void TRANSACTION::SecretRegister() {
  Category* category_from = new Category(*category);
  Category* category_to = new Category(*category);
  category_from -> set_type(-1);
  category_to -> set_type(1);
  category = category_from;
  from->ADD_TRANS(*this);
  category = category_to;
  to->ADD_TRANS(*this);
}

void TRANSACTION::Register(std::vector<Operation>& operations_) {
  Category* category_from = new Category(*category);
  Category* category_to = new Category(*category);
  category_from -> set_type(-1);
  category_to -> set_type(1);
  category = category_from;
  from->ADD_TRANS(*this);
  category = category_to;
  to->ADD_TRANS(*this);
  operations_.push_back(Operation(id, TYPE_TRANS(-1), from, sum, date, descr, category_from));
  operations_.push_back(Operation(id, TYPE_TRANS(1), to, sum, date, descr, category_to));
}

void TRANSACTION::log(std::ostream& out) const {
  out << "--------------------------------------------------------------------------------------------\n      ";
  id.log(out);
  out << "\n      FROM: ";
  from->get_name().log(out);
  out << "\n      TO: ";
  to->get_name().log(out);
  out << "\n      ";
  sum.log(out);
  out << "\n      ";
  date.log(out);
  out << "\n      ";
  category->log(out);
  out << "\n--------------------------------------------------------------------------------------------";
}
