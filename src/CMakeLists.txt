add_library(zslib 
    dataset/constructors/Constructors.cpp
    dataset/operators/Operators.cpp
    dataset/encapsulators/Encapsulators.cpp
    dataset/DataSet.cpp
)
target_include_directories(zslib PRIVATE include)

add_executable(main main.cpp)
target_link_libraries(main zslib)
