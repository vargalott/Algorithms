#pragma once
#ifndef __MEDIATOR_HPP__
#define __MEDIATOR_HPP__

#include <string>

namespace patterns::behavioral::mediator {

class icomponent {
public:
  virtual ~icomponent(void){};

  virtual std::string react(void) = 0;
};

class imediator {
public:
  virtual ~imediator(void){};

  virtual std::string notify(icomponent *component) = 0;
};

class concrete_component1 final : public icomponent {
public:
  concrete_component1(imediator *mediator);

  virtual std::string react(void) override final;
  std::string operation1(void);

private:
  imediator *mediator;
};
class concrete_component2 final : public icomponent {
public:
  concrete_component2(imediator *mediator);

  virtual std::string react(void) override final;
  std::string operation2(void);

private:
  imediator *mediator;
};
class concrete_component3 final : public icomponent {
public:
  concrete_component3(imediator *mediator);

  virtual std::string react(void) override final;
  std::string operation3(void);

private:
  imediator *mediator;
};

class concrete_mediator final : public imediator {
public:
  void set_components(concrete_component1 *cc1, concrete_component2 *cc2,
                      concrete_component3 *cc3);

  virtual std::string notify(icomponent *component) override final;

private:
  concrete_component1 *cc1;
  concrete_component2 *cc2;
  concrete_component3 *cc3;
};

}; // namespace patterns::behavioral::mediator

#endif // !__MEDIATOR_HPP__
