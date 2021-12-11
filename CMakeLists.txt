set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(zsl)
cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)