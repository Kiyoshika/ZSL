enable_testing()

# ----------------------------------------------------------------------------------------------------

add_executable(
    CountNAtest
    dataset/aggregates/CountNAtest.cpp
)
target_link_libraries(
    CountNAtest
    ${CMAKE_SOURCE_DIR}/build/src/libzsl.a
    pthread
    gtest
)
target_include_directories(CountNAtest PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
add_test(CountNAtest CountNAtest)

# ----------------------------------------------------------------------------------------------------

add_executable(
    Appendtest
    dataset/append/Appendtest.cpp
)
target_link_libraries(
    Appendtest
    ${CMAKE_SOURCE_DIR}/build/src/libzsl.a
    pthread
    gtest
)
target_include_directories(Appendtest PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
add_test(Appendtest Appendtest)

# ----------------------------------------------------------------------------------------------------

add_executable(
    Castingtest
    dataset/casting/Castingtest.cpp
)
target_link_libraries(
    Castingtest
    ${CMAKE_SOURCE_DIR}/build/src/libzsl.a
    pthread
    gtest
)
target_include_directories(Castingtest PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
add_test(Castingtest Castingtest)

# ----------------------------------------------------------------------------------------------------