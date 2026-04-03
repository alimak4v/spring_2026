#include "../include/ID.h"


std::map<int64_t, bool> ID::WAS_USED;

ID::ID() {
  ID id_ = GENERATE_UNIQUE();
  id = id_();
  MARK_AS_USED(id_());
}

ID::ID(int64_t id_) {
  if (id_ < 0) {
    throw ID_Exception();
  }
  if (IS_USED(id_)) {
    throw ID_Exception();
  }
  id = id_;
  MARK_AS_USED(id_);
}

ID& ID::operator=(const ID& other) {
    if (this != &other) {
        id = other.id;
    }
    return *this;
}

ID ID::GENERATE_UNIQUE() {
  static int64_t last_id = 1;
  while (IS_USED(last_id)) {
    // std::cout << "uze posecheno:" << last_id << std::endl;
    ++last_id;
  }
  return ID(last_id);
}

bool ID::IS_USED(int64_t id_) {
  return WAS_USED.find(id_) != WAS_USED.end();
}

void ID::MARK_AS_USED(int64_t id_) {
  if (id_ >= 0) {
    WAS_USED[id_] = true;
  }
}

int64_t ID::operator()() const {
  return id;
}

void ID::log(std::ostream& out) const {
  out << "ID: " << id;
}
