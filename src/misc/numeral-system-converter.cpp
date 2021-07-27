#include <algorithms/misc/numeral-system-converter.hpp>

using namespace algorithms::misc::numeral_system_converter;

_10_to_x::_10_to_x(short base) : base(base) {
  this->digits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B",
                  "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
                  "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
}

std::string _10_to_x::convert(std::size_t decval) const {
  if (decval == 0) {
    return std::string();
  }

  std::string ret;
  ret.insert(0, this->digits[decval % this->base]);
  ret.insert(0, this->convert(decval /= this->base));

  return ret;
}
