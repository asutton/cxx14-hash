// Copyright (c) 2016 Andrew Sutton
// All rights reserved

#ifndef HASH_HASH_HPP
#define HASH_HASH_HPP

#include "fnv1.hpp"

#include <type_traits>


namespace origin {

// Hash append for trivially comparable T.
template<typename H, typename T>
inline typename std::enable_if<std::is_integral<T>::value, void>::type
hash_append(H& h, T const& t)
{
  h(&t, sizeof(t));
}

// Hash append for floating point T. Guarantee that 0 and -0 have the same 
// hash code since 0 == -0.
template<typename H, typename T>
inline typename std::enable_if<std::is_floating_point<T>::value, void>::type
hash_append(H& h, T t)
{
  if (t == 0)
    t = 0;
  h(&t, sizeof(t));
}

// Hash append for pointers-to-T. This just hashes the bits of the value.
template<typename H, typename T>
inline void
hash_append(H& h, const T* p)
{
  h(&p, sizeof(p));
}

// Hash append for nullptr.
template<typename H>
inline void
hash_append(H& h, std::nullptr_t p)
{
  h(&p, sizeof(p));
}

// Range-based hash append.
template<typename H, typename I>
inline void
hash_append(H& h, I first, I limit)
{
  while (first != limit) {
    hash_append(h, *first);
    ++first;
  }
}


// A std-compatible hash function.
template<typename H = fnv1a_hasher>
struct std_hash
{
  template<typename T>
  std::size_t operator()(T const& t) const {
    H h;
    hash_append(h, t);
    return h;
  }
};

} // namespace origin


#endif
