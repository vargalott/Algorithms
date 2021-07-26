#include <algorithms/patterns/behavioral/visitor.hpp>

using namespace patterns::behavioral::visitor;

std::string concrete_element1::accept(ivisitor *visitor) {
  return visitor->visit(this);
}
std::string concrete_element1::feature1(void) { return "[cc1]: feature1"; }

std::string concrete_element2::accept(ivisitor *visitor) {
  return visitor->visit(this);
}
std::string concrete_element2::feature2(void) { return "[cc2]: feature2"; }

std::string concrete_visitor::visit(concrete_element1 *element) {
  return element->feature1();
}
std::string concrete_visitor::visit(concrete_element2 *element) {
  return element->feature2();
}
