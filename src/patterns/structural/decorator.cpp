#include <algorithms/patterns/structural/decorator.hpp>

using namespace patterns::structural::decorator;

std::string concrete_component::execute(void) { return "[concrete_component]"; }

base_decorator::base_decorator(icomponent *wrappee) : wrappee(wrappee) {}
std::string base_decorator::execute(void) { return this->wrappee->execute(); }

concrete_decorator1::concrete_decorator1(icomponent *wrappee)
    : base_decorator(wrappee) {}
std::string concrete_decorator1::execute(void) {
  return base_decorator::execute() + this->do_extra();
}
std::string concrete_decorator1::do_extra(void) {
  return "[concrete_decorator1 extra]";
}

concrete_decorator2::concrete_decorator2(icomponent *wrappee)
    : base_decorator(wrappee) {}
std::string concrete_decorator2::execute(void) {
  return base_decorator::execute() + this->do_extra();
}
std::string concrete_decorator2::do_extra(void) {
  return "[concrete_decorator2 extra]";
}
