#pragma once
#ifndef __FLYWEIGHT_HPP__
#define __FLYWEIGHT_HPP__

#include <algorithm>
#include <string>
#include <vector>

namespace patterns::structural::flyweight {

class flyweight {
public:
  flyweight(void) = default;
  flyweight(std::ptrdiff_t repeating);
  ~flyweight(void) = default;

  std::ptrdiff_t get(void) const;

private:
  std::ptrdiff_t repeating;
};

class context {
public:
  context(void) = delete;
  context(flyweight *repeating, std::ptrdiff_t unique);
  flyweight* const get(void) const;

private:
  flyweight *f;
  std::ptrdiff_t unique;
};

class flyweight_factory {
public:
  flyweight &get(flyweight *repeating);

private:
  std::vector<flyweight *> cache;
};

}; // namespace patterns::structural::flyweight

#endif // !__FLYWEIGHT_HPP__
