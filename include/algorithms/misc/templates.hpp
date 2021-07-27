#pragma once
#ifndef __TEMPLATES_HPP__
#define __TEMPLATES_HPP__

#include <cstddef>
#include <utility>

namespace algorithms::misc::templates {

// see more: https://en.cppreference.com/w/cpp/named_req/PODType
// only unless c++20
namespace pod_count {

class pod_reflection final {
public:
  template <typename Type>
  inline static constexpr auto detect_fields_count(std::size_t &out) noexcept -> void {
    static_assert(std::is_pod<Type>::value, "Not a pod-value");
    pod_reflection::refl_detect_fields_count<Type>(
      out, std::make_index_sequence<std::size_t(max_search_count)>()
    );
  };

private:
  static constexpr std::size_t max_search_count = 100;

  struct pod_any_cast_constructible {
    template <typename any_type>
    constexpr operator any_type(void) const noexcept {
      return any_type();
    };
    explicit pod_any_cast_constructible(void) = default;
  };

  template <std::size_t another_param> struct pod_any_cast {
    template <typename any_type>
    constexpr operator any_type &(void) const noexcept; // not implemented!
  };

  // more specialized template
  template <typename pod_struct, std::size_t param, std::size_t... another_params>
  inline static auto constexpr refl_detect_fields_count(
      std::size_t &out,
      std::index_sequence<param, another_params...> const) noexcept
      -> decltype(
        pod_struct{pod_any_cast<param>(),
        pod_any_cast<another_params>{}...}
      ) {
    out = sizeof...(another_params) + static_cast<std::size_t>(1);
    return pod_any_cast_constructible();
  };

  // less specialized template
  template <typename pod_struct, std::size_t... another_params>
  inline static auto constexpr refl_detect_fields_count(
    std::size_t &out, std::index_sequence<another_params...>) noexcept -> void {
    refl_detect_fields_count<pod_struct>(
      out, std::make_index_sequence<sizeof...(another_params) - 1>())
    ;
  };
};

}; // namespace pod_count

template <typename T>
auto call_foo_or_bar(T const &obj) -> decltype(obj.foo()) {
  return obj.foo();
};
template <typename T>
auto call_foo_or_bar(T const &obj) -> decltype(obj.bar()) {
  return obj.bar();
};

template <std::size_t n> struct factorial {
  static constexpr std::size_t result = n * factorial<n - 1>::result;
};
template <> struct factorial<std::size_t(0)> {
  static constexpr std::size_t result = std::size_t(1);
};

} // namespace algorithms::misc::templates

#endif // !__TEMPLATES_HPP__
