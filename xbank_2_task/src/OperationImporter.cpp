#include "../include/OperationImporter.h"
#include <fstream>
#include <sstream>
#include <iostream>


std::string OperationImporter::ReadFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "[ERROR] CAN'T OPEN FILE: " << filename << std::endl;
    return "";
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

void OperationImporter::Import(const std::string& filename) {
  std::string content = ReadFile(filename);
  if (content.empty()) return;
  ParseAndCreateOperations(content);
  std::cout << "[IMPORT] SUCCESFUL IMPORT FROM FILE: " << filename << std::endl;
}
