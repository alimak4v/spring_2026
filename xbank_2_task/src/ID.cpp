#include "../include/ID.h"


std::map<int64_t, bool> ID::WAS_USED;
bool ID::importing;

ID::ID() {
  ID id_ = GenerateUnique();
  id = id_();
  MarkAsUsed(id_());
}

ID::ID(int64_t id_) {
  if (id_ < 0) {
    throw ID_Exception();
  }
  if (IsUsed(id_) && importing == false) {
    throw ID_Exception();
  }
  id = id_;
  MarkAsUsed(id_);
}

ID& ID::operator=(const ID& other) {
    if (this != &other) {
        id = other.id;
    }
    return *this;
}

ID ID::GenerateUnique() {
  static int64_t last_id = 1;
  while (IsUsed(last_id)) {
    // std::cout << "uze posecheno:" << last_id << std::endl;
    ++last_id;
  }
  return ID(last_id);
}

bool ID::IsUsed(int64_t id_) {
  return WAS_USED.find(id_) != WAS_USED.end();
}

void ID::MarkAsUsed(int64_t id_) {
  if (id_ >= 0) {
    WAS_USED[id_] = true;
  }
}

int64_t ID::operator()() const {
  return id;
}

void ID::Log(std::ostream& out) const {
  out << "ID: " << id;
}
