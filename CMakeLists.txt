cmake_minimum_required(VERSION 3.1)
project(exvote)

#add_subdirectory(src)
add_executable(exvote
  src/main.cpp /
  src/cp3.hpp /
  src/cp3.cpp /
  src/cp4.hpp /
  src/cp4.cpp /
  src/cp5.hpp /
  src/cp5.cpp /
  test/catch.hpp /
  test/test3.cpp /
  test/test4.cpp /
  test/test5.cpp
)
#backup
#add_executable(exvote
#  src/main.cpp /
#  src/topic.cpp /
# src/topic.hpp /
#  src/cp1.cpp /
#  src/cp1.hpp /
#  src/cp2.cpp /
#  src/cp2.hpp /
#  src/cp3.hpp /
#  src/cp3.cpp /
#  test/catch.hpp /
#  test/test.cpp /
#  test/test1.cpp /
#  test/test2.cpp /
#  test/test3.cpp
#)
