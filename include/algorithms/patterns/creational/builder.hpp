#pragma once
#ifndef __BUILDER_HPP__
#define __BUILDER_HPP__

#include <string>

namespace patterns::creational::builder {

class ibuilder {
public:
  virtual ~ibuilder(void){};

  virtual void reset(void) noexcept = 0;
  virtual void step1(void) = 0;
  virtual void step2(void) = 0;
  virtual void step3(void) = 0;
};

class concrete_builder1 final : public ibuilder {
public:
  concrete_builder1(void) = default;
  ~concrete_builder1(void) = default;

  virtual void reset(void) noexcept override final;
  virtual void step1(void) override final;
  virtual void step2(void) override final;
  virtual void step3(void) override final;

  std::string &get_result(void) noexcept;

private:
  std::string result;
};

class concrete_builder2 final : public ibuilder {
public:
  concrete_builder2(void) = default;
  ~concrete_builder2(void) = default;

  virtual void reset(void) noexcept override final;
  virtual void step1(void) override final;
  virtual void step2(void) override final;
  virtual void step3(void) override final;

  ptrdiff_t &get_result(void) noexcept;

private:
  ptrdiff_t result;
};

class director {
public:
  director(void) = default;
  director(ibuilder *builder);
  ~director(void) = default;

  void change_builder(ibuilder &builder);
  void make(void) const;

private:
  ibuilder *builder;
};

}; // namespace patterns::creational::builder

#endif // !__BUILDER_HPP__
