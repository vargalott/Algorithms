#pragma once
#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <string>

namespace patterns::behavioral::state {

class context;
class istate {
public:
  virtual ~istate(void){};

  virtual std::string some_operation(void) = 0;
  virtual void change_context(context *context) = 0;
};

class context {
public:
  context(istate *state);

  std::string some_operation(void);
  void change_state(istate *state);

private:
  istate *state;
};

class concrete_state1 final : public istate {
public:
  virtual std::string some_operation(void) override final;
  virtual void change_context(context *c) override final;

private:
  context *c;
};
class concrete_state2 final : public istate {
public:
  virtual std::string some_operation(void) override final;
  virtual void change_context(context *c) override final;

private:
  context *c;
};

}; // namespace patterns::behavioral::state

#endif // !__STATE_HPP__
