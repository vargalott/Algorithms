#include <algorithms/patterns/behavioral/mediator.hpp>

using namespace patterns::behavioral::mediator;

concrete_component1::concrete_component1(imediator *mediator)
    : mediator(mediator) {}
std::string concrete_component1::react(void) { return "cc1:react"; }
std::string concrete_component1::operation1(void) {
  return this->mediator->notify(this);
}

concrete_component2::concrete_component2(imediator *mediator)
    : mediator(mediator) {}
std::string concrete_component2::react(void) { return "cc2:react"; }
std::string concrete_component2::operation2(void) {
  return this->mediator->notify(this);
}

concrete_component3::concrete_component3(imediator *mediator)
    : mediator(mediator) {}
std::string concrete_component3::react(void) { return "cc3:react"; }
std::string concrete_component3::operation3(void) {
  return this->mediator->notify(this);
}

void concrete_mediator::set_components(concrete_component1 *cc1,
                                       concrete_component2 *cc2,
                                       concrete_component3 *cc3) {
  this->cc1 = cc1;
  this->cc2 = cc2;
  this->cc3 = cc3;
}

std::string concrete_mediator::notify(icomponent *component) {
  // some piece of weird logic

  if (typeid(*component) == typeid(concrete_component1)) {
    return this->cc2->react(); // reacting on concrete_component1
  } else if (typeid(*component) == typeid(concrete_component2)) {
    return this->cc3->react(); // reacting on concrete_component2
  } else if (typeid(*component) == typeid(concrete_component3)) {
    return this->cc1->react(); // reacting on concrete_component3
  }
}
