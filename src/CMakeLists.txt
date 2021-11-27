add_library(zsl 
    dataset/constructors/Constructors.cpp
    dataset/operators/Operators.cpp
    dataset/encapsulators/Encapsulators.cpp
    dataset/DataSet.cpp
    dataset/io/DataIO.cpp
)
target_include_directories(zsl PRIVATE include)

add_executable(main main.cpp)
target_link_libraries(main zsl)
