#include <algorithms/patterns/structural/flyweight.hpp>

using namespace patterns::structural::flyweight;

flyweight::flyweight(std::ptrdiff_t repeating) : repeating(repeating) {}
std::ptrdiff_t flyweight::get(void) const { return this->repeating; }

context::context(class flyweight *repeating, std::ptrdiff_t unique)
    : f(repeating), unique(unique) {}

flyweight *const context::get(void) const { return this->f; };

flyweight &flyweight_factory::get(class flyweight *repeating) {
  std::vector<flyweight *>::iterator pos =
      std::find_if(this->cache.begin(), this->cache.end(),
                   [&repeating](flyweight *flyweight) {
                     return flyweight->get() ==
                            repeating->get(); // implement your copy constructor
                                              // for the required classes
                   });
  if (pos == this->cache.end()) {
    this->cache.emplace_back(repeating);
    return *this->cache.back();
  } else {
    return **pos;
  }
}
