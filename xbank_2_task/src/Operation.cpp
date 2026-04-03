#include "../include/Operation.h"
#include "../include/BankAccount.h"
#include "../include/Category.h"


Operation::Operation(const ID& id_, TYPE_TRANS type_, BankAccount* bank_account_, RUB sum_, DATE date_, STR descr_, Category* category_) : date(date_) {
  id = id_;
  type = type_;
  if (bank_account_ == nullptr || category_ == nullptr) {
    throw TRANS_Exception();
  }
  bank_account = bank_account_;
  sum = sum_;
  descr = descr_;
  category = category_;
}

void Operation::log(std::ostream& out) const {
  out << "[\n   ";
  id.log(out);
  out << "\n   ACCOUNT: ";
  bank_account->get_name().log(out);
  out << "\n   ";
  sum.log(out);
  out << "\n   ";
  date.log(out);
  out << "\n   ";
  category->log(out);
  out << "\n];\n";
}
