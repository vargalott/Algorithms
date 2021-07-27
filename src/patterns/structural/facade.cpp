#include <algorithms/patterns/structural/facade.hpp>

using namespace patterns::structural::facade;

std::string subsystem1::cast_fireball(void) { return "[fireball]"; }
std::string subsystem1::make_illusion(void) { return "[illusion]"; }

std::string subsystem2::cast_shield(void) { return "[shield]"; }
std::string subsystem2::make_haste(void) { return "[haste]"; }

std::string subsystem3::cast_explosion(void) { return "[explosion]"; }
std::string subsystem3::make_rest(void) { return "[rest]"; }

std::string facade::do_magic(void) {
  subsystem1 ss1;
  subsystem2 ss2;
  subsystem3 ss3;

  return ss1.cast_fireball() + ss1.make_illusion() + ss2.cast_shield() +
         ss2.make_haste() + ss3.cast_explosion() + ss3.make_rest();
}
