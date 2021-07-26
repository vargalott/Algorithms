#pragma once
#ifndef __ABSTRACT_FACTORY_HPP__
#define __ABSTRACT_FACTORY_HPP__

#include <string>

namespace patterns::creational::abstract_factory {

class iproduct {
public:
  virtual ~iproduct(void){};

  virtual std::string some_operation(void) = 0;
};
class concrete_product_a1 final : public iproduct {
public:
  virtual std::string some_operation(void) override final;
};
class concrete_product_a2 final : public iproduct {
public:
  virtual std::string some_operation(void) override final;
};
class concrete_product_b1 final : public iproduct {
public:
  virtual std::string some_operation(void) override final;
};
class concrete_product_b2 final : public iproduct {
public:
  virtual std::string some_operation(void) override final;
};

class iabstract_factory {
public:
  virtual ~iabstract_factory(void){};

  virtual iproduct *create_product1(void) = 0;
  virtual iproduct *create_product2(void) = 0;
};
class concrete_factory1 final : public iabstract_factory {
public:
  virtual iproduct *create_product1(void) override final;
  virtual iproduct *create_product2(void) override final;
};
class concrete_factory2 final : public iabstract_factory {
public:
  virtual iproduct *create_product1(void) override final;
  virtual iproduct *create_product2(void) override final;
};

class client {
public:
  client(void) = default;
  client(iabstract_factory &factory);
  ~client(void) = default;

  void change_factory(iabstract_factory &factory);

  iproduct *create_product1(void) noexcept;
  iproduct *create_product2(void) noexcept;

private:
  iabstract_factory *current_factory;
};

}; // namespace patterns::creational::abstract_factory

#endif // !__ABSTRACT_FACTORY_HPP__
