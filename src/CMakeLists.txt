FILE(GLOB_RECURSE AllSources ./**.cpp)

add_library(zsl 
    ${AllSources}
)
target_compile_options(zsl PRIVATE -O2)
target_include_directories(zsl PRIVATE include)

add_executable(main main.cpp)
target_compile_options(main PRIVATE -O2)
target_link_libraries(main zsl)
