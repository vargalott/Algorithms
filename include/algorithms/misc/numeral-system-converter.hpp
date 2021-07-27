#pragma once
#ifndef __NUMERAL_SYSTEM_CONVERTER_HPP__
#define __NUMERAL_SYSTEM_CONVERTER_HPP__

#include <string>
#include <vector>

namespace algorithms::misc::numeral_system_converter {

class _10_to_x {
public:
  _10_to_x(short base);
  ~_10_to_x(void) = default;

  std::string convert(std::size_t decval) const;
private:
  std::vector<std::string> digits;
  short base;
};

} // namespace algorithms::misc::numeral_system_converter

#endif // !__NUMERAL_SYSTEM_CONVERTER_HPP__

