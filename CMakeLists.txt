cmake_minimum_required(VERSION 3.1)
project(exvote)

#add_subdirectory(src)
add_executable(exvote
  src/main.cpp /
  src/topic.cpp /
  src/topic.hpp /
  src/cp1.cpp /
  src/cp1.hpp /
  src/cp2.cpp /
  src/cp2.hpp /
  test/catch.hpp /
  test/test.cpp /
  test/test1.cpp /
  test/test2.cpp
)
