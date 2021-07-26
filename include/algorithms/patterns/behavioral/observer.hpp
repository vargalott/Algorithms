#pragma once
#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include <algorithm>
#include <string>
#include <vector>

namespace patterns::behavioral::observer {

class isubscriber {
public:
  virtual ~isubscriber(void){};

  virtual std::string update(void) = 0;
};

class publisher {
public:
  void subscribe(isubscriber *subscriber);
  void unsubscribe(isubscriber *subscriber);
  void notify(void) const;

  void do_smth(void);

private:
  std::vector<isubscriber *> subscribers;
  std::ptrdiff_t state;
};

class concrete_subscriber final : public isubscriber {
public:
  virtual std::string update(void) override final;

  bool is_notified_once = false;
};

}; // namespace patterns::behavioral::observer

#endif // !__OBSERVER_HPP__
