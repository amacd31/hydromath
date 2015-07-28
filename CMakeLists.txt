cmake_minimum_required (VERSION 2.6)
project (HydroMath)

add_executable(test_hydromath stats.c hydromath.c test.c)
add_library(hydromath SHARED stats.c hydromath.c)
target_link_libraries(test_hydromath hydromath m)
