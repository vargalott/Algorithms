#include <catch2/catch.hpp>

#include <array>

#include <algorithms/patterns/behavioral/command.hpp>
#include <algorithms/patterns/behavioral/cor.hpp>
#include <algorithms/patterns/behavioral/iterator.hpp>
#include <algorithms/patterns/behavioral/mediator.hpp>
#include <algorithms/patterns/behavioral/memento.hpp>
#include <algorithms/patterns/behavioral/observer.hpp>
#include <algorithms/patterns/behavioral/state.hpp>
#include <algorithms/patterns/behavioral/strategy.hpp>
#include <algorithms/patterns/behavioral/template-method.hpp>

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

TEST_CASE("patterns::behavioral::mediator", "mediator") {
  auto comp1 = "cc2:react";
  auto comp2 = "cc3:react";
  auto comp3 = "cc1:react";

  mediator::concrete_mediator mediator;
  mediator::concrete_component1 cc1(&mediator);
  mediator::concrete_component2 cc2(&mediator);
  mediator::concrete_component3 cc3(&mediator);

  auto ret1 = cc1.operation1();
  auto ret2 = cc2.operation2();
  auto ret3 = cc3.operation3();

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
  REQUIRE(ret3 == comp3);
}

TEST_CASE("patterns::behavioral::iterator", "iterator") {
  std::array<std::size_t, 10> comp = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  iterator::concrete_collection<std::size_t> collection;
  auto iterator = collection.create_iterator();

  for (std::size_t t = 0; t < 10; ++t) {
    collection += t;
  }

  std::array<std::size_t, 10> ret = {};
  while (iterator->has_more()) {
    static std::size_t i = 0;
    ret[i++] = iterator->get_next();
  }

  REQUIRE(ret == comp);
}

TEST_CASE("patterns::behavioral::memento", "memento") {
  memento::originator originator;
  memento::caretaker ctk(&originator);

  ctk.do_smth(); // state "1"
  REQUIRE(originator.get_state() == "1");

  ctk.do_smth(); // state "2"
  REQUIRE(originator.get_state() == "2");

  ctk.do_smth(); // state "3"
  REQUIRE(originator.get_state() == "3");

  ctk.undo(); // state "2"
  REQUIRE(originator.get_state() == "2");
}

TEST_CASE("patterns::behavioral::observer", "observer") {
  observer::publisher pb;
  observer::concrete_subscriber csb;

  pb.subscribe(&csb);

  pb.do_smth();

  REQUIRE(csb.is_notified_once);
}

TEST_CASE("patterns::behavioral::state", "state") {
  // concrete_state1 => concrete_state2 => concrete_state1 => ...
  auto comp1 = "[state1]";
  auto comp2 = "[state2]";

  state::istate *state = new state::concrete_state1();
  state::context context(state);

  auto ret1 = context.some_operation();
  auto ret2 = context.some_operation();

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
}

TEST_CASE("patterns::behavioral::strategy", "strategy") {
  auto comp1 = "[concrete_strategy1]";
  auto comp2 = "[concrete_strategy2]";

  strategy::concrete_strategy1 cc1;
  strategy::concrete_strategy2 cc2;
  strategy::context ctx;

  ctx.set(&cc1);
  auto ret1 = ctx.do_smth();

  ctx.set(&cc2);
  auto ret2 = ctx.do_smth();

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
}

TEST_CASE("patterns::behavioral::template_method", "template_method") {
  auto comp1 = "[at]: 1 [at]: 2 [ct1]: 3 [ct1]: 4";
  auto comp2 = "[at]: 1 [ct2]: 2 [ct2]: 3 [ct2]: 4";

  template_method::abstract_template *tm1 = new template_method::concrete_template1();
  template_method::abstract_template *tm2 = new template_method::concrete_template2();

  auto ret1 = tm1->template_method();
  auto ret2 = tm2->template_method();

  REQUIRE(ret1 == comp1);
  REQUIRE(ret2 == comp2);
}
