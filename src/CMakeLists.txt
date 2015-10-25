include_directories(${PROJECT_SOURCE_DIR}/includes)
add_executable(test_hydromath stats.c hydromath.c test.c)
add_library(hydromath SHARED stats.c hydromath.c)
target_link_libraries(test_hydromath hydromath m)

install(TARGETS hydromath EXPORT libExport
    DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/includes/hydromath.h DESTINATION include)
