#pragma once
#ifndef __SORTING_HPP__
#define __SORTING_HPP__

#include <vector>

namespace algorithms::misc::sorting {

template <typename T> void bubble_sort(std::vector<T> &arr) {
  for (std::size_t i = 0; i < arr.size(); ++i) {
    for (std::size_t j = 0; j < arr.size() - i - 1; ++j) {
      if (arr.at(j) > arr.at(j + 1)) {
        std::swap(arr.at(j), arr.at(j + 1));
      }
    }
  }
}

template <typename T> void coctail_sort(std::vector<T> &arr) {
  for (std::size_t l = 0, r = arr.size() - 1; l < r;) {
    for (std::size_t i = l; i < r; ++i) {
      if (arr.at(i + 1) < arr.at(i)) {
        std::swap(arr.at(i + 1), arr.at(i));
      }
    }
    --r;
    for (std::size_t i = r; i > l; --i) {
      if (arr.at(i - 1) > arr.at(i)) {
        std::swap(arr.at(i - 1), arr.at(i));
      }
    }
    ++l;
  }
}

template <typename T> void even_odd_sort(std::vector<T> &arr) {
  for (std::size_t i = 0; i < arr.size(); ++i) {
    for (std::size_t j = (i % 2 == 0) ? 0 : 1; j < arr.size() - 1; j += 2) {
      if (arr.at(j) > arr.at(j + 1)) {
        std::swap(arr.at(j), arr.at(j + 1));
      }
    }
  }
}

template <typename T> void combo_sort(std::vector<T> &arr) {
  std::size_t count = 0;
  double coeff = 1.2473309; // 1 / (1 - e ^(-ϕ))
  double step = arr.size() - 1;

  while (step >= 1) {
    for (std::size_t i = 0; i + static_cast<std::size_t>(step) < arr.size();
         ++i) {
      if (arr.at(i) > arr.at(i + static_cast<std::size_t>(step))) {
        std::swap(arr.at(i), arr.at(i + static_cast<std::size_t>(step)));
        ++count;
      }
    }

    step /= coeff;
    for (std::size_t i = 0; i < arr.size() - 1; ++i) {
      bool is_swap = false;

      for (std::size_t j = 0; j < arr.size() - i - 1; ++j) {
        if (arr.at(j) > arr.at(j + 1)) {
          std::swap(arr.at(j), arr.at(j + 1));
          is_swap = true;
          ++count;
        }
      }

      if (!is_swap) {
        break;
      }
    }
  }
}

} // namespace algorithms::misc::sorting

#endif // !__SORTING_HPP__
