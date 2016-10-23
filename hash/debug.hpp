// Copyright (c) 2016 Andrew Sutton
// All rights reserved

#ifndef HASH_DEBUG_HPP
#define HASH_DEBUG_HPP

#include <vector>
#include <iostream>
#include <iomanip>


namespace origin {

// A debug hasher that accumulates the hashed bytes.
struct debug_hasher
{
  void operator()(const void* p, int n) 
  {
    unsigned char const* first = static_cast<unsigned char const*>(p);
    unsigned char const* limit = first + n;
    bytes.insert(bytes.end(), first, limit);
  }

  operator std::size_t() const
  {
    std::cout << std::hex;
    std::cout << std::setfill('0');
    int n = 0;
    for (auto c : bytes) {
      std::cout << std::setw(2) << (int)c << ' ';
      if (++n == 16) {
        std::cout << '\n';
        n = 0;
      }
    }
    std::cout << '\n';
    std::cout << std::dec;
    std::cout << std::setfill(' ');
    return bytes.size();
  }

  std::vector<unsigned char> bytes;
};

} // namespace origin


#endif
