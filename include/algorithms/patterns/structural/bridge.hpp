#pragma once
#ifndef __BRIDGE_HPP__
#define __BRIDGE_HPP__

#include <string>

namespace patterns::structural::bridge {

class iimplementation {
public:
  virtual ~iimplementation(void){};

  virtual std::string method1(void) noexcept = 0;
  virtual std::string method2(void) noexcept = 0;
  virtual std::string method3(void) noexcept = 0;
};
class concrete_implementation1 final : public iimplementation {
public:
  virtual std::string method1(void) noexcept override final;
  virtual std::string method2(void) noexcept override final;
  virtual std::string method3(void) noexcept override final;
};
class concrete_implementation2 final : public iimplementation {
public:
  virtual std::string method1(void) noexcept override final;
  virtual std::string method2(void) noexcept override final;
  virtual std::string method3(void) noexcept override final;
};

class abstraction {
public:
  abstraction(void) = default;
  ~abstraction(void) = default;

  void change_implementation(iimplementation *implementation);
  std::string feature1(void) noexcept;
  std::string feature2(void) noexcept;
  std::string feature3(void) noexcept;

private:
  iimplementation *implementation;
};

class client {
public:
  void change_implementation(iimplementation *implementation);
  std::string use_feature1() noexcept;
  std::string use_feature2() noexcept;
  std::string use_feature3() noexcept;

private:
  abstraction a;
};

}; // namespace patterns::structural::bridge

#endif // !__BRIDGE_HPP__
