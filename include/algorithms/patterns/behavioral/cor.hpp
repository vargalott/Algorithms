#pragma once
#ifndef __COR_HPP__
#define __COR_HPP__

#include <string>

namespace patterns::behavioral::cor {

class ihandler {
public:
  virtual ~ihandler(void){};

  virtual void set_next(ihandler *handler) = 0;
  virtual std::string handle(std::string const &request) = 0;
};

class base_handler : public ihandler {
public:
  virtual void set_next(ihandler *handler) override final;
  virtual std::string handle(std::string const &request) override;

protected:
  ihandler *next;
};

class concrete_handler1 final : public base_handler {
public:
  virtual std::string handle(std::string const &request) override final;
};
class concrete_handler2 final : public base_handler {
public:
  virtual std::string handle(std::string const &request) override final;
};
class concrete_handler3 final : public base_handler {
public:
  virtual std::string handle(std::string const &request) override final;
};

}; // namespace patterns::behavioral

#endif // !__COR_HPP__
