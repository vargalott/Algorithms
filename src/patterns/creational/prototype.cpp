#include <algorithms/patterns/creational/prototype.hpp>

using namespace patterns::creational::prototype;

concrete_prototype::concrete_prototype(void) {
  std::ostringstream addr;
  addr << (void const *)this;
  this->data = addr.str();
}
iprototype *concrete_prototype::clone(void) {
  iprototype *cloned = new concrete_prototype();

  *cloned = *this; // do necessary things to copy itself
  return cloned;
}
std::string concrete_prototype::get_data(void) const noexcept {
  return this->data;
}
