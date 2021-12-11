enable_testing()

add_executable(
    CountNAtest
    dataset/aggregates/CountNAtest.cpp
)
target_link_libraries(
    CountNAtest
    ${CMAKE_SOURCE_DIR}/build/src/libzsl.a
    pthread
    gtest_main
)
target_include_directories(CountNAtest PRIVATE ${CMAKE_SOURCE_DIR}/src/include)

add_test(CountNAtest CountNAtest)