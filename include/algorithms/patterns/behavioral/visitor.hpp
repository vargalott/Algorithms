#pragma once
#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include <string>

namespace patterns::behavioral::visitor {

class ivisitor;
class ielement {
public:
  virtual ~ielement(void){};

  virtual std::string accept(ivisitor *visitor) = 0;
};

class concrete_element1 final : public ielement {
public:
  virtual std::string accept(ivisitor *visitor) override final;

  std::string feature1(void);
};
class concrete_element2 final : public ielement {
public:
  virtual std::string accept(ivisitor *visitor) override final;

  std::string feature2(void);
};

class ivisitor {
public:
  virtual ~ivisitor(void){};

  virtual std::string visit(concrete_element1 *element) = 0;
  virtual std::string visit(concrete_element2 *element) = 0;
};

class concrete_visitor final : public ivisitor {
public:
  virtual std::string visit(concrete_element1 *element) override final;
  virtual std::string visit(concrete_element2 *element) override final;
};

}; // namespace patterns::behavioral::visitor

#endif // !__VISITOR_HPP__
