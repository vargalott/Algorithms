#include <catch2/catch.hpp>

#include <algorithms/patterns/structural/adapter.hpp>
#include <algorithms/patterns/structural/bridge.hpp>
#include <algorithms/patterns/structural/composite.hpp>
#include <algorithms/patterns/structural/decorator.hpp>
#include <algorithms/patterns/structural/facade.hpp>
#include <algorithms/patterns/structural/flyweight.hpp>

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

TEST_CASE("patterns::structural::composite", "composite") {
  auto comp = "[leaf][leaf][leaf][leaf][leaf]"; // 5 times

  composite::composite root;
  root.add(new composite::leaf()); // 1
  root.add(new composite::leaf()); // 2

  composite::composite parent1, parent2;
  parent1.add(new composite::leaf()); // 3
  parent1.add(new composite::leaf()); // 4
  parent2.add(new composite::leaf()); // 5

  root.add(&parent1);
  root.add(&parent2);

  auto ret = root.execute();

  REQUIRE(ret == comp);
}

TEST_CASE("patterns::structural::decorator", "decorator") {
  auto comp1 = "[concrete_component]";
  auto comp2 = "[concrete_component][concrete_decorator1 extra]";
  auto comp3 = "[concrete_component][concrete_decorator2 extra]";

  decorator::icomponent *cc = new decorator::concrete_component();
  auto ret1 = cc->execute();

  decorator::icomponent *decorated = new decorator::concrete_decorator1(cc);
  auto ret2 = decorated->execute();

  decorated = new decorator::concrete_decorator2(cc);
  auto ret3 = decorated->execute();

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
  REQUIRE(ret3 == comp3);
}

TEST_CASE("patterns::structural::facade", "facade") {
  auto comp = "[fireball][illusion][shield][haste][explosion][rest]";

  facade::facade facade;
  auto ret = facade.do_magic();

  REQUIRE(ret == comp);
}

TEST_CASE("patterns::structural::flyweight", "flyweight") {
  flyweight::flyweight_factory factory;
  flyweight::flyweight flyweight(42);
  std::vector<flyweight::context> contexts;

  for (std::size_t i = 0; i < 100; ++i) {
    contexts.emplace_back(
        *new flyweight::context(&factory.get(&flyweight), std::ptrdiff_t(i)));
  }

  // just random indexes to make sure that
  // the flyweight instance is still the same one

  REQUIRE(contexts.at(23).get() == contexts.at(42).get());
  REQUIRE(contexts.at(57).get() == contexts.at(76).get());
  REQUIRE(contexts.at(14).get() == contexts.at(92).get());
  REQUIRE(contexts.at(36).get() == contexts.at(58).get());
}
