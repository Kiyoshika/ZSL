add_library(zsl 
    dataset/constructors/Constructors.cpp
    dataset/operators/Operators.cpp
    dataset/encapsulators/Encapsulators.cpp
    dataset/DataSet.cpp
    dataset/io/DataIO.cpp
    dataset/casting/Casting.cpp
    dataset/select/Select.cpp
    dataset/filter/Filter.cpp
    dataset/drop/Drop.cpp
    dataset/replace/Replace.cpp
    dataset/sample/Sample.cpp
)
target_include_directories(zsl PRIVATE include)

add_executable(main main.cpp)
target_link_libraries(main zsl)
