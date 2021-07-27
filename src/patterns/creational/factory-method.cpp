#include <algorithms/patterns/creational/factory-method.hpp>

using namespace patterns::creational::factory_method;

std::string default_product::do_smth(void) { return "[default_product]"; }
std::string concrete_product1::do_smth(void) { return "[concrete_product1]"; }
std::string concrete_product2::do_smth(void) { return "[concrete_product2]"; }

iproduct *creator::create_product(void) { return new default_product(); }
concrete_product1 *concrete_creator1::create_product(void) {
  return new concrete_product1();
}
concrete_product2 *concrete_creator2::create_product(void) {
  return new concrete_product2();
}
