#include <algorithms/patterns/behavioral/state.hpp>

using namespace patterns::behavioral::state;

context::context(istate *state) : state(state) {
  this->state->change_context(this);
}
void context::change_state(istate *state) {
  this->state = state;
  this->state->change_context(this);
}
std::string context::some_operation(void) {
  return this->state->some_operation();
}

std::string concrete_state1::some_operation(void) {
  this->c->change_state(new concrete_state2);
  return "[state1]";
}
void concrete_state1::change_context(context *c) {
  this->c = c;
}

std::string concrete_state2::some_operation(void) {
  this->c->change_state(new concrete_state1);
  return "[state2]";
}
void concrete_state2::change_context(context *c) {
  this->c = c;
}
