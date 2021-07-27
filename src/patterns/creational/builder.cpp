#include <algorithms/patterns/creational/builder.hpp>

using namespace patterns::creational::builder;

void concrete_builder1::reset(void) noexcept { this->result.clear(); }
void concrete_builder1::step1(void) { this->result.append("[step1]"); }
void concrete_builder1::step2(void) { this->result.append("[step2]"); }
void concrete_builder1::step3(void) { this->result.append("[step3]"); }
std::string &concrete_builder1::get_result(void) noexcept {
  return this->result;
}

void concrete_builder2::reset(void) noexcept { this->result = ptrdiff_t(0); }
void concrete_builder2::step1(void) { this->result += 100; }
void concrete_builder2::step2(void) { this->result += 1000; }
void concrete_builder2::step3(void) { this->result += 10000; }
ptrdiff_t &concrete_builder2::get_result(void) noexcept { return this->result; }

director::director(ibuilder *builder) : builder(builder) {}
void director::change_builder(ibuilder &builder) { this->builder = &builder; }
void director::make(void) const {
  this->builder->reset();
  this->builder->step1();
  this->builder->step2();
  this->builder->step3();
}
