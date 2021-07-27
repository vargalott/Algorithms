#pragma once
#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include <string>

namespace patterns::structural::decorator {

class icomponent {
public:
  virtual ~icomponent(void){};

  virtual std::string execute(void) = 0;
};

class concrete_component final : public icomponent {
public:
  virtual std::string execute(void) override final;
};

class base_decorator : public icomponent {
public:
  base_decorator(void) = delete;
  base_decorator(icomponent *wrappee);
  ~base_decorator(void) = default;

  virtual std::string execute(void) override;

private:
  icomponent *wrappee;
};

class concrete_decorator1 final : public base_decorator {
public:
  concrete_decorator1(icomponent *wrappee);

  virtual std::string execute(void) override final;
  std::string do_extra(void);
};

class concrete_decorator2 final : public base_decorator {
public:
  concrete_decorator2(icomponent *wrappee);

  virtual std::string execute(void) override final;
  std::string do_extra(void);
};

}; // namespace patterns::structural::decorator

#endif // !__DECORATOR_HPP__
