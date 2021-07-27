#include <algorithms/patterns/structural/proxy.hpp>

using namespace patterns::structural::proxy;

std::string service::do_smth(void) { return "[service do_smth]"; }

proxy::proxy(void) : s(new service()), is_alloc(true) {}
proxy::proxy(class service *service) {
  this->s = service;
  this->is_alloc = false;
}
proxy::~proxy(void) {
  if (this->is_alloc) {
    delete this->s;
  }
}
std::string proxy::do_smth(void) {
  return this->s->do_smth() + this->do_smth_other();
}
std::string proxy::do_smth_other(void) { return "[proxy do_smth_other]"; }
