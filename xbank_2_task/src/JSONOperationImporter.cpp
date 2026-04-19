#include "../include/JSONOperationImporter.h"
#include "../include/Operation.h"
#include "../include/BankFacade.h"
#include "../include/BankAccountFactory.h"
#include "../include/Category.h"
#include <sstream>
#include <cstdio>
#include <algorithm>


void JSONOperationImporter::ParseAndCreateOperations(const std::string& content) {
  std::string data = content;
  data.erase(std::remove_if(data.begin(), data.end(), ::isspace), data.end());
  if (!data.empty() && data.front() == '[') {
    data.erase(0, 1);
  }
  if (!data.empty() && data.back() == ']') {
    data.pop_back();
  }

  size_t pos = 0;
  while (true) {
    size_t start = data.find('{', pos);
    size_t end = data.find('}', start);
    if (start == std::string::npos || end == std::string::npos) {
      break;
    }

    std::string obj = data.substr(start, end - start + 1);
    pos = end + 1;

    auto extractInt = [&](const std::string& key) -> int {
      size_t kpos = obj.find("\"" + key + "\"");
      if (kpos == std::string::npos) return 0;
      size_t colon = obj.find(':', kpos);
      if (colon == std::string::npos) return 0;
      size_t comma = obj.find_first_of(",}", colon);
      std::string val = obj.substr(colon + 1, comma - colon - 1);
      return std::stoi(val);
    };

    auto extractStr = [&](const std::string& key) -> std::string {
      size_t kpos = obj.find("\"" + key + "\"");
      if (kpos == std::string::npos) return "";
      size_t colon = obj.find(':', kpos);
      if (colon == std::string::npos) return "";
      size_t q1 = obj.find('"', colon + 1);
      size_t q2 = obj.find('"', q1 + 1);
      if (q1 == std::string::npos || q2 == std::string::npos) return "";
      return obj.substr(q1 + 1, q2 - q1 - 1);
    };

    int id_ = extractInt("id");
    std::string type_ = extractStr("type");
    int bank_account_id_ = extractInt("bank_account_id");
    int amount_ = extractInt("amount");
    std::string date_str = extractStr("date");
    std::string descr_ = extractStr("description");
    int category_id_ = extractInt("category_id");

    int day = 1, month = 1, year = 2026;
    sscanf(date_str.c_str(), "%d.%d.%d", &day, &month, &year);

    static std::vector<BankAccount> dummy_accounts;
    static std::vector<Category> dummy_categories;

    dummy_accounts.push_back(BankAccountFactory::Create(ID(bank_account_id_ > 0 ? bank_account_id_ : 999), "Imported Account"));
    dummy_categories.push_back(Category(ID(category_id_ > 0 ? category_id_ : 999), "Imported Category"));

    ID safe_id = (id_ > 0) ? ID(id_) : ID(999);
    Operation op(safe_id, TYPE_TRANS(type_), &dummy_accounts.back(), RUB(amount_), DATE(day, month, year), STR(descr_), &dummy_categories.back());
    BankFacade::AddOperation(op);
  }
}
