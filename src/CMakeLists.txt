add_library(zslib 
    include/dataset/constructors/Constructors.cpp
    include/dataset/operators/Operators.cpp
)
target_include_directories(zslib PRIVATE include include/dataset)

add_executable(main main.cpp)
target_link_libraries(main zslib)
