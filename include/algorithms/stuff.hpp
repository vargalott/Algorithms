#pragma once
#ifndef __STUFF_HPP__
#define __STUFF_HPP__

#include <iostream>
#include <string>

/*
 *  auto some_pointer = ...;
 *  if (some_pointer) {
 *    some_pointer->some_method();
 *  }
 *
 *  auto some_pointer = ...;
 *  safe_call_void(some_pointer, some_method());
 *
 *  auto some_pointer = ...;
 *  auto x = safe_call(0, some_pointer, some_method());
 */

#define safe_call_expr(default_value, obj_pointer, arity_method)               \
  ((pointer) ? ((pointer)->arity_method) : (default_value))

#define safe_call(default_value, obj_pointer, arity_method)                    \
  [&](decltype((obj_pointer)) &&pointer)                                       \
      -> decltype(safe_call_expr(default_value, pointer, arity_method)) {      \
    return safe_call_expr(default_value, pointer, arity_method);               \
  }(obj_pointer)

#define safe_call_void(obj_pointer, arity_method)                              \
  [&](decltype((obj_pointer)) &&pointer) {                                     \
    if (pointer) {                                                             \
      (pointer->arity_method);                                                 \
    }                                                                          \
  }(obj_pointer)

#define var_dump(variable)                                                     \
  std::cout << #variable << " = [" << (variable) << "]" << std::endl;

[[noreturn]] inline static volatile void
__panic(std::string const &message) noexcept {
  std::cerr << message << std::endl;
  std::exit(EXIT_FAILURE);
};

namespace algorithms {} // namespace algorithms

#endif // !__STUFF_HPP__
