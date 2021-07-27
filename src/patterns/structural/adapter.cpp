#include <algorithms/patterns/structural/adapter.hpp>

using namespace patterns::structural::adapter;

std::string service::do_smth_diff(void) { return "[service do_smth]"; }
std::string adapter::do_smth(void) noexcept { return this->do_smth_diff(); }
