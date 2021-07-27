#pragma once
#ifndef __PROTOTYPE_HPP__
#define __PROTOTYPE_HPP__

#include <sstream>
#include <string>

namespace patterns::creational::prototype {

class iprototype {
public:
  virtual ~iprototype(void){};

  virtual iprototype *clone(void) = 0;
};

class concrete_prototype final : public iprototype {
public:
  concrete_prototype(void);
  ~concrete_prototype(void) = default;

  virtual iprototype *clone(void) override final;
  std::string get_data(void) const noexcept;

private:
  std::string data;
};

}; // namespace patterns::creational::prototype

#endif // !__PROTOTYPE_HPP__
