cmake_minimum_required(VERSION 3.0.0)
project(riverine VERSION 0.1.0)

include(CTest)
enable_testing()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)



add_executable(riverine src/main.cpp)
add_executable(riverine_test src/test.cpp)
add_library(riverine_lib src/sph.hpp src/three_dimension.hpp)
set_target_properties(riverine_lib PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries (riverine ${CMAKE_THREAD_LIBS_INIT} riverine_lib)
target_link_libraries (riverine ${CMAKE_THREAD_LIBS_INIT} riverine_lib)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
