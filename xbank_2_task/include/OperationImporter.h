#pragma once
#include <string>
#include "BankFacade.h"


class OperationImporter {
public:
  virtual ~OperationImporter() = default;
  void Import(const std::string& filename);
protected:
  std::string ReadFile(const std::string& filename);
  virtual void ParseAndCreateOperations(const std::string& content) = 0;
};
