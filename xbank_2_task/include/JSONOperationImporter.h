#pragma once
#include "OperationImporter.h"


class JSONOperationImporter : public OperationImporter {
protected:
  void ParseAndCreateOperations(const std::string& content) override;
};
