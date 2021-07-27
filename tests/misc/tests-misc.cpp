#include <catch2/catch.hpp>

#include <algorithms/misc/numeral-system-converter.hpp>

using namespace algorithms::misc;

TEST_CASE("misc::numeral_system_converter", "_10_to_x") {
  auto comp = "CG";
  auto ret = numeral_system_converter::_10_to_x(20).convert(256);

  REQUIRE(ret == comp);
}
