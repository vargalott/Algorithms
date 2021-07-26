#include <catch2/catch.hpp>

#include <algorithms/patterns/behavioral/command.hpp>

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
