#pragma once
#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <string>

namespace patterns::behavioral::command {

class icommand {
public:
  virtual ~icommand(void){};

  virtual std::string execute() = 0;
};

class receiver1 {
public:
  std::string some_operation(void);
};

class receiver2 {
public:
  std::string some_operation(void);
};

class concrete_command1 final : public icommand {
public:
  concrete_command1(receiver1 *receiver);

  virtual std::string execute(void) override final;

private:
  receiver1 *receiver;
};

class concrete_command2 final : public icommand {
public:
  concrete_command2(receiver2 *receiver);

  virtual std::string execute(void) override final;

private:
  receiver2 *receiver;
};

class invoker {
public:
  invoker(icommand *command);

  void change(icommand *command);
  std::string execute();

private:
  icommand *command;
};

}; // namespace patterns::behavioral

#endif // !__COMMAND_HPP__
