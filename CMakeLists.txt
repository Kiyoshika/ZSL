project(zslib)
cmake_minimum_required(3.1.0)

include(CTest)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)