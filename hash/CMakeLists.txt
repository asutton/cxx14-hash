# Copyright (c) 2016 Andrew Sutton
# All rights reserved

add_library(hash
  fnv1.cpp
  hash.cpp
)


macro(add_unit_test target)
  add_executable(${target} ${ARGN})
  target_link_libraries(${target} graph)
  add_test(${target} ${target})
endmacro()


# add_subdirectory(graph.test)
# add_subdirectory(digraph.test)
# add_subdirectory(dfs.test)
# add_subdirectory(queue.test)
