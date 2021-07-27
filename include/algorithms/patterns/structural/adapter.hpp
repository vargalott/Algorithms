#pragma once
#ifndef __ADAPTER_HPP__
#define __ADAPTER_HPP__

#include <string>

namespace patterns::structural::adapter {

class iclient_interface {
public:
  virtual ~iclient_interface(void){};

  virtual std::string do_smth(void) noexcept = 0;
};

class service {
public:
  std::string do_smth_diff(void);
};

class adapter final : public iclient_interface, service {
public:
  virtual std::string do_smth(void) noexcept override final;
};

}; // namespace patterns::structural::adapter

#endif // !__ADAPTER_HPP__
