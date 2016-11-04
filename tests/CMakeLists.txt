include_directories(${PROJECT_SOURCE_DIR}/includes)
add_executable(test_hydromath test_stats.c)
target_link_libraries(test_hydromath hydromath check m)
