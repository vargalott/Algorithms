#include <catch2/catch.hpp>

#include <algorithms/patterns/structural/adapter.hpp>

using namespace patterns::structural;

TEST_CASE("patterns::structural::adapter", "adapter") {
  auto comp = "[service do_smth]";

  adapter::adapter adapter;
  auto ret = adapter.do_smth();

  REQUIRE(ret == comp);
}
