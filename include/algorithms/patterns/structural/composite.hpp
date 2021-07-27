#pragma once
#ifndef __COMPOSITE_HPP__
#define __COMPOSITE_HPP__

#include <algorithm>
#include <string>
#include <vector>

namespace patterns::structural::composite {

class icomponent {
public:
  virtual ~icomponent(void){};

  virtual std::string execute(void) = 0;
};

class leaf final : public icomponent {
public:
  virtual std::string execute(void) override final;
};

class composite : public icomponent {
public:
  void add(icomponent *component);
  void remove(icomponent const *component);
  std::vector<icomponent *> get_children() const;

  virtual std::string execute() override;

private:
  std::vector<icomponent *> children;
};

}; // namespace patterns::structural::composite

#endif // !__COMPOSITE_HPP__
