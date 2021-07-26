#pragma once
#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <cstddef>
#include <iostream>
#include <vector>

namespace patterns::behavioral::iterator {

template <typename T> class iiterator {
public:
  virtual ~iiterator(void){};

  virtual T &get_next(void) = 0;
  virtual bool has_more(void) const = 0;
};

template <typename T> class iiterable_collection {
public:
  virtual ~iiterable_collection(void){};

  virtual iiterator<T> *create_iterator(void) = 0;
};

template <typename T> class concrete_collection;
template <typename T> class concrete_iterator final : public iiterator<T> {
public:
  concrete_iterator(concrete_collection<T> *collection);

  virtual T &get_next(void) override final;
  virtual bool has_more(void) const override final;

private:
  concrete_collection<T> *collection;
  std::size_t iteration_state;
};

template <typename T>
class concrete_collection final : public iiterable_collection<T> {
public:
  concrete_collection();

  void add(T const &element);
  void operator+=(T const &element);
  bool operator==(concrete_collection const& collection);

  virtual iiterator<T> *create_iterator(void) override final;

  friend class concrete_iterator<T>;

private:
  T *collection;
  std::size_t collection_size;
};

template <typename T>
inline concrete_collection<T>::concrete_collection()
    : collection(nullptr), collection_size(0) {}

template <typename T>
inline void concrete_collection<T>::add(T const &element) {
  if (this->collection_size == 0) {
    this->collection = new T[++this->collection_size];
    this->collection[this->collection_size - 1] = element;
  } else {
    T *new_collection = new T[++this->collection_size];
    for (std::size_t t = 0; t < this->collection_size - 1; ++t) {
      new_collection[t] = this->collection[t];
    }
    delete[] this->collection;
    this->collection = new_collection;
    this->collection[this->collection_size - 1] = element;
  }
}

template <typename T>
inline void concrete_collection<T>::operator+=(T const &element) {
  this->add(element);
}
template <typename T>
inline bool concrete_collection<T>::operator==(concrete_collection const &collection) {
  if (this->collection_size != collection->collection_size) {
    return false;
  }

  for (std::size t = 0; t < this->collection_size; ++t) {
    if (this->collection[t] != collection[t]) {
      return false;
    }
  }

  return true;
}
template <typename T>
inline iiterator<T> *concrete_collection<T>::create_iterator(void) {
  return new concrete_iterator(this);
}

template <typename T>
inline concrete_iterator<T>::concrete_iterator(
    concrete_collection<T> *collection)
    : collection(collection), iteration_state(0) {}

template <typename T> inline T &concrete_iterator<T>::get_next(void) {
  return this->collection->collection[this->iteration_state++];
}

template <typename T>
inline bool concrete_iterator<T>::has_more(void) const {
  return this->iteration_state >= this->collection->collection_size ||
                 this->collection->collection == nullptr
             ? false
             : true;
}

}; // namespace patterns::behavioral::iterator

#endif // !__ITERATOR_HPP__
