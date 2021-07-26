#include <algorithms/patterns/behavioral/memento.hpp>

using namespace patterns::behavioral::memento;

originator::memento *originator::save(void) const {
  return new memento(this->state);
}
void originator::restore(memento const *snapshot) {
  this->state = snapshot->get_state();
}
void originator::update(std::string const &state) { this->state = state; }
std::string originator::get_state(void) const { return this->state; }

originator::memento::memento(std::string state) : state(state) {}
std::string originator::memento::get_state(void) const { return this->state; }

caretaker::caretaker(originator *o) : o(o) {}
void caretaker::do_smth(void) {
  this->history.emplace_back(this->o->save());

  static int times = 1;
  this->o->update(std::to_string(times++));
}
void caretaker::undo(void) {
  this->o->restore(this->history.back());
  this->history.pop_back();
}
