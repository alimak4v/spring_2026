#include "../include/Category.h"


Category::Category(const Category& category_) {
  id = category_.id;
  type = category_.type;
  name = category_.name;
}

Category::Category(int64_t id_, std::string name_) {
  id = ID(id_);
  name = STR(name_);
}

Category::Category(const ID& id_, std::string name_) {
  id = id_;
  name = STR(name_);
}

Category::Category(const ID& id_, STR name_) {
  id = id_;
  name = name_;
}

void Category::set_type(int64_t dif_balance_) {
  type = TYPE_TRANS(dif_balance_);
}

void Category::log(std::ostream& out) const {
  out << "CATEGORY: [";
  id.log(out);
  out << "; ";
  type.log(out);
  out << "; NAME: ";
  name.log(out);
  out << "]";
}
