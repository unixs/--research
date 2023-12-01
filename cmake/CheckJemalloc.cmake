find_package(PkgConfig REQUIRED)

pkg_check_modules(JEMALLOC jemalloc)

include_directories(${JEMALLOC_INCLUDE_DIRS})
link_libraries(${JEMALLOC_LDFLAGS})
