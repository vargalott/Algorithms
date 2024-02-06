

#include "RandomF.hpp"

std::mt19937 mt19937_random;
std::random_device rd;

std::uniform_int_distribution<short> rangeColor(10, 255);
std::uniform_real_distribution<float> rangeSize(10, 100);
std::uniform_real_distribution<float> rangeAngle(0.f, 360.f);
std::uniform_real_distribution<float> rangeSpeed(1.f, 10.f);
