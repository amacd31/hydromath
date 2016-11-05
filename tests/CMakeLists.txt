include_directories(${PROJECT_SOURCE_DIR}/includes)
add_executable(test_hydromath test.c test_stats.c test_hydromath.c)
target_link_libraries(test_hydromath hydromath check m)
