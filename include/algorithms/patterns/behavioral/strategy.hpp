#pragma once
#ifndef __STRATEGY_HPP__
#define __STRATEGY_HPP__

#include <string>

namespace patterns::behavioral::strategy {

class istrategy {
public:
  virtual ~istrategy(void){};

  virtual std::string execute(void) = 0;
};

class concrete_strategy1 final : public istrategy {
public:
  virtual std::string execute(void) override final;
};

class concrete_strategy2 final : public istrategy {
public:
  virtual std::string execute(void) override final;
};

class context {
public:
  context(void) = default;
  context(istrategy *strategy);
  ~context(void) = default;

  void set(istrategy *strategy);
  std::string do_smth(void);

private:
  istrategy *strategy;
};

}; // namespace patterns::behavioral::strategy

#endif // !__STRATEGY_HPP__
