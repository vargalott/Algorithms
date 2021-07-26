#include <algorithms/patterns/creational/abstract-factory.hpp>

using namespace patterns::creational::abstract_factory;

std::string concrete_product_a1::some_operation(void) {
  return "[concrete_product_a1]";
}
std::string concrete_product_a2::some_operation(void) {
  return "[concrete_product_a2]";
}
std::string concrete_product_b1::some_operation(void) {
  return "[concrete_product_b1]";
}
std::string concrete_product_b2::some_operation(void) {
  return "[concrete_product_b2]";
}

iproduct *concrete_factory1::create_product1(void) {
  return new concrete_product_a1();
}
iproduct *concrete_factory1::create_product2(void) {
  return new concrete_product_a2();
}
iproduct *concrete_factory2::create_product1(void) {
  return new concrete_product_b1();
}
iproduct *concrete_factory2::create_product2(void) {
  return new concrete_product_b2();
}

client::client(iabstract_factory &factory) { this->current_factory = &factory; }
void client::change_factory(iabstract_factory &factory) {
  this->current_factory = &factory;
}
iproduct *client::create_product1(void) noexcept {
  return this->current_factory->create_product1();
}
iproduct *client::create_product2(void) noexcept {
  return this->current_factory->create_product2();
}
