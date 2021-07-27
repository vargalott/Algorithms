#pragma once
#ifndef __FACADE_HPP__
#define __FACADE_HPP__

#include <string>

namespace patterns::structural::facade {

class subsystem1 {
public:
  std::string cast_fireball(void);
  std::string make_illusion(void);
};

class subsystem2 {
public:
  std::string cast_shield(void);
  std::string make_haste(void);
};

class subsystem3 {
public:
  std::string cast_explosion(void);
  std::string make_rest(void);
};

class facade {
public:
  std::string do_magic(void);
};

}; // namespace patterns::structural::facade

#endif // !__FACADE_HPP__
