// Copyright (c) 2016 Andrew Sutton
// All rights reserved

#ifndef HASH_FNV1_HPP
#define HASH_FNV1_HPP

#include <cstddef>
#include <cstdint>


namespace origin {

namespace fnv1_detail {

#ifndef ORIGIN_BITS
#  error Target architecture not configured
#endif

constexpr std::uint32_t prime_32() { return 16777619u; }
constexpr std::uint32_t basis_32() { return 2166136261u; }

constexpr std::uint64_t prime_64() { return 1099511628211ul; }
constexpr std::uint64_t basis_64() { return 14695981039346656037ul; }


#if ORIGIN_BITS == 32
constexpr std::size_t prime() { return prime_32(); }
constexpr std::size_t basis() { return basis_32(); }
#elif ORIGIN_BITS == 64
constexpr std::size_t prime() { return prime_64(); }
constexpr std::size_t basis() { return basis_64(); }
#else 
#  error Unknown target architecture
#endif

} // namespace fnv1_detail


// The fnv1a hash algorithm.
struct fnv1a
{
  fnv1a()
    : code(fnv1_detail::basis())
  { }

  void operator()(const void* p, int n) 
  {
    unsigned char const* first = static_cast<unsigned char const*>(p);
    unsigned char const* limit = first + n;
    for ( ; first != limit; ++first)
      code = (code ^ *first) * fnv1_detail::prime();
  }

  std::size_t code;
};

} // namespace origin


#endif
