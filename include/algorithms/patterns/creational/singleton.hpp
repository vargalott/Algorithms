#pragma once
#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

namespace patterns::creational::singleton {

template <typename T> class pure_singleton {
public:
  pure_singleton() = delete;
  pure_singleton(pure_singleton<T> const &) = delete;
  pure_singleton(pure_singleton<T> &&) = delete;
  pure_singleton<T> const &operator=(pure_singleton<T> const &) = delete;
  pure_singleton<T> const &operator=(pure_singleton<T> &&) = delete;

  [[nodiscard]] static T *const get_instance(void) {
    if (pure_singleton<T>::instance == nullptr) {
      pure_singleton<T>::instance = new T();
    }
    return pure_singleton<T>::instance;
  };
  template <typename... Args>
  [[nodiscard]] static T *const get_instance(Args... args) {
    if (pure_singleton<T>::instance == nullptr) {
      pure_singleton<T>::instance = new T(args...);
    }
    return pure_singleton<T>::instance;
  };

  static void dispose(void) noexcept { delete pure_singleton<T>::instance; };

private:
  inline static T *instance = nullptr;
};

}; // namespace patterns::creational::singleton

#endif // !__SINGLETON_HPP__
