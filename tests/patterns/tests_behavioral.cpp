#include <catch2/catch.hpp>

#include <algorithms/patterns/behavioral/command.hpp>
#include <algorithms/patterns/behavioral/cor.hpp>

using namespace patterns::behavioral;

TEST_CASE("patterns::behavioral::command", "command") {
  auto comp1 = "receiver1::some_operation";
  auto comp2 = "receiver2::some_operation";

  command::receiver1 r1;
  command::receiver2 r2;
  command::concrete_command1 cc1(&r1);
  command::concrete_command2 cc2(&r2);

  command::invoker invoker(&cc1);
  auto ret1 = invoker.execute();
  invoker.change(&cc2);
  auto ret2 = invoker.execute();

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
}

TEST_CASE("patterns::behavioral::cor", "cor") {
  auto comp1 = "[handle1] handle1";
  auto comp2 = "[handle2] handle2";
  auto comp3 = "[handle3] handle3";
  auto comp4 = "[end]";

  cor::ihandler *h1 = new cor::concrete_handler1();
  cor::ihandler *h2 = new cor::concrete_handler2();
  cor::ihandler *h3 = new cor::concrete_handler3();

  h1->set_next(h2);
  h2->set_next(h3);

  auto ret1 = h1->handle("handle1");
  auto ret2 = h1->handle("handle2");
  auto ret3 = h1->handle("handle3");
  auto ret4 = h1->handle("end");

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
  REQUIRE(ret3 == comp3);
  REQUIRE(ret4 == comp4);
}
