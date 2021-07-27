#include <catch2/catch.hpp>

#include <algorithms/patterns/creational/abstract-factory.hpp>
#include <algorithms/patterns/creational/builder.hpp>
#include <algorithms/patterns/creational/factory-method.hpp>
#include <algorithms/patterns/creational/prototype.hpp>

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

TEST_CASE("patterns::creational::builder", "builder") {
  auto comp1 = "[step1][step2][step3]";
  auto comp2 = 11100;

  builder::director director;
  builder::concrete_builder1 builder1;
  builder::concrete_builder2 builder2;

  director.change_builder(builder1);
  director.make();
  auto ret1 = builder1.get_result();

  director.change_builder(builder2);
  director.make();
  auto ret2 = builder2.get_result();

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
}

TEST_CASE("patterns::creational::factory_method", "factory_method") {
  auto comp1 = "[default_product]";
  auto comp2 = "[concrete_product1]";
  auto comp3 = "[concrete_product2]";

  auto ret1 = factory_method::creator().create_product()->do_smth();
  auto ret2 = factory_method::concrete_creator1().create_product()->do_smth();
  auto ret3 = factory_method::concrete_creator2().create_product()->do_smth();

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
  REQUIRE(ret3 == comp3);
}

TEST_CASE("patterns::creational::prototype", "prototype") {
  prototype::concrete_prototype existing;

  prototype::concrete_prototype *cloned =
      dynamic_cast<prototype::concrete_prototype *>(existing.clone());

  REQUIRE(existing.get_data() != cloned->get_data());
}
