#include <catch2/catch.hpp>

#include <algorithms/patterns/structural/adapter.hpp>
#include <algorithms/patterns/structural/bridge.hpp>

using namespace patterns::structural;

TEST_CASE("patterns::structural::adapter", "adapter") {
  auto comp = "[service do_smth]";

  adapter::adapter adapter;
  auto ret = adapter.do_smth();

  REQUIRE(ret == comp);
}

TEST_CASE("patterns::structural::bridge", "bridge") {
  auto comp1 = "[concrete_implementation1 - method1]";
  auto comp2 = "[concrete_implementation1 - method2]";
  auto comp3 = "[concrete_implementation1 - method3]";
  auto comp4 = "[concrete_implementation2 - method1]";
  auto comp5 = "[concrete_implementation2 - method2]";
  auto comp6 = "[concrete_implementation2 - method3]";

  bridge::client client;
  client.change_implementation(new bridge::concrete_implementation1());

  auto ret1 = client.use_feature1();
  auto ret2 = client.use_feature2();
  auto ret3 = client.use_feature3();

  client.change_implementation(new bridge::concrete_implementation2());

  auto ret4 = client.use_feature1();
  auto ret5 = client.use_feature2();
  auto ret6 = client.use_feature3();

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
  REQUIRE(ret3 == comp3);
  REQUIRE(ret4 == comp4);
  REQUIRE(ret5 == comp5);
  REQUIRE(ret6 == comp6);
}
