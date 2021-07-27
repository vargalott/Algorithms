#include <catch2/catch.hpp>

#include <algorithms/misc/numeral-system-converter.hpp>
#include <algorithms/misc/templates.hpp>

using namespace algorithms::misc;

TEST_CASE("misc::numeral_system_converter", "_10_to_x") {
  auto comp = "CG";
  auto ret = numeral_system_converter::_10_to_x(20).convert(256);

  REQUIRE(ret == comp);
}

TEST_CASE("misc::templates::pod_count", "pod_count::pod_reflection") {
  struct POD final {
    double d; // 1
    int i;    // 2
    char c;   // 3
  };
  std::size_t comp = 3;

  std::size_t ret = 0;
  templates::pod_count::pod_reflection::detect_fields_count<POD>(ret);

  REQUIRE(ret == comp);
}

TEST_CASE("misc::templates::call_foo_or_bar", "call_foo_or_bar") {
  auto comp1 = "foo";
  auto comp2 = "bar";

  struct has_foo {
    inline std::string foo() const noexcept { return "foo"; }
  } foo;
  struct has_bar {
    inline std::string bar() const noexcept { return "bar"; }
  } bar;

  auto ret1 = templates::call_foo_or_bar(foo);
  auto ret2 = templates::call_foo_or_bar(bar);

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
}

TEST_CASE("misc::templates::factorial", "factorial") {
  auto comp = 3628800;
  auto ret = templates::factorial<10>::result;

  REQUIRE(ret == comp);
}
