#pragma once
#ifndef __MEMENTO_HPP__
#define __MEMENTO_HPP__

#include <string>
#include <vector>

namespace patterns::behavioral::memento {

class originator {
public:
  class memento {
  public:
    memento(std::string state);

    std::string get_state(void) const;

  private:
    std::string state;
  };

  memento *save(void) const;
  void restore(memento const *snapshot);

  void update(std::string const &state);
  std::string get_state(void) const;

private:
  std::string state;
};

class caretaker {
public:
  caretaker(originator *o);

  void do_smth(void);
  void undo(void);

private:
  originator *o;
  std::vector<originator::memento *> history;
};

}; // namespace patterns::behavioral::memento

#endif // !__MEMENTO_HPP__
