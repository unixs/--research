cmake_minimum_required(VERSION 3.15)

project(c-research
	LANGUAGES C CXX
	VERSION 0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CheckCPUFlags)
include(BuildConfig)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)
