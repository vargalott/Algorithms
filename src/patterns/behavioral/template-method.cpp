#include <algorithms/patterns/behavioral/template-method.hpp>

using namespace patterns::behavioral::template_method;

std::string abstract_template::step1(void) { return "[at]: 1"; }
std::string abstract_template::step2(void) { return "[at]: 2"; }
std::string abstract_template::template_method(void) {
  return this->step1() + " " + this->step2() + " " + this->step3() + " " +
         this->step4();
}

std::string concrete_template1::step3(void) { return "[ct1]: 3"; }
std::string concrete_template1::step4(void) { return "[ct1]: 4"; }

std::string concrete_template2::step2(void) { return "[ct2]: 2"; }
std::string concrete_template2::step3(void) { return "[ct2]: 3"; }
std::string concrete_template2::step4(void) { return "[ct2]: 4"; }
