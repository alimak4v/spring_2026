#include "../include/BankAccountFactory.h"


BankAccount BankAccountFactory::Create(int64_t id_, std::string name_) {
  return BankAccount(ID(id_), STR(name_), RUB(0, 0));
}

BankAccount BankAccountFactory::Create(const ID &id_, std::string name_) {
  return BankAccount(id_, STR(name_), RUB(0, 0));
}
