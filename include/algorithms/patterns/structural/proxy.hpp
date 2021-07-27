#pragma once
#ifndef __PROXY_HPP__
#define __PROXY_HPP__

#include <string>

namespace patterns::structural::proxy {

class iservice {
public:
  virtual ~iservice(void){};

  virtual std::string do_smth(void) = 0;
};

class service final : public iservice {
public:
  virtual std::string do_smth(void) override final;
};

class proxy final : public iservice {
public:
  proxy(void);
  proxy(service *service);
  ~proxy(void);

  virtual std::string do_smth(void) override final;
  std::string do_smth_other(void);

private:
  service *s;
  bool is_alloc;
};

}; // namespace patterns::structural::proxy

#endif // !__PROXY_HPP__
