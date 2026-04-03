#include <iostream>
#include <vector>
#include "include/exceptions.h"
#include "include/RUB_INT.h"
#include "include/RUB_FLOAT.h"
#include "include/RUB.h"
#include "include/ID.h"
#include "include/STR.h"
#include "include/DATE.h"
#include "include/TYPE_TRANS.h"
#include "include/Category.h"
#include "include/TRANS_LIST.h"
#include "include/TRANSACTION.h"
#include "include/Operation.h"
#include "include/BankAccount.h"
#include "include/BankAccountFactory.h"


int main() {
  std::cout << "======================================= X-Bank Test ========================================\n\n";
  std::vector<Operation> BANK;

  BankAccount a0 = BankAccountFactory::create(ID(), "Eupatii Kolovratov");
  BankAccount a1 = BankAccountFactory::create(ID(), "Aleksei Sinitsyn");
  BankAccount a2 = BankAccountFactory::create(ID(), "Sasha Petrova");

  a1.TOP_UP_ACCOUNT(RUB(50000, 0));
  // a1.log();
  // std::cout << std::endl;

  Category c1(ID(), "TRANSFER BETWEEN FRIENDS");
  Category c2(ID(), "FOOD");

  DATE d1(28, 2, 2026);
  TRANSACTION t0(ID(1991), &a1, &a0, RUB(15000, 50), d1, &c1);
  t0.Register(BANK);
  TRANSACTION t1(ID(100), &a1, &a2, RUB(15000, 50), d1, &c1);
  t1.set_describtion(STR("transfer"));
  t1.Register(BANK);

  DATE d2(2, 4, 2026);
  TRANSACTION t2(ID(), &a2, &a1, RUB(100, 99), d2, &c2);
  t2.set_describtion(STR("kupil suhariki"));
  t2.Register(BANK);

  a1.log();
  std::cout << std::endl;
  a2.log();
  std::cout << std::endl;
  
  a2.UPDATE_NAME("Sasha Markova");

  std::cout << "\n\n\nOPERATION LIST:\n";
  for (const auto& o : BANK) {
    o.log();
    std::cout << std::endl;
  }
  std::cout << "\n\n";

  return 0;
}