#include <algorithms/patterns/behavioral/cor.hpp>

using namespace patterns::behavioral::cor;

void base_handler::set_next(ihandler *handler) { this->next = handler; }
std::string base_handler::handle(std::string const &request) {
  if (this->next != nullptr) {
    return this->next->handle(request);
  } else {
    return "[end]";
  }
}

std::string concrete_handler1::handle(std::string const &request) {
  if (request != "handle1") {
    return base_handler::handle(request);
  } else {
    return "[handle1] " + request;
  }
}
std::string concrete_handler2::handle(std::string const &request) {
  if (request != "handle2") {
    return base_handler::handle(request);
  } else {
    return "[handle2] " + request;
  }
}
std::string concrete_handler3::handle(std::string const &request) {
  if (request != "handle3") {
    return base_handler::handle(request);
  } else {
    return "[handle3] " + request;
  }
}
