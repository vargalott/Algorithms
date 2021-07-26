#include <algorithms/patterns/behavioral/command.hpp>

using namespace patterns::behavioral::command;

concrete_command1::concrete_command1(receiver1 *receiver)
    : receiver(receiver) {}
std::string concrete_command1::execute(void) {
  return this->receiver->some_operation();
}
concrete_command2::concrete_command2(receiver2 *receiver)
    : receiver(receiver) {}
std::string concrete_command2::execute(void) {
  return this->receiver->some_operation();
}

std::string receiver1::some_operation(void) {
  return "receiver1::some_operation";
}
std::string receiver2::some_operation(void) {
  return "receiver2::some_operation";
}

invoker::invoker(icommand *command) : command(command) {}
void invoker::change(icommand *command) { this->command = command; }
std::string invoker::execute() { return this->command->execute(); }
