#include <algorithms/patterns/structural/bridge.hpp>

using namespace patterns::structural::bridge;

std::string concrete_implementation1::method1(void) noexcept {
  return "[concrete_implementation1 - method1]";
}
std::string concrete_implementation1::method2(void) noexcept {
  return "[concrete_implementation1 - method2]";
}
std::string concrete_implementation1::method3(void) noexcept {
  return "[concrete_implementation1 - method3]";
}

std::string concrete_implementation2::method1(void) noexcept {
  return "[concrete_implementation2 - method1]";
}
std::string concrete_implementation2::method2(void) noexcept {
  return "[concrete_implementation2 - method2]";
}
std::string concrete_implementation2::method3(void) noexcept {
  return "[concrete_implementation2 - method3]";
}

void abstraction::change_implementation(iimplementation *implementation) {
  this->implementation = implementation;
}
std::string abstraction::feature1(void) noexcept {
  return this->implementation->method1();
}
std::string abstraction::feature2(void) noexcept {
  return this->implementation->method2();
}
std::string abstraction::feature3(void) noexcept {
  return this->implementation->method3();
}

void client::change_implementation(iimplementation *implementation) {
  this->a.change_implementation(implementation);
}
std::string client::use_feature1() noexcept { return this->a.feature1(); }
std::string client::use_feature2() noexcept { return this->a.feature2(); }
std::string client::use_feature3() noexcept { return this->a.feature3(); }
