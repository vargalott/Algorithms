#pragma once
#ifndef __FACTORY_METHOD_HPP__
#define __FACTORY_METHOD_HPP__

#include <string>

namespace patterns::creational::factory_method {

class iproduct {
public:
  virtual ~iproduct(void){};

  virtual std::string do_smth(void) = 0;
};

class default_product final : public iproduct {
public:
  virtual std::string do_smth(void) override final;
};
class concrete_product1 final : public iproduct {
public:
  virtual std::string do_smth(void) override final;
};
class concrete_product2 final : public iproduct {
public:
  virtual std::string do_smth(void) override final;
};

class creator {
public:
  creator(void) = default;
  ~creator(void) = default;

  virtual iproduct *create_product(void);
};

class concrete_creator1 final : public creator {
public:
  virtual concrete_product1 *create_product(void) override final;
};
class concrete_creator2 final : public creator {
public:
  virtual concrete_product2 *create_product(void) override final;
};

}; // namespace patterns::creational::factory_method

#endif // !__FACTORY_METHOD_HPP__
