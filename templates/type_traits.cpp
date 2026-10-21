#include <type_traits>
#include <cstdint>

static_assert(std::is_integral_v<int>);
static_assert(!std::is_integral_v<double>);
static_assert(std::is_same_v<int, int32_t>);
static_assert(std::is_trivially_copyable_v<int>);