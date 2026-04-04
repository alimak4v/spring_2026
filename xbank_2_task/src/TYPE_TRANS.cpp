#include "../include/TYPE_TRANS.h"


TYPE_TRANS::TYPE_TRANS(int8_t diff_balance_) {
  if (diff_balance_ >= 0) {
    type = STR("+");
  } else if (diff_balance_ == -1) {
    type = STR("-");
  } else {
    throw TYPE_TRANS_Exception();
  }
}

TYPE_TRANS::TYPE_TRANS(std::string diff_balance_) {
  if (diff_balance_ == "+" || diff_balance_ == "-") {
    type = STR(diff_balance_);
  } else {
    throw TYPE_TRANS_Exception();
  }
}

void TYPE_TRANS::Log(std::ostream& out) const {
  out << "TYPE_TRANSACTION: ";
  type.Log(out);
}
