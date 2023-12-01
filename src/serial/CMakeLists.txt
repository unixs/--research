add_library(sparse OBJECT spase.cc)

include_directories(.)

add_executable(serial serial.cc)
target_link_libraries(serial PRIVATE sparse)
