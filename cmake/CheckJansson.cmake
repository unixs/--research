find_package(PkgConfig REQUIRED)

pkg_check_modules(JANSSON REQUIRED jansson)

include_directories(${JANSSON_INCLUDE_DIRS})
link_libraries(${JANSSON_LDFLAGS})
