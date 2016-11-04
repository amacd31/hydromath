include_directories(${PROJECT_SOURCE_DIR}/includes)
add_library(hydromath SHARED stats.c hydromath.c)

install(TARGETS hydromath EXPORT libExport
    DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/includes/hydromath.h DESTINATION include)
