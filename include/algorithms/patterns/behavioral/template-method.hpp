#pragma once
#ifndef __TEMPLATE_METHOD_HPP__
#define __TEMPLATE_METHOD_HPP__

#include <string>

namespace patterns::behavioral::template_method {

class abstract_template {
public:
  virtual ~abstract_template(void){};

  virtual std::string template_method(void) final;

private:
  virtual std::string step1(void);
  virtual std::string step2(void);
  virtual std::string step3(void) = 0;
  virtual std::string step4(void) = 0;
};

class concrete_template1 final : public abstract_template {
private:
  virtual std::string step3(void) override final;
  virtual std::string step4(void) override final;
};

class concrete_template2 final : public abstract_template {
private:
  virtual std::string step2(void) override final;
  virtual std::string step3(void) override final;
  virtual std::string step4(void) override final;
};

}; // namespace patterns::behavioral::template_method

#endif // !__TEMPLATE_METHOD_HPP__
