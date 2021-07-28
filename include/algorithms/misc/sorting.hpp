#pragma once
#ifndef __SORTING_HPP__
#define __SORTING_HPP__

#include <functional>
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

template <typename T> void insert_sort(std::vector<T> &arr) {
  for (std::size_t i = 1; i < arr.size(); ++i) {
    for (std::size_t j = i; j > 0 && arr.at(j - 1) > arr.at(j); --j) {
      std::swap(arr.at(j - 1), arr.at(j));
    }
  }
}

template <typename T> void selection_sort(std::vector<T> &arr) {
  for (std::size_t i = 0; i < arr.size() - 1; ++i) {
    std::size_t min = i;
    for (std::size_t j = i + 1; j < arr.size(); ++j) {
      if (arr.at(j) < arr.at(min)) {
        min = j;
      }
    }
    if (min != i) {
      std::swap(arr.at(i), arr.at(min));
      min = i;
    }
  }
}

template <typename T> void merge_sort(std::vector<T> &arr) {
  if (arr.size() <= 1) {
    return;
  }

  std::size_t mid = arr.size() / 2;
  std::vector<T> left, right;

  for (std::size_t i = 0; i < mid; ++i) {
    left.push_back(arr.at(i));
  }
  for (std::size_t i = mid; i < arr.size(); ++i) {
    right.push_back(arr.at(i));
  }

  merge_sort(left);
  merge_sort(right);

  arr.clear();
  auto merge = [](std::vector<T> &left,
                  std::vector<T> &right) -> std::vector<T> & {
    std::vector<T> *result = new std::vector<T>(left.size() + right.size());
    std::size_t l = 0, r = 0;

    for (std::size_t i = 0; i < result->size(); ++i) {
      if (l == left.size()) {
        result->at(i) = right.at(r++);
      } else if (r == right.size()) {
        result->at(i) = left.at(l++);
      } else {
        if (left.at(l) < right.at(r)) {
          result->at(i) = left.at(l++);
        } else {
          result->at(i) = right.at(r++);
        }
      }
    }

    return *result;
  };

  arr = merge(left, right);
}

template <typename T> void shell_sort(std::vector<T> &arr) {
  std::size_t step = arr.size() / 2;

  while (step > 0) {
    for (std::size_t i = 0; i < arr.size() - step; ++i) {
      std::ptrdiff_t j = i;

      while (j >= 0 && arr.at(j) > arr.at(j + step)) {
        std::swap(arr.at(j), arr.at(j + step));
        --j;
      }
    }
    step /= 2;
  }
}

template <typename T> void quick_sort(std::vector<T> &arr) {
  std::function<void(std::vector<T> &, std::size_t, std::size_t)>
      quick_sort_inner = [&quick_sort_inner](std::vector<T> &arr,
                                             std::ptrdiff_t left,
                                             std::ptrdiff_t right) -> void {
    std::ptrdiff_t pivot;
    std::ptrdiff_t lo = left, hi = right;
    pivot = arr.at(left);

    while (left < right) {
      while (arr.at(right) >= pivot && left < right)
        --right;
      if (left != right) {
        arr.at(left) = arr.at(right);
        ++left;
      }
      while ((arr.at(left) <= pivot) && (left < right)) {
        ++left;
      }
      if (left != right) {
        arr.at(right) = arr.at(left);
        --right;
      }
    }

    arr.at(left) = pivot;
    pivot = left;
    left = lo;
    right = hi;

    if (left < pivot) {
      quick_sort_inner(arr, left, pivot - 1);
    }
    if (right > pivot) {
      quick_sort_inner(arr, pivot + 1, right);
    }
  };

  quick_sort_inner(arr, 0, arr.size() - 1);
}

} // namespace algorithms::misc::sorting

#endif // !__SORTING_HPP__
