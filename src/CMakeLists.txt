add_library(zslib 
    include/dataset/constructors/Constructors.cpp
    include/dataset/operators/Operators.cpp
    include/dataset/encapsulators/Encapsulators.cpp
    include/dataset/DataSet.cpp
)
target_include_directories(zslib PRIVATE include)

add_executable(main main.cpp)
target_link_libraries(main zslib)
