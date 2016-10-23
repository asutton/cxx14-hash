// Copyright (c) 2016 Andrew Sutton
// All rights reserved

#include "../hash.hpp"
#include "../std.hpp"

#include <cassert>
#include <iostream>

using namespace std::literals;
using namespace origin;

int
main()
{
  origin::std_hash<> h;

  std::vector<int> v {1, 2, 3, 4, 5};

  std::cout << h(5) << '\n';
  std::cout << h(3.1415) << '\n';
  std::cout << h("hello") << '\n';
  std::cout << h("hello"s) << '\n';
  std::cout << h(v) << '\n';
}
