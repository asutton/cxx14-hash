// Copyright (c) 2016 Andrew Sutton
// All rights reserved

#include "../hash.hpp"
#include "../std.hpp"
#include "../debug.hpp"

#include <cassert>
#include <iostream>

using namespace std::literals;
using namespace origin;

int
main()
{
  origin::std_hash<debug_hasher> h;

  std::vector<int> v {1, 2, 3, 4, 5};

  h(5);
  h(3.1415);
  h("hello");
  h("hello"s);
  h(v);
}
