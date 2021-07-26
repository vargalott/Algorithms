#include <catch2/catch.hpp>

#include <algorithms/patterns/creational/abstract-factory.hpp>

using namespace patterns::creational;

TEST_CASE("patterns::creational::abstract_factory", "abstract_factory") {
  auto comp1 = "[concrete_product_a1]";
  auto comp2 = "[concrete_product_a2]";
  auto comp3 = "[concrete_product_b1]";
  auto comp4 = "[concrete_product_b2]";

  abstract_factory::concrete_factory1 cf1;
  abstract_factory::concrete_factory2 cf2;
  abstract_factory::client client(cf1);

  auto ret1 = client.create_product1()->some_operation();
  auto ret2 = client.create_product2()->some_operation();

  client.change_factory(cf2);

  auto ret3 = client.create_product1()->some_operation();
  auto ret4 = client.create_product2()->some_operation();

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
  REQUIRE(ret3 == comp3);
  REQUIRE(ret4 == comp4);
}
