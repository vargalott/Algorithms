#include <algorithms/patterns/behavioral/strategy.hpp>

using namespace patterns::behavioral::strategy;

std::string concrete_strategy1::execute(void) { return "[concrete_strategy1]"; }
std::string concrete_strategy2::execute(void) { return "[concrete_strategy2]"; }

context::context(istrategy *strategy) : strategy(strategy) {}
void context::set(istrategy *strategy) { this->strategy = strategy; }
std::string context::do_smth(void) { return this->strategy->execute(); }
