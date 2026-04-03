#include "../include/BankAccountFactory.h"


BankAccount BankAccountFactory::create(int64_t id_, std::string name_) {
  return BankAccount(ID(id_), STR(name_), RUB(0, 0));
}

BankAccount BankAccountFactory::create(const ID &id_, std::string name_) {
  return BankAccount(id_, STR(name_), RUB(0, 0));
}
