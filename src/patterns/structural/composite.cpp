#include <algorithms/patterns/structural/composite.hpp>

using namespace patterns::structural::composite;

std::string leaf::execute(void) { return "[leaf]"; }

void composite::add(icomponent *component) {
  this->children.emplace_back(component);
}
void composite::remove(icomponent const *component) {
  std::vector<icomponent *>::iterator del_pos = std::find_if(
      this->children.begin(), this->children.end(), [](icomponent *component) {
        return true; // implement your copy constructor for the required classes
      });
  if (del_pos != this->children.end()) {
    this->children.erase(del_pos);
  }
}
std::vector<icomponent *> composite::get_children() const {
  return this->children;
}
std::string composite::execute() {
  std::string executed = "";
  std::for_each(
      this->children.begin(), this->children.end(),
      [&executed](icomponent *component) { executed += component->execute(); });
  return executed;
}
