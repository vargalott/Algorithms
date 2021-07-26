#include <algorithms/patterns/behavioral/observer.hpp>

using namespace patterns::behavioral::observer;

void publisher::subscribe(isubscriber *subscriber) {
  this->subscribers.emplace_back(subscriber);
}
void publisher::unsubscribe(isubscriber *subscriber) {
  std::vector<isubscriber *>::iterator del_pos = std::find_if(
      this->subscribers.begin(), this->subscribers.end(),
      [](isubscriber *subscriber) {
        return true; // implement your copy constructor for the required classes
      });

  if (del_pos != this->subscribers.end()) {
    this->subscribers.erase(del_pos);
  }
}
void publisher::notify(void) const {
  std::for_each(this->subscribers.begin(), this->subscribers.end(),
                [](isubscriber *subscriber) { subscriber->update(); });
}
void publisher::do_smth(void) {
  this->state = 42;
  this->notify();
}

std::string concrete_subscriber::update(void) {
  this->is_notified_once = true;
  return "[notified]";
}
