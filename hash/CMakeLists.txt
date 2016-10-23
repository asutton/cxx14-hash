# Copyright (c) 2016 Andrew Sutton
# All rights reserved

add_library(hash
  fnv1.cpp
  debug.cpp
  hash.cpp
  std.cpp
)

macro(add_unit_test target)
  add_executable(${target} ${ARGN})
  target_link_libraries(${target} hash)
  add_test(${target} ${target})
endmacro()


add_subdirectory(hash.test)
